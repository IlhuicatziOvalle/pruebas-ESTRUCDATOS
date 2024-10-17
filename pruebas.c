#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListaDoble/ListaDoble.h"  // Asegúrate de que este archivo incluya las declaraciones necesarias

int main() {
    ArbolBinario arbol;
    arbol.raiz = NULL;
    arbol.tam = 0;
    
    // Lista de palabras a agregar al árbol
    char *palabras[] = {"Amor", "Azul", "Casa", "Broma", "Cielo", "Dedal", "Esfera", "Florido", "Generoso", "Aguacates"};
    int n = sizeof(palabras) / sizeof(palabras[0]);

    // Agregar cada palabra al árbol binario
    for (int i = 0; i < n; i++) {
        AgregarArbol(&arbol, palabras[i], compararPalabras);
    }

    // Imprimir el árbol en orden BFS
    printf("Árbol binario por niveles:\n");
    printBFS(&arbol,imprimirPalabras);

    
    return 0;
}
