#include <iostream>
#include <stack>

using namespace std;

typedef struct {
    char num;
    int index;
} digit;

bool operator<(const digit& d1, const digit& d2){
    return d1.num < d2.num;
}

bool operator==(const digit& d1, const digit& d2){
    return d1.num == d2.num;
}

bool operator<=(const digit& d1, const digit& d2){
    return (d1.num == d2.num or d1.num < d2.num);
}

string biggestNumber(string inputNum, int finalLen, int delNum) {
    stack <digit> selector;
    int delCounter = 0;

    for (int i = 0; i < inputNum.length(); i++) {
        digit dgt = {inputNum[i], i};
//        cout << "dgt in play = " << dgt.num << endl;
        while (selector.size() > 0 and selector.top() < dgt and delCounter < delNum) {
//            if (selector.top() == dgt) {
//                selector.pop();
//                delCounter++;
//                cout << "pop first by else" << endl;
//            }
            selector.pop();
            delCounter++;
//            cout << "pop by while" << endl;
        }
        if (selector.size() < finalLen) {
            selector.push(dgt);
//            cout << "push by last if" << endl;
        } else delCounter++;
//        cout << "end of dgt in play" << endl;
    }

    char tempOutputNum[finalLen];
    for (int i = finalLen - 1; i > -1; i--) {
        tempOutputNum[i] = selector.top().num;
        selector.pop();
    }

    string outputNum;
    for (int i = 0; i < finalLen; ++i) {
        outputNum += tempOutputNum[i];
    }

    return outputNum;
}

int main() {
    int numLen, delNum;
    string inputNum;

    while (true) {
        cin >> numLen >> delNum;
        if (numLen == 0 and delNum == 0) break;
        int finalLen = numLen - delNum;

        cin >> inputNum;
        cout << biggestNumber(inputNum, finalLen, delNum) << endl;
    }
    return 0;
}