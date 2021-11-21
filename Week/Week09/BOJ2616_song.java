package com.algorithm.baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ2616 {
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

			// 입력
			int n = Integer.parseInt(br.readLine()); // 객차의 개수
			String[] input = br.readLine().split(" ");
			int maxCarriage = Integer.parseInt(br.readLine()); // 소형기관차 한 대당 끌 수 있는 객차의 수
			
			// 선언 & 생성
			int[] arr = new int[n+1]; // 각각의 객차에 타고 있는 손님 수
			int[] sum = new int[n+1]; // 첫번째 객차부터 각 객차까지 타고 있는 손님 수의 누적합
			int[][] dp = new int[4][n+1];
			
			// 초기화
			for(int i=1; i<=n; i++) {
				arr[i] = Integer.parseInt(input[i-1]);
				sum[i] = sum[i-1] + arr[i];
			}

			// DP 알고리즘
			for(int i=1; i<=3; i++) {
				// 소형기관차 한 대당 끌 수 있는 객차의 수가 maxCarriage이므로
				// i대의 소형기관차로 i*maxCarrriage보다 적은 객차를 운용할 수 없음
				for(int j=i*maxCarriage; j<=n; j++) {
					// 소형기관차가 i대일 때 j개의 객차로 운용할 수 있는 최대 손님 수 구하기
					// dp[i][j-1] : i대의 소형기관차로 j번째 객차를 끌지 않고 j-1번째 객차까지 끄는 경우의 손님 수
					// dp[i-1][j-maxCarriage] + (sum[j] - sum[j-maxCarriage]): i대의 소형기관차로 j번째 객차를 끄는 경우,
					//  i-1대의 소형기관차로 j-maxCarriage번째 객차까지 끄는 경우의 손님 수 + j-maxCarriage의 다음 객차부터 j번째 객차까지의 손님 수의 누적합
					dp[i][j] = Math.max(dp[i][j-1], dp[i-1][j-maxCarriage] + (sum[j] - sum[j-maxCarriage]));
				}
			}
			
			bw.write(dp[3][n]+"\n");
			bw.close();
		} catch(FileNotFoundException e) {
			e.getStackTrace();
		} catch(IOException e) {
			e.getStackTrace();
		}
	}
}