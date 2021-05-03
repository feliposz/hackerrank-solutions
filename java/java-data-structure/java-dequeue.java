    import java.util.*;
    
        
    public class test {
        public static void main(String[] args) {
            Scanner in = new Scanner(System.in);
            Deque<Integer> deque = new ArrayDeque<Integer>();
            Map<Integer, Integer> map = new HashMap<Integer, Integer>();
            int n = in.nextInt();
            int m = in.nextInt();
            int max = 0;
            for (int i = 0; i < n; i++) {
                int num = in.nextInt();
                if (deque.size() >= m) {
                    int old = deque.removeFirst();
                    int x = map.get(old);
                    map.put(old, x - 1);
                    if (x == 1) {
                        map.remove(old);
                    }
                }
                deque.addLast(num);
                int x = 0;
                if (map.containsKey(num)) {
                    x = map.get(num);
                }
                map.put(num, x + 1);
                if (map.size() > max) {
                    max = map.size();
                }
            }
            System.out.println(max);
        }
    }




