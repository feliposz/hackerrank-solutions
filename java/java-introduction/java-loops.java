import java.util.*;
import java.io.*;

class Solution{
    static void generateSeries(int a, int b, int n) {
      int acc = 0;
      for (int i=0; i<n; i++) {
        acc += (int)Math.pow(2, i) * b;
        System.out.print(a + acc);
        if (i < n - 1) {
          System.out.print(' ');
        }
      }
      System.out.println();
    }

    public static void main(String []argh){
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        for(int i=0;i<t;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();
            generateSeries(a, b, n);
        }
        in.close();
    }
}


