#include<iostream>

using namespace std;

void takeBiggerNumb(int* numbers, int length, int quantToAdd, int* output) {
    // printando o array que vai ser enviado pra takeBiggerNumb
    // for (int i = 0; i < length; i++) cout << numbers[i] << ", "; cout << "endl " << endl;
    int quantAdded = 0, outputCounter = 0, wantedNumb = 9;
    while (quantAdded < quantToAdd) {
        for (int i = length - 1; i > -1; i--) {
            if (numbers[i] == wantedNumb) {
                numbers[i] += 50;
                quantAdded++;
                if (quantAdded == quantToAdd) break;
            }
        }
        wantedNumb--;
    }
    for (int i = 0; i < length; i++) {
        if (numbers[i] >= 50) {
            output[outputCounter] = numbers[i] - 50;
            outputCounter++;
        }
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
        takeBiggerNumb(numbers, quantNumbers, quantNumbers - quantToRemove, output);
        for (int i = 0; i < quantNumbers - quantToRemove; i++) cout << output[i]; cout << endl;
    }
    return 0;
}