

   // Write your code here
    public PerformOperation isOdd() {
        return new PerformOperation() {
            public boolean check(int a) {
                return a % 2 == 1;
            }
        };
    }
    
    public PerformOperation isPrime() {
        return new PerformOperation() {
            public boolean check(int a) {
                if (a == 2) return true;
                if (a < 2) return false;
                if (a % 2 == 0) return false;
                for (int d = 3; d < (a/2+1); d++) {
                    if (a % d == 0)
                        return false;
                }
                return true;
            }
        };
    }

    public PerformOperation isPalindrome() {
        return new PerformOperation() {
            public boolean check(int a) {
                int orig = a;
                int rev = 0;
                while (a > 0) {
                    rev = rev * 10 + a % 10;
                    a /= 10;
                }
                return orig == rev;
            }
        };
    }
}


