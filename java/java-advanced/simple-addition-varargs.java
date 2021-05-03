

class Add {
    void add(int ... a) {
        int sum = 0;
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i]);
            if (i == a.length - 1) {
                System.out.print("=");
            } else {
                System.out.print("+");
            }
            sum += a[i];
        }
        System.out.println(sum);
    }
}


