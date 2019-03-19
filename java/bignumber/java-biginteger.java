import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        BigInteger a = new BigInteger(scan.nextLine());
        BigInteger b = new BigInteger(scan.nextLine());
        BigInteger sum = a.add(b);
        BigInteger prod = a.multiply(b);
        System.out.printf("%s\n", sum);
        System.out.printf("%s\n", prod);
    }
}


