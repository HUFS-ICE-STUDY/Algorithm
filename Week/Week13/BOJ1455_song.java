package com.algorithm.baekjoon;

import java.io.*;
import java.util.StringTokenizer;

public class BOJ1455 {
    public static int[][] grid;
    public static int max_x, max_y, cnt;
    public static boolean found = false;
    // 주어진 탐색 범위 안에서 동전을 뒤집는 함수
    public static void reverseCoin() {
        for(int i=0; i<=max_x; i++) {
            for(int j=0; j<=max_y; j++) {
                if(grid[i][j]==0) grid[i][j] = 1;
                else if(grid[i][j]==1) grid[i][j] = 0;
            }
        }
        // 뒤집기 횟수 증가
        cnt++;
    }
    // 뒷면인 동전을 찾고 탐색 범위를 갱신하는 함수
    public static boolean findTail(int n, int m) {
        // 최대 x, 최대 y 초기화
        max_x = max_y = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                // 동전이 앞면이면 continue
                if(grid[i][j]==0) continue;
                // 동전이 뒷면이면 탐색 범위 갱신 및 찾았음을 표시
                if(max_x+max_y < i+j) {
                    max_x = i;
                    max_y = j;
                }
                found = true;
            }
        }
        return found;
    }
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            max_x = max_y = 0;

            grid = new int[n][m];
            for(int i=0; i<n; i++) {
                String num = br.readLine();
                for(int j=0; j<m; j++) {
                    grid[i][j] = Integer.parseInt(num.substring(j, j+1));
                }
            }

            cnt = 0;
            // 뒷면인 동전이 없을 때까지
            while(findTail(n,m)) {
                reverseCoin();
                // found 재사용
                found = false;
            }
            
            bw.write(cnt+"\n");
            bw.close();
        } catch(IOException e) {
            e.getStackTrace();
        }
    }
}