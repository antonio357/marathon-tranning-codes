#include <iostream>
#include <string>

using namespace std;
#define nLetters 26
#define a 97
#define A 65

int main() {
    int nCases;
    int biggest = 0;
    cin >> nCases;
    string input;
    char c;
    int alphabet_letters[nLetters];

    for (int j = 0; j < nCases; ++j) {
        // zerando o array de letras e o biggest
        for (int i = 0; i < nLetters; ++i) {
            alphabet_letters[i] = 0;
        }
        biggest = 0;

        setbuf(stdin, NULL);
        getline(cin, input);

        for (int k = 0; k < input.length(); ++k) {
            c = input[k];
            if (c >= a and c < a + nLetters ) {
                alphabet_letters[c - a] += 1;
            }
            else if (c >= A and c < A + nLetters) {
                alphabet_letters[c - A] += 1;
            }
        }

        for (int l = 0; l < nLetters; ++l) {
            if (alphabet_letters[l] > biggest) biggest = alphabet_letters[l];
        }

        for (int m = 0; m < nLetters; ++m) {
            if (alphabet_letters[m] == biggest) cout << (char)(m + a);
        }
        cout << endl;
    }
    return 0;
}
