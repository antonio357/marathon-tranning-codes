#include<iostream>

using namespace std;

void outputAdd(int* output, int* outputPositionCounter, int value) {
    output[*outputPositionCounter] = value;
    *outputPositionCounter++;
}

void biggerOne(int* numbers, int* initialPosition, int *finalPosition, int* biggerFound, int* rem) {
    int p;
    *rem = 0;
    for (p = *finalPosition - 1; p >= *initialPosition; p++) {
        if (numbers[p] > *biggerFound) { 
            *biggerFound = numbers[p];
            *rem = *finalPosition - *initialPosition - 1; 
            *initialPosition = p;
            
        }
    }
}

void takeBiggerNumb(int* numbers, int length, int quantToRemove, int* output) {
    // int arrayLastPosition = length - 1, arrayInitialPosition = 0;
    int outputPositionCounter = 0, quantAdd = 0;
    int inicio = -1, fim, biggerFound, reindexacao, k;
    while(quantAdd < length - quantToRemove) {
        cout << "lenght = " << length << ", " << "quantToRemove = " << quantToRemove << ", " << "quantAdd = " << quantAdd << endl;
        if (inicio == -1) k = 1;
        else k = 0;
        fim = length - k - quantToRemove + quantAdd;
        reindexacao = fim;
        biggerFound = numbers[fim];
        cout << "varredura do fim = " << fim << " ate o inicio > " << inicio << endl;
        for (int i = fim - 1; i > inicio; i--) {
            if (numbers[i] > biggerFound) {
                cout << "found a bigger number when, i = " << i << endl;
                biggerFound = numbers[i];
                reindexacao = i;
            }
        }
        inicio = reindexacao;
        cout << "nesta varredura o maior numero encontrado foi = " << biggerFound << endl;
        output[outputPositionCounter] = biggerFound;
        outputPositionCounter++;
        quantAdd++;
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