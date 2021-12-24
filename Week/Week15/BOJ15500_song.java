package com.algorithm.baekjoon;

import java.io.*;
import java.util.*;

public class BOJ15500 {
    public static int cnt = 0;
    public static ArrayList<Integer> list;
    public static ArrayList<Node> answer;
    public static HashMap<Integer, Stack<Integer>> map;
    static class Node {
        int key;
        int val;
        public Node(int key, int val) {
            this.key = key;
            this.val = val;
        }
    }
    public static void moveHanoi(int idx) {
        int max = list.get(list.size()-1);
        // idx번째 스택에 max 값이 존재할 때까지
        while(map.get(idx).contains(max)) {
            // 이동 횟수가 12345번을 넘으면 반복문 탈출
            if(cnt>12345) break;
            // idx의 peek 값이 max와 일치한다면
            if(Objects.equals(map.get(idx).peek(), max)) {
                // list에서 삭제
                list.remove(list.size()-1);
                // idx번째 스택에서 pop한 값을 마지막 스택으로 푸시
                max = map.get(idx).pop();
                map.get(2).push(max);
                // 이동 횟수 증가 후에 반복문 탈출
                answer.add(new Node(idx, 2));
                cnt++;
                break;
            }
            // 만약에 idx가 0이라면 1로 이동, idx가 1이라면 0으로 이동
            int pop = map.get(idx).pop();
            map.get((idx+1)%2).push(pop);
            // 이동 횟수 증가
            answer.add(new Node(idx, (idx+1)%2));
            cnt++;
        }
    }
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

            int n = Integer.parseInt(br.readLine());

            list = new ArrayList<>();
            answer = new ArrayList<>();

            map = new HashMap<>();
            map.put(0, new Stack<>());
            map.put(1, new Stack<>());
            map.put(2, new Stack<>());

            StringTokenizer st = new StringTokenizer(br.readLine());
            while(st.hasMoreTokens()) {
                int token = Integer.parseInt(st.nextToken());
                map.get(0).push(token);
                list.add(token);
            }

            // 오름차순 정렬
            Collections.sort(list);
            // 리스트가 빌 때까지 진행
            while(!list.isEmpty()) {
                // 이동 횟수가 12345번을 넘으면 반복문 탈출
                if(cnt>12345) break;
                // 0번째, 1번째 스택에서만 max 값의 이동이 존재
                for(int i=0; i<2; i++) {
                    // i번째 스택에 max 값이 존재하면
                    if(map.get(i).contains(list.get(list.size()-1))) {
                        // 무조건 2번 스택으로 max 값이 옮겨지므로 다음 while 진행
                        moveHanoi(i);
                        break;
                    }
                }
            }

            if(cnt>12345) bw.write(-1+"\n");
            else {
                bw.write(cnt+"\n");
                for(Node node : answer) {
                    int key = node.key+1;
                    int val = node.val+1;
                    bw.write(key+ " " + val +"\n");
                }
            }
            bw.close();
        } catch (IOException e) {
            e.getStackTrace();
        }
    }
}