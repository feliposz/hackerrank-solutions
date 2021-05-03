
import static java.lang.System.in;

class Prime {
    boolean isPrime(int n) {
        if (n == 2) {
            return true;
        }
        if (n % 2 == 0) {
            return false;
        }
        if (n < 2) {
            return false;
        }
        for (int d = 3; d <= (n/2+1); d += 2) {
            if (n % d == 0) {
                return false;
            }
        }
        return true;
    }
    
    public void checkPrime(int ... a) {
        for (int n : a) {
            if (isPrime(n)) {
                System.out.print(n + " ");
            }
        }
        System.out.println();
    }
    
}


