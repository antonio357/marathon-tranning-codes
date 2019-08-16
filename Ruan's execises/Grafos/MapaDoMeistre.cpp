#include<iostream>
#include<iterator>
#include <bits/stdc++.h>
#include<list>
#include<map>
using namespace std;
#define LEFT '<'
#define RIGHT '>'
#define UP '^'
#define DOWN 'v'
#define TREASURE '*'
#define DEADLINE '!'
#define WAIT '.'

struct cord {
    int l, c;
};

struct vertex {
    char comand;
    bool visited;
    cord loc;
};

struct line {
    int index;
    list<vertex> array_list;
};

bool travel(list<line>::iterator& lp, list<vertex>::iterator& cp, list<line>* matrix) {
    int line_index = cp->loc.l;
    int col_index = cp->loc.c;
    list<line>::iterator l;
    list<vertex>::iterator c;

    for (l = matrix->begin(); l != matrix->end(); ++l) {
        if (l->index == line_index) {
            for (c = l->array_list.begin(); c != l->array_list.end(); ++c) {
                if (c->loc.c == col_index) {
                    lp = l;
                    cp = c;
                    return true;
                }
            }
        }
    }
    return false;
}

char find(list<line>* matrix) {
    list<line>::iterator lp;
    list<vertex>::iterator cp;
    lp = matrix->begin(); lp++;
    cp = lp->array_list.begin(); cp++;

    while (true) {
        if (cp->visited == true) break;
        cp->visited = true;
        if (cp->comand == TREASURE) return TREASURE;
        if (travel(lp, cp, matrix) == false) break;
    }

    return DEADLINE;
}

int main () {
    int nLines, nColumns;
    cin >> nColumns;
    cin >> nLines;
    string input;
    list<line> matrix;
    char c, answer;

    for (int l = 0; l < nLines; l++) {
        cin >> input;
        list<vertex> array_l;

        for (int col = 0; col < nColumns; col++) {
            c = input[col];

            if (c != WAIT) {
                cord cd = {l, col};
                vertex v = {c, false, cd};
                array_l.push_back(v);
            }
        }

        if (array_l.size() > 0) {
            line row = {l, array_l};
            matrix.push_back(row);
        }
    }
    if (matrix.size() > 0) {
        answer = find(&matrix);
        cout << answer << endl;
    }
    else cout << DEADLINE << endl;
    return 0;
}


