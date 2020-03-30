#include <iostream> 

void print_func(int n, int m, char** matrix) {
    int i, j;
    int matrix_in[n][m-1];

    // print input
    /*for (i = 0; i < n; i++) {
        for (j = 0; matrix[i][j] != '\0'; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }*/

    // zero
    for (i = 0; i < n; i++) {
        for (j = 0; j < m - 1; j++) {
            matrix_in[i][j] = 0;
        }
    }

    // print zeros
    /*for (i = 0; i < n; i++) {
        for (j = 0; j < m - 1; j++) {
            printf("%d", matrix_in[i][j]);
        }
        printf("\n");
    }*/

    for (i = 0; i < n; i++) {
        for (j = 0; j < m - 1; j++) {
            if (matrix[i][j] == '*') matrix_in[i][j] = 9;
            //printf("in camp matrix[%d][%d]\n", i, j);
            if (i - 1 > -1) { // up
                //printf("up\n");
                if (matrix[i - 1][j] == '*') matrix_in[i][j]++;
                if (j + 1 < m - 1) { // right
                    //printf("up and right\n");
                    if (matrix[i - 1][j + 1] == '*') matrix_in[i][j]++;
                }
                if (j - 1 > -1) { // left 
                    //printf("up and left\n");
                    if (matrix[i - 1][j - 1] == '*') matrix_in[i][j]++;
                }
            }
            if (i + 1 < n) { // down
                //printf("down\n");
                if (matrix[i + 1][j] == '*') matrix_in[i][j]++;
                if (j + 1 < m - 1) { // right
                    //printf("down and right\n");
                    if (matrix[i + 1][j + 1] == '*') matrix_in[i][j]++;
                }
                if (j - 1 > -1) { // left 
                    //printf("down and left\n");
                    if (matrix[i + 1][j - 1] == '*') matrix_in[i][j]++;
                }
            }
            if (j - 1 > -1) { // left 
                //printf("left\n");
                if (matrix[i][j - 1] == '*') matrix_in[i][j]++;
            }
            if (j + 1 < m - 1) { // right
                //printf("right\n");
                if (matrix[i][j + 1] == '*') matrix_in[i][j]++;
            }
        }
    }

    // print output
    for (i = 0; i < n; i++) {
        for (j = 0; j < m - 1; j++) {
            if (matrix_in[i][j] >= 9) printf("*");
            else printf("%d", matrix_in[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}

int main() {
    int n, m, i, j, field = 0;
    char** matrix;    
    while(1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;

        // alocandao dinamicamente
        m++; // pra acidionar espaço para o caracter de final de string nas 
        matrix = new char*[n];
        for (i = 0; i < n; i++) {
            matrix[i] = new char[m];
        }

        // input
        for (i = 0; i < n; i++) {
            scanf("%s", matrix[i]);
        }

        field++;
        printf("Field #%d:\n", field);
        print_func(n, m, matrix);
    }   
    return 0;
}
