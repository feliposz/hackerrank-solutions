import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        ArrayList<ArrayList<Integer>> data = new ArrayList<ArrayList<Integer>>(n);
        for (int i = 0; i < n; i++) {
            int d = scan.nextInt();
            data.add(new ArrayList<Integer>(d));
            while (d-- > 0) {
                data.get(i).add(scan.nextInt());
            }
        }
        
        int q = scan.nextInt();

        while (q-- > 0) {
            int x = scan.nextInt();
            int y = scan.nextInt();
            try {
                int value = data.get(x-1).get(y-1);
                System.out.println(value);
            } catch (Exception e) {
                System.out.println("ERROR!");                
            }
        }
    }
}


