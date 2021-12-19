package com.algorithm.baekjoon;

import java.io.*;
import java.util.HashMap;
import java.util.Stack;
import java.util.StringTokenizer;

public class BOJ2841 {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int p = Integer.parseInt(st.nextToken());

            HashMap<Integer, Stack<Integer>> map = new HashMap<>();

            int movement = 0;
            for(int i=0; i<n; i++) {
                st = new StringTokenizer(br.readLine());
                int line = Integer.parseInt(st.nextToken());
                int fret = Integer.parseInt(st.nextToken());
                // line에 해당하는 스택이 없으면 생성
                if(!map.containsKey(line)) map.put(line, new Stack<>());
                // 스택이 비어있으면 푸시
                if(map.get(line).isEmpty()) {
                    map.get(line).push(fret);
                    movement++;
                    continue;
                }
                // 스택이 비어있지 않은 상태에서 입력받은 프렛이 스택의 맨 위에 있는 프렛보다 작다면
                while(!map.get(line).isEmpty() && fret<map.get(line).peek()) {
                    map.get(line).pop();
                    movement++;
                }
                // 스택이 비어있으면 푸시
                if(map.get(line).isEmpty()) {
                    map.get(line).push(fret);
                    movement++;
                    continue;
                }
                // 입력받은 프렛이 스택의 맨 위에 있는 프렛보다 크다면 스택에 푸시
                if(fret>map.get(line).peek()) {
                    map.get(line).push(fret);
                    movement++;
                }
            }

            bw.write(movement+"\n");
            bw.close();
        } catch (IOException e) {
            e.getStackTrace();
        }
    }
}