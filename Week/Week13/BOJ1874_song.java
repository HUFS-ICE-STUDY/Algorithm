package com.algorithm.baekjoon;

import java.io.*;
import java.util.ArrayList;
import java.util.Stack;

public class BOJ1874 {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

            int n = Integer.parseInt(br.readLine());

            ArrayList<Integer> list = new ArrayList<>();
            ArrayList<Character> result = new ArrayList<>();
            for(int i=0; i<n; i++)
                list.add(Integer.parseInt(br.readLine()));

            Stack<Integer> s = new Stack<>();
            int idx = 0;
            // 1부터 n까지의 숫자에 대해서
            for(int i=1; i<=n; i++) {
                // 각각의 숫자를 스택에 푸시하고 result에 '+' 추가
                result.add('+');
                s.push(i);
                // 스택의 맨 위에 있는 숫자가 idx가 가리키는 숫자와 일치하는 경우
                while(!s.isEmpty() && s.peek().equals(list.get(idx))) {
                    // 스택에서 팝하고 result에 '-' 추가 및 idx 1증가
                    result.add('-');
                    s.pop();
                    idx++;
                }
            }
            
            // 스택이 비어있지 않으면 수열을 만들지 못하는 경우이므로 NO 출력
            if(!s.isEmpty()) bw.write("NO\n");
            // 스택이 비어있으면 수열을 모두 사용할 수 있다는 뜻이므로 연산 출력
            else {
                for(char item : result) {
                    bw.write(item + "\n");
                }
            }

            bw.close();
        } catch(IOException e) {
            e.getStackTrace();
        }
    }
}