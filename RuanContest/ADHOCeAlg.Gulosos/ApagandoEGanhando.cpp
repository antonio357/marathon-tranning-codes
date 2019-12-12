#include <iostream>

using namespace std;

int getBiggestDigitIndex(string* inputNum, int startIndex, int endIndex) {
    char biggest = (*inputNum)[startIndex];
    int index = startIndex;

    for (int i = startIndex + 1; i < endIndex; ++i) {
        if ((*inputNum)[i] > biggest) {
            biggest = (*inputNum)[i];
            index = i;
        }
    }
    return index;
}

string biggestNumber(string* inputNum, int finalLen) {
    string result = "";
    int startIndex = 0, index;

    for (int i = finalLen; i > 0; --i) {
        index = getBiggestDigitIndex(inputNum, startIndex, inputNum->length() - i + 1);
        result += (*inputNum)[index];
        startIndex = index + 1;
    }

    return result;
}

int main() {
    int numLen, delNum;
    string inputNum;

    while (true) {
        cin >> numLen >> delNum;
        if (numLen == 0 and delNum == 0) break;

        cin >> inputNum;
        cout << biggestNumber(&inputNum, numLen - delNum) << endl;
    }
    return 0;
}