#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListaDoble/ListaDoble.h"  // Asegúrate de que este archivo incluya las declaraciones necesarias

int main() {
    PQueue IMSS;
    initPQueue(&IMSS,7);

    Paciente p1 = {"Juanito", &(Lesion){70, "Pierna rota"}};
    Paciente p2 = {"Pepito", &(Lesion){80, "balazo"}};
    Paciente p3 = {"Rogelio", &(Lesion){50, "clavo en el pie"}};
    Paciente p4 = {"Eva", &(Lesion){40, "COVID"}};
    Paciente p5 = {"Rosario", &(Lesion){90, "Convulsion"}};
    Paciente p6 = {"Jesus", &(Lesion){60, "Contucion"}};
    Paciente p7 = {"Ana", &(Lesion){100, "Sobre dosis"}};

    insercionHeap(&IMSS, &p1, -1, compararSeveridad);
    insercionHeap(&IMSS, &p2, -1, compararSeveridad);
    insercionHeap(&IMSS, &p3, -1, compararSeveridad);
    insercionHeap(&IMSS, &p4, -1, compararSeveridad);
    insercionHeap(&IMSS, &p5, -1, compararSeveridad);
    insercionHeap(&IMSS, &p6, -1, compararSeveridad);
    insercionHeap(&IMSS, &p7, -1, compararSeveridad);

    // Imprimir los pacientes en el MaxHeap sin funciones adicionales
    printf("Pacientes en orden de prioridad en el heap:\n");
    for (int i = 0; i < IMSS.heap_size; i++) {
        Paciente *paciente = (Paciente *)IMSS.heap[i].valor;
        printf("Nombre: %s\n" ,paciente->nombre);
    }

    pq_pop(&IMSS,-1,compararSeveridad);
    // Imprimir los pacientes en el MaxHeap sin funciones adicionales
    printf("\nSe hace pop al atendido:\n");
    for (int i = 0; i < IMSS.heap_size; i++) {
        Paciente *paciente = (Paciente *)IMSS.heap[i].valor;
        printf("Nombre: %s\n" ,paciente->nombre);
    }
    pq_pop(&IMSS,-1,compararSeveridad);
    
    // Imprimir los pacientes en el MaxHeap sin funciones adicionales
    printf("\nSe hace pop al atendido:\n");
    for (int i = 0; i < IMSS.heap_size; i++) {
        Paciente *paciente = (Paciente *)IMSS.heap[i].valor;
        printf("Nombre: %s\n" ,paciente->nombre);
    }

    remover(&IMSS,)
    return 0;
}

/*int main() {
    // Expresión infija
    char expresion[] = "(P * Q) + C ^ (-D)";

    // Convertir la expresión a postinfix (forma postfija)
    char *postinfix = PostInfixPtr(expresion);

    // Imprimir la expresión postfija
    printf("Expresion en notacion postfija:\n %s", postinfix);

    // Crear el árbol de expresión
    NodoExpr *arbolExpresion = NULL;
    AgregarNodoExpr(&arbolExpresion, postinfix);

    // Inicializar estructura ArbolBinario y asignar la raíz
    ArbolBinario arbol;
    arbol.raiz = arbolExpresion;
    arbol.altura = 0; // Puedes calcular la altura si lo necesitas
    arbol.tam = 0; // Puedes calcular el tamaño si lo necesitas

    // Imprimir el árbol de expresión por niveles
    printf("\nArbol de expresion (impresion por niveles):\n");
    printBFS(&arbol, printfdatodeseado);  // Debes definir o adaptar la función 'printfdatodeseado'

    // Liberar memoria
    free(postinfix);

    return 0;
}*/
/*int main() {
    // Expresión infija
    char expresion[] = "A ^B ^C";

    // Convertir la expresión a postinfix (forma postfija)
    char *postinfix = PostInfixPtr(expresion);

    // Imprimir la expresión postfija
    printf("Expresion en notacion postfija:\n %s", postinfix);

    // Crear el árbol de expresión
    NodoExpr *arbolExpresion = NULL;
    AgregarNodoExpr(&arbolExpresion, postinfix);

    // Inicializar estructura ArbolBinario y asignar la raíz
    ArbolBinario arbol;
    arbol.raiz = arbolExpresion;
    arbol.altura = 0; // Puedes calcular la altura si lo necesitas
    arbol.tam = 0; // Puedes calcular el tamaño si lo necesitas



    // Imprimir el árbol de expresión por niveles
    printf("\nArbol de expresion (impresion por niveles):\n");
    printBFS(&arbol, printfdatodeseado);  // Debes definir o adaptar la función 'printfdatodeseado'

    // Liberar memoria
    free(postinfix);

    return 0;
}
*/
/*int main() {
    // Expresión infija
    char expresion[] = "A + B * C / F^H";

    // Convertir la expresión a postinfix (forma postfija)
    char *postinfix = PostInfixPtr(expresion);

    // Imprimir la expresión postfija
    printf("Expresion en notacion postfija:\n %s", postinfix);

    // Crear el árbol de expresión
    NodoExpr *arbolExpresion = NULL;
    AgregarNodoExpr(&arbolExpresion, postinfix);

    // Inicializar estructura ArbolBinario y asignar la raíz
    ArbolBinario arbol;
    arbol.raiz = arbolExpresion;
    arbol.altura = 0; // Puedes calcular la altura si lo necesitas
    arbol.tam = 0; // Puedes calcular el tamaño si lo necesitas

    // Imprimir el árbol de expresión por niveles
    printf("\nArbol de expresion (impresion por niveles):\n");
    printBFS(&arbol, printfdatodeseado);  // Debes definir o adaptar la función 'printfdatodeseado'

    // Liberar memoria
    free(postinfix);

    return 0;
}
*/