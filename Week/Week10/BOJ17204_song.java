package com.algorithm.baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashSet;

public class BOJ17204 {
	public static ArrayList<Integer> list;
	public static int theGameOfDeath(int n, int k) {
		HashSet<Integer> set = new HashSet<Integer>();
		int start, cnt;
		start = cnt = 0;
		
		// 0을 추가하는 것으로 시작
		set.add(start);
		while(!set.contains(list.get(start))) { // start가 가리키는 번호가 set에 없다면
			cnt++;
			set.add(list.get(start)); // start가 가리키는 번호를 set에 추가
			start = list.get(start); // start를 start가 가리키는 번호로 갱신
			if(start==k) break; // 갱신한 번호가 보성이의 번호면 즉시 반복문 탈출
		}
		// 보성이의 번호가 set에 없으면 접근이 불가한 것이므로 -1 반환
		if(!set.contains(k)) return -1;
		// 그렇지 않으면 cnt 반환
		return cnt;
	}
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

			// 입력
			String[] nk = br.readLine().split(" ");
			int n = Integer.parseInt(nk[0]);
			int k = Integer.parseInt(nk[1]);
			
			// 선언 & 생성 & 초기화
			list = new ArrayList<Integer>();
			for(int i=0; i<n; i++)
				list.add(Integer.parseInt(br.readLine()));
			
			// 출력
			bw.write(theGameOfDeath(n, k)+"\n");			
			bw.close();
		} catch(FileNotFoundException e) {
			e.getStackTrace();
		} catch(IOException e) {
			e.getStackTrace();
		}
	}
}