package com.algorithm.baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

public class BOJ1057 {
	// 다음 라운드에 진출할 사람들의 리스트를 갱신해주는 메소드
	public static void migration(ArrayList<Integer> list, ArrayList<Integer> next) {
		list.clear();
		for(int item : next)
			list.add(item);
		next.clear();
	}
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

			String[] input = br.readLine().split(" ");
			int n = Integer.parseInt(input[0]);
			int kim = Integer.parseInt(input[1]);
			int lim = Integer.parseInt(input[2]);

			ArrayList<Integer> list = new ArrayList<Integer>();
			ArrayList<Integer> next = new ArrayList<Integer>();
			for(int i=1; i<=n; i++)
				list.add(i);
			
			int cnt = 0;
			boolean found = false;
			while(list.size()!=1) {
				cnt++;
				for(int i=0; i<list.size(); i+=2) {
					// 마지막으로 대결하는 조에서 대결할 상대방이 없는 경우(부전승으로 진출하는 경우)
					if(i==list.size()-1) break;
					// 김지민과 임한수가 대결 상대로 만났을 때
					if( (list.get(i)==kim && list.get(i+1)==lim) || (list.get(i+1)==kim && list.get(i)==lim) ) {
						found = true;
						break;
					}
					// 김지민 또는 임한수가 서로 만나지 못해서 상대방을 이기고 올라올 때
					else if(list.get(i+1)==kim || list.get(i+1)==lim) next.add(list.get(i+1));
					// 대결하는 사람이 김지민 또는 임한수가 아닐 때
					else next.add(list.get(i));
				}
				// 김지민과 임한수가 대결 상대로 만난 경우 반복문을 빠져나감
				if(found) break;

				// 현재 라운드에서 대결하는 사람의 수가 홀수일 때 마지막 사람은 부전승으로 진출
				if(list.size()%2==1) next.add(list.get(list.size()-1));
				
				// 다음 라운드에 진출할 사람들을 list에 추가하여 갱신
				migration(list, next);
			}
			
			if(found) bw.write(cnt+"\n");
			else bw.write(-1+"\n");
			bw.close();
		} catch(FileNotFoundException e) {
			e.getStackTrace();
		} catch(IOException e) {
			e.getStackTrace();
		}
	}
}