#include <iostream>

using namespace std;

char zeroZero[8] = {'1','2','3','4','5','6','7','8'};
char zeroOne[6] = {'3','4','6','7','9','0'};
char oneZero[6] = {'2','6','7','8','9','0'};
char oneOne[5] = {'4','5','7','8','0'};

bool itIs(char* numbers, int lenght,  int numb) {
    for (int i = 0; i < lenght; i++) {
        if (numbers[i] == numb) return true;
    }
    return false;
}

void adjust(int number, int seg, char* pr) {
    if (seg == 0) {
        if (itIs(zeroZero, 8, number) == true) {
            pr[0] = '*';
        }
        if (itIs(zeroOne, 6, number) == true) {
            pr[1] = '*';
        }
    }
    else if (seg == 1) {
        if (itIs(oneZero, 6, number) == true) {
            pr[0] = '*';
        }
        if (itIs(oneOne, 5, number) == true) {
            pr[1] = '*';
        }
    }
}

void toBraille(char* numbers, int lenght) {
    char pr[2] = {'.', '.'};
    for (int seg = 0; seg < 3; seg++) {
        for (int numb = 0; numb < lenght; numb++) {
            pr[0] = '.'; pr[1] = '.';
            adjust(numbers[numb], seg, pr);
            if (numb == (lenght - 1)) printf("%c%c\n", pr[0], pr[1]);
            else printf("%c%c ", pr[0], pr[1]);
        }
    }
}

int number(char** matrix, int column) {
    cout << "inside number function" << endl;
    char actual = matrix[0][column];
    char right = matrix[0][column + 1];
    char down = matrix[1][column];
    char downRight = matrix[1][column + 1];
    cout << actual << right << down << downRight << endl;
    if (actual == '.' && down == '*' && downRight == '*' && right == '*') return 0;
    else if (actual == '*' && down == '.' && downRight == '.' && right == '.') return 1;
    else if (actual == '*' && down == '*' && downRight == '.' && right == '.') return 2;
    else if (actual == '*' && down == '.' && downRight == '.' && right == '*') return 3;
    else if (actual == '*' && down == '.' && downRight == '*' && right == '*') return 4;
    else if (actual == '*' && down == '.' && downRight == '*' && right == '.') return 5;
    else if (actual == '*' && down == '*' && downRight == '.' && right == '*') return 6;
    else if (actual == '*' && down == '*' && downRight == '*' && right == '*') return 7;
    else if (actual == '*' && down == '*' && downRight == '*' && right == '.') return 8;
    else if (actual == '.' && down == '*' && downRight == '.' && right == '*') return 9;
    return -1;
}

void toNumbers(char** braille, int lenght) {
    for (int column = 0; column < lenght*2; column += 2) { 
        printf("%d", number(braille, column));
    } 
    printf("\n");
}

int main() {
    int n;
    char type;
    string input[3];
    int inCounter;
    char* numbers;
    char** brailleInput;
    char checkBlankSpace;
    while (1) {
        cin >> n;
        if (n == 0) break;
        cin >> type;
        if (type == 'S') {
            numbers = new char[n];
            cin >> numbers;
            toBraille(numbers, n);
        }
        else {
            brailleInput = new char*[3];
            for (int seg = 0; seg < 3; seg++) {
                brailleInput[seg] = new char[n*2 + 1];
                getline(cin, input[seg]);
                cin.ignore();
                inCounter = 0;
                for (int i = 0; i < input[seg].length(); i++) {
                    checkBlankSpace = input[seg][i];
                    if (checkBlankSpace != ' ') {
                        brailleInput[seg][inCounter] = checkBlankSpace;
                        inCounter++;
                    }
                } brailleInput[seg][input[seg].length() - 1] = '\0';
            }
            //for (int i = 0; i < 3; i++) cout << brailleInput[i] << endl;
            toNumbers(brailleInput, n);
        }
    }
    return 0;
}