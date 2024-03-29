#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'anagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int anagram(string s) {
    map<char, int> a, b;
    if (s.size() % 2 == 1) {
        return -1;
    }
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        a[s[i]]++;
        b[s[j]]++;
    }
    int da = 0, db = 0;
    for (auto c : b) {
        int d = c.second - a[c.first];
        da += d > 0 ? d : 0;
    }
    for (auto c : a) {
        int d = c.second - b[c.first];
        db += d > 0 ? d : 0;
    }
    return da < db ? da : db;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        fout << result << "\n";
    }

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

