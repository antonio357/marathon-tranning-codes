#include <iostream>
#include <queue>

using namespace std;

class Camiseta {
    public:
        string name;
        string label_color;
        char size;

    Camiseta(string name, string label_color, char size) {
        this->name = name;
        this->label_color = label_color;
        this->size = size;
    }
};

bool operator<(const Camiseta& c1, const Camiseta& c2) {
    if (c1.label_color > c2.label_color) return true;
    else if (c1.label_color < c2.label_color) return false;
    else if (c1.label_color == c2.label_color) {
        if (c1.size < c2.size) return true;
        else if (c1.size > c2.size) return false;
        else if (c1.size == c2.size) {
            if (c1.name > c2.name) return true;
            else return false;
        }
    }
    return true;
}

int main() {
    int nCases;
    bool first_case = true;
    string name;
    string label_color;
    char size;
    priority_queue<Camiseta> camisetas;

    while (true) {
        cin >> nCases;
        cin.ignore();
        if (nCases == 0) break;

        for (int i = 0; i < nCases; i++) {
            getline(cin, name);
            cin >> label_color >> size;
            cin.ignore();
//            cout << name << endl;
//            cout << label_color << size << endl;

            camisetas.push(Camiseta(name, label_color, size));
        }

        if (not first_case) cout << endl;
        else first_case = false;
        while (not camisetas.empty()) {
            Camiseta c = camisetas.top();
            camisetas.pop();

            cout << c.label_color << " " << c.size << " " << c.name << endl;
        }
    }
    return 0;
}

