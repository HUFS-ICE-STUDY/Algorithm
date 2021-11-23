package com.algorithm.baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class BOJ1966 {
	public static class Print {
		int num;
		int priority;
		public Print(int num, int priority) {
			this.num = num;
			this.priority = priority;
		}
	}
	public static ArrayList<Integer> ans;
	public static LinkedList<Integer> list;
	public static void printer(int n, int m) {
		Queue<Print> q = new LinkedList<Print>();
		// 순서 출력을 위한 변수 cnt
		int cnt = 0;
		// 현재 문서의 우선도 보다 높은 우선도를 가진 프린트가 큐에 있는지 판단
		boolean exists = false;
		for(int i=0; i<n; i++)
			q.offer(new Print(i, list.get(i)));
		while(!q.isEmpty()) {
			Print print = q.poll();
			for(int i=1; i<list.size(); i++) {
				// 현재 문서의 우선도 보다 높은 우선도를 가진 프린트가 큐에 존재할 경우
				if(print.priority<list.get(i)) {
					// 현재 프린트의 우선도를 맨 뒤에 이동
					int tmp = list.get(0);
					list.removeFirst();
					list.addLast(tmp);
					// 현재 프린트 객체를 큐의 맨 뒤에 추가
					q.offer(print);
					// 현재 문서의 우선도 보다 높은 프린트 객체가 큐에 존재함을 의미
					exists = true;
					break;
				}
			}
			// 현재 문서의 우선도 보다 높은 우선도를 가진 프린트가 큐에 존재하지 않을 경우
			if(!exists ) {
				// 출력 순서를 1 증가
				 cnt++;
				// 현재 프린트의 우선도를 제거
				list.removeFirst();
				// 현재 프린트의 번호가 요구하는 번호와 같은 경우 현재 출력 순서를 정답 리스트에 추가
				if(print.num==m) ans.add(cnt);
			}
			// 변수를 재사용하기 위해서 false로 초기화
			exists = false;
		}
	}
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

			ans = new ArrayList<Integer>();
			
			int t = Integer.parseInt(br.readLine());
			for(int i=0; i<t; i++) {
				// 입력
				String[] nm = br.readLine().split(" ");
				String[] input = br.readLine().split(" ");
				
				int n = Integer.parseInt(nm[0]); // 문서의 개수
				int m = Integer.parseInt(nm[1]); // 타겟 문서 번호
				
				// 생성 & 초기화
				list = new LinkedList<Integer>();
				for(int j=0; j<n; j++)
					list.add(Integer.parseInt(input[j]));
				printer(n, m);
			}
			
			// 출력
			for(int item : ans)
				bw.write(item+"\n");
			bw.close();
		} catch(FileNotFoundException e) {
			e.getStackTrace();
		} catch(IOException e) {
			e.getStackTrace(); 
		}
	}
}
