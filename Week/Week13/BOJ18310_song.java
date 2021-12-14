import java.io.*;
import java.util.*;

public class BOJ18310 {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

            int n = Integer.parseInt(br.readLine());
            ArrayList<Integer> list = new ArrayList<>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()) {
                int input = Integer.parseInt(st.nextToken());
                list.add(input);
            }

            Collections.sort(list);
            bw.write(list.get((n-1)/2) + "\n");
            bw.close();
        } catch (IOException e) {
            e.getStackTrace();
        }
    }
}