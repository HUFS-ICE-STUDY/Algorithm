package com.algorithm.baekjoon;

import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class BOJ2636 {
    static class Cheese {
        int x,y;
        public Cheese(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    public static int cnt;
    public static int[][] grid;
    public static boolean[][] visited;
    public static Queue<Cheese> q;
    public static ArrayList<Integer> list;
    public static int[] dx = { -1, 1, 0, 0 };
    public static int[] dy = { 0, 0, -1, 1 };
    public static void bfs(int row, int col) {
        q.offer(new Cheese(0, 0)); // 시작점 추가
        while(!q.isEmpty()) {
            Cheese c = q.poll();
            visited[c.x][c.y] = true;
            for(int i=0; i<4; i++) {
                int nx = c.x + dx[i];
                int ny = c.y + dy[i];
                // 범위 제한
                if(nx>=0 && nx<row && ny>=0 && ny<col) {
                    // 다음으로 방문하려는 위치가 방문된 적이 없으면
                    if(!visited[nx][ny]) {
                        // 무조건 방문 때리는 이유 : 몰?루
                        visited[nx][ny] = true;
                        // 그 위치에 치즈가 없다면 해당 위치를 큐에 추가
                        if(grid[nx][ny]==0) q.offer(new Cheese(nx, ny));
                        // 그 위치에 치즈가 있다면 공기로 만들고 및 치즈 개수 감소
                        else {
                            grid[nx][ny] = 0;
                            cnt--;
                        }
                    }
                }
            }
        }
    }
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

            String[] rc = br.readLine().split(" ");
            int row = Integer.parseInt(rc[0]);
            int col = Integer.parseInt(rc[1]);

            q = new LinkedList<>();
            list = new ArrayList<>();

            grid = new int[row][col];
            for(int i=0; i<row; i++) {
                String[] input = br.readLine().split(" ");
                for(int j=0; j<input.length; j++) {
                    grid[i][j] = Integer.parseInt(input[j]);
                    if(grid[i][j]==1) cnt++; // 초기 치즈 개수 계산
                }
            }

            int time = 0;
            visited = new boolean[row][col];
            if(cnt==0) bw.write(0+"\n"+0+"\n");
            else {
                while(cnt!=0) {
                    time++; // 루프가 돌 때마다 1증가
                    list.add(cnt); // 치즈 개수 기억
                    bfs(row, col);
                    for(int i=0; i<row; i++) {
                        for(int j=0; j<col; j++) {
                            // 배열을 재사용하기 위한 초기화
                            visited[i][j] = false;
                        }
                    }
                }
                bw.write(time+"\n"+list.get(list.size()-1)+"\n");
            }
            bw.close();
        } catch(FileNotFoundException e) {
            e.getStackTrace();
        } catch(IOException e) {
            e.getStackTrace();
        }
    }
}