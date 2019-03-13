import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        /* Enter your code here. Print output to STDOUT. */
        boolean palindrome = true;
        for (int i = 0, j = A.length() - 1; i < j; i++, j-- ) {
            if (A.charAt(i) != A.charAt(j)) {
                palindrome = false;
                break;
            }
        }
        if (palindrome) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}




