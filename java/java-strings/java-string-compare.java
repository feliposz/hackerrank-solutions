

    public static String getSmallestAndLargest(String s, int k) {
        String smallest = "";
        String largest = "";
        
        // Complete the function
        // 'smallest' must be the lexicographically smallest substring of length 'k'
        // 'largest' must be the lexicographically largest substring of length 'k'
        for (int i = 0; i < s.length() - k + 1; i++) {
            String sub = s.substring(i, i+k);
            if (smallest.isEmpty() || sub.compareTo(smallest) < 0) {
                smallest = sub;
            }
            if (largest.isEmpty() || sub.compareTo(largest) > 0) {
                largest = sub;
            }
        }
        
        return smallest + "\n" + largest;
    }


