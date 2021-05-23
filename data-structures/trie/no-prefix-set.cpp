#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'noPrefix' function below.
 *
 * The function accepts STRING_ARRAY words as parameter.
 */


struct Node {
    char value;
    bool complete;
    int size;
    map<char, Node> children;
};

bool addNode(Node &root, string s) {
    //cerr << "add " << s << endl;
    Node *node = &root;
    bool bad = false;
    for (int i = 0; i < s.size(); i++) {
        node = &node->children[s[i]];
        node->value = s[i];
        node->size++;
        if (node->complete) {
            bad = true;
            break;
        }
        if (i == s.size() - 1) {
            node->complete = true;
            if (node->size > 1) {
                bad = true;
                break;
            }
        }
    }
    return bad;
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

void noPrefix(vector<string> words) {
    Node root;
    for (string word : words) {
        if (addNode(root, word)) {
            cout << "BAD SET" << endl;
            cout << word << endl;
            return;
        }
    }
    cout << "GOOD SET" << endl;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        string words_item;
        getline(cin, words_item);

        words[i] = words_item;
    }

    noPrefix(words);

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

