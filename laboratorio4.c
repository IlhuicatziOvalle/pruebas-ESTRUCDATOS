#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListaDoble/ListaDoble.h"  // Asegúrate de que este archivo incluya las declaraciones necesarias

#define SIZE 1000

void inicializarMatrices(int matrizA[SIZE][SIZE], int matrizB[SIZE][SIZE]) {
    srand(time(NULL)); // Inicializa el generador de números aleatorios

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrizA[i][j] = rand() % 100; // Rellena matrizA con valores entre 0 y 99
            matrizB[i][j] = rand() % 100; // Rellena matrizB con valores entre 0 y 99
        }
    }
}

int main() {
    int matrizA[SIZE][SIZE];
    int matrizB[SIZE][SIZE];

    inicializarMatrices(matrizA, matrizB);

    printf("Matrices inicializadas correctamente.\n");

    // Imprimir algunas posiciones para verificar
    printf("Matriz A[0][0]: %d, Matriz B[0][0]: %d\n", matrizA[0][0], matrizB[0][0]);

    // Imprimir parte de las matrices
    printf("Primeras 5 filas y columnas de Matriz A:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matrizA[i][j]);
        }
        printf("\n");
    }

    return 0;
}