#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int SLOW_sherlockAndAnagrams(string s) {
    int count = 0;
    for (int len = 1; len < s.size(); len++) {
        for (int i = 0; s[i]; i++) {
            string a = s.substr(i, len);
            sort(a.begin(), a.end());            
            for (int j = i + 1; s[j]; j++) {
                string b = s.substr(j, len);
                sort(b.begin(), b.end());                
                if (a == b) {
                    cerr << "(" << i << "," << (i + len - 1) << ") (" << j << "," << (j + len - 1) << ") -> " << a << endl;
                    count++;
                }
            }
        }
    }
    return count;   
}

int sherlockAndAnagrams(string s) {
    int count = 0;
    map<string, int> anagrams;
    for (int len = 1; len < s.size(); len++) {
        for (int i = 0; i < s.size() - (len - 1); i++) {
            string a = s.substr(i, len);
            sort(a.begin(), a.end());
            anagrams[a]++;
        }
    }
    cerr <<"s = " << s << endl;
    for (auto &p : anagrams) {
        cerr << p.first << " " << p.second << endl;
        if (p.second > 1) {
            for (int i = 1; i < p.second; i++) {
                count += i;
            }
        }
    }
    cerr << endl;
    return count;   
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

        int result = sherlockAndAnagrams(s);

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

