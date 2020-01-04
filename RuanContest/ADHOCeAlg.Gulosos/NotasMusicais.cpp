#include<iostream>

using namespace std;

typedef struct {
    string nt;
    int position;
    int counter;
} note;


int main() {
    string Notes[12] = {"si", "do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#"};
    note notes[12];
    for (int i = 0; i < 12; i++){
        note n = {Notes[i], i, 0};
        notes[i] = n;
    }

    int nNotes;
    cin >> nNotes;
    int inputNotes[nNotes];
    
    for (int i = 0; i < nNotes; i++) {
        cin >> inputNotes[i];
    }

    for (int i = 0; i < nNotes; i++) {
        notes[inputNotes[i] % 12].counter += 1;
    }
    
    for (int i = 0; i < 12; i++) {
        cout << notes[i].nt << " == " << notes[i].counter << endl;
    }
    
    return 0;
}