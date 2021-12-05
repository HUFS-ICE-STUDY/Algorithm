package com.algorithm.baekjoon;

import java.io.*;

public class BOJ14916 {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

            int n = Integer.parseInt(br.readLine());
            int[] dp = new int[n+1];
            for(int i=1; i<=n; i++) {
                int x, y;
                x = y = Integer.MAX_VALUE;
                // 거스름돈이 2보다 크고, 2를 뺐을 때 거슬러줄 수 있는 경우
                if(i-2>=0 && dp[i-2]!=-1) x = dp[i-2];
                // 거스름돈이 5보다 크고, 5를 뺐을 때 거슬러줄 수 있는 경우
                if(i-5>=0 && dp[i-5]!=-1) y = dp[i-5];
                // 거슬러 줄 수 없으면 -1
                if(x==Integer.MAX_VALUE && y==Integer.MAX_VALUE) dp[i] = -1;
                // 거슬러 줄 수 있으면 x와 y 중에 최솟값을 구해서 +1
                else dp[i] = Math.min(x, y) + 1;
            }

            bw.write(dp[n]+"\n");
            bw.close();
        } catch(FileNotFoundException e) {
            e.getStackTrace();
        } catch(IOException e) {
            e.getStackTrace();
        }
    }
}