#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListaDoble/ListaDoble.h"  // Asegúrate de que este archivo incluya las declaraciones necesarias
#include <unistd.h>




int main() {
    
    
    /*NUMEROS


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
 


    return 0;*/

/*PALABRAS
    ArbolBinario arbol;
    inicializarArbol(&arbol);

    
    char *palabras[] = {"Amor", "Azul", "Casa", "Broma", "Cielo", "Dedal", "Esfera", "Florido", "Generoso", "Aguacates"};
    int n = sizeof(palabras) / sizeof(palabras[0]);

    for (int i = 0; i < n; i++) {
        char *palabra = malloc(strlen(palabras[i]) + 1);
        strcpy(palabra, palabras[i]);
        AgregarArbol(&arbol, palabra, compararPalabras);
    }

    printf("Árbol binario por niveles:\n");
    printBFS(&arbol);

    return 0;*/
}