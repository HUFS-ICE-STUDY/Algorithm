package com.algorithm.baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ1331 {
	public static int[][] grid;
	public static int[] dr = { -2, -1, 1, 2, 2, 1, -1, -2 };
	public static int[] dc = { 1, 2, 2, 1, -1, -2, -2, -1 };
	public static class Node {
		int row, col;
		public Node(int row, int col) {
			this.row = row;
			this.col = col;
		}
	}
	public static boolean check(int start_row, int start_col, int next_row, int next_col) {
		for(int i=0; i<8; i++) {
			int check_row = start_row + dr[i];
			int check_col = start_col + dc[i];
			// 나이트가 이동할 수 있는 8개의 위치와 입력받은 위치가 일치하는지 비교
			if(check_row!=next_row || check_col!=next_col) continue;
			// 범위 이탈 방지
			if(check_row>=0 && check_row<6 && check_col>=0 && check_col<6) {
				// 다음으로 방문할 위치가 방문된 적이 있으면 조건에 위배되므로 false 반환
				if(grid[check_row][check_col]==1) return false;
				else {
					// 다음으로 방문할 위치가 방문된 적이 없으면 옳게 이동한 것이므로 해당 위치를 1로 설정 및 true 반환
					grid[check_row][check_col] = 1;
					return true;
				}
			}
		}
		// 나이트가 이동할 수 있는 8개의 위치가 위의 조건문들에 하나도 해당하지 않으면 false 반환
		return false;
	}
	public static int convert(String alphabet) {
		int result = 0;
		switch(alphabet) {
		case "A":
			result = 0;
			break;
		case "B":
			result = 1;
			break;
		case "C":
			result = 2;
			break;
		case "D":
			result = 3;
			break;
		case "E":
			result = 4;
			break;
		case "F":
			result = 5;
		}
		return result;
	}
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

			Node[] arr = new Node[36];
			for(int i=0; i<36; i++) {
				String input = br.readLine();
				int input_row = convert(input.substring(0, 1));
				int input_col = Integer.parseInt(input.substring(1, 2))-1;
				arr[i] = new Node(input_row, input_col);
			}

			grid = new int[6][6];
			for(int i=1; i<36; i++) {
				int start_row = arr[i-1].row;
				int start_col = arr[i-1].col;
				int next_row = arr[i].row;
				int next_col = arr[i].col;
				// check 메소드를 통해서 한 번이라도 false가 반환되면 Invalid 출력 및 프로그램 종료
				if(!check(start_row, start_col, next_row, next_col)) {
					bw.write("Invalid\n");
					bw.close();
					return;
				}
			}
			
			// 마지막 위치로부터 시작 위치로 이동할 수 있는지 검사
			if(!check(arr[arr.length-1].row, arr[arr.length-1].col, arr[0].row, arr[0].col)) bw.write("Invalid\n");
			else bw.write("Valid\n");
			bw.close();
		} catch(FileNotFoundException e) {
			e.getStackTrace();
		} catch(IOException e) {
			e.getStackTrace();
		}
	}
}
