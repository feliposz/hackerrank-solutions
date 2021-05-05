#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct UndoOp {
    int type;
    size_t len;
    string content;
};

int OLD_main() {

    vector<UndoOp> undo_stack;
    
    ios::sync_with_stdio(false);
    
    string s;
    
    s.reserve(1000000);
    undo_stack.reserve(1000000);
    
    int q;
    cin >> q;
    
    while (q-- > 0) {
        int op;
        cin >> op;
        switch (op) {
            
            case 1: {
                string w;
                cin >> w;
                s += w;
                undo_stack.push_back({2, w.size(), ""});
            } break;
            
            case 2: {
                size_t k;
                cin >> k;
                undo_stack.push_back({1, k, s.substr(s.size() - k)});
                s.resize(s.size() - k);
            } break;
            
            case 3: {
                size_t k;
                cin >> k;
                cout << s[k - 1] << endl;
            } break;
            
            case 4: {
                UndoOp uo = undo_stack.back();                
                if (uo.type == 1) {
                    s += uo.content;
                } else {
                    s.resize(s.size() - uo.len);
                }
                undo_stack.pop_back();
            } break;

        }
        cerr << "s = " << s << endl;
        
    }
    
    return 0;
}

int main() {

    vector<string> undo_stack;
    
    ios::sync_with_stdio(false);
    
    string s;
    
    int q;
    cin >> q;
    
    while (q-- > 0) {
        int op;
        cin >> op;
        switch (op) {
            
            case 1: {
                string w;
                cin >> w;
                undo_stack.push_back(s);
                s += w;
            } break;
            
            case 2: {
                size_t k;
                cin >> k;
                undo_stack.push_back(s);
                s.resize(s.size() - k);
            } break;
            
            case 3: {
                size_t k;
                cin >> k;
                cout << s[k - 1] << endl;
            } break;
            
            case 4: {
                s = undo_stack.back();
                undo_stack.pop_back();
            } break;

        }
        
    }
    
    return 0;
}

