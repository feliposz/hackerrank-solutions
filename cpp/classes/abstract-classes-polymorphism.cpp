

class LRUCache : public Cache {
    
    int size;
    
public:

    LRUCache(int capacity) {
        size = 0;
        cp = capacity;
        tail = head = nullptr;        
    };
    
    virtual void set(int k, int v) override {
        //cerr << "set " << k << "," << v << endl;
        Node *n;
        if (mp.count(k)) {
            //cerr << "found" << endl;
            n = mp[k];
        } else if (size < cp) {
            //cerr << "growing" << endl;
            n = new Node(k, v);
            mp[k] = n;
            size++;
        } else {
            //cerr << "reusing" << endl;
            n = tail;
            mp.erase(tail->key);
            mp[k] = n;
        }
        n->value = v;
        move_to_head(n);
    }
    
    void move_to_head(Node *n) {
        //cerr << "moving to head" << endl;
        if (n != head) {
            if (n->prev) {
                n->prev->next = n->next;
            }
            if (n->next) {
                n->next->prev = n->prev;
            }
            if (tail == n) {
                tail = n->prev;
            }
            if (head) {                
                head->prev = n;
            }
            n->next = head;
            head = n;
        }
        if (!tail) {
            tail = n;
        }
        for (Node *nd = head; nd; nd = nd->next) {
            //cerr << nd->key << "(" << nd->value << ") ";
        }
        //cerr << endl;
    }
    
    virtual int get(int k) override {
        //cerr << "get " << k << endl;
        if (mp.count(k)) {
            Node *n = mp[k];
            //move_to_head(n);
            return n->value;
        }
        return -1;
    }
};


