#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string superReducedString(string s) {
    bool reduced = true;
    while (reduced) {
        string t;
        reduced = false;
        for (int i = 0; i < s.size(); i++) {
            if ((i < s.size() - 1) && (s[i] == s[i+1])) {
                i++;
                reduced = true;
            } else {
                t += s[i];
            }
        }
        //cerr << s << "->" << t << endl;
        s = t;
    }
    if (s.size() == 0) {
        return "Empty String";
    }
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

