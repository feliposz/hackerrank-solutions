#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'contacts' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_STRING_ARRAY queries as parameter.
 */

struct Node {
    char value;
    bool complete;
    int size;
    map<char, Node> children;
};

void addNode(Node &root, string s) {
    //cerr << "add " << s << endl;
    Node *node = &root;
    for (int i = 0; i < s.size(); i++) {
        node = &node->children[s[i]];
        node->value = s[i];
        node->size++;
        if (i == s.size() - 1) {
            node->complete = true;
        }
    }
}

int countChildren(Node &node) {
    //cerr << "count from... " << node.value << endl;
    int count = 0;
    for (auto p : node.children) {
        count += countChildren(p.second);
    }
    return count + (node.complete ? 1 : 0);
}

int countPartial(Node &root, string s) {
    //cerr << "find " << s << endl;
    Node *node = &root;
    for (int i = 0; i < s.size(); i++) {
        if (node->children.count(s[i]) == 0) {
            return 0;
        }
        node = &node->children[s[i]];
    }    
    return node->size; //countChildren(*node);   
}

void printTrie(Node &node, int depth) {
    for (auto p : node.children) {        
        for (int i = 0; i < depth; i++) {
            cerr << "  ";
        }
        cerr << p.first << endl;
        printTrie(p.second, depth + 1);
    }    
}

vector<int> contacts(vector<vector<string>> queries) {
    Node root;
    vector<int> result;
    for (size_t i = 0; i < queries.size(); i++) {
        if (queries[i][0] == "add") {
            addNode(root, queries[i][1]);
        } else {
            result.push_back(countPartial(root, queries[i][1]));
        }
    }
    
    //printTrie(root, 0);
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string queries_rows_temp;
    getline(cin, queries_rows_temp);

    int queries_rows = stoi(ltrim(rtrim(queries_rows_temp)));

    vector<vector<string>> queries(queries_rows);

    for (int i = 0; i < queries_rows; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            string queries_row_item = queries_row_temp[j];

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> result = contacts(queries);

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

