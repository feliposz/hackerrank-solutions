import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> data = new ArrayList<Integer>();
        while (n-- > 0) {
            data.add(sc.nextInt());
        }
        int q = sc.nextInt();
        while (q-- > 0) {
            String op = sc.next();
            if (op.equals("Insert")) {
                int x = sc.nextInt();
                int y = sc.nextInt();
                data.add(x, y);
            } else {
                int x = sc.nextInt();
                data.remove(x);
            }            
        }
        for (int v : data) {
            System.out.print(v + " ");
        }
    }
}

