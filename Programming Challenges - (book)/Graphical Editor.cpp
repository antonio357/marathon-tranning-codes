#include <iostream>
#include <list>
#include <map>
// #include <fstream>

using namespace std;

#define ascii 48
// fstream fileOut;
// fstream fileIn;

class Image {
    private:
        string command;
        int rows, columns, x, xEnd, y, yTop, yBottom;
        list<string> pixelMatrix;
        list<string> :: iterator row, rowBottom;
        list<int> integers;
        list<int> :: iterator integerIterator;
        string integer;
        string rowModel;
        char color, originalColor;
        list<string> :: iterator end;

    public:
        void printStatus(string location, bool printRow) {
            cout << "at " << location << endl;
            cout << "command = " << command << endl;
            cout << "rows = " << rows << ", columns = " << columns << endl;
            if (printRow) cout << "row = " << *row << endl;
            cout << "pixelMatrix" << endl;
            print();
            cout << "[ ";
            for (integerIterator = integers.begin(); integerIterator != integers.end(); integerIterator++) {
                cout << *integerIterator << ", ";
            } cout << ']' << endl;
            cout << "integer = " << integer << endl;
        }
        void print() {
            for (row = pixelMatrix.begin(); row != pixelMatrix.end(); row++) {
                cout << *row << endl;
                // fileOut << *row << endl;
                // for (int column = 0; column < columns; column++) {
                //     cout << (*row)[column];
                // }
                // cout << endl;
            }
        }
        void execute(string * command, char * commandFunction) {
            this->command = *command;
            color = this->command[this->command.length() - 1];
            if (*commandFunction == 'I') I();
            else if (*commandFunction == 'C') C();
            else if (*commandFunction == 'L') L();
            else if (*commandFunction == 'V') V();
            else if (*commandFunction == 'H') H();
            else if (*commandFunction == 'K') K();
            else if (*commandFunction == 'F') F();
            else if (*commandFunction == 'S') S();
        }
        void initPixelMatrix() {
            for (int row = 0; row < rows; row++) {
               pixelMatrix.push_back(rowModel);
            }

            end = pixelMatrix.end();
            end--;
        }
        void recursion(int x, list<string> :: iterator y) {
            // fileOut << "at recursion(" << x << ", " << y << ')' << endl;
            (*y)[x] = color;

            if (x > 0) {
                // fileOut << "left" << endl;
                // fileOut << (*row)[x - 1] << " == " << originalColor << endl; 
                if ((*y)[x - 1] == originalColor) {
                    recursion(x - 1, y);
                }
            }
            if (x + 1 < columns) {
                // fileOut << "right" << endl;
                // fileOut << (*row)[x + 1] << " == " << originalColor << endl; 
                if ((*y)[x + 1] == originalColor) {
                    recursion(x + 1, y);
                }
            }
            if (y != pixelMatrix.begin()) {
                y--;
                // fileOut << "down" << endl;
                // fileOut << (*row)[x] << " == " << originalColor << endl; 
                if ((*y)[x] == originalColor) {
                    recursion(x, y);
                }
                y++;
            }
            if (y != end) {
                y++;
                // fileOut << "up" << endl;
                // fileOut << (*row)[x] << " == " << originalColor << endl; 
                if ((*y)[x] == originalColor) {
                    recursion(x, y);
                }
                y--;
            }
        }

        void rowToY(int y) {
            row = pixelMatrix.begin();  
            advance(row, y);
        }
        void rowBottomToY(int y) {
            rowBottom = pixelMatrix.begin();  
            advance(rowBottom, y);
        }

        int getIntegerFromString() {
            int number = 0;
            int decimalPlace = 1;
            for (int ch = integer.length() - 1; ch > -1; ch--) {
                if (not (ch == integer.length() - 1)) {
                    decimalPlace *= 10;
                }
                number += (integer[ch] - ascii) * (decimalPlace);
            }
            return number;
        }
        void getIntegersParams() {
            integers.clear();
            integer = "";
            char c;
            command.append(" "); 
            /* command.append(" ");
            to avoid the case "L 3 2" it does bug if tries to 
            get the last number whitout the extra " " in the end; 
            */
            int ch = 0;
            while (ch < command.length()) {
                c = command[ch];
                if (c>='0' and c<='9') {
                    integer += c;
                }
                else if (not integer.empty()) {
                    integers.push_back(getIntegerFromString());
                    integer.clear();
                }
                ch++;
            }
        }
        void getInteger(int * integer) {
            *integer = *integers.begin();
            integers.pop_front();
        }
        void getIntegerCoordinate(int * integer) {
            *integer = *integers.begin() - 1;
            integers.pop_front();
        }

        void I() {
            pixelMatrix.clear();
            rowModel.clear();
            getIntegersParams();

            // printStatus("I before getInteger", false);
            getInteger(&columns);
            getInteger(&rows);
            for (int column = 0; column < columns; column++) {
                rowModel += 'O';
            }
            
            initPixelMatrix();
            // printStatus("I end", false);
        }
        void C() {
            for (row = pixelMatrix.begin(); row != pixelMatrix.end(); row++) {
                *row = rowModel;
            }
        }
        void L() {
            getIntegersParams();

            getIntegerCoordinate(&x); 
            getIntegerCoordinate(&y);

            rowToY(this->y);
            (*row)[x] = color;
        }
        void V() {
            getIntegersParams();
            
            getIntegerCoordinate(&x);
            getIntegerCoordinate(&yTop);
            getIntegerCoordinate(&yBottom);

            if (yTop > yBottom) swap(yTop, yBottom);

            rowToY(this->yTop);
            rowBottomToY(this->yBottom + 1);
            
            for (; row != rowBottom; row++) {
                (*row)[x] = color;
                // row->replace(x, 1, to_string(color));
            }
        }
        void H() {
            getIntegersParams();

            getIntegerCoordinate(&x);
            getIntegerCoordinate(&xEnd);
            getIntegerCoordinate(&y);

            if (x > xEnd) swap(x, xEnd);

            rowToY(this->y);
            for (int column = x; column <= xEnd; column++) {
                (*row)[column] = color;
            }
        }
        void K() {
            getIntegersParams();

            getIntegerCoordinate(&x);
            getIntegerCoordinate(&y);
            getIntegerCoordinate(&xEnd);
            getIntegerCoordinate(&yBottom);

            if (x > xEnd) swap(x, xEnd);
            if (y > yBottom) swap(y, yBottom);

            rowToY(this->y);
            rowBottomToY(this->yBottom + 1);
            for (; row != rowBottom; row++) {
                for (int column = x; column <= xEnd; column++) {
                    (*row)[column] = color;
                }
            }
        }
        void F() {
            getIntegersParams();

            getIntegerCoordinate(&x); 
            getIntegerCoordinate(&y);

            rowToY(this->y);
            originalColor = (*row)[x];
            // fileOut << "called F()" << endl;
            if (color != originalColor) recursion(this->x, this->row);
        }
        void S() {
            command.replace(0, 2, "");
            cout << command << endl;
            // fileOut << command << endl; 
            print();
        }
};

void charArrayToString(char array[], string * str) {
    for (int ch = 0; array[ch] != '\0'; ch++) {
        (*str) += array[ch];
    }
}

int main() {
    // fileOut.open("log.txt", ios::out); 
    // fileIn.open("testCases.txt");

    Image image;
    // char subCommand[50];
    string command;
    char commandFunction;

    while (true) {
        getline(cin, command);
        // if (not getline(fileIn, command, '\n')) break;
        // cout << command << endl;
        // scanf("%[^\n]", subCommand);
        // charArrayToString(subCommand, &command);
        commandFunction = command[0];
        if (commandFunction == 'X') break;
        image.execute(&command, &commandFunction);
    }
}