

static int B, H;
static boolean flag;

static {
    try {
        Scanner s = new Scanner(System.in);
        B = s.nextInt();
        H = s.nextInt();

        flag = B > 0 && H > 0;

        if (!flag) {
            throw new Exception("Breadth and height must be positive");
        }
    } catch (Exception e) {
        System.out.println(e);
    }
    
}


