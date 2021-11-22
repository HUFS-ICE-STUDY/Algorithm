package com.algorithm.baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ15988 {
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
			
			// 입력
			int n = Integer.parseInt(br.readLine());
			
			// 선언 & 생성 & 초기화
			int[] arr = new int[n];
			for(int i=0; i<n; i++)
				arr[i] = Integer.parseInt(br.readLine());
			
			// DP
			long[] dp = new long[1000001];
			dp[0] = 1; 
			dp[1] = dp[0];
			dp[2] = dp[0]+dp[1];
			for(int i=3; i<=1000000; i++)
				dp[i] = (dp[i-1]+dp[i-2]+dp[i-3])%1000000009;
			
			// 출력
			for(int item : arr)
				bw.write(dp[item]+"\n");
			bw.close();
		} catch(FileNotFoundException e) {
			e.getStackTrace();
		} catch(IOException e) {
			e.getStackTrace(); 
		}
	}
}