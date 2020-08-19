#include <iostream>
#include <fstream>

using namespace std;
fstream file1;
fstream file2;
fstream fileDiff;

int main() {
    string lineFile1, lineFile2;
    bool hasLine, counted;
    int counter = 0;
    file1.open("answers.txt", ios::in);
    file2.open("log.txt", ios::in);
    fileDiff.open("diff.txt", ios::out);

    fileDiff << "answers.txt" << " | " << "log.txt" << endl;
    while (true) {
        hasLine = false;
        counted = false;
        if (getline(file1, lineFile1, '\n')) {
            hasLine = true;
            // if (not counted) {
            //     counter++;
            //     counted = true;
            // }
        }
        else lineFile1 = "empty";
        if (getline(file2, lineFile2, '\n')) {
            hasLine = true;
            // if (not counted) {
            //     counter++;
            //     counted = true;
            // }
        }
        else lineFile2 = "empty";
        if (not hasLine) break;
        else {
            counter++;
            if (lineFile1.compare(lineFile2)) {
                fileDiff << "on line " << counter << " : ";
                fileDiff << lineFile1 << " | " << lineFile2 << endl;
            }
        }
    }
}