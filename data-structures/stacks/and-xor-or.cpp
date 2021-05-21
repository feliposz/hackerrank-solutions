#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'andXorOr' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int andXorOr(vector<int> a) {
    
    int max = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            int value = a[i]^a[j];
            if (max < value) {
                cerr << value << " " << a[i] << " " << a[j] << endl;
                max = value;
            }
        }
    }
    return max;
    /*
    sort(a.begin(), a.end());
    int max = 0;
    for (int i = 0; i < a.size()-1; i++) {
        int j = i + 1;
        int value = a[i]^a[j];
        if (max < value) {
            cerr << value << " " << a[i] << " " << a[j] << endl;
            max = value;
        }
    }
    return max;*/
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = andXorOr(a);

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

