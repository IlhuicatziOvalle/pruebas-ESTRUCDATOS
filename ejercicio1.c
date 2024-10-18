#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListaDoble/ListaDoble.h"  // Asegúrate de que este archivo incluya las declaraciones necesarias

int main() {
    // Inicialización del árbol
    ArbolBinario arbol;
    arbol.raiz = NULL;
    arbol.tam = 0;
    
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
    InOrdenDescendente(&arbol, ImprimirNumeros);
    printf("\n");

    // Elegir un número a eliminar desde la entrada del usuario
    int eliminar;
    printf("Introduce el número a eliminar: ");
    scanf("%d", &eliminar);

    // Llamar a la función eliminarNodo
    if (eliminarNodo(&arbol.raiz, &eliminar, comparar)) {
        printf("Eliminado exitosamente.\n");
    } else {
        printf("El número %d no se encontró en el árbol.\n", eliminar);
    }

    // Imprimir en orden descendente después de eliminar el nodo
    printf("Elementos en orden descendente tras la eliminación:\n");
    InOrdenDescendente(&arbol, ImprimirNumeros);
    printf("\n");

    
    return 0;
}