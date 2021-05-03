import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        BitSet[] b = new BitSet[2];
        b[0] = new BitSet(n);
        b[1] = new BitSet(n);
        
        while (m-- > 0) {
            String op = sc.next();
            int x = sc.nextInt();
            int y = sc.nextInt();
            switch (op) {
                case "AND":
                    b[x-1].and(b[y-1]);
                    break;
                case "OR":
                    b[x-1].or(b[y-1]);
                    break;
                case "XOR":
                    b[x-1].xor(b[y-1]);
                    break;
                case "FLIP":
                    b[x-1].flip(y);
                    break;
                case "SET":
                    b[x-1].set(y);
                    break;
            }
            System.out.println(b[0].cardinality() + " " + b[1].cardinality());
        }
    }
}

