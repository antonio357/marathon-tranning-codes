#include<iostream>
#include<fstream> // lembrar de comentar
#include<string>
#include<map>

using namespace std;

int process(map<char, int>* alphabet, const char* frase) {
    char caracter;
    int num, bigger = -1;
    for (int i = 0; frase[i] != '\0'; i++) {
        caracter = (char) frase[i];
        num = (int) caracter;
        if (num >= 97 && num <= 122) {
            (*alphabet)[caracter]++;
            if ((*alphabet)[caracter] > bigger) bigger = (*alphabet)[caracter];
        }
        else if (num >= 65 && num <= 90) {
            (*alphabet)[caracter + 32]++;
            if ((*alphabet)[caracter + 32] > bigger) bigger = (*alphabet)[caracter + 32];
        }
    }
    return bigger;
}

int main() {
    ofstream file__; // lembrar de comentar
    file__.open("txtsFiles\\output"); // lembrar de comentar
    // preparing the map 
    map<char, int> alphabet;
    for (int i = 97; i < 123; i++) {
        alphabet.insert(pair <char, int> ((char) i, 0));
    }
    // input + output
    int nCases, bigger;
    char caracter;
    //cin >> nCases;
    scanf("%d", &nCases);
    char input[210]; 
    for (int n = 0; n < nCases; n++) {
        // zerando o mapa
        for (int i = 97; i < 123; i++) {
            caracter = (char) i;
            alphabet[caracter] = 0;
        }
        scanf("%[^\n]s", input);
        //bigger = process(&alphabet, input);
        for (int i = 97; i < 123; i++) {
            if (alphabet[i] == bigger) {
                cout << (char) i;
                file__ << (char) i; // lembrar de comentar
            }
        }
        cout << endl;
        file__ << endl; // lembrar de comentar
    }
    file__.close(); // lembrar de comentar
}