package com.algorithm.baekjoon;

import java.io.*;
import java.util.Stack;

public class BOJ10773 {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

            int n = Integer.parseInt(br.readLine());

            Stack<Integer> s = new Stack<>();
            for(int i=0; i<n; i++) {
                int input = Integer.parseInt(br.readLine());
                if(input==0) {
                    // 재민이가 쓴 수가 없는데 재현이가 0을 부르는 경우
                    if(s.isEmpty()) continue;
                    // 재민이가 쓴 수가 있는데 재현이가 0을 부르는 경우
                    s.pop();
                }
                // 재현이가 0을 부르지 않는 경우 스택에 넣음
                else s.push(input);
            }

            int sum = 0;
            while(!s.isEmpty()) {
                // 스택이 빌 때까지 데이터를 뽑아내서 sum에 더해줌
                sum += s.pop();
            }
            bw.write(sum+"\n");
            bw.close();
        } catch(FileNotFoundException e) {
            e.getStackTrace();
        } catch(IOException e) {
            e.getStackTrace();
        }
    }
}