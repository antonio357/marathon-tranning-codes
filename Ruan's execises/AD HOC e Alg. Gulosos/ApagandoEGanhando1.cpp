#include<iostream>

using namespace std;

void takeBiggerNumb(int* numbers, int length, int quantToRemove, int* output) {
    for (int i = 0; i < length - quantToRemove; i++) output[i] = -1;
    // printando o array que vai ser enviado pra takeBiggerNumb
    // for (int i = 0; i < length; i++) cout << numbers[i] << ", "; cout << "endl " << endl;
    int quantRemoved = 0, biggerFound = 0, initialPositionToLeft;
    int outputCounter = 0, p, pAnt = 0, limitanteInicial = -1, k; // na primeira iteracao eh limitanteInicial = -1
    while (quantRemoved <= quantToRemove) {
        initialPositionToLeft = length - 1 - (quantToRemove - quantRemoved);
        biggerFound = numbers[initialPositionToLeft];
        p = initialPositionToLeft;
        for (int i = initialPositionToLeft; i > limitanteInicial; i--) {
            if (numbers[i] > biggerFound) {
                biggerFound = numbers[i];
                p = i;
            }
        }
        if (outputCounter >= length - quantToRemove) break;
        output[outputCounter] = p;
        outputCounter++;
        if (limitanteInicial == -1) k = 0; // na primeira iteracao era necessario ser zero assim com limitanteInicial = -1
        else k = 1;
        limitanteInicial = p;
        quantRemoved += p - pAnt - k;
        pAnt = p;
    }
    for (int i = 0; i < length - quantToRemove; i++) {
        if (output[i] > -1) output[i] = numbers[output[i]]; 
        else cout << "Deu errado" << endl;
    }
}

int main() {
    string input;
    int* numbers;
    int* output;
    int quantNumbers, quantToRemove;
    while (true) {
        cin >> quantNumbers >> quantToRemove;
        if (quantNumbers == 0) break;
        
        cin >> input;
        numbers = new int[input.length()];
        for (int i = 0; i < quantNumbers; i++) numbers[i] = input[i] - '0';
        output = new int[quantNumbers - quantToRemove];
        // printando o array que vai ser enviado pra takeBiggerNumb
        // for (int i = 0; i < quantNumbers; i++) cout << numbers[i] << ", "; cout << "endl " << endl;
        takeBiggerNumb(numbers, quantNumbers, quantToRemove, output);
        for (int i = 0; i < quantNumbers - quantToRemove; i++) cout << output[i]; cout << endl;
    }
    return 0;
}