#include<iostream>

using namespace std;

unsigned long long int somaAreas(unsigned long long int* compsTapetes, int length) {
    unsigned long long int sum = 0;
    for (int i = 0; i < length; i++)  compsTapetes[i] *= compsTapetes[i];
    /*cout << '[';
    for (int i = 0; i < length; i++) cout << compsTapetes[i] << ", ";
    cout << "endl ]" << endl;*/
    for (int i = 0; i < length; i++) sum += compsTapetes[i];
    return sum;
}

int main() {
    long int compTubo; 
    int quantTapetes;
    cin >> compTubo >> quantTapetes;
    unsigned long long int compsTapetes[quantTapetes];
    compsTapetes[0] = compTubo - (quantTapetes - 1);
    for (int i = 1; i < quantTapetes; i++) compsTapetes[i] = 1;
    /*cout << '[';
    for (int i = 0; i < quantTapetes; i++) cout << compsTapetes[i] << ", ";
    cout << "endl ]" << endl;*/
    cout << somaAreas(compsTapetes, quantTapetes) << endl;
    return 0;
}