#include <iostream>

using namespace std;

int main() {
    while (true) {
        int lights_off = 0;
        int height = 0, lines = 0, num = 0, width = 0;

        cin >> height >> width >> lines;
        if (height == 0 and width == 0 and lines == 0) break;

        for (int i = 0; i < lines; i++) {
            cin >> num;
            num = num % width;
            if (num == 0) lights_off += 1;
            else lights_off += width - (num - 1);
        }
        cout << "Lights: " << lights_off << endl;
    }
    return 0;
}

