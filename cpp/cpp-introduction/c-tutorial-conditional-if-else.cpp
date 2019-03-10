#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Write Your Code Here
    string digits[11] {
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
        "Greater than 9"
    };

    if (n > 9) {
        cout << digits[10];
    } else {
        cout << digits[n];
    }

    return 0;
}

