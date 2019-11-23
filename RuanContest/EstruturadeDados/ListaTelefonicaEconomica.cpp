#include <iostream>
#include <set>

using namespace std;

int prefixLength(const string string1, const string string2) {
    int c = 0;

    for (int i = 0; i < string1.length(); ++i) {
        if ((string1)[i] == (string2)[i]) c++;
        else break;
    }

    return c;
}

unsigned long long int getTotal(set <string>* numbers) {
    unsigned long long int sum = 0;
    auto end = numbers->end(); end--;

    for (auto it = numbers->begin(); it != end; ++it) {
        sum += prefixLength(*it, *(it++)); it--;
    }
    return sum;
}

void printSet(set <string>* numbers) {
    auto end = numbers->end(); end--;

    cout << "set = ";
    for (auto it = numbers->begin(); it != end; ++it) {
        cout << *it << ", ";
    } cout << endl;
}

int main() {
    int nCases;
    string input;
    set <string> numbers;

    while (cin >> nCases) {
        numbers.clear();

        for (int i = 0; i < nCases; ++i) {
            cin >> input;
            numbers.insert(input);
        }

//        printSet(&numbers);
        cout << getTotal(&numbers) << endl;
    }
    return 0;
}
