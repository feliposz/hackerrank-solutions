#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
  // Complete this function
  vector<int> v;
  stringstream ss(str);
  for (;;) {
    if (ss.eof())
      break;
    int num;
    ss >> num;
    v.push_back(num);
    if (ss.eof())
      break;
    char ch;
    ss >> ch;
  }
  return v;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}


