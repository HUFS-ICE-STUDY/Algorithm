package com.algorithm.baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;

public class BOJ1159 {
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
			
			int n = Integer.parseInt(br.readLine());
			
			ArrayList<String> arr = new ArrayList<String>();
			for(int i=0; i<n; i++) {
				arr.add(br.readLine().substring(0, 1)); // 첫번째 문자만 잘라서 리스트에 넣기
			}
			
			String str = "";
			HashSet<String> set = new HashSet<String>(arr); // 리스트에서 중복되는 요소를 제거해주는 HashSet 생성
			for(String abc : set) {
				if(Collections.frequency(arr, abc) < 5) continue; // HashSet 내의 각각의 원소들이 리스트에 5개 이하 존재할 경우
				else str += abc;
			}
			
			if(str.length()==0) bw.write("PREDAJA\n");
			else {
				char[] temp = str.toCharArray();
				Arrays.sort(temp);
				
				String result = new String(temp);
				bw.write(result+"\n");
			}
			bw.close();
		} catch(FileNotFoundException e) {
			e.getStackTrace();
		} catch(IOException e) {
			e.getStackTrace();
		}
	}
}
