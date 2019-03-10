#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string a, b;
    getline(cin, a);
    getline(cin, b);
    cout << a.length() << ' ' << b.length() << endl;
    cout << a + b << endl;
    char tmp = a[0];
    a[0] = b[0];
    b[0] = tmp;
    cout << a << ' ' << b << endl;
  
    return 0;
}


