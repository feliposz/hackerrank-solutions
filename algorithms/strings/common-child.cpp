#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'commonChild' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int commonChild(string s1, string s2) {
    vector<vector<int>> dp(s1.size() + 1);
    for (auto &row : dp) {
        row.resize(s2.size() + 1);
        for (auto &val : row) {
            val = 0;
        }
    }
    
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            int da = dp[i][j-1];
            int db = dp[i-1][j];
            int dm = dp[i-1][j-1] + 1;
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dm;
            } else {
                dp[i][j] = da > db ? da : db;
            }
        }
    }
    
    return dp[s1.size()][s2.size()];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}

