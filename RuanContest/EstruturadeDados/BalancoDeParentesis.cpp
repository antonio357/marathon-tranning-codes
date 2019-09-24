#include <iostream>
#include <stack>
#define LEFTP '('
#define  RIGHTP ')'
using namespace std;

string itsCorrect(string line) {
    stack<char> p;
    char c;

    for (int i = 0; i < line.length(); i++) {
        c = line[i];
        if (c == LEFTP or c == RIGHTP) {
            if (p.empty()) p.push(c);
            else {
                if (p.top() == LEFTP and c == RIGHTP) p.pop();
                else p.push(c);
            }
        }
    }

    if (p.empty()) return "correct";
    return "incorrect";
}

int main() {
    string input;
    while ( cin >> input ) {
        cout << itsCorrect(input) << endl;
    }
    return 0;
}
