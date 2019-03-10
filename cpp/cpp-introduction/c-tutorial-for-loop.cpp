#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    
    int a, b;

    cin >> a >> b;

       // Write Your Code Here
    string digits[12] {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "even",
        "odd"
    };

    for (int i = a; i <= b; i++) {
        if (i < 10) {
            cout << digits[i];
        } else if (i % 2) {
            cout << digits[11];
        } else {
            cout << digits[10];
        }
        cout << endl;
    }
    

    return 0;
}


