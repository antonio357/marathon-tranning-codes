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

void printArray(const woodSpecie* tr, int len, int total) {
    double percentage;
    for (int i = 0; i < len; ++i) {
        percentage = (tr[i].quant * 100.0/total);
        cout << tr[i].name << ' ' << percentage << endl;
    } cout << endl;
}

void printList(const list<woodSpecie>* trees) {
    for (auto it = trees->begin(); it != trees->end(); ++it) {
        cout << it->name << ' ' << it->normalizedName << ' ' << it->quant << ", ";
    } cout << endl;
}

int compare(const void *tree1, const void *tree2) {
    auto tr1 = (woodSpecie*)tree1;
    auto tr2 = (woodSpecie*)tree2;
    woodSpecie trr1 = *tr1;
    woodSpecie trr2 = *tr2;
    int ctr1 = 0, ctr2 = 0, dif;

    cout << trr2.normalizedName << ", " << trr1.normalizedName << endl;

    while (true) {
        dif = trr2.normalizedName[ctr2] - trr1.normalizedName[ctr1];
        cout << "dif = " << trr2.normalizedName[ctr2] << " - " << trr1.normalizedName[ctr1] << endl;
        ctr1++; ctr2++;

        if (dif != 0) {
            cout << "ok dif = " << dif << endl;
            if (dif < 0) return 1;
            if (dif > 0) return -1;
        }
        if (ctr1 == trr1.normalizedName.length()) {
            cout << "not dif" << endl;
            return 0;
        }
        if (ctr2 == trr2.normalizedName.length()) {
            cout << "not dif" << endl;
            return 1;
        }
    }
}

woodSpecie* convertListArray(const list<woodSpecie>* trees, woodSpecie* tr) {
    int c = 0;

    for (auto it = trees->begin(); it != trees->end(); ++it) {
        tr[c] = *it;
        c++;
    }

    return tr;
}

int main() {
    int nCases, total;
    string input;
    list<woodSpecie> trees;

    cin >> nCases;
    cin.ignore(); cin.ignore(); // this is to ignore the blank line input

    for (int i = 0; i < nCases; ++i) {
        trees.clear();
        total = 0;

        while (true) {
            getline(cin, input);
            if (input.length() == 0) break;

            woodSpecie tree = {input, normalizedString(&input), 1};
            addWoodSpecies(&trees, tree); total++;
        }

        woodSpecie tr[trees.size()];
        convertListArray(&trees, tr);
        qsort(tr, 3, sizeof(woodSpecie), compare);
        printArray(tr, trees.size(), total);
    }
    return 0;
}

