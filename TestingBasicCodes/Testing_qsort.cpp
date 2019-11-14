#include <iostream>
#define size 3

using namespace std;

int compare_strings_alphabetically(const void *str_in1, const void *str_in2) {
    auto str_p1 = (string*)str_in1;
    auto str_p2 = (string*)str_in2;
    string str1 = *str_p1;
    string str2 = *str_p2;
    int counter = 0, dif;

    while (true) {
        dif = str1[counter] - str2[counter];
        cout << "dif = " << str1[counter] << " - " << str2[counter] << " = " << dif << endl;
        counter++;

        if (dif != 0) {
            if (dif > 0) return true;
            if (dif < 0) return false;
        }
        if (counter == str1.length()) return false;
        if (counter == str2.length()) return true;
    }
}

int main() {
//    string strArray[] = {"a", "b", "c"}; // working fine
//    string strArray[] = {"a", "c", "b"}; // not working
//    string strArray[] = {"b", "a", "c"}; // not working
//    string strArray[] = {"b", "c", "a"}; // not working
    string strArray[] = {"c", "b", "a"}; // not working
//    string strArray[] = {"c", "a", "b"}; // not working

    qsort(strArray, size, sizeof(string), compare_strings_alphabetically);

    cout << '[';
    for (int i = 0; i < size; ++i) {
        if (i == size - 1) cout << strArray[i];

        else cout << strArray[i] << ", ";
    }
    cout << ']' << endl;
    return 0;
}
