#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

struct tag {
    string name;
    map<string, string> attributes;
    map<string, tag*> children;
    tag *parent;
    
    tag(string name, tag *ptr) : name(name) {
        parent = ptr;
    }
};

int main() {
  
    tag *root = new tag("root", nullptr);
    tag *current = root;
  
    string n_q;
    getline(cin, n_q);
    int n, q;
    size_t idx = 0;
    n = stoi(n_q, &idx);
    q = stoi(n_q.substr(idx));
    
    // cerr << n << endl;
    // cerr << q << endl;
    
    while (n-- > 0) {
        string line;
        getline(cin, line);
        // cerr << line << endl;
        if (line.substr(0, 2) == "</") {
            current = current->parent;
            // cerr << "closing" << endl;
        } else {
            string name;
            int i = 0;
            if (line[i] == '<') {
                i++;
            }
            while (line[i] != ' ' && line[i] != '>') {
                name += line[i];
                i++;
            }
            // cerr << "name: " << name << endl;
            tag *child = new tag(name, current);
            current->children[name] = child;
            
            while (line[i] != '>') {
                string attr;
                string value;
                while (line[i] == ' ') {
                    i++;
                }     
                while (line[i] != ' ' && line[i] != '=') {
                    attr += line[i];
                    i++;
                }
                // cerr << "attr: " << attr << endl;
                while (line[i] == ' ') {
                    i++;
                }     
                if (line[i] == '=') {
                    i++;
                }
                while (line[i] == ' ') {
                    i++;
                }     
                if (line[i] == '"') {
                    i++;
                    while (line[i] != '"') {
                        value += line[i];
                        i++;
                    }
                    i++;
                }
                // cerr << "value: " << value << endl;
                child->attributes[attr] = value;                
                
            }
            current = child;
        }
    }
    
    while (q-- > 0) {
        string query;
        getline(cin, query);
        // cerr << "query: " << query << endl;
        
        current = root;    
        int i = 0;
        while (query[i] != '~') {
            string name;
            while (query[i] != '.' && query[i] != '~') {
                name += query[i];
                i++;
            }
            // cerr << "name: " << name << endl;
            if (query[i] == '.') {
                i++;
            }
            if (current->children.count(name)) {
                current = current->children[name];
            } else {
                current = nullptr;
                break;
            }
        }
        i++;
        
        // cerr << "current: " << current << endl;
        // cerr << "attributes: " << current->attributes.size() << endl;
        
        if (!current) {
            cout << "Not Found!" << endl;
        } else {
            string attr;
            while (query[i]) {
                attr += query[i];
                i++;
            }
            // cerr << "attr: " << attr << endl;
            if (current->attributes.count(attr)) {
                cout << current->attributes[attr] << endl;            
            } else {
                cout << "Not Found!" << endl;
            }
        }
        
    }
    
    return 0;
}

