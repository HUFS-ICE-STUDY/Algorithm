package com.algorithm.baekjoon;

import java.io.*;

public class BOJ10844 {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

            int n = Integer.parseInt(br.readLine());
            long[][] dp = new long[n+1][10];
            // 숫자 1부터 9까지의 DP는 1로 초기화
            for(int j=1; j<=9; j++)
                dp[1][j] = 1;
            // DP
            for(int i=2; i<=n; i++) {
                for(int j=0; j<=9; j++) {
                    if(j==0) dp[i][j] = dp[i-1][j+1] % 1000000000;
                    else if(j==9) dp[i][j] = dp[i-1][j-1] % 1000000000;
                    else dp[i][j] += (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
                }
            }

            long result = 0;
            for(long item : dp[n])
                result += item;
            bw.write(result%1000000000+"\n");
            bw.close();
        } catch(FileNotFoundException e) {
            e.getStackTrace();
        } catch(IOException e) {
            e.getStackTrace();
        }
    }
}