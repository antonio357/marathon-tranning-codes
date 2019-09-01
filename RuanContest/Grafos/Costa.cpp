#include <iostream>
using namespace std;

bool itsCosta(string* matrix, int x, int y, int nLines, int nColumns) {
    if (x == 0 or x == nColumns - 1 or y == 0 or y == nLines - 1) return true;

    char left = matrix[x - 1][y];
    char right = matrix[x + 1][y];
    char up = matrix[x][y + 1];
    char down = matrix[x][y - 1];

    if (left == '.' or right == '.' or up == '.' or down == '.') return true;
    return false;
}

int count(string* matrix, int nLines, int nColumns) {
    int costaCounter = 0;

    for (int l = 0; l < nLines; l++) {
        for (int c = 0; c < nColumns; c++) {
            if (matrix[l][c] == '#') {
                if (itsCosta(matrix, l, c, nLines, nColumns)) costaCounter++;
            }
        }
    }

    return costaCounter;
}

int main () {
    int nLines, nColumns;
    cin >> nLines >> nColumns;
    string* matrix = new string[nLines];

    for (int l = 0; l < nLines; l++) {
        cin >> matrix[l];
    }

    cout << count(matrix, nLines, nColumns) << endl;
    return 0;
}

