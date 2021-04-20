#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumDistances function below.
int minimumDistances(vector<int> a) {
    int *pos = new int[100001];
    for (int i = 0; i < 100001; i++) {
        pos[i] = -1;
    }
    int a_count = a.size();
    int distance = a_count + 1;
    for (int i = 0; i < a_count; i++) {
        int n = a[i];
        if ((pos[n] != -1) && (distance > (i - pos[n]))) {
            distance = i - pos[n];
            printf("i = %d, j = %d, distance = %d\n", pos[n], i, distance);
            if (distance == 1) {
                break;
            }
        }        
        pos[n] = i;
    }
    if (distance > a_count) {
        distance = -1;
    }
    return distance;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = minimumDistances(a);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

