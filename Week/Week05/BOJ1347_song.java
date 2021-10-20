package com.algorithm.baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ1347 {
	public static int[] dx = { -1, 0, 1, 0 }; // 상, 좌, 하, 우
	public static int[] dy = { 0, -1, 0, 1 }; // 상, 좌, 하, 우
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
			
			int n = Integer.parseInt(br.readLine());
			String str = br.readLine();
			
			// 격자 내용을 모두 '#'으로 초기화
			char[][] grid = new char[101][101];
			for(int i=0; i<101; i++) {
				for(int j=0; j<101; j++) {
					grid[i][j] = '#';
				}
			}
			
			// x, y는 초기 시작 위치
			// minX, maxX는 X의 최소값과 최대값
			// minY, maxY는 Y의 최소값과 최대값
			int x, y, minX, minY, maxX, maxY;
			x = y = minX = minY = maxX = maxY = 50;
			
			int dir = 2; // 시작 방향을 아래로 표시
			grid[x][y] = '.'; // 시작 위치를 ' . '으로 표시
			for(int i=0; i<n; i++) {
				// 입력받은 문자가 'L'이면 왼쪽으로 회전
				if(str.charAt(i)=='L') {
					if(dir==3) dir=0;
					else dir += 1;
				// 입력받은 문자가 'R'이면 오른쪽으로 회전
				} else if(str.charAt(i)=='R') {
					if(dir==0) dir=3;
					else dir -= 1;
				} else {
					// 입력받은 문자가 'F'면 현재 바라보고 있는 방향으로 1칸 전진
					x += dx[dir];
					y += dy[dir];
					// 이동한 위치의 문자를 ' . '로 표시
					grid[x][y] = '.';
					// 이동한 지점과 현재 최소값/최대값을 비교하여 갱신
					minX = Math.min(minX, x);
					minY = Math.min(minY, y);
					maxX = Math.max(maxX, x);
					maxY = Math.max(maxY, y);
				}
			}
			
			// 결과 격자 출력
			for(int i=minX; i<=maxX; i++) {
				for(int j=minY; j<=maxY; j++)
					bw.write(grid[i][j]+"");
				bw.write("\n");
			}
			
			bw.close();
		} catch(FileNotFoundException e) {
			e.getStackTrace();
		} catch(IOException e) {
			e.getStackTrace();
		}
	}
}
