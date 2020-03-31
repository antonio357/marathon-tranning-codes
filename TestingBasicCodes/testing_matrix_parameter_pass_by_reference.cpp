#include<iostream>

using namespace std;

void func_indian(int * arr, int rows, int columns) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            *(arr+(3)) = 0;
            cout << *(arr+(0)); 
        }
        cout << endl;
    }
    
}

void func_american(int** arr, int rows, int columns) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            arr[i][j] = 2;
            cout << arr[i][j];
        }
        cout << endl; 
    }
    
}

int main() {
    //int matrix_indian[2][2] = {{1, 2}, {3, 4}};
    //func_indian((int*)matrix_indian, 2, 2);

    int** matrix_american = new int*[2];
    for (int i = 0; i < 2; i++)
    {
        matrix_american[i] = new int[2];
    }
    int counter = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matrix_american[i][j] = ++counter;
        }
        
    }
    
    func_american(matrix_american, 2, 2);
    return 0;
}