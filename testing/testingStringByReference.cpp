#include<iostream>

using namespace std;

void f(string * str) {
    *str = "inside function";
    cout << "this print" << endl;
    cout << (*str).find(1) << endl;
    cout << "this print" << endl;
}

int main() {
    string t = "not modified";
    f(&t);
    cout << t << endl;

    string m = "a";
    cout << m.empty() << endl;
}