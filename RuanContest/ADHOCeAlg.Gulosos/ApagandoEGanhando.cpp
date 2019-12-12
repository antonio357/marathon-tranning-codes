#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct digit {
    char num;
    int index;
};

bool operator<(const digit& d1, const digit& d2) {
   if (d1.num == d2.num) return d1.index < d2.index;
   else return d1.num < d2.num;
}

bool compareDigitByIndex(digit dgt1, digit dgt2) {
    return dgt1.index < dgt2.index;
}

string biggestNumber(string inputNum, int finalLen) {
    string result = "";

    // digits sorted by size
    priority_queue <digit> digits;
    for (int i = 0; i < inputNum.length(); ++i) {
        digit dgt = {inputNum[i], i};
        digits.push(dgt);
    }

    // digits sorted by index
    digit arr[finalLen];
    for (int j = 0; j < finalLen; ++j) {
        arr[j] = digits.top();
        digits.pop();
    }
    int n = sizeof(arr) * finalLen/ sizeof(arr[0]);
    sort(arr, arr+n, compareDigitByIndex);

    // creating result
    for (int k = 0; k < finalLen; ++k) {
        result += arr[k].num;
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
        cout << "case = " << biggestNumber(inputNum, numLen - delNum) << endl;
    }
    return 0;
}