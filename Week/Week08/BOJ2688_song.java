package com.algorithm.baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

public class BOJ2688 {
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

			int n = Integer.parseInt(br.readLine());
			
			ArrayList<Integer> list = new ArrayList<Integer>();
			int max = Integer.MIN_VALUE;
			for(int i=0; i<n; i++) {
				int tmp = Integer.parseInt(br.readLine());
				max = Math.max(max, tmp);
				list.add(tmp);
			}
			
			// 줄어들지 않는 숫자로 구성된 수열 생성
			long[][] arr = new long[max][9];
			// 0번째 열의 값을 전부 1로
			for(int i=0; i<max; i++)
				arr[i][0] = 1;
			// 0번째 행의 값을 전부 1로
			for(int i=0; i<9; i++)
				arr[0][i] = 1;
			// i행 j열에 위치한 값은 i행 j-1열에 위치한 값 + i-1행 j열에 위치한 값
			for(int i=1; i<max; i++) {
				for(int j=1; j<9; j++) {
					arr[i][j] = arr[i][j-1] + arr[i-1][j];
				}
			}
			
			// DP 배열 생성
			long[] dp = new long[max];
			// 맨 처음 배열은 편의상 10으로 초기화
			dp[0] = 10;
			// i번째 dp 배열은 i-1번째 dp 배열 + 줄어들지 않는 숫자로 구성된 수열의  i번째 행을 전부 합
			for(int i=1; i<max; i++) {
				long sum = 0;
				for(int j=0; j<9; j++)
					sum += arr[i][j];
				dp[i] = dp[i-1] + sum; 
			}
			
			for(int item : list)
				bw.write(dp[item-1]+"\n");
			bw.close();
		} catch(FileNotFoundException e) {
			e.getStackTrace();
		} catch(IOException e) {
			e.getStackTrace();
		}
	}
}
