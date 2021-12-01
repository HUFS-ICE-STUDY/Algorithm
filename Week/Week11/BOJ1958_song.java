package com.algorithm.baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ1958 {
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
			
			String a = br.readLine();
			String b = br.readLine();
			String c = br.readLine();
			
			int[][][] dp = new int[a.length()+1][b.length()+1][c.length()+1];
			for(int i=1; i<=a.length(); i++) {
				for(int j=1; j<=b.length(); j++) {
					for(int k=1; k<=c.length(); k++) {
						// 문자열 a의 i-1번째 문자, 문자열 b의 j-1번째 문자와 문자열 c의 k-1번째 문자가 일치하는 경우
						if(a.charAt(i-1)==b.charAt(j-1) && b.charAt(j-1)==c.charAt(k-1)) {
							// 이전 DP + 1
							dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
						}
						// 일치하지 않는 경우
						else {
							// 이전 값 중에서 가장 큰 값을 그대로 가져옴
							dp[i][j][k] = Math.max(Math.max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]);
						}
					}
				}
			}
			
			bw.write(dp[a.length()][b.length()][c.length()]+"\n");
			bw.close();
		} catch(FileNotFoundException e) {
			e.getStackTrace();
		} catch(IOException e) {
			e.getStackTrace(); 
		}
	}
}