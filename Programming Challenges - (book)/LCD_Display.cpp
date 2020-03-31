#include<iostream>
#include<typeinfo>

#define d_row 3
#define d_column 5
#define coord 2

using namespace std;

class digit{

    private:
        const int initialCoordinates[7][coord] = {{0,1}, {1,0}, {1,2}, {2,1}, {3,0}, {3,2}, {4,1}};

    protected:
        int len, row_len, column_len;
        char** display_matrix;
        //int coordinate[2];
        int dpc[2];

    public:
        /*digit(int len, char** display_matrix, int display_pointer_coordinate[2], int row_len, int column_len) {
            this->len = len;
            this->display_matrix = display_matrix;
            setDPC(display_pointer_coordinate[0], display_pointer_coordinate[1]);
            setRowLen(row_len);
            setColumnLen(column_len);
        };*/

        /*void reset_coordinate() {
            this->coordinate[0] = this->dpc[0];
            this->coordinate[1] = this->dpc[1];
        };*/

        void coordinate_x(int r, int c) {
            for (int col = c; col < this->len + c; col++)
                this->display_matrix[r][col] = '-';
        };

        void coordinate_y(int r, int c) {
            for (int row = r; row < this->len + r; row++)
                this->display_matrix[row][c] = '|';
        };

        void setLen(int len) {
            this->len = len;
        };

        void setDisplayMatrix(char** display_matrix) {
            this->display_matrix = display_matrix;
        };

        void setDPC(int r, int c) {
            this->dpc[0] = r;
            this->dpc[1] = c;
        };

        void setRowLen(int row_len) {
            this->row_len = row_len;
        };

        void setColumnLen(int column_len) {
            this->column_len = column_len;
        };

        int setInitialCoordinateR(int coordNum) {
            if (coordNum >= 3 and coordNum <= 5) return dpc[0] + initialCoordinates[coordNum][0] + len - 1;
            if (coordNum == 6) return dpc[0] + initialCoordinates[coordNum][0] + ((len - 1) * 2);
            return dpc[0] + initialCoordinates[coordNum][0];
        };

        int setInitialCoordinateC(int coordNum) {
            if (coordNum == 2 or coordNum == 5) return dpc[1] + initialCoordinates[coordNum][1] + len - 1;
            return dpc[1] + initialCoordinates[coordNum][1];
        };

        void call(int coordNum) {
            if (coordNum == 0 or coordNum == 3 or coordNum == 6) coordinate_x(setInitialCoordinateR(coordNum), setInitialCoordinateC(coordNum));
            else coordinate_y(setInitialCoordinateR(coordNum), setInitialCoordinateC(coordNum));
        };

        virtual void build() {};

        /*void setCoordinate(int row, int col) {
            this->coordinate[0] = row;
            this->coordinate[1] = col;
        };*/
};

class Zero : public digit {

    private:
        const int initialCoordinatesClass[6] = {0, 1, 2, 4, 5, 6};

    public:
        /*Zero(int len, char** display_matrix, int display_pointer_coordinate[2], int row_len, int column_len) 
        : digit(len, display_matrix, display_pointer_coordinate, row_len, column_len) {};*/
        
        void build() {
           for (int i = 0; i < 6; i++) {
               call(this->initialCoordinatesClass[i]);
               //cout << "zero class" << endl;
           }
        };
};

class One : public digit {

    private:
        const int initialCoordinatesClass[2] = {2, 5};

    public:
        /*Zero(int len, char** display_matrix, int display_pointer_coordinate[2], int row_len, int column_len) 
        : digit(len, display_matrix, display_pointer_coordinate, row_len, column_len) {};*/
        
        void build() {
           for (int i = 0; i < 2; i++) call(this->initialCoordinatesClass[i]);
           //cout << "built One" << endl;
        };
};

class Two : public digit {

    private:
        const int initialCoordinatesClass[5] = {0, 2, 3, 4, 6};

    public:
        /*Zero(int len, char** display_matrix, int display_pointer_coordinate[2], int row_len, int column_len) 
        : digit(len, display_matrix, display_pointer_coordinate, row_len, column_len) {};*/
        
        void build() {
           for (int i = 0; i < 5; i++) call(this->initialCoordinatesClass[i]);
           //cout << "built Two" << endl;
        };
};

class Three : public digit {

    private:
        const int initialCoordinatesClass[5] = {0,2,3,5,6};

    public:
        /*Zero(int len, char** display_matrix, int display_pointer_coordinate[2], int row_len, int column_len) 
        : digit(len, display_matrix, display_pointer_coordinate, row_len, column_len) {};*/
        
        void build() {
           for (int i = 0; i < 5; i++) call(this->initialCoordinatesClass[i]);
        };
};

class Four : public digit {

    private:
        const int initialCoordinatesClass[4] = {1,2,3,5};

    public:
        /*Zero(int len, char** display_matrix, int display_pointer_coordinate[2], int row_len, int column_len) 
        : digit(len, display_matrix, display_pointer_coordinate, row_len, column_len) {};*/
        
        void build() {
           for (int i = 0; i < 4; i++) call(this->initialCoordinatesClass[i]);
        };
};

class Five : public digit {

    private:
        const int initialCoordinatesClass[5] = {0,1,3,5,6};

    public:
        /*Zero(int len, char** display_matrix, int display_pointer_coordinate[2], int row_len, int column_len) 
        : digit(len, display_matrix, display_pointer_coordinate, row_len, column_len) {};*/
        
        void build() {
           for (int i = 0; i < 5; i++) call(this->initialCoordinatesClass[i]);
        };
};

class Six : public digit {

    private:
        const int initialCoordinatesClass[6] = {0,1,3,5,6,4};

    public:
        /*Zero(int len, char** display_matrix, int display_pointer_coordinate[2], int row_len, int column_len) 
        : digit(len, display_matrix, display_pointer_coordinate, row_len, column_len) {};*/
        
        void build() {
           for (int i = 0; i < 6; i++) call(this->initialCoordinatesClass[i]);
        };
};

class Seven : public digit {

    private:
        const int initialCoordinatesClass[3] = {0,2,5};

    public:
        /*Zero(int len, char** display_matrix, int display_pointer_coordinate[2], int row_len, int column_len) 
        : digit(len, display_matrix, display_pointer_coordinate, row_len, column_len) {};*/
        
        void build() {
           for (int i = 0; i < 3; i++) call(this->initialCoordinatesClass[i]);
        };
};

class Eight : public digit {

    private:
        const int initialCoordinatesClass[7] = {0,1,2,3,4,5,6};

    public:
        /*Zero(int len, char** display_matrix, int display_pointer_coordinate[2], int row_len, int column_len) 
        : digit(len, display_matrix, display_pointer_coordinate, row_len, column_len) {};*/
        
        void build() {
           for (int i = 0; i < 7; i++) call(this->initialCoordinatesClass[i]);
        };
};

class Nine : public digit {

    private:
        const int initialCoordinatesClass[6] = {0,1,2,3,5,6};

    public:
        /*Zero(int len, char** display_matrix, int display_pointer_coordinate[2], int row_len, int column_len) 
        : digit(len, display_matrix, display_pointer_coordinate, row_len, column_len) {};*/
        
        void build() {
           for (int i = 0; i < 6; i++) call(this->initialCoordinatesClass[i]);
        };
};

Zero zero; One one; Two two; Three three; Four four; Five five; Six six; Seven seven; Eight eight; Nine nine;
digit &zero_digit = zero; digit &one_digit = one; digit &two_digit = two; digit &three_digit = three; 
digit &four_digit = four; digit &five_digit = five; digit &six_digit = six; digit &seven_digit = seven; 
digit &eight_digit = eight; digit &nine_digit = nine;
digit* array[10] = {&zero_digit, &one_digit, &two_digit, &three_digit, &four_digit, &five_digit, &six_digit, 
                    &seven_digit, &eight_digit, &nine_digit};


int main() {
    string num;
    int size, d_row_len, row_len, column_len, d, initial_index;

    while (true) {
        cin >> size >> num; 
        if (num == "0" and size == 0) break;
        initial_index = 0;

        column_len = 2 * size + 3; d_row_len = size + 2;
        row_len = d_row_len * num.length() + num.length() - 1;
        char** display_matrix = new char*[column_len];
        for (int i = 0; i < column_len; i++) display_matrix[i] = new char[row_len];
        
        // setting objects
        for (int i = 0; i < 10; i++) {
            array[i]->setLen(size);
            array[i]->setDisplayMatrix(display_matrix);
        }

        int counter = 0;
        for (int digit = 0; digit < num.length(); digit++) {
            d = (int)(num[digit] - 48);

            array[d]->setDPC(0, counter); 
            array[d]->build();
            counter += d_row_len + 1;
        }

        for (int i = 0; i < column_len; i++) {
            for (int j = 0; j < row_len; j++) {   
                if (display_matrix[i][j] == '|' or display_matrix[i][j] == '-') cout << display_matrix[i][j];
                else cout << ' ';         
            } cout << endl;
        } cout << endl; 
    } 

    return 0;
}