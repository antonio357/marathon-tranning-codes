#include <iostream>

#define end '\000'
using namespace std;

int getBiggestDigitIndex(char inputNum[], int startIndex, int endIndex) {
    char biggest = inputNum[startIndex];
    int index = startIndex;

    for (int i = startIndex + 1; i < endIndex; ++i) {
        if (inputNum[i] > biggest) {
            biggest = inputNum[i];
            index = i;
        }
    }
    return index;
}

void biggestNumber(char inputNum[], int numLen, char result[], int finalLen) {
    int startIndex = 0, index, counter = -1;

    for (int i = finalLen; i > 0; --i) {
        index = getBiggestDigitIndex(inputNum, startIndex, numLen - i + 1);
        result[++counter] = inputNum[index];
        startIndex = index + 1;
    }
    result[++counter] = end;
}

int main() {
    int numLen, delNum;

    while (true) {
        cin >> numLen >> delNum;
        if (numLen == 0 and delNum == 0) break;
        int finalLen = numLen - delNum;

        char inputNum[numLen];
        char outputNum[finalLen + 1];

        cin >> inputNum;
        biggestNumber(inputNum, numLen, outputNum, finalLen);
        cout << outputNum << endl;
    }
    return 0;
}