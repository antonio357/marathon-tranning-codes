#include <iostream>
#include <map>

using namespace std;
#define toBraille 'S'
#define toNum 'B'
#define nLayers 3
#define nColumns 2
#define nDigits 10
#define zeroInChar 48

typedef struct {
    char matrix[nLayers][nColumns];
    char digit;
} brailleScript;

bool operator==(const brailleScript &bs1, const brailleScript &bs2) {
    for (int i = 0; i < nLayers; ++i) {
        for (int j = 0; j < nColumns; ++j) {
            if (bs1.matrix[i][j] != bs2.matrix[i][j]) return false;
        }
    }
    return true;
}

brailleScript zero = {{'.', '*', '*', '*', '.', '.'}, '0'};
brailleScript one = {{'*', '.', '.', '.', '.', '.'}, '1'};
brailleScript two = {{'*', '.', '*', '.', '.', '.'}, '2'};
brailleScript tree = {{'*', '*', '.', '.', '.', '.'}, '3'};
brailleScript four = {{'*', '*', '.', '*', '.', '.'}, '4'};
brailleScript five = {{'*', '.', '.', '*', '.', '.'}, '5'};
brailleScript six = {{'*', '*', '*', '.', '.', '.'}, '6'};
brailleScript seven = {{'*', '*', '*', '*', '.', '.'}, '7'};
brailleScript eight = {{'*', '.', '*', '*', '.', '.'}, '8'};
brailleScript nine = {{'.', '*', '*', '.', '.', '.'}, '9'};

brailleScript brailleScripts[nDigits] = {zero, one, two, tree, four, five, six, seven, eight, nine};

class Braille {
    private:
        brailleScript brailleScript1;
        int lineCounter;

        void setNum() {
            if (lineCounter == nLayers) {
                for (int i = 0; i < nDigits; ++i) {
                    if (brailleScripts[i] == brailleScript1) brailleScript1.digit = brailleScripts[i].digit;
                }
            }
        }

    public:
        Braille() {
            lineCounter = 0;
            brailleScript1.digit = '\0';
        }

        void setMatrix (string input) {
            if (lineCounter < nLayers) {
                for (int i = 0; i < nColumns; ++i) {
                    brailleScript1.matrix[lineCounter][i] = input[i];
                }
                lineCounter++;
            }
        }

        void printNum() {
            if (brailleScript1.digit == '\0') {
                setNum();
            }
            cout << brailleScript1.digit;
        }
};

int main() {
    int len;
    char translation;
    string input;

    while (true) {
        cin >> len;
        if (len == 0) break;

        cin >> translation;
        if (translation == toBraille) {
            cin >> input;

            for (int l = 0; l < nLayers; ++l) {
                for (int d = 0; d < len; ++d) {
                    for (int c = 0; c < nColumns; ++c) {
                        cout << brailleScripts[input[d] - zeroInChar].matrix[l][c];
                    }
                    if (d == len - 1) cout << endl;
                    else cout << ' ';
                }
            }
        } else if (translation == toNum) {
            Braille brailles[len];
            for (int k = 0; k < len; ++k) {
                Braille braille;
                brailles[k] = braille;
            }

            for (int i = 0; i < nLayers; ++i) {
                for (int j = 0; j < len; ++j) {
                    cin >> input;
                    brailles[j].setMatrix(input);
                }
            }

            for (int l = 0; l < len; ++l) {
                brailles[l].printNum();
            } cout << endl;
        }
    }

    return 0;
}