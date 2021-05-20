#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'aOrB' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. STRING a
 *  3. STRING b
 *  4. STRING c
 */

string trimzeros(const string &str) {
    string s(str);

    s.erase(0, min(s.find_first_not_of('0'), s.size()-1));

    return s;
}

int h2d(char hex) {
    if ((hex >= '0') && (hex <= '9'))
        return hex - '0';
    else if ((hex >= 'A') && (hex <= 'F'))
        return hex - 'A' + 10;
    else if ((hex >= 'a') && (hex <= 'f'))
        return hex - 'f' + 10;
    else 
        return -1;
}

void aOrB(int k, string a, string b, string c) {

    char d2h[] = "0123456789ABCDEF";
    int bits[] = {0,1,1,2,1,1,2,3,1,2,2,3,2,3,3,4};
    
    string outA, outB;
    
    long count = 0;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        
        int A = h2d(a[i]);
        int B = h2d(b[i]);
        int C = h2d(c[i]);
        
        // count wrong bits
        int D = (A|B) ^ C; 
        count += bits[D];        
        if (count > k) {
            cout << -1 << endl;
            return;
        }
                
        // unset zero bits
        int A_ = (A & C);
        int B_ = (B & C) | (~(A|B) & C);
        // set bits on B_ if zero on both A and B
        
        //fprintf(stderr, "A=%x B=%x C=%x D=%x A_=%x B_=%x C_=%x\n", A, B, C, D, A_, B_, A_ | B_);
        
        outA += d2h[A_];
        outB += d2h[B_];
    }
            
    cout << trimzeros(outA) << endl;
    cout << trimzeros(outB) << endl;    
    
}

/*
C8582
707A00790
8AF10287D
48B1B534E
B9BB94E
8BB3CA95E
*/

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string k_temp;
        getline(cin, k_temp);

        int k = stoi(ltrim(rtrim(k_temp)));

        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string c;
        getline(cin, c);

        aOrB(k, a, b, c);
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

