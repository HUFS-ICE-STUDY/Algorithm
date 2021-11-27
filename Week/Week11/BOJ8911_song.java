package com.algorithm.baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

public class BOJ8911 {
	public static int minX, minY, maxX, maxY, dir ;
	public static int[] dx = { -1, 0, 1, 0 }; // 상, 우, 하, 좌
	public static int[] dy = { 0, 1, 0, -1 }; // 상, 우, 하, 좌
	public static int[][] grid;
	public static ArrayList<Integer> list;
	public static void turtle(String input) {
		int x, y;
		x = y = minX = minY = maxX = maxY = 250;
		grid[x][y] = 1;
		for(int i=0; i<input.length(); i++) {
			int nx, ny;
			switch(input.charAt(i)) {
			// 거북이가 앞으로 가는 경우
			case 'F':
				nx = x + dx[dir];
				ny = y + dy[dir];
				grid[nx][ny] = 1;
				x = nx; y = ny;
				minX = Math.min(minX,  x); minY = Math.min(minY,  y);
				maxX = Math.max(maxX,  x); maxY = Math.max(maxY,  y);
				break;
			// 거북이가 뒤로 가는 경우(0->2, 1->3, 2->0, 3->1)
			case 'B':
				nx = x + dx[(dir+2)%4];
				ny = y + dy[(dir+2)%4];
				grid[nx][ny] = 1;
				x = nx; y = ny;
				minX = Math.min(minX,  x); minY = Math.min(minY,  y);
				maxX = Math.max(maxX,  x); maxY = Math.max(maxY,  y);
				break;
			// 거북이가 왼쪽으로 회전하는 경우(0->3, 1->0, 2->1, 3->2)
			case 'L':
				if(dir==0) dir = 3;
				else dir -= 1; 
				break;
			// 거북이가 오른쪽으로 회전하는 경우(0->1, 1->2, 2->3, 3->0)
			case 'R':
				dir = (dir+1)%4;
				break;
			}
		}
	}
	public static void countArea() {
		if(minX==maxX || minY==maxY) list.add(0);
		else list.add((maxX-minX) * (maxY-minY));
	}
	// 메모리 제한 때문에 반복마다 메모리 할당이 불가능하므로 모든 원소를 0으로 초기화 
	public static void initializeZero() {
		for(int i=0; i<grid.length; i++) {
			for(int j=0; j<grid[i].length; j++) {
				grid[i][j] = 0;
			}
		}
	}
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

			int t = Integer.parseInt(br.readLine());
			list = new ArrayList<Integer>();
			grid = new int[501][501];
			
			for(int i=0; i<t; i++) {
				String input = br.readLine();
				// 거북이가 명령에 따라서 움직이며 최대 x, y와 최소 x, y를 기록
				turtle(input);
				// (최대 x - 최소 x) X (최대 y - 최소 y)를 통해서 넓이 계산
				countArea();
				// 모든 원소를 0으로 초기화하여 grid 배열을 재사용
				initializeZero();
			}

			for(int item : list)
				bw.write(item+"\n");
			bw.close();
		} catch(FileNotFoundException e) {
			e.getStackTrace();
		} catch(IOException e) {
			e.getStackTrace();
		}
	}
}