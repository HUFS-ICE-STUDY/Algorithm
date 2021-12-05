package com.algorithm.baekjoon;

import java.io.*;
import java.util.PriorityQueue;

public class BOJ18405 {
    static class Virus implements Comparable<Virus> {
        // 바이러스 번호 및 위치 정보
        int index = 0;
        int x = 0;
        int y = 0;
        
        // 생성자
        public Virus(int index, int x, int y) {
            this.index = index;
            this.x = x;
            this.y = y;
        }
        
        // 인덱스 비교해서 오름차순으로 큐에 삽입
        @Override
        public int compareTo(Virus o) {
            if(this.index < o.index) return -1;
            else return 1;
        }
    }
    public static int[][] grid;
    public static boolean[][] visited;
    public static PriorityQueue<Virus> pq, nextPQ;
    public static int[] dx = { 1, -1, 0, 0 };
    public static int[] dy = { 0, 0, -1, 1 };
    public static void func() {
        // 바이러스들을 모두 퍼뜨릴 때까지
        while(!pq.isEmpty()) {
            Virus v = pq.poll();
            // 바이러스의 현재 위치가 방문됐음을 표시
            visited[v.x][v.y] = true;
            for(int i=0; i<4; i++) {
                int nx = v.x + dx[i];
                int ny = v.y + dy[i];
                // 범위 제한
                if(nx>=0 && nx<grid.length && ny>=0 && ny<grid.length) {
                    if(!visited[nx][ny]) {
                        // 바이러스가 퍼진 곳을 바이러스의 번호로 변경
                        grid[nx][ny] = v.index;
                        // 해당 위치는 바이러스가 방문됐으므로 true 표시
                        visited[nx][ny] = true;
                        // 다음으로 퍼뜨릴 바이러스의 번호와 위치 정보를 큐에 추가
                        nextPQ.offer(new Virus(grid[nx][ny], nx, ny));
                    }
                }
            }
        }
        migration();
    }
    // 다음 회차에서 퍼뜨릴 바이러스를 갱신
    public static void migration() {
        pq.clear();
        while(!nextPQ.isEmpty()) {
            pq.offer(nextPQ.poll());
        }
    }
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

            String[] nk = br.readLine().split(" ");
            int n = Integer.parseInt(nk[0]);
            int k = Integer.parseInt(nk[1]);

            // 바이러스를 번호의 오름차순으로 퍼뜨리기 위한 우선순위 큐
            pq = new PriorityQueue<>();
            // 다음 회차에 퍼뜨릴 바이러스를 위한 우선순위 큐
            nextPQ = new PriorityQueue<>();

            grid = new int[n][n];
            for(int i=0; i<n; i++) {
                String[] input = br.readLine().split(" ");
                for(int j=0; j<input.length; j++) {
                    grid[i][j] = Integer.parseInt(input[j]);
                    // 입력받은 번호가 0이 아니면 우선순위 큐에 삽입
                    if(grid[i][j]>0) {
                        pq.offer(new Virus(grid[i][j], i, j));
                    }
                }
            }

            String[] sxy = br.readLine().split(" ");
            int s = Integer.parseInt(sxy[0]);
            int x = Integer.parseInt(sxy[1]);
            int y = Integer.parseInt(sxy[2]);

            visited = new boolean[n][n];
            for(int i=0; i<s; i++)
                func();

            bw.write(grid[x-1][y-1]+"\n");
            bw.close();
        } catch(FileNotFoundException e) {
            e.getStackTrace();
        } catch(IOException e) {
            e.getStackTrace();
        }
    }
}