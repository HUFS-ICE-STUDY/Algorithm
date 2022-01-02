package com.algorithm.baekjoon;

import java.io.*;
import java.util.ArrayList;
import java.util.Stack;

public class BOJ4889 {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

            Stack<Character> s = new Stack<>();
            ArrayList<Integer> list = new ArrayList<>();

            while(true) {
                int cnt = 0;
                String input = br.readLine();
                if(input.contains("-")) break;
                // 안정적인 문자열({})을 모두 제거하고 쌍이 없는 문자열만 푸시
                for(int i=0; i<input.length(); i++) {
                    char c = input.charAt(i);
                    if(!s.isEmpty() && s.peek()=='{' && c=='}') s.pop();
                    else s.push(c);
                }
                // 같은 방향을 보고 있으면 하나만 바꿔주면 되지만
                // 서로 다른 방향을 보고 있으면 둘 다 바꿔줘야함
                while(!s.isEmpty()) {
                    if(s.pop()=='{') cnt++;
                    if(s.pop()=='}') cnt++;
                }
                list.add(cnt);
            }

            for(int i=1; i<=list.size(); i++)
                bw.write(i+". "+list.get(i-1)+"\n");
            bw.close();
        } catch (IOException e) {
            e.getStackTrace();
        }
    }
}