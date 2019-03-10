#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
  int queries;
  cin >> queries;
  map<string,int> s;
  while (queries-- > 0) {
    int type, marks;
    string name;
    cin >> type >> name;
    switch (type) {
    case 1:
      cin >> marks;
      s[name] += marks;
      break;
    case 2:
      s.erase(name);
      break;
    case 3:
      cout << s[name] << endl;
      break;
    }
  }
  return 0;
}




