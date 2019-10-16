#include <iostream>

using namespace std;

int main() {
    int m, n, p, sum, in;
    while (true) {
        cin >> m;
        cin >> n;
        cin >> p;
        if (m == 0 and n == 0 and p == 0) break;
        sum = 0;
        for (int i = 0; i < p; i++) {
            cin >> in;
            sum = sum + ((n + 1) - in);
        }
        cout << "Lights: " << sum << endl;
    }
    return 0;
}

