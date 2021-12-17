package com.algorithm.baekjoon;

import java.io.*;
import java.util.StringTokenizer;

public class BOJ16953 {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            int cnt = 1;
            while(b!=a) {
                // 연산 결과로 b가 a보다 작아지거나 b가 1을 제외한 홀수인 경우 만들 수 없으므로 반복문 탈출
                if(b<a || (b%2==1 && b%10!=1)) {
                    cnt = -1;
                    break;
                }
                else {
                    // b가 짝수이면 2로 나눠준다
                    if(b%2==0) b /= 2;
                        // b의 뒷자리가 1이면 10으로 나눠준다
                    else if(b%10==1) b /= 10;
                    cnt++;
                }
            }

            bw.write(cnt+"\n");
            bw.close();
        } catch (IOException e) {
            e.getStackTrace();
        }
    }
}