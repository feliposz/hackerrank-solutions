import java.util.*;
class Solution{
	
	public static void main(String []argh)
	{
		Scanner sc = new Scanner(System.in);
		
		while (sc.hasNext()) {
            Stack<Character> s = new Stack<Character>();
            String input=sc.next();
            //Complete the code
            boolean error = false;
            for (int i = 0; i < input.length(); i++) {
                char c = input.charAt(i);
                switch (c) {
                    case '{': 
                    case '[': 
                    case '(': 
                        s.push(c); 
                        break;
                    case ')':
                        if (s.empty() || s.pop() != '(') {
                            error = true;
                        }
                        break;
                    case ']':
                        if (s.empty() || s.pop() != '[') {
                            error = true;
                        }
                        break;
                    case '}':
                        if (s.empty() || s.pop() != '{') {
                            error = true;
                        }
                        break;                       
                }
                if (error) {
                    break;
                }
            }
            if (!s.empty()) {
                error = true;
            }
            System.out.println(!error);
		}
		
	}
}




