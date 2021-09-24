package com.algorithm.codetree.simulation;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.LinkedList;

public class 십자_모양_폭발 {
	public static int[] dx = { -1, 1, 0, 0 }; // 좌, 우, 상, 하
	public static int[] dy = { 0, 0, 1, -1 }; // 좌, 우, 상, 하
	public static void func(ArrayList<LinkedList<Integer>> list, int row, int col, int n) {
		// 반복 횟수를 구하기 위한 변수 val
		int val = list.get(col).get(n-1-row)-1;
		
		// 폭발 범위의 수평에 위치한 노드들을 삭제
		for(int i=0; i<2; i++) { // 방향 관련
			int nx = col;
			int ny = n-1-row;
			for(int j=0; j<val; j++) { // 횟수 관련
				nx += dx[i];
				if(nx>=0 && nx<n) {
					list.get(nx).remove(ny);
					list.get(nx).addLast(0);
				}
			}
		}
		
		// 폭발 범위의 수직에 위치한 값들을 0으로 변환
		for(int i=2; i<4; i++) {
			int ny = n-1-row;
			for(int j=0; j<val; j++) {
				ny += dy[i];
				if(ny>=0 && ny<n) list.get(col).set(ny, 0);
			}
		}
		
//		// 
//		for(int i=0; i<list.get(col).size(); i++) {
//			if(list.get(col).get(i)==0) {
//				while(list.get(col).get(i+1)!=0) {
//					list.get(col).remove(i);
//					list.get(col).addLast(0);
//				}
//				break;
//			}
//		}
	}
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
			
			int n = Integer.parseInt(br.readLine());
			ArrayList<LinkedList<Integer>> list = new ArrayList<LinkedList<Integer>>();
			for(int i=0; i<n; i++)
				list.add(new LinkedList<Integer>());
			
			// 각각의 LinkedList를 초기화하는 과정
			for(int i=0; i<n; i++) {
				String[] str = br.readLine().split(" ");
				for(int j=0; j<str.length; j++) {
					list.get(j).addFirst(Integer.parseInt(str[j]));
				}
			}
			
			String[] str = br.readLine().split(" ");
			int row = Integer.parseInt(str[0])-1;
			int col = Integer.parseInt(str[1])-1;
			
			func(list, row, col, n);
			
			for(int j=n-1; j>=0; j--) {
				for(int i=0; i<n; i++)
					bw.write(list.get(i).get(j)+" ");
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