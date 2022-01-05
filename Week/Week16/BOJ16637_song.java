package com.algorithm.baekjoon;

import java.io.*;
import java.util.ArrayList;

public class BOJ16637 {
    public static int N;
    public static int max = Integer.MIN_VALUE;
    public static ArrayList<Integer> number;
    public static ArrayList<Character> operation;
    public static void dfs(int total, int index) {
        // 입력받은 연산자의 개수를 초과하면 max를 갱신하고 종료
        if(index>=operation.size()) {
            max = Math.max(max, total);
            return;
        }
        
        // 괄호를 사용하지 않는 경우
        dfs(cal(total, number.get(index+1), operation.get(index)), index+1);

        // total 다음 숫자를 시작으로 괄호를 사용하는 경우
        if(index+1<operation.size()) {
            int subTotal = cal(number.get(index+1), number.get(index+2), operation.get(index+1));
            dfs(cal(total, subTotal, operation.get(index)), index+2);
        }
    }
    public static int cal(int a, int b, char op) {
        if(op=='+') return a+b;
        if(op=='-') return a-b;
        return a*b;
    }
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

            N = Integer.parseInt(br.readLine());
            number = new ArrayList<>();
            operation = new ArrayList<>();

            String input = br.readLine();
            for(int i=0; i<N; i++) {
                char c = input.charAt(i);
                if(i%2!=0) operation.add(c);
                else number.add(Character.getNumericValue(c));
            }

            // 배열의 첫번째 숫자로 시작하고 다음 깊이를 1로 설정
            dfs(number.get(0), 0);
            bw.write(max+"\n");
            bw.close();
        } catch (IOException e) {
            e.getStackTrace();
        }
    }
}