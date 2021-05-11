#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'runningMedian' function below.
 *
 * The function is expected to return a DOUBLE_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */


vector<double> runningMedian(vector<int> a) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minq;
    std::priority_queue<int> maxq;
    vector<double> result;
  
    double median = 0;

    for (auto it = a.begin(); it != a.end(); it++) {
        double x = (double)*it;
        
        if (x <= median) {
            maxq.push(x);
        } else {
            minq.push(x);
        }
        
        if (minq.size() == (maxq.size() + 2)) {
            maxq.push(minq.top());
            minq.pop();
        } else if ((minq.size() + 2) == maxq.size()) {
            minq.push(maxq.top());
            maxq.pop();
        }
        
        if (minq.size() == maxq.size()) {
            median = (minq.top() + maxq.top()) / 2.0;
        } else if (minq.size() > maxq.size()) {
            median = minq.top();
        } else {
            median = maxq.top();
        }
        
        result.push_back(median);
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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

