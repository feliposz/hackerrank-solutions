

class Person {
protected:
    string name;
    int age;
public:
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

class Professor : public Person {
    int publications;
    int cur_id;
    static int seq_id;
public:
    virtual void getdata() override {
        cin >> name >> age >> publications; 
        cur_id = seq_id++;
    }
    
    virtual void putdata() override {
        cout << name << " " << age << " " << publications << " " << cur_id << endl;    
    }
};

int Professor::seq_id = 1;


class Student : public Person {
    int marks[6];
    int cur_id;
    static int seq_id;
public:
    virtual void getdata() override {
        cin >> name >> age;    
        for (int i = 0; i < 6; i++) {
            cin >> marks[i];
        }
        cur_id = seq_id++;
    }
    
    virtual void putdata() override {
        int sum = 0;
        for (int i = 0; i < 6; i++) {
            sum += marks[i];
        }
        cout << name << " " << age << " " << sum << " " << cur_id << endl;    
    }    
};

int Student::seq_id = 1;


