#include <iostream>
#include <map>

using namespace std;
#define a 97
#define A 65

struct woodSpecie {
    string name, normalizedName;
    double quant = 1;
};

void addWoodSpecie(map<string, woodSpecie>* trees, woodSpecie tree) {
    auto it = trees->find(tree.name);
    if (it == trees->end())
        trees->insert(pair <string, woodSpecie> (tree.name, tree));
    else it->second.quant++;
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

double totalTrees(const map<string, woodSpecie>* trees) {
    double counter = 0;

    for (auto it = trees->begin(); it != trees->end(); ++it)
        counter += it->second.quant;

    return counter;
}

void printWoodSpecies(const map <string, woodSpecie>* trees) {
    double percentage;
    double total = totalTrees(trees);
    cout.precision(4);

    for (auto it = trees->begin(); it != trees->end(); ++it) {
        percentage = (100.0 * it->second.quant) / total;

        cout << it->second.name << ' ';
        cout << fixed << percentage << endl; // printf("%.4lf\n", percentage);
    }
}

int main() {
    int nCases;
    string input;
    map<string, woodSpecie> trees;

    cin >> nCases;
    getline(cin, input); // this is to ignore the blank line input
    cin.ignore();

    for (int i = 0; i < nCases; ++i) {
        trees.clear();

        while (true) {
            getline(cin, input);
            if (input.length() == 0) break;

            woodSpecie tree = {input, normalizedString(&input), 1};
            addWoodSpecie(&trees, tree);
        }

        if (i > 0) cout << endl;
        printWoodSpecies(&trees);
    }
    return 0;
}
