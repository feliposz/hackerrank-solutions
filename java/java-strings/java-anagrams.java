

    static boolean isAnagram(String a, String b) {
        if (a.isEmpty() && b.isEmpty()) {
            return true;
        } else if (a.isEmpty() || b.isEmpty()) {
            return false;
        }
        char c = a.toLowerCase().charAt(0);
        int i = b.toLowerCase().indexOf(c);
        if (i < 0) {
            return false;
        }
        return isAnagram(a.substring(1), b.substring(0, i)+b.substring(i+1));
    }


