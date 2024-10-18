#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListaDoble/ListaDoble.h"  // Asegúrate de que este archivo incluya las declaraciones necesarias

/*int main() {
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
    InOrdenDescendente(&arbol,ImprimirNumeros);
    printf("\n");

    // Elegir un número a eliminar
    int eliminar = 71;  // Puedes cambiar este valor para probar con otros números
    printf("Eliminando el número %d...\n", eliminar);

    // Llamar a la función eliminarNodo
    if (eliminarNodo(&arbol.raiz, &eliminar, comparar)) {
        printf("Eliminado exitosamente.\n");
    } else {
        printf("El número %d no se encontró en el árbol.\n", eliminar);
    }

    // Imprimir en orden descendente después de eliminar el nodo
    printf("Elementos en orden descendente tras la eliminación:\n");
    InOrdenDescendente(&arbol,ImprimirNumeros);
    printf("\n");



    return 0;
}*/
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

