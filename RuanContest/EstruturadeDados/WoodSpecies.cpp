#include <iostream>
#include <list>

using namespace std;
#define a 97
#define A 65

struct woodSpecie {
    string name, normalizedName;
    int quant = 1;
};

void addWoodSpecies(list<woodSpecie>* trees, woodSpecie tree) {
    for (auto it = trees->begin(); it != trees->end(); ++it) {
        if (it->name == tree.name) {
            it->quant++;
            return;
        }
    }
    trees->push_back(tree);
}

string normalizedString(const string* string1) {
    string str;
    char c;

    for (int i = 0; i < string1->length(); ++i) {
        c = (*string1)[i];

        if (c != ' ') {
            if (c < a) {
                str.push_back(c + (a - A));
            }
            else str.push_back(c);
        }
    }

    return str;
}

//bool operator<(const woodSpecie& c1, const woodSpecie& c2) {
//    return true;
//}

void printArray(woodSpecie* tr, int len, int total) {
    for (int i = 0; i < len; ++i) {
        cout << tr->name << ' ' << (total / tr->quant) << endl;
    }
}

void printList(list<woodSpecie>* trees) {
    for (auto it = trees->begin(); it != trees->end(); ++it) {
        cout << it->name << ' ' << it->normalizedName << ' ' << it->quant << ", ";
    } cout << endl;
}

int compare(const void *tree1, const void *tree2) {
    auto tr1 = (woodSpecie*)tree1;
    auto tr2 = (woodSpecie*)tree2;
    return (tr1->quant - tr2->quant);
}

int main() {
    int nCases;
    string input;
    list<woodSpecie> trees;

    cin >> nCases;
    cin.ignore(); cin.ignore(); // this is to ignore the blank line input

    for (int i = 0; i < nCases; ++i) {
        trees.clear();

        while (true) {
            getline(cin, input);
            if (input.length() == 0) break;

            woodSpecie tree = {input, normalizedString(&input), 1};
            addWoodSpecies(&trees, tree);
        }
        printList(&trees);
        woodSpecie tr[trees.size()];
        int c = 0;
        for (auto it = trees.begin(); it != trees.end(); ++it) {
            tr[c] = (*it);
            c++;
        }
//        qsort(tr, trees.size(), sizeof(woodSpecie), compare);
        printArray(tr, trees.size(), 30);
        cout << endl;
    }

    return 0;
}

