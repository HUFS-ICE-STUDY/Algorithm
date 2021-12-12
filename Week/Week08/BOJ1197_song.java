package com.algorithm.baekjoon;

import java.io.*;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class BOJ1197 {
    public static class Node implements Comparable<Node> {
        int num;
        long weight;
        public Node(int num, long weight) {
            this.num = num;
            this.weight = weight;
        }
        @Override
        public int compareTo(Node o) {
            return Long.compare(this.weight, o.weight);
        }
    }
    public static ArrayList<ArrayList<Node>> list;
    public static PriorityQueue<Node> pq;
    public static boolean[] visited;
    public static long prim(int src, int n) {
        int cnt = 0;
        long sum = 0;
        pq.offer(new Node(src, 0));
        // 우선순위 큐를 통해서 간선의 가중치가 작은 정점들을 우선적으로 방문함
        // 따라서 큐에 들어간 정점이 다시 큐에 들어가도 가중치가 더 작은 정점이 앞으로 옴
        while(!pq.isEmpty()) {
            Node node = pq.poll();
            // 큐에서 node를 꺼냈는데 방문한 정점이면 패스
            if(visited[node.num]) continue;
            // 방문하지 않은 정점이면 방문 처리해주고 가중치를 더해줌
            visited[node.num] = true;
            sum += node.weight;
            // 그래프에서의 정점 개수와 방문한 정점 개수 같으면 탈출
            if(++cnt==n) break;
            // 해당 노드와 인접한 정점들에 대해서 방문되지 않았으면 큐에 추가
            for(int i=0; i<list.get(node.num).size(); i++) {
                Node next = list.get(node.num).get(i);
                if(visited[next.num]) continue;
                pq.offer(next);
            }
        }
        return sum;
    }
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

            // 입력
            String[] nm = br.readLine().split(" ");
            int n = Integer.parseInt(nm[0]);
            int m = Integer.parseInt(nm[1]);

            // 선언 & 생성
            list = new ArrayList<ArrayList<Node>>();
            for(int i=0; i<=n; i++)
                list.add(new ArrayList<Node>());

            // 초기화
            for(int i=0; i<m; i++) {
                String[] uvw = br.readLine().split(" ");
                int u = Integer.parseInt(uvw[0]);
                int v = Integer.parseInt(uvw[1]);
                long w = Long.parseLong(uvw[2]);
                list.get(u).add(new Node(v, w));
                list.get(v).add(new Node(u, w));
            }

            visited = new boolean[n+1];
            pq = new PriorityQueue<>();
            bw.write(prim(1, n)+"\n");
            bw.close();
        } catch(IOException e) {
            e.getStackTrace();
        }
    }
}