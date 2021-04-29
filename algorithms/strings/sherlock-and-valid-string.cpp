#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    map<char, int> letters;    
    for (char c : s) {
        letters[c]++;
    }
    
    map<int, int> counts;    
    int min = INT_MAX;
    int max = INT_MIN;
    for (auto &n : letters) {
        if (n.second > 0) {
            cerr << n.first << ": " << n.second << endl;
            min = (n.second < min) ? n.second : min;
            max = (n.second > max) ? n.second : max;
            counts[n.second]++;
        }
    }
    
    if (counts.size() < 3) {
        if (max == min) {
            return "YES";
        } else if ((min == 1) && (counts[min] == 1)) {
            return "YES";
        } else if (((max - min) == 1) && (counts[max] == 1)) {
            return "YES";
        }       
    }
    
    return "NO";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

