//Complete this code or write your own from scratch
import java.util.*;
import java.io.*;

class Solution{
	public static void main(String []argh)
	{
        Map<String, String> book = new HashMap<String, String>();
		Scanner in = new Scanner(System.in);        
		int n=Integer.parseInt(in.nextLine());
		while(n-- > 0) {
			String name=in.nextLine();
            String phone=in.nextLine();
            book.put(name, phone);
		}
		while(in.hasNext())
		{
			String q=in.nextLine();
            if (book.containsKey(q)) {
                System.out.println(q + "=" + book.get(q));                
            } else {
                System.out.println("Not found");
            }
		}
	}
}




