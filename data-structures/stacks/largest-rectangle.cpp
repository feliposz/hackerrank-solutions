#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'largestRectangle' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY h as parameter.
 */

long rectArea(vector<int> &h, int min, int max)
{
    if (min > max) {
        return 0;
    }
    int minH = 10000000;
    int pos = -1;
    for (int i = min; i <= max; i++) {
        if (minH > h[i]) {
            minH = h[i];
            pos = i;
        }        
    }
    long a = (long)minH * (max - min + 1);
    long left = rectArea(h, min, pos - 1);
    long right = rectArea(h, pos + 1, max);
    a = a > left ? a : left;
    a = a > right ? a : right;
    return a;
}

long largestRectangle(vector<int> h) {
    /*
    long maxA = 0;
    for (int len = 1; len <= h.size(); len++) {        
        for (int i = 0; i < h.size() - len + 1; i++) {
            int minH = 10000000;
            for (int j = i; j < i + len; j++) {
                if (minH > h[j]) {
                    minH = h[j];
                }
            }
            long A = (long)minH * len;
            if (maxA < A) {
                maxA = A;
            }
        }
    }
    return maxA;
    */
    return rectArea(h, 0, h.size() - 1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split(rtrim(h_temp_temp));

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

    fout.close();

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

