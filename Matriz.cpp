#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int sumaRecursivaMatrices(int** mat1, int** mat2, int f, int c);

int sumaRecursivaMatrices(int** mat1, int** mat2, int f, int c) {
    if ((f == 0) && (c == 0))
        return *(*(mat1 + f) + c) + *(*(mat2 + f) + c);
    else {
        if (f > -1) {
            c--;
            if (c >= -1)
                return *(*(mat1 + f) + (c + 1)) + *(*(mat2 + f) + (c + 1)) + sumaRecursivaMatrices(mat1, mat2, f, c);
            else
                return sumaRecursivaMatrices(mat1, mat2, f - 1, 2);
        }
    }
}

int main(int argc, char** argv) {
    // Usando malloc para asignar memoria dinámica
    int** mat1 = (int**)malloc(3 * sizeof(int*));
    int** mat2 = (int**)malloc(3 * sizeof(int*));

    for (int i = 0; i < 3; i++) {
        mat1[i] = (int*)malloc(3 * sizeof(int));
        mat2[i] = (int*)malloc(3 * sizeof(int));
    }

    srand(time(NULL));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat1[i][j] = (int)((rand() / 32768.1) * 1000);
            mat2[i][j] = (int)((rand() / 32768.1) * 1000);
        }
    }

    // Imprimir las matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << *(*(mat1 + i) + j) << "\t";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << *(*(mat2 + i) + j) << "\t";
        }
        cout << endl;
    }

    // Calcular la suma recursiva de matrices
    cout << "Suma de Matrices es: " << sumaRecursivaMatrices(mat1, mat2, 2, 2) << endl;

    // Liberar la memoria dinámica
    for (int i = 0; i < 3; i++) {
        free(mat1[i]);
        free(mat2[i]);
    }
    free(mat1);
    free(mat2);

    return 0;
}

