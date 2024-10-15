#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListaDoble/ListaDoble.h"  // Asegúrate de que este archivo incluya las declaraciones necesarias
#include <unistd.h>




int main() {
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

    return 0
}