#include <iostream>
#include <list>
using namespace std;

struct coordinate {
    int x, y;
};

struct instruction {
    char item;
    coordinate cord;
};

bool updateActualCoordinate(char** matrix, int nLines, int nChars, instruction* actual) {
    int begin;

    if (actual->item == '<') {
        begin = actual->cord.y - 1;
        if (begin > -1) {
            for (int c = begin; c >= 0; c--) {
                if (matrix[actual->cord.x][c] != '.') {
                    actual->cord.y = c;
                    actual->item = matrix[actual->cord.x][c];
                    return true;
                }
            }
        }
    }

    else if (actual->item == '>') {
        begin = actual->cord.y + 1;
        if (begin < nChars) {
            for (int c = begin; c < nChars; c++) {
                if (matrix[actual->cord.x][c] != '.') {
                    actual->cord.y = c;
                    actual->item = matrix[actual->cord.x][c];
                    return true;
                }
            }
        }
    }

    else if (actual->item == '^') {
        begin = actual->cord.x - 1;
        if (begin > 0) {
            for (int l = begin; l >= 0; l--) {
                if (matrix[l][actual->cord.y] != '.') {
                    actual->cord.x = l;
                    actual->item = matrix[l][actual->cord.y];
                    return true;
                }
            }
        }
    }

    else if (actual->item == 'v') {
        begin = actual->cord.x + 1;
        if (begin < nLines) {
            for (int l = begin; l < nLines; l++) {
                if (matrix[l][actual->cord.y] != '.') {
                    actual->cord.x = l;
                    actual->item = matrix[l][actual->cord.y];
                    return true;
                }
            }
        }
    }

    return false;
}

char find(char** matrix, int nLines, int nChars, instruction first_char) {
    instruction actual = first_char;
    list <coordinate> cords;
    bool visited;

    while (true) {
        // verifying if actual coordinate was visited already
        visited = false;
        for (auto cd = cords.begin(); cd != cords.end(); ++cd) {
            if (cd->x == actual.cord.x and cd->y == actual.cord.y) {
                visited  = true;
                break;
            }
        }
        if (visited) break;

        // adding coordinate as visited
        cords.push_back(actual.cord);

        if (actual.item == '*') return '*';

        if (not updateActualCoordinate(matrix, nLines, nChars, &actual)) break;
    }

    return '!';
}

int main() {
    int nColumns, nLines;
    cin >> nColumns >> nLines;
    char** matrix;
    matrix =  new char*[nLines];
    instruction first_char = {'.', {-1, -1}};
    bool got_fist_char = false;

    for (int l = 0; l < nLines; l++) {
        matrix[l] = new char[nColumns];
        cin >> matrix[l];

        if (not got_fist_char) {
            for (int c = 0; c < nColumns; c++) {
                if (matrix[l][c] != '.' and not got_fist_char) {
                    got_fist_char = true;
                    first_char.item = matrix[l][c];
                    first_char.cord.x = l;
                    first_char.cord.y = c;
                }
            }
        }
    }

    cout << find(matrix, nLines, nColumns, first_char) << endl;
    return 0;
}