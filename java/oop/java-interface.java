

//Write your code here
class MyCalculator implements AdvancedArithmetic {
    
    public int divisor_sum(int n) {
        int sum = 0;
        for (int d = 1; d <= n; d++) {
            if (n % d == 0) {
                sum += d;
            }
        }
        return sum;
    }
}


