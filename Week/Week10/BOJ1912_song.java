package com.algorithm.baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ1912 {
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
			
			// 입력
			int n = Integer.parseInt(br.readLine());
			String[] input = br.readLine().split(" ");
			
			// 선언 & 생성 & 초기화
			int[] arr = new int[n+1];
			for(int i=1; i<=n; i++)
				arr[i] = Integer.parseInt(input[i-1]);
			
			int max = Integer.MIN_VALUE;
			int[] dp = new int[n+1];
			for(int i=1; i<=n; i++) {
				// 이전 dp 및 현재 위치값을 더했을 때와 단순히 현재 위치값만을 비교
				// 점화식은 이전 합들을 끌고 갈 것인지 또는 버리고 갈 것인지를 결정해줌
				dp[i] = Math.max(dp[i-1]+arr[i], arr[i]);
				if(dp[i]>max) max = dp[i];
			}
			
			bw.write(max+"\n");
			bw.close();
		} catch(FileNotFoundException e) {
			e.getStackTrace();
		} catch(IOException e) {
			e.getStackTrace(); 
		}
	}
}