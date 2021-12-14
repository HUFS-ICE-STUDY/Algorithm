package com.algorithm.baekjoon;

import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ9205 {
    public static class Node {
        int x;
        int y;
        int dist;
        boolean visited;
        public Node(int x, int y, int dist, boolean visited) {
            this.x = x;
            this.y = y;
            this.dist = dist;
            this.visited = visited;
        }
    }
    public static void floydWarshallBFS(Node src) {
        Queue<Node> q = new LinkedList<>();
        q.offer(src);
        while(!q.isEmpty()) {
            // 시작 정점 정의
            Node start = q.poll();
            // 거쳐가려는 각각의 편의점에 대해서
            for(Node node : store) {
                // 해당 편의점이 방문되지 않았을 때
                if(!node.visited) {
                    // 맨하탄 거리 계산
                    int dist = Math.abs(start.x - node.x) + Math.abs(start.y - node.y);
                    // 시작 정점과 편의점의 거리가 1000 이하일 때
                    if(dist <= 1000) {
                        // 해당 편의점을 방문 예정으로 표시
                        node.visited = true;
                        // 해당 편의점의 거리 정보를 갱신
                        node.dist = dist;
                        // 다음에 방문하기 위해서 큐에 추가
                        q.offer(node);
                    }
                }
            }
        }
    }
    public static ArrayList<Node> store;
    public static ArrayList<Integer> result;
    public static int max = Integer.MAX_VALUE;
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

            store = new ArrayList<>();
            result = new ArrayList<>();

            // t : 테스트 케이스 개수
            int t = Integer.parseInt(br.readLine());
            for(int i=0; i<t; i++) {
                // n : 편의점의 개수
                int n = Integer.parseInt(br.readLine());

                // 상근이네 집의 좌표
                StringTokenizer st = new StringTokenizer(br.readLine());
                int src_x = Integer.parseInt(st.nextToken());
                int src_y = Integer.parseInt(st.nextToken());
                Node src = new Node(src_x, src_y, 0, true);

                // 각 편의점의 좌표
                for(int j=0; j<n; j++) {
                    st = new StringTokenizer(br.readLine());
                    int x = Integer.parseInt(st.nextToken());
                    int y = Integer.parseInt(st.nextToken());
                    store.add(new Node(x, y, max, false));
                }

                // 락 페스티벌(마지막 편의점)의 좌표
                st = new StringTokenizer(br.readLine());
                int dsc_x = Integer.parseInt(st.nextToken());
                int dsc_y = Integer.parseInt(st.nextToken());
                store.add(new Node(dsc_x, dsc_y, max, false));

                floydWarshallBFS(src);
                // 락 페스티벌의 거리값(dist)을 결과 리스트(result)에 저장
                Node dsc = store.get(store.size()-1);
                result.add(dsc.dist);
                // store 재사용을 위한 초기화
                store.clear();
            }

            // 각각의 결과에 대해서 max 값이면 sad, 아니면 happy
            for(int item : result) {
                if(item!=max) bw.write("happy\n");
                else bw.write("sad\n");
            }
            bw.close();
        } catch (IOException e) {
            e.getStackTrace();
        }
    }
}