package com.algorithm.baekjoon;

import java.io.*;
import java.util.StringTokenizer;

public class BOJ11048 {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            int[][] grid = new int[n+1][m+1];
            for(int i=1; i<=n; i++) {
                st = new StringTokenizer(br.readLine());
                for(int j=1; j<=m; j++) {
                    grid[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            int[][] dp = new int[n+1][m+1];
            dp[1][1] = grid[1][1];
            for(int i=1; i<=n; i++) {
                for(int j=1; j<=m; j++) {
                    // 행이 1이고 열이 1보다 크다면, 현재 위치의 사탕 개수와 이전 열의 dp 값을 더해줌
                    if(i==1 && j>1) dp[i][j] = grid[i][j] + dp[i][j-1];
                    // 열이 1이고 행이 1보다 크다면, 현재 위치의 사탕 개수와 이전 열의 dp 값을 더해줌
                    else if(i>1 && j==1) dp[i][j] = grid[i][j] + dp[i-1][j];
                    // 나머지 경우에 대해서 왼쪽에서 오는 값, 위에서 오는 값, 대각선에서 오는 값을 비교해서 가장 큰 값을 현재 위치의 사탕 개수와 더해줌
                    else dp[i][j] = grid[i][j] + Math.max(Math.max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
                }
            }

            bw.write(dp[n][m]+"\n");
            bw.close();
        } catch (IOException e) {
            e.getStackTrace();
        }
    }
}