package com.algorithm.codetree.simulation;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class 떨어지는_1차_블록 {
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
			
			String[] str = br.readLine().split(" ");
			int n = Integer.parseInt(str[0]); // 격자의 크기 nxn
			int m = Integer.parseInt(str[1]); // 블록의 크기 1*m
			int k = Integer.parseInt(str[2])-1; /// 블록은 k번째 열부터 k+m-1번째 열까지의 공간을 차지하며 떨어짐
			
			if(n==1) bw.write(1+"\n"); // 입력이 1 1 1인 경우
			else {
				int[][] arr = new int[n][n];
				for(int i=0; i<n; i++) {
					str = br.readLine().split(" ");
					for(int j=0; j<n; j++) {
						arr[i][j] = Integer.parseInt(str[j]);
					}
				}
				
				// 블록의 모든 부분의 밑이 0이면 떨어지고
				// 블록의 모든 부분 중 밑이 하나라도 1이면 멈춤
				boolean isBlocked = false;
				int idx = 0;
				while(idx<n) {
					for(int j=k; j<k+m; j++) {
						if(arr[idx+1][j]==1) {
							isBlocked = true;
							break;
						}
					}
					if(isBlocked) break;
					idx++;
				}
				
				// idx행에 멈춘 블록의 값을 1로 채우기
				for(int i=k; i<k+m; i++)
					arr[idx][i] = 1;
				
				// 출력
				for(int i=0; i<n; i++) {
					for(int j=0; j<n; j++)
						bw.write(arr[i][j]+" ");
					bw.write("\n");
				}
			}
			bw.close();
		} catch(FileNotFoundException e) {
			e.getStackTrace();
		} catch(IOException e) {
			e.getStackTrace();
		}
	}
}