

class Message {
    string msg;
    static int seq;
public: 
    int order;
    Message() {order = seq++;}
    const string& get_text() {
        return msg;    
    }
    
    void set_text(const string& text) {
        msg = text;
    }
};

int Message::seq = 0;

bool operator<(const Message &a, const Message &b) {
    return a.order < b.order;
}

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        Message m;
        m.set_text(text);
        return m;
    }
};


