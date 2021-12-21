package com.algorithm.baekjoon;

import java.io.*;
import java.util.HashSet;
import java.util.StringTokenizer;

public class BOJ1987 {
    public static int cnt = 0;
    public static char[][] grid;
    public static HashSet<Character> set;
    public static int max = Integer.MIN_VALUE;
    public static int[] dx = { -1, 0, 1, 0 };
    public static int[] dy = { 0, -1, 0, 1 };
    public static void dfs(int x, int y, int r, int c) {
        // 지나는 알파벳 개수 1 증가
        cnt++;
        // 방문한 알파벳은 다시 방문하지 않기 위해서 체크
        set.add(grid[x][y]);
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 범위 제한
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            // 다음으로 방문하려는 알파벳이 방문하지 않은 알파벳이라면 DFS 수행
            if(!set.contains(grid[nx][ny])) dfs(nx, ny, r, c);
        }
        // 알파벳을 가장 많이 지나는 경로를 max로 갱신
        max = Math.max(max, cnt);
        // 다른 경로가 현재 알파벳을 탐색해야하므로 집합에서 제거
        set.remove(grid[x][y]);
        // cnt 재사용을 위해서 -1
        cnt--;
    }
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

            StringTokenizer st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            grid = new char[r][c];
            for(int i=0; i<r; i++) {
                String input = br.readLine();
                for(int j=0; j<c; j++) {
                    grid[i][j] = input.charAt(j);
                }
            }

            set = new HashSet<>();
            dfs(0, 0, r, c);

            bw.write(max+"\n");
            bw.close();
        } catch (IOException e) {
            e.getStackTrace();
        }
    }
}