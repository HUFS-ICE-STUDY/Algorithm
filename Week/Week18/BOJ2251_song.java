package com.algorithm.baekjoon;

import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.TreeSet;

public class BOJ2251 {
    public static int A, B, C;
    public static boolean[][][] visited;
    public static TreeSet<Integer> set;
    static class State {
        int a;
        int b;
        int c;
        public State(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }
    public static void bfs(int a, int b, int c) {
        Queue<State> q = new LinkedList<>();
        q.offer(new State(a, b, c));
        visited[a][b][c] = true;
        while(!q.isEmpty()) {
            State state = q.poll();
            if(state.a==0) set.add(state.c);
            // C에서 A로 물을 붓는 경우
            if(state.c>0 && state.a<A) {
                int nextC = 0;
                int nextA = state.c + state.a;
                // C+A가 A의 최대치를 넘기는 경우
                if(nextA > A) {
                    nextC = nextA - A;
                    nextA = A;
                }
                if(!visited[nextA][state.b][nextC]) {
                    q.offer(new State(nextA, state.b, nextC));
                    visited[nextA][state.b][nextC] = true;
                }
            }
            // C에서 B로 물을 붓는 경우
            if(state.c>0 && state.b<B) {
                int nextC = 0;
                int nextB = state.c + state.b;
                if(nextB > B) {
                    nextC = nextB - B;
                    nextB = B;
                }
                if(!visited[state.a][nextB][nextC]) {
                    q.offer(new State(state.a, nextB, nextC));
                    visited[state.a][nextB][nextC] = true;
                }
            }
            // B에서 A로 물을 붓는 경우
            if(state.b>0 && state.a<A) {
                int nextB = 0;
                int nextA = state.b + state.a;
                if(nextA > A) {
                    nextB = nextA - A;
                    nextA = A;
                }
                if(!visited[nextA][nextB][state.c]) {
                    q.offer(new State(nextA, nextB, state.c));
                    visited[nextA][nextB][state.c] = true;
                }
            }
            // B에서 C로 물을 붓는 경우
            if(state.b>0 && state.c<C) {
                int nextB = 0;
                int nextC = state.b + state.c;
                if(nextC > C) {
                    nextB = nextC - C;
                    nextC = C;
                }
                if(!visited[state.a][nextB][nextC]) {
                    q.offer(new State(state.a, nextB, nextC));
                    visited[state.a][nextB][nextC] = true;
                }
            }
            // A에서 B로 물을 붓는 경우
            if(state.a>0 && state.b<B) {
                int nextA = 0;
                int nextB = state.a + state.b;
                if(nextB > B) {
                    nextA = nextB - B;
                    nextB = B;
                }
                if(!visited[nextA][nextB][state.c]) {
                    q.offer(new State(nextA, nextB, state.c));
                    visited[nextA][nextB][state.c] = true;
                }
            }
            // A에서 C로 물을 붓는 경우
            if(state.a>0 && state.c<C) {
                int nextA = 0;
                int nextC = state.a + state.c;
                if(nextC > C) {
                    nextA = nextC - C;
                    nextC = C;
                }
                if(!visited[nextA][state.b][nextC]) {
                    q.offer(new State(nextA, state.b, nextC));
                    visited[nextA][state.b][nextC] = true;
                }
            }
        }
    }
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

            set = new TreeSet<>();

            String[] str = br.readLine().split(" ");
            A = Integer.parseInt(str[0]);
            B = Integer.parseInt(str[1]);
            C = Integer.parseInt(str[2]);

            visited = new boolean[A+1][B+1][C+1];
            bfs(0, 0, C);

            for(int item : set)
                bw.write(item+" ");
            bw.close();
        } catch (IOException e) {
            e.getStackTrace();
        }
    }
}