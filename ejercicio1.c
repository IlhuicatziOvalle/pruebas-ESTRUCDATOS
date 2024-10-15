#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListaDoble/ListaDoble.h"  // Asegúrate de que este archivo incluya las declaraciones necesarias
#include <unistd.h>




int main() {
    // Inicialización del árbol
    ArbolBinario arbol;
    inicializarArbol(&arbol);

    // Array de números a insertar
    int numeros[] = {42, 61, -71, 71, -80, 16, -54, 97, 40, 81, -53, 14, 79, -49, 56, 45, 87, -65, -80, 82};
    int numElems = sizeof(numeros) / sizeof(numeros[0]);

    // Insertar elementos en el árbol
    for (int i = 0; i < numElems; i++) {
        int *dato = malloc(sizeof(int));
        *dato = numeros[i];
        AgregarArbol(&arbol, dato, comparar);
    }

    // Imprimir en orden descendente
    printf("Elementos en orden descendente:\n");
    InOrdenDescendente(arbol.raiz);
    printf("\n");

    LiberarArbol(arbol.raiz);
 


    return 0;
}