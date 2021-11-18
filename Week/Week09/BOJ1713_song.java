package com.algorithm.baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class BOJ1713 {
	public static class Student implements Comparable<Student> {
		int num = 0; // 학생의 번호
		int total = 0; // 학생이 받은 추천수
		int tStamp = 0; // 사진이 게시된 시간
		public Student(int num, int total, int tStamp) {
			this.num = num;
			this.total = total;
			this.tStamp = tStamp;
		}
		@Override
		public int compareTo(Student o) {
			// 후보들의 추천수가 동일하다면 사진이 게시된 시간이 빠른 후보순으로 정렬
			if(this.total == o.total) return this.tStamp - o.tStamp;
			// 후보들의 추천수가 같지 않다면 추천수가 낮은 후보순으로 정렬
			else return this.total - o.total;
		}
	}
	
	public static int[] arr;
	public static ArrayList<Student> list;
	public static void recommendation(int n) {
		list = new ArrayList<Student>();
		for(int i=0; i<arr.length; i++) {
			// 추천을 받은 후보의 사진이 게시되어 있지 않다면
			if(!onBoard(i)) {
				// 사진이 게시된 후보의 수가 사진틀의 개수와 같다면
				if(list.size()==n) {
					// 추천수가 가장 낮은 후보를 삭제하되
					// 추천수가 가장 낮은 후보가 여러명인 경우
					// 사진이 게시된 시간이 가장 빠른 후보를 삭제
					Collections.sort(list);
					list.remove(0);
				}
				// 추천을 받은 후보의 사진을 게시
				list.add(new Student(arr[i], 1, i));
			}
		}
	}
	
	// 추천을 받은 후보의 사진이 게시되어 있는지 확인
	public static boolean onBoard(int i) {
		for(int j=0; j<list.size(); j++) {
			// 추천을 받은 후보의 사진이 이미 게시되어 있는 경우
			// 해당 후보의 추천수를 1 증가시키고 true 반환
			if(list.get(j).num==arr[i]) {
				list.get(j).total += 1;
				return true;
			}
		}
		// 추천을 받은 후보의 사진이 게시되어 있지 않은 경우 false 반환
		return false;
	}
	
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

			// 입력
			int n = Integer.parseInt(br.readLine()); // 사진틀의 개수
			int m = Integer.parseInt(br.readLine());
			String[] input = br.readLine().split(" ");
			
			// 선언 & 초기화
			arr = new int[m];
			for(int i=0; i<m; i++)
				arr[i] = Integer.parseInt(input[i]);
			
			// 알고리즘
			recommendation(n);

			// 후보들의 번호를 오름차순으로 정렬
			Collections.sort(list, new Comparator<Student>() {
				@Override
				public int compare(Student o1, Student o2) {
					return o1.num - o2.num;
				}
			});
			
			// 최종 출력
			for(Student item : list)
				bw.write(item.num+" ");
			bw.close();
		} catch(FileNotFoundException e) {
			e.getStackTrace();
		} catch(IOException e) {
			e.getStackTrace();
		}
	}
}