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

void biggestNumber(string inputNum, int finalLen, int delNum) {
    stack <digit> selector;
    int delCounter = 0;

    for (int i = 0; i < inputNum.length(); i++) {
        digit dgt = {inputNum[i], i};
        while (selector.size() > 0 and selector.top() < dgt and delCounter < delNum) {
            selector.pop();
            delCounter++;
        }
        if (selector.size() < finalLen) selector.push(dgt);
        else delCounter++;
    }

    string tempOutputNum;
    while (not selector.empty()) {
        if (selector.top().num >= '0' and selector.top().num <= '9') tempOutputNum += selector.top().num;
        selector.pop();
    }

    string outputNum;
    for (int i = tempOutputNum.length() - 1; i > -1; --i) {
        outputNum += tempOutputNum[i];
    }

    cout << outputNum << endl;
}

int main() {
    int numLen, delNum;
    string inputNum;

    while (true) {
        cin >> numLen >> delNum;
        if (numLen == 0 and delNum == 0) break;
        int finalLen = numLen - delNum;

        cin >> inputNum;
        biggestNumber(inputNum, finalLen, delNum);
    }
    return 0;
}