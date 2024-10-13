#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListaDoble/ListaDoble.h"  // Asegúrate de que este archivo incluya las declaraciones necesarias
#include <unistd.h>




int main() {
   ArbolBinario arbol;
    arbol.raiz = NULL;
    
    // Array de números a insertar
    int valores[] = {42, 61, -71, 71, -80, 16, -54, 97, 40, 81, -53, 14, 79, -49, 56, 45, 87, -65, -80, 82};
    int numValores = sizeof(valores) / sizeof(valores[0]);

    // Inserta cada valor en el árbol
    for (int i = 0; i < numValores; i++) {
        AgregarArbol(&arbol, &valores[i], comparar);
    }

    // Imprime el árbol en inorden
    printf("Impresión en inorden:\n");
    InOrden(&arbol);

    
    return 0;
}