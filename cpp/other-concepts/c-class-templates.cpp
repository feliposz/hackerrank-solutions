

/*Write the class AddElements here*/
template <class T>
class AddElements {
    T value;
public:
    AddElements(T value) : value(value) {}
    T add(T other) { return value + other; }
    T concatenate(T other) { return value + other; }
};

template <>
class AddElements <string> {
    string value;
public:
    AddElements(string value) : value(value) {}
    string concatenate(string &other) { return value + other; }
};

int start_up() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}

int static r = start_up();

#define endl '\n';


