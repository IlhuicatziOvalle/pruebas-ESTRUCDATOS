#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListaDoble/ListaDoble.h"  // Asegúrate de que este archivo incluya las declaraciones necesarias

int main() {
    int subDim = 4;  // Puedes ajustar esto a 1000 para el tamaño máximo

    // Inicialización de las matrices con valores específicos
    int** A = (int**)malloc(subDim * sizeof(int*));
    int** B = (int**)malloc(subDim * sizeof(int*));

    // Ejemplo para el caso dado:
    int A_valores[4][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13,14, 15, 16}
    };

    int B_valores[4][4] = {
        {1,  2,  1,  2},
        {0,  0,  0,  0},
        {-1,-2, -1, -2},
        {2,  1,  2,  1}
    };

    // Copia los valores en las matrices A y B
    for (int i = 0; i < subDim; i++) {
        A[i] = (int*)malloc(subDim * sizeof(int));
        B[i] = (int*)malloc(subDim * sizeof(int));
        for (int j = 0; j < subDim; j++) {
            A[i][j] = A_valores[i][j];
            B[i][j] = B_valores[i][j];
        }
    }

    // Realiza el producto-suma para las matrices
    int** C = productoSuma(subDim, A, B);

    // Imprime las matrices y los resultados
    printf("Matriz A:\n");
    imprimirMatriz(A, subDim);

    printf("\nMatriz B:\n");
    imprimirMatriz(B, subDim);

    printf("\nProducto-suma C:\n");
    imprimirMatriz(C, subDim);

    // Libera la memoria de las matrices
    liberarMatriz(A, subDim);
    liberarMatriz(B, subDim);
    liberarMatriz(C, subDim);

    return 0;
}