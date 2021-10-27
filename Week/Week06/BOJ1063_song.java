package com.algorithm.baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ1063 {
	public static int[][] grid;
	public static int king_row, king_col, stone_row, stone_col;
	public static int[] dr = { -1, -1, 0, 1, 1, 1, 0, -1 }; // 상, 우상, 우, 우하, 하, 좌하, 좌, 좌상
	public static int[] dc = { 0, 1, 1, 1, 0, -1, -1, -1 }; // 상, 우상, 우, 우하, 하, 좌하, 좌, 좌상
	public static void move(String cmd) {
		int dir = decideDir(cmd);
		int nkr = king_row + dr[dir];
		int nkc = king_col + dc[dir];

		// 왕이 범위 밖으로 나가면 return
		if(!inRange(nkr, nkc)) return;
		// 왕이 이동하려는 위치에 돌이 있으면 돌을 이동해야 함
		if(nkr==stone_row && nkc==stone_col) {
			int nsr = stone_row + dr[dir];
			int nsc = stone_col + dc[dir];
			// 돌이 범위 밖으로 나가면 return
			if(!inRange(nsr, nsc)) return;
			// 돌이 범위 밖으로 나가지 않으면 돌을 이동
			stone_row = nsr;
			stone_col = nsc;
		}
		// 왕이 범위 밖을 나가지 않으므로 이동하려는 위치에 돌이 있든 없든 이동
		king_row = nkr;
		king_col = nkc;
	}
	public static boolean inRange(int row, int col) {
		if(row<0 || row>=8 || col<0 || col>=8) return false;
		else return true;
	}
	public static int decideDir(String cmd) {
		switch(cmd) {
		case "B": return 0;
		case "RB": return 1;
		case "R": return 2;
		case "RT": return 3;
		case "T": return 4;
		case "LT": return 5;
		case "L": return 6;
		default: return 7;
		}
	}
	public static int convert(String alphabet) {
		switch(alphabet) {
		case "A": return 0;
		case "B": return 1;
		case "C": return 2;
		case "D": return 3;
		case "E": return 4;
		case "F": return 5;
		case "G": return 6;
		default: return 7;
		}
	}
	public static String convert(int col) {
		String result = "";
		switch(col) {
		case 0: return "A";
		case 1: return "B";
		case 2: return "C";
		case 3: return "D";
		case 4: return "E";
		case 5: return "F";
		case 6: return "G";
		case 7: return "H";
		}
		return result;
	}
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

			String[] input = br.readLine().split(" ");
			king_col = convert(input[0].substring(0, 1));
			king_row = Integer.parseInt(input[0].substring(1, 2))-1;
			stone_col = convert(input[1].substring(0, 1));
			stone_row = Integer.parseInt(input[1].substring(1, 2))-1;
			int n = Integer.parseInt(input[2]);

			grid = new int[8][8];
			for(int i=0; i<n; i++) {
				String cmd = br.readLine();
				move(cmd);
			}
			
			String result_king = convert(king_col)+Integer.toString(king_row+1);
			String result_stone = convert(stone_col)+Integer.toString(stone_row+1);
			bw.write(result_king+'\n');
			bw.write(result_stone+"\n");
			bw.close();
		} catch(FileNotFoundException e) {
			e.getStackTrace();
		} catch(IOException e) {
			e.getStackTrace();
		}
	}
}