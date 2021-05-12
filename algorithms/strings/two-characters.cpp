#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'alternate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int alternate(string s) {
    int max_len = 0;
    int n = s.size();
    for (char a = 'a'; a <= 'z'; a++) {
        for (char b = a + 1; b <= 'z'; b++) {
            char flag = 0;
            int len = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == a) {
                    if ((flag == 0) || (flag == a)) {
                        len++;
                        flag = b;
                    } else {
                        len = -1;
                        i = n;
                    }
                } else if (s[i] == b) {
                    if ((flag == 0) || (flag == b)) {
                        len++;
                        flag = a;
                    } else {
                        len = -1;
                        i = n;
                    }
                }
            }
            if (len > max_len) {
                max_len = len;
            }
        }
    }
    if (max_len < 2) {
        max_len = 0;
    }
    return max_len;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

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

