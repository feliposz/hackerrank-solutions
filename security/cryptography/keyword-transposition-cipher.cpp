#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void make_key(string& kw, string& key) {
    char m[26][7];
    // clear matrix
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 7; j++) {
            m[i][j] = 0;
        }
    }
    
    // fill keyword
    int kwlen = 0;
    for (char c : kw) {
        bool found = false;
        for (int i = 0; i < kwlen; i++) {
            if (c == m[0][i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            m[0][kwlen++] = c;
        }
    }
    
    // fill alphabet
    int row = 1;
    int col = 0;
    for (char c : "ABCDEFGHIJKLMNOPQRSTUVWXYZ") {
        bool found = false;
        for (int i = 0; i < kwlen; i++) {
            if (c == m[0][i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            m[row][col++] = c;
            if (col == kwlen) {
                col = 0;
                row++;
            }
        }
    }

    /*
    for (int i = 0; i <= row; i++) {
        for (int j = 0; j < kwlen; j++) {
            cerr << m[i][j];
        }
        cerr << endl;
    }
    */

    // sort columns
    bool swapped;
    do {
        swapped = false;
        for (int j = 0; j < kwlen - 1; j++) {
            if (m[0][j] > m[0][j+1]) {
                for (int i = 0; i <= row; i++) {
                    int t = m[i][j];
                    m[i][j] = m[i][j+1];
                    m[i][j+1] = t;
                    swapped = true;
                }
            }
        }
    } while (swapped);

    // build key
    for (int j = 0; j < kwlen; j++) {
        for (int i = 0; i <= row; i++) {
            if (m[i][j]) {
                key += m[i][j];
            }
        }
    }
}

void decode(string& kw, string& msg, string& result) {
    string key;
    make_key(kw, key);    
    //cerr << "key: " << key << endl;
    int len = key.length();
    for (char e : msg) {
        char d = e;
        for (int i = 0; i < len; i++) {
            if (e == key[i]) {
                d = i + 'A';
                break;
            }
        }
        cout << d;
    }
}

int main() {
    string nstr;
    getline(cin, nstr);
    int n = stoi(nstr);
    while (n-- > 0) {
        string kw, msg, result;
        getline(cin, kw);
        getline(cin, msg);
        decode(kw, msg, result);
        cout << result << endl;
    }
    return 0;
}

