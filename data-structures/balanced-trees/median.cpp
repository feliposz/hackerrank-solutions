#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

void median(vector<char> s,vector<int> X) {
    map<int, int> data;
    
    int q = s.size();
    int size = 0;
    for (int i = 0; i < q; i++) {
        int op = s[i];
        int x = X[i];
        if (op == 'a') {
            data[x]++;
            size++;
        } else {
            if (size > 0 && data[x] > 0) {
                data[x]--;
                size--;
            } else {
                cout << "Wrong!" << endl;
                continue;
            }
        }
        if (size == 0) {
            cout << "Wrong!" << endl;
        } else {
            int j = 0;
            int median_p1, median_p2; //01234567
            if (size%2) {
                median_p1 = median_p2 = size/2;
            } else {
                median_p2 = size/2;
                median_p1 = median_p2 - 1;
            }        
            int median_v1 = 0, median_v2 = 0;
            for (auto p : data) {
                if ((median_p1 >= j) && (median_p1 < (j + p.second))) {
                    median_v1 = p.first;
                }
                if ((median_p2 >= j) && (median_p2 < (j + p.second))) {
                    median_v2 = p.first;
                    break;
                }
                j += p.second;
            }
            
            cout << (median_v1 + median_v2)/2.0 << endl;
        }
    }
    
}
int main(void){

//Helpers for input and output

	int N;
	cin >> N;
	
	vector<char> s;
    vector<int> X;
	char temp;
    int tempint;
	for(int i = 0; i < N; i++){
		cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
	}
	
	median(s,X);
	return 0;
}

