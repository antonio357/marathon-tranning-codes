#include <iostream>
#include <queue>

using namespace std;
#define nLetters 26
#define a 97
#define A 65

struct woodSpecie {
    string name;
    int quant = 0;
};

void clearPriorityQueue(priority_queue<woodSpecie>* priority_queue) {
    while (not priority_queue->empty()) {
        priority_queue->pop();
    }
}

// (int)(*str)[*position]
int nextNormalizedCharValue(const string str, string::iterator* sp) {

}

bool operator<(const string& c1, const string& c2) {
    string::iterator c1_position, c2_position;

    while (c_c1 < c1.length()) {
        if (c1[c_c1] == ' ') c_c1++;
        if (c2[c_c2] == ' ') c_c2++;
        if (c1[c_c1] < a)
        c_c1++;
        c_c2++;
    }

    return true;
}

void priority_queue_append(priority_queue<woodSpecie>* trees, woodSpecie tree) {
    
}

int main() {
    int nCases;
    string input;
    priority_queue<woodSpecie> trees;

    cin >> nCases;
    cin.ignore(); cin.ignore(); // this is to ignore the blank line input

    for (int i = 0; i < nCases; ++i) {
        clearPriorityQueue(&trees);

        while (true) {
            getline(cin, input);
            if (input.length() == 0) break;

            woodSpecie tree = {input, 0};

            trees.push();
        }
        clearPriorityQueue(&trees);
        cout << endl;
    }

    return 0;
}

