#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListaDoble/ListaDoble.h"  // Asegúrate de que este archivo incluya las declaraciones necesarias

int main() {
    int subDim = 4;  // Dimensión de las submatrices

    // Inicialización de las submatrices con valores aleatorios
    int** A_sub1 = crearSubmatriz(subDim);
    int** B_sub1 = crearSubmatriz(subDim);

    int** A_sub2 = crearSubmatriz(subDim);
    int** B_sub2 = crearSubmatriz(subDim);

    // Realiza el producto-suma para las submatrices
    int** C_sub1 = productoSuma(subDim, A_sub1, B_sub1);
    int** C_sub2 = productoSuma(subDim, A_sub2, B_sub2);

    // Imprime las submatrices y los resultados
    printf("Submatriz A_sub1:\n");
    imprimirMatriz(A_sub1, subDim);
    printf("\nSubmatriz B_sub1:\n");
    imprimirMatriz(B_sub1, subDim);
    printf("\nProducto-suma C_sub1:\n");
    imprimirMatriz(C_sub1, subDim);

    printf("\nSubmatriz A_sub2:\n");
    imprimirMatriz(A_sub2, subDim);
    printf("\nSubmatriz B_sub2:\n");
    imprimirMatriz(B_sub2, subDim);
    printf("\nProducto-suma C_sub2:\n");
    imprimirMatriz(C_sub2, subDim);

    // Libera la memoria de las matrices
    liberarMatriz(A_sub1, subDim);
    liberarMatriz(B_sub1, subDim);
    liberarMatriz(C_sub1, subDim);
    liberarMatriz(A_sub2, subDim);
    liberarMatriz(B_sub2, subDim);
    liberarMatriz(C_sub2, subDim);

    return 0;
}