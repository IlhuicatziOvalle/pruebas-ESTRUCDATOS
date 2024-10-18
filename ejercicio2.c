#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListaDoble/ListaDoble.h"  // Asegúrate de que este archivo incluya las declaraciones necesarias


int main() {
     ArbolBinario arbol;
    arbol.raiz = NULL;
    arbol.tam = 0;

    char *palabras[] = {"Amor", "Azul", "Casa", "Broma", "Cielo", "Dedal", "Esfera", "Florido", "Generoso", "Aguacates"};
    int n = sizeof(palabras) / sizeof(palabras[0]);

    for (int i = 0; i < n; i++) {
        AgregarArbol(&arbol, palabras[i], compararPalabras);
    }

    printf("Árbol binario impreso por nivel:\n");
    printBFS(&arbol,imprimirPalabras);

    // Eliminar un nodo (por ejemplo, "Azul")
    eliminarNodo(&(arbol.raiz), "Azul", compararPalabras);

    printf("\nÁrbol después de eliminar 'Azul':\n");
    printBFS(&arbol,imprimirPalabras);

    return 0;
}

