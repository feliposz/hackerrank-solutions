#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
int depth_map[15][15] = {};

int move(int x, int y)
{
    if (x >= 1 && x <= 15 && y >= 1 && y <= 15)
    {
        if (depth_map[x-1][y-1] >= 0) {
            return depth_map[x-1][y-1];
        }
        int a = move(x - 2, y + 1);
        int b = move(x - 2, y - 1);
        int c = move(x + 1, y - 2);
        int d = move(x - 1, y - 2);
        int depth = 1 + min(min(a, b), min(c, d));
        depth_map[x-1][y-1] = depth;
        return depth;
    }
    return 0;
}

// Complete the chessboardGame function below.
string chessboardGame(int x, int y) {
    if (move(x, y) % 2 == 0) {
        return "First";
    } else {
        return "Second";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            depth_map[i][j] = -1;

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string xy_temp;
        getline(cin, xy_temp);

        vector<string> xy = split_string(xy_temp);

        int x = stoi(xy[0]);

        int y = stoi(xy[1]);

        string result = chessboardGame(x, y);

        fout << result << "\n";
    }

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

