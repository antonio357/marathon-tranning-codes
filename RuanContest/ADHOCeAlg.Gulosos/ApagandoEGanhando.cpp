#include <iostream>
#include <list>

using namespace std;

typedef struct {
    char num;
    int index;
} digit;

bool operator<(const digit& d1, const digit& d2){
    if (d1.num == d2.num) return d1.index < d2.index;
    return d1.num > d2.num;
}

bool operator==(const digit& d1, const digit& d2){
    return d1.num == d2.num and d1.index == d2.index;
}

string biggestNumber(char inputNum[], int len, char outputNum[], int finalLen) {

    list <digit> digits;
    for (int i = 0; i < len; ++i) {
        digit dgt = {inputNum[i], i};
        digits.push_back(dgt);
    }
    digits.sort();

    int sill = len - finalLen;
    int previousIndex = -1;
    for (int j = 0; j < finalLen; ++j) {
        for (auto it = digits.begin(); it != digits.end(); ++it) {
            if (it->index <= sill and it->index > previousIndex) {
                outputNum[j] = it->num;
                sill++;
                digits.remove(*it);
                previousIndex = it->index;
                break;
            }
        }
    }
}

int main() {
    int numLen, delNum;

    while (true) {
        cin >> numLen >> delNum;
        if (numLen == 0 and delNum == 0) break;
        int finalLen = numLen - delNum;

        char inputNum[numLen + 1];
        char outputNum[finalLen + 1];
        scanf("%s", &inputNum);
        biggestNumber(inputNum, numLen, outputNum, finalLen);
        printf("%s\n", outputNum);
    }
    return 0;
}