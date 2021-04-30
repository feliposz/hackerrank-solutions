

        //Write your code here
        
        Arrays.sort(s, 0, n,  Collections.reverseOrder(new Comparator<String>() {
            @Override
            public int compare(String m1, String m2) {
                BigDecimal bd1 = new BigDecimal(m1);
                BigDecimal bd2 = new BigDecimal(m2);
                return bd1.compareTo(bd2);
            }
        }));


