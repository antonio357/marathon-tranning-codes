#include <iostream>

using namespace std;

int prefixLength(string* string1, string* string2) {
    int c = 0;

    for (int i = 0; i < string1->length(); ++i) {
        if ((*string1)[i] == (*string2)[i]) c++;
        else break;
    }

    return c;
}

int main() {
    int nCases;
    unsigned long long int sum;
    string top_num;
    string bottom_num;

    while (cin >> nCases) {
        sum = 0;

        cin >> top_num;
        if (nCases > 1) {
            cin >> bottom_num;

            sum += prefixLength(&top_num, &bottom_num);
            for (int i = 0; i < nCases - 2; ++i) {
                top_num = bottom_num;
                cin >> bottom_num;

                sum += prefixLength(&top_num, &bottom_num);
            }
        }

        cout << sum << endl;
    }
    return 0;
}
