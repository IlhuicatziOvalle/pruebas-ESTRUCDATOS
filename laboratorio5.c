#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListaDoble/ListaDoble.h"  // Asegúrate de que este archivo incluya las declaraciones necesarias
#include <unistd.h>


void ImprimirNumeros(void *dato)
{
    printf("%d\n", *(int *)dato);
}
void printfdatodeseado(void *dato){
    printf("%c ", *(char *)dato);
}
void imprimirPalabras(void *dato) {
    printf("%s\n", (char *)dato);
}

int main() {
    SimularAtencionClientes();
    return 0;
}