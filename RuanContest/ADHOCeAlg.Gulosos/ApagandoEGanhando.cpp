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
    return d1.num == d2.num and d1.index == d2.index;
}


class biggestNumber {
    private:
        int finalLen;
        int removeCounter;
        bool firstAdd;
        string inputNum;
        stack <digit> selector;

        void process() {
            for (int i = 0; i < inputNum.length(); i++) {
                digit dgt = {inputNum[i], i};
                if (firstAdd) {
                    this->firstAdd = false;
                    selector.push(dgt);
                } else {
                    while (selector.top() < dgt and removeCounter < inputNum.length() - finalLen) {
                        removeCounter++;
                        selector.pop();
                    }
                    selector.push(dgt);
                }
            }
        }

        void print() {
            cout << "here" << endl;
            char outputNum[finalLen + 1];
            for (int i = finalLen - 1; i > -1; --i) {
                outputNum[i] = selector.top().num;
                selector.pop();
            } outputNum [finalLen] = '\000';
            cout << outputNum << endl;
        }

    public:
        biggestNumber(string inputNum, int finalLen) {
        this->inputNum = inputNum;
        this->finalLen = finalLen;
        this->firstAdd = true;
        this->removeCounter = 0;
        process();
        print();
    }
};

int main() {
    int numLen, delNum;
    string inputNum;

    while (true) {
        cin >> numLen >> delNum;
        if (numLen == 0 and delNum == 0) break;
        int finalLen = numLen - delNum;

        cin >> inputNum;
        biggestNumber(inputNum, finalLen);
    }
    return 0;
}