package com.algorithm.baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ5212 {
	public static char[][] island, newIsland;
	public static void makeMap(int row, int col) {
		for(int i=1; i<row+1; i++) {
			for(int j=1; j<col+1; j++) {
				int cnt = 0; // 바다와 인접한 방향의 개수를 찾기 위한 변수 cnt
				if(island[i][j]=='.') continue; // 현재 위치가 섬이 아닌 바다인 경우 continue
				if(island[i-1][j]=='.') cnt++; // 섬의 윗 부분이 바다와 인접한 경우
				if(island[i+1][j]=='.') cnt++; 	// 섬의 아랫 부분이 바다와 인접한 경우
				if(island[i][j-1]=='.') cnt++; // 섬의 좌측 부분이 바다와 인접한 경우
				if(island[i][j+1]=='.') cnt++; // 섬의 우측 부분이 바다와 인접한 경우
				if(cnt>=3) newIsland[i][j] = '.'; // cnt가 3이상이라면 해당 위치의 X값을 '.'으로 변경
			}
		}
	}
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

			// 입력
			String[] input = br.readLine().split(" ");
			int r = Integer.parseInt(input[0]);
			int c = Integer.parseInt(input[1]);
			
			// 패딩을 이용하여 바다의 면적을 증가
			island = new char[r+2][c+2];
			newIsland = new char[r+2][c+2];
			// 패딩을 통해서 만들어진 바다를 '.'으로 표시
			for(int i=0; i<r+2; i++) {
				for(int j=0; j<c+2; j++) {
					island[i][j] = newIsland[i][j] =  '.';
				}
			}
			// 입력받은 지도를 통해서 섬의 위치를 'X'로 표시
			for(int i=1; i<r+1; i++) {
				String map = br.readLine();
				for(int j=1; j<c+1; j++) {
					island[i][j] = newIsland[i][j] = map.charAt(j-1);
				}
			}
			
			// 50년 후의 남아있는 섬을 지도에 표시하는 알고리즘
			makeMap(r, c);
			// 한 행 또는 한 열이 바다로 이뤄지면 지도에서
			// 없어지므로 정답을 출력하기 위한 지도를 재구성
			int minR, maxR, minC, maxC;
			minR = minC = Integer.MAX_VALUE;
			maxR = maxC = Integer.MIN_VALUE;
			for(int i=1; i<r+1; i++) {
				for(int j=1; j<c+1; j++) {
					if(newIsland[i][j]=='X') {
						minR = Math.min(minR,  i);
						maxR = Math.max(maxR,  i);
						minC = Math.min(minC,  j);
						maxC = Math.max(maxC,  j);
					}
				}
			}
			
			// 출력
			for(int i=minR; i<=maxR; i++) {
				for(int j=minC; j<=maxC; j++)
					bw.write(newIsland[i][j]+"");
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