#include <map>
#include <iostream>
#include <functional>

using namespace std;

struct st {
    string name;
    string * matrix;
};

void print(st* s) {
    cout << s->name << endl;
    for (int i = 0; i < 3; i++) {
        cout << s->matrix[i] << endl;
    }
}

map<string, function<void(st*)>> m;

void f1(st* s) {
    print(s);
    cout << "f1" << endl;
}

void f2(st* s) {
    print(s);
    cout << "f2" << endl;
}

void f3(st* s) {
    print(s);
    cout << "f3" << endl;
}


int main() {
    st s;
    s.name = "name";
    string matrix[3] = {"132", "321" , "213"};
    s.matrix = matrix;

    m.insert(pair<string, function<void(st*)>>("f1", f1));
    m.insert(pair<string, function<void(st*)>>("f2", f2));
    m.insert(pair<string, function<void(st*)>>("f3", f3));
    
    m.at("f1")(&s);
    m.at("f3")(&s);
    m.at("f2")(&s);
    return 0;
}