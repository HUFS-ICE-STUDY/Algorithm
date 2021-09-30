package com.algorithm.codetree;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class 핀볼게임 {
	public static int[] dx = { 0, 0, -1, 1 }; // 상, 하, 좌, 우
	public static int[] dy = { -1, 1, 0, 0 }; // 상, 하, 좌, 우
	public static int func(int[][] arr, int row, int col, int dir, int n) {
		int cnt = 0; // 격자를 빠져나오기까지 걸린 시간을 측정하기 위한 변수 cnt
		while(row>=0 && col>=0 && row<n && col<n) { // 격자를 빠져나올 때까지 반복
			cnt++; // 반복문이 한번 돌 때마다 cnt 1증가
			if(arr[row][col]==1) { // 상<->우 & 하<->좌
				switch(dir) {
				case 0:
					dir = 3;
					break;
				case 1:
					dir = 2;
					break;
				case 2:
					dir = 1;
					break;
				case 3:
					dir = 0;
					break;
				}
			} else if(arr[row][col]==2) { // 상<->좌 & 하<->우
				switch(dir) {
				case 0:
					dir = 2;
					break;
				case 1:
					dir = 3;
					break;
				case 2:
					dir = 0;
					break;
				case 3:
					dir = 1;
					break;
				}
			}
			col += dx[dir]; // 다음 x 위치 갱신
			row += dy[dir]; // 다음 y 위치 갱신
		}
		return cnt+1; // 빠져나오는 시간도 포함되므로 +1을 반환
	}
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
			
			int n = Integer.parseInt(br.readLine());
			int[][] arr = new int[n][n];
			for(int i=0; i<n; i++) {
				String[] str = br.readLine().split(" ");
				for(int j=0; j<n; j++) {
					arr[i][j] = Integer.parseInt(str[j]);
				}
			}
			
			int ans = 0;
			for(int i=0; i<n; i++) {
				ans = Math.max(ans, func(arr, n-1, i, 0, n));
				ans = Math.max(ans, func(arr, 0, i, 1, n));
				ans = Math.max(ans, func(arr, i, n-1, 2, n));
				ans = Math.max(ans, func(arr, i, 0, 3, n));
			}
			bw.write(ans+"\n");
			bw.close();
		} catch(FileNotFoundException e) {
			e.getStackTrace();
		} catch(IOException e) {
			e.getStackTrace();
		}
	}
}
