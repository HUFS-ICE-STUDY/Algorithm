package com.algorithm.baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class BOJ16236 {
	public static int n; // 격자의 크기를 담기 위한 변수
	
	public static Fish shark;
	public static int state = 2; // 상어의 초기 크기
	public static int eaten = 0; // 상어가 먹은 물고기의 마리수
	public static int time = 0; // 엄마 상어를 호출하기 전까지 걸리는 시간
	
	public static int[] dx = { -1, 1, 0, 0 };
	public static int[] dy = { 0, 0, -1, 1 };
	
	public static int[][] grid; // 상어의 위치와 물고기의 위치를 담은 2차원 격자
	
	public static ArrayList<Fish> fishes = new ArrayList<Fish>(); // 먹을 수 있는 물고기의 정보를 담은 ArrayList
	
	// 상어 또는 물고기의 현재 행과 열 정보 및 거리 정보를 담은 Node 클래스
	public static class Fish {
		int x = 0, y = 0, distance = 0;
		public Fish(int x, int y, int distance) {
			this.x = x;
			this.y = y;
			this.distance = distance;
		}
	}
	
	// 범위 확인 메소드
	public static boolean inRange(int x, int y) {
		return x>=0 && x<n && y>=0 && y<n;
	}
	
	// 물고기가 어디있는지 찾기 위한 FindFish 메소드
	public static void FindFish() {
		while(true) { // 물고기 '한 마리'를 먹는 알고리즘이므로 while(true)를 통해서 모든 물고기에 대해서 과정 반복
			Queue<Fish> q = new LinkedList<Fish>(); // 상어가 BFS를 수행하기 위한 Queue
			boolean[][] visited = new boolean[n][n]; // grid의 위치를 방문했는지 표시하기 위한 2차원 격자
			q.offer(shark); // 상어의 위치를 시작점으로 지정
			visited[shark.x][shark.y] = true; // 시작점은 방문됐음을 표시
			while(!q.isEmpty()) {
				Fish cur = q.poll();
				for(int i=0; i<4; i++) {
					int nx = cur.x + dx[i];
					int ny = cur.y + dy[i];
					if(!inRange(nx, ny) || visited[nx][ny]) continue; // 범위 이탈 및 방문 여부 확인
					
					// 다음 이동하려는 위치에 물고기가 있고 상어보다 작으면 물고기 리스트에 추가 & 방문했음을 표시하고 큐에 올림
					if(grid[nx][ny]>=1 && grid[nx][ny]<state) {
						fishes.add(new Fish(nx, ny, cur.distance+1));
						q.offer(new Fish(nx, ny, cur.distance+1));
						visited[nx][ny] = true;
					}
					// 빈 칸이거나 물고기의 크기가 상어와 같으면 방문했음을 표시하고 큐에 올림
					else if(grid[nx][ny]==0 || grid[nx][ny]==state) {
						q.offer(new Fish(nx, ny, cur.distance+1));
						visited[nx][ny] = true;
					}
				}
			}
			if(fishes.size()!=0) EatFish();
			else return; // 격자 상에 먹을 수 있는 물고기가 더이상 없는 경우 알고리즘 종료
		}
	}
	
	// 먹을 수 있는 물고기 중에서 상어와의 거리가 최소인 물고기를 찾고 먹는 메소드
	public static void EatFish() {
		Fish edible = fishes.get(0);
		for(int i=1; i<fishes.size(); i++) { // 물고기 리스트 중에서
			// 상어와의 거리가 최소인 물고기를 타겟으로 삼음
			if(fishes.get(i).distance < edible.distance) {
				edible = fishes.get(i);
			}
			// 상어와의 거리가 모두 같다면 x 좌표 값이 작은 물고기를 타겟으로 변경
			else if(fishes.get(i).distance == edible.distance) {
				if(fishes.get(i).x < edible.x) {
					edible = fishes.get(i);
				}
			}
		}
		
		// 상어의 크기만큼 물고기를 먹은 경우 크기 증가
		if(++eaten==state) {
			state++;
			eaten = 0;
		}
		grid[edible.x][edible.y] = 0; // 먹힌 물고기의 위치값을 0으로 변경
		time += edible.distance; // 엄마 상어 호출까지의 시간 갱신
		shark.x = edible.x; // 상어의 좌표 먹힌 물고기의 좌표로 변경
		shark.y = edible.y; // 상어의 좌표 먹힌 물고기의 좌표로 변경
		fishes.clear(); // 물고기 리스트 초기화
	}
	
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
			
			n = Integer.parseInt(br.readLine());
			grid = new int[n][n];
			
			for(int i=0; i<n; i++) {
				String[] str = br.readLine().split(" ");
				for(int j=0; j<n; j++) {
					grid[i][j] = Integer.parseInt(str[j]);
					if(grid[i][j]==9) {
						shark = new Fish(i, j, 0); // 상어의 위치를 특정
						grid[i][j] = 0; // 상어가 위치한 값을 0으로 초기화
					}
				}
			}
			
			FindFish();
			bw.write(time+"\n");
			bw.close();
		} catch(FileNotFoundException e) {
			e.getStackTrace();
		} catch(IOException e) {
			e.getStackTrace();
		}
	}
}