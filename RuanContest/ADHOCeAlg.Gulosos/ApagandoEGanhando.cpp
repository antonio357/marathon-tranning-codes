#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct {
    char num;
    int index;
} digit;

bool operator<(const digit& d1, const digit& d2) {
   if (d1.num == d2.num) return d1.index < d2.index;
   else return d1.num < d2.num;
}

bool compareDigitByIndex(digit dgt1, digit dgt2) {
    return dgt1.index < dgt2.index;
}

void printList1(priority_queue <digit>* digits_debug) {
    cout << "priority_queue = [";
    while (not digits_debug->empty()) {
        cout << digits_debug->top().num << ", ";
        digits_debug->pop();
    } cout << ']' << endl;
}

void printArray(digit arr[], int len) {
    cout << "array = [";
    for (int i = 0; i < len; ++i) {
        cout << arr[i].num << ", ";
    } cout << ']' << endl;
}

string biggestNumber(string inputNum, int finalLen) {
    string result = "";

    // digits sorted by size
    priority_queue <digit> digits;
//    priority_queue <digit> digits_debug;
    for (int i = 0; i < inputNum.length(); ++i) {
        digit dgt = {inputNum[i], i};
        digits.push(dgt);
//        digits_debug.push(dgt);
    }
//    printList1(&digits_debug);

    // digits sorted by index
    digit arr[finalLen];
    for (int j = 0; j < finalLen; ++j) {
        arr[j] = digits.top();
        digits.pop();
    }
//    cout << "before get sorted" << endl;
//    printArray(arr, finalLen);
    sort(arr, arr+finalLen, compareDigitByIndex);
//    cout << "after get sorted" << endl;
//    printArray(arr, finalLen);

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
//        cout << "inputNUm = " << inputNum << endl;
        cout << biggestNumber(inputNum, numLen - delNum) << endl;
    }
    return 0;
}