#include <iostream>
#include <list>

using namespace std;

typedef struct {
    string name;
    int rows, columns;
    list<string> pixelMatrix;
} image;

void f(image* img) {
    list<string> :: iterator row;
    for (row = img->pixelMatrix.begin(); row != img->pixelMatrix.end(); ++row) {
        cout << *row << endl;
    }
}

int main() {
    image img;
    img.pixelMatrix.push_back("antonio");
    img.pixelMatrix.push_back("carlos");
    //f(&img);

    string command = "S anotnio.carlos";
    command.replace(0, 2, "");
    cout << command << endl;
    return 0;
}