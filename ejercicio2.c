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
    printBFS(&arbol, imprimirPalabras);

    // Solicitar al usuario que ingrese la palabra que desea eliminar
    char palabraEliminar[30];
    printf("\n Ingrese la palabra a eliminar: ");
    scanf("%s", palabraEliminar);

    // Eliminar el nodo con la palabra ingresada
    eliminarNodo(&(arbol.raiz), palabraEliminar, compararPalabras);

    printf("\nÁrbol después de eliminar '%s':\n", palabraEliminar);
    printBFS(&arbol, imprimirPalabras);

    return 0;
}