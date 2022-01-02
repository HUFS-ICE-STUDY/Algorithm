package com.algorithm.baekjoon;

import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ13335 {
    public static int N, L, W; // 트럭의 개수, 다리의 길이, 다리의 최대 하중
    public static int time = 0; // 다리를 건너는데 필요한 최단시간
    public static int weight = 0; // 다리 위에 올라와있는 트럭들의 무게
    public static int[] trucks; // 다리 위에 올라가지 않은 대기 트럭의 무게 배열
    public static Queue<Integer> onBridge; // 다리 위에 올라와있는 트럭의 리스트
    public static int moveTruck() {
        for(int i=0; i<N; i++) {
            while(true) {
                // 다리가 트럭으로 꽉 찼다면 선두 트럭을 큐에서 제거
                if(onBridge.size()==L) weight -= onBridge.poll();
                // 다리 위에 트럭이 올라와있지 않다면 새로운 트럭을 추가
                if(weight+trucks[i]>W) {
                    onBridge.offer(0);
                    time++;
                }
                // 다리 위에 트럭이 없거나 새로운 트럭을 추가한 무게가 다리의 최대하중을 넘지 않는다면
                // 새로운 트럭을 추가하고 현재 무게에 새로운 트럭의 무게를 더해줌
                else {
                    onBridge.offer(trucks[i]);
                    weight += trucks[i];
                    time++;
                    break;
                }
            }
        }
        // 마지막 트럭이 건너는 시간(다리의 길이)를 더해줘야함
        return time+L;
    }
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            L = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());

            trucks = new int[N];
            onBridge = new LinkedList<>();

            st = new StringTokenizer(br.readLine());
            for(int i=0; i<N; i++)
                trucks[i] = Integer.parseInt(st.nextToken());

            bw.write(moveTruck()+"\n");
            bw.close();
        } catch (IOException e) {
            e.getStackTrace();
        }
    }
}