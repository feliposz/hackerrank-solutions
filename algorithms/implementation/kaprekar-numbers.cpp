#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'kaprekarNumbers' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER q
 */

void kaprekarNumbers(int p, int q) {
    bool valid = false;
    for (int n = p; n <= q; n++) {
        long n2 = (long)n * n;        
        
        // count digits
        long tmp = n;
        long digits = 0;
        long div = 1;
        while (tmp > 0) {
            tmp /= 10;
            digits++;
            div *= 10;
        }

        long l = n2 / div;
        long r = n2 % div;
        if ((l + r) == n) {
            //cerr << l << " " << r << " " << n << endl;
            cout << n << " ";
            valid = true;
        }
    }
    if (!valid) {
        cout << "INVALID RANGE" << endl;
    }
}
//2223 2728 4950 5050 7272 7777 9999
int main()
{
    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    kaprekarNumbers(p, q);

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

