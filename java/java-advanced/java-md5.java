import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.security.*;
import java.nio.charset.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        
        Scanner sc = new Scanner(System.in);
        
        String input = sc.nextLine();
        
        try {
            MessageDigest md = MessageDigest.getInstance("MD5");
            
            md.update(input.getBytes(StandardCharsets.UTF_8));
            
            // Get the hashbytes
            byte[] hashBytes = md.digest();
            
            //Convert hash bytes to hex format
            StringBuilder sb = new StringBuilder();
            for (byte b : hashBytes) {
                sb.append(String.format("%02x", b));
            }

            // Print the hashed text
            System.out.println(sb.toString());
        } catch (NoSuchAlgorithmException e) {
            
        }
    }
}

