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

string biggestNumber(string inputNum, int finalLen) {
    int removeCounter = 0;
    bool firstAdd = true;
    stack <digit> selector;

    for (int i = 0; i < inputNum.length(); i++) {
        digit dgt = {inputNum[i], i};
        if (firstAdd) {
            firstAdd = false;
            selector.push(dgt);
        } else {
            while (selector.size() > 0 and selector.top() < dgt and removeCounter < inputNum.length() - finalLen) {
                selector.pop();
                removeCounter++;
            }
            if (selector.size() > 0 and selector.top() == dgt and selector.size() == finalLen) {
                selector.pop();
                removeCounter++;
            }
            selector.push(dgt);
        }
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
        cout << biggestNumber(inputNum, finalLen) << endl;
    }
    return 0;
}