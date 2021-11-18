package com.algorithm.baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

public class BOJ1967 {
	public static class Node {
		int node; // 연결된 노드
		int weight; // 노드 사이의 가중치
		Node(int node, int weight) {
			this.node = node;
			this.weight = weight;
		}
	}
	
	// 노드 vtx에 대해서 DFS 수행
	public static void findDiameter(int vtx, int sum, boolean[] visited) {
		// 현재 노드가 방문됐음을 표시
		visited[vtx] = true;
		// 현재 노드와 인접한 노드들에 대해서
		for(int i=0; i<list.get(vtx).size(); i++) {
			// 현재 노드와 인접한 노드가 방문되지 않았다면
			if(!visited[list.get(vtx).get(i).node]) {
				// 현재 노드와 인접한 노드 간의 가중치를 sum에 더함
				sum += list.get(vtx).get(i).weight;
				// 현재 노드와 인접한 각각의 노드에 대해서 새로운 DFS 수행
				findDiameter(list.get(vtx).get(i).node, sum, visited);
				// DFS가 종료된 후에는 인접한 노드와 새로운 인접한 노드 간의 가중치를 제거
				sum -= list.get(vtx).get(i).weight;
			}
		}
		max = Math.max(max,  sum);
	}
	
	public static int n;
	public static int max = Integer.MIN_VALUE;
	public static ArrayList<ArrayList<Node>> list;
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

			// 입력 & 선언
			n = Integer.parseInt(br.readLine());
			list = new ArrayList<ArrayList<Node>>();
			for(int i=0; i<n+1; i++)
				list.add(new ArrayList<Node>());
			
			// 초기화
			for(int i=0; i<n-1; i++) {
				String[] input = br.readLine().split(" ");
				int vtx1 = Integer.parseInt(input[0]);
				int vtx2 = Integer.parseInt(input[1]);
				int weight = Integer.parseInt(input[2]);
				list.get(vtx1).add(new Node(vtx2, weight));
				list.get(vtx2).add(new Node(vtx1, weight));
			}
			
			// DFS 알고리즘
			boolean visited[] = new boolean[n+1];
			int sum = 0;
			for(int vtx=1; vtx<=n; vtx++) {
				findDiameter(vtx, sum, visited);
				// 배열 visited를 재사용하기 위해서 false로 초기화
				for(int i=0; i<visited.length; i++)
					visited[i] = false;
				// 변수 sum을 재사용하기 위해서 0으로 초기화
				sum = 0;
			}
			
			bw.write(max+"\n");
			bw.close();
		} catch(FileNotFoundException e) {
			e.getStackTrace();
		} catch(IOException e) {
			e.getStackTrace();
		}
	}
}