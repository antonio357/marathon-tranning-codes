#include<iostream>
#include<stack>

using namespace std;

stack <int> takeBiggerNumb(int* numbers, int length, int quantToRemove) {
    stack <int> output;
    int removeCounter = 0, i = 0, numb, emptyStackSlots, digitsLeft;
    while (true) {
        if (i == length) break;
        numb = numbers[i];
        while (true) {
            emptyStackSlots = length - quantToRemove - output.size();
            digitsLeft = length - i;
            if (output.empty() == true) break;
            if (removeCounter >= quantToRemove) break;
            if (numb < output.top()) break;
            //if (digitsLeft <= emptyStackSlots) break;
            //cout << "pop(" << output.top() << ")" << endl;
            output.pop();
            removeCounter++;
        }
        output.push(numb);
        //cout << "push(" << numb << ")" << endl;
        i++;
    }
    return output; 
}

/*void takeBiggerNumb(int* numbers, int length, int quantToRemove, stack <int>* output) {
    int i = 1;
    output->push(numbers[0]);
    while (true) {
        while (numbers[i] >= output->top()) { 
            if (i == length) break;
            output->pop();
            output->push(numbers[i]);
            i++;
        }
        if (i == length) break;
        output->push(numbers[i]);
        i++;
    }
}*/

int main() {
    string input;
    int num;
    int* numbers;
    int counter;
    stack <int> output;
    int quantNumbers, quantToRemove;
    while (true) {
        cin >> quantNumbers >> quantToRemove;
        if (quantNumbers == 0) break;
        int forPrint[quantNumbers - quantToRemove];
        
        cin >> input;
        numbers = new int[input.length()];
        for (int i = 0; i < quantNumbers; i++) numbers[i] = input[i] - '0';
        
        output =  takeBiggerNumb(numbers, quantNumbers, quantToRemove);
        counter = quantNumbers - quantToRemove - 1;
        while (output.size() > 0) {
            forPrint[counter] = output.top();
            counter--;
            output.pop();
        }
        for (int i = 0; i < quantNumbers - quantToRemove; i++) cout << forPrint[i]; cout << endl;
    }
    return 0;
}

