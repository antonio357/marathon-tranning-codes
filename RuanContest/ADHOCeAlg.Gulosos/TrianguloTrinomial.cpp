#include <iostream>
#include <math.h>

using namespace std; 

void convertPrint(unsigned long long int * result , const unsigned long long int * cst ) {
    if (*result > *cst) {
        *result = (*result / *cst) + (*result % *cst) - 1;
    }
    cout << *result << endl;
}

int main() {
    unsigned long int inputNum;
    unsigned long long int result;
    unsigned long long int cst = 2147483647;
    cin >> inputNum;

    result = pow(3, inputNum);
    convertPrint(&result, &cst);
    return 0;
}