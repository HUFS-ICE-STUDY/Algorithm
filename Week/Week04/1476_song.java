package com.algorithm.baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ1476 {
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

			String[] esm = br.readLine().split(" ");
			int E = Integer.parseInt(esm[0]);
			int S = Integer.parseInt(esm[1]);
			int M = Integer.parseInt(esm[2]);
			
			int cnt = 1;
			int[] arr = new int[3];
			arr[0] = arr[1] = arr[2] = 1;
			while(arr[0]!=E || arr[1]!=S || arr[2]!=M) {
				if(++arr[0]>15) arr[0] = 1;
				if(++arr[1]>28) arr[1] = 1;
				if(++arr[2]>19) arr[2] = 1;
				cnt++;
			}
			
			// 출력
			bw.write(cnt+"\n");
			bw.close();
		} catch(FileNotFoundException e) {
			e.getStackTrace();
		} catch(IOException e) {
			e.getStackTrace();
		}
	}
}