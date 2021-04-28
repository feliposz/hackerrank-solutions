

/* Define the exception here */
class BadLengthException : exception {
        int n;
    public:
        BadLengthException(int n) : n(n) {}
        int what() {
            return n;
        }
};

