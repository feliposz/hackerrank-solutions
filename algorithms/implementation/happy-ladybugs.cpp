#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'happyLadybugs' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING b as parameter.
 */

string happyLadybugs(string b) {
    map<char, int> colors;
    bool happy = true;
    bool has_empty = false;
    for (int i = 0; i < b.size(); i++) {
        char c = b[i];
        colors[c]++;
        if (b[i] != '_') {
            if (((i > 0) && (b[i-1] != b[i])) &&
                ((i < (b.size() - 1)) && (b[i+1] != b[i]))) {
                happy = false;
            }
        }
        if (b[i] == '_') {
            has_empty = true;
        }
    }
    cerr << "board: " << b << endl;
    for (auto p : colors) {
        cerr << p.first << " " << p.second << endl;
        if (p.first != '_') {
            if (p.second == 1) {
                return "NO";
            }
        }
    }
    if (has_empty) {
        // TODO: other cases
        return "YES";
    } else {
        if (happy) {
            return "YES";
        } else {
            return "NO";
        }
    }
}

/*
NO
NO
NO
NO
YES
YES
NO
*/

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

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

