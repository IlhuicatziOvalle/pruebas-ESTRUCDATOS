#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListaDoble/ListaDoble.h"  // Asegúrate de que este archivo incluya las declaraciones necesarias

int main() {
    // Lista de números generados aleatoriamente
    int numeros[] = {42, 61, -71, 71, -80, 16, -54, 97, 40, 81, -53, 14, 79, -49, 56, 45, 87, -65, -80, 82};
    int tam = sizeof(numeros) / sizeof(numeros[0]);

    // Inicializamos el árbol binario
    ArbolBinario arbol;
    arbol.raiz = NULL;
    arbol.tam = 0;

    // Insertamos cada número en el árbol binario
    for (int i = 0; i < tam; i++) {
        AgregarArbol(&arbol, &numeros[i], compararEnteros);
    }

    // Imprimimos el árbol en InOrden
    printf("Recorrido BFS del árbol binario:\n");
    printBFS(&arbol);

    return 0;
}