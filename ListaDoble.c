#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "ListaDoble.h"


void InicializarListaDoble(ListaDoble *lista) {
    lista->Head = NULL;
    lista->Tail = NULL;
    lista->Curr = NULL;
    lista->size = 0;
}

void PushFront(ListaDoble *lista, void *item) {
    NodoDoble *nuevo = (NodoDoble *)malloc(sizeof(NodoDoble));
    nuevo->dato = item;
    nuevo->next = lista->Head;
    nuevo->prev = NULL;

    if (lista->Head != NULL) {
        lista->Head->prev = nuevo;
    }
    lista->Head = nuevo;

    if (lista->Tail == NULL) {
        lista->Tail = nuevo;
    }
    lista->size++;
}

void PushBack(ListaDoble *lista, void *item) {
    NodoDoble *nuevo = (NodoDoble *)malloc(sizeof(NodoDoble));
    nuevo->dato = item;
    nuevo->next = NULL;
    nuevo->prev = lista->Tail;

    if (lista->Tail != NULL) {
        lista->Tail->next = nuevo;
    }
    lista->Tail = nuevo;

    if (lista->Head == NULL) {
        lista->Head = nuevo;
    }
    lista->size++;
}


NodoDoble *GetNodo(ListaDoble *lista, void *item)
{
    lista->Curr = lista->Head;
    while (lista->Curr->dato != item && lista->Curr != NULL)
    {
        lista->Curr = lista->Curr->next;
    }
    return lista->Curr;
}


NodoDoble *GetNodoPos(ListaDoble *lista, int pos) {
    NodoDoble *temp = lista->Head;
    for (int i = 0; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    return temp;
}

void PushPos(ListaDoble *lista, void *item, int pos) {
    if (pos == 0) { 
        PushFront(lista, item); //si la posicion es 0, se inserta al frente
        return;
    }
    if (pos == lista->size) {
        PushBack(lista, item); //si la posicion es igual al tamaño de la lista, inserta al final
        return;
    }

//En otro caso, inserta en la posición intermedia ajustando los punteros de los nodos circundantes.

    NodoDoble *nuevo = (NodoDoble *)malloc(sizeof(NodoDoble));
    nuevo->dato = item;

    NodoDoble *curr = GetNodoPos(lista, pos);
    if (curr != NULL) {
        nuevo->next = curr;
        nuevo->prev = curr->prev;
        if (curr->prev != NULL) {
            curr->prev->next = nuevo;
        }
        curr->prev = nuevo;
        if (pos == 0) {
            lista->Head = nuevo;
        }
    }
    lista->size++;
}

int BorrarPos(ListaDoble *lista, int pos) {
    if (pos < 0 || pos >= lista->size) return -1;

    NodoDoble *temp = lista->Head;
    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        lista->Head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    } else {
        lista->Tail = temp->prev;
    }

    free(temp->dato);
    free(temp);
    lista->size--;
    return 0;
}

void ImprimirLista(const ListaDoble *const lista, void (*func)(void *)) {
    NodoDoble *temp = lista->Head;
    while (temp != NULL) {
        printf("[%p] (%p) -> ",(void*)temp->prev,(void*)temp);
        func(temp->dato);
        printf(" -> [%p] \n",(void*)temp->next);
        temp = temp->next;
    }
}

void LiberarLista(ListaDoble *lista) {
    NodoDoble *temp;
    while (lista->Head != NULL) {
        temp = lista->Head;
        lista->Head = lista->Head->next;
        free(temp->dato);  // Asegúrate de que data sea liberado si se aloca dinámicamente
        free(temp);
    }
    lista->Tail = NULL;
    lista->size = 0;
}

void BorrarNodo(ListaDoble *lista, void *dato){
    NodoDoble *curr = GetNodo(lista, dato);
    if (curr == NULL) {
        printf("No se encontro el nodo\n");
        return;
    }

    if (curr->prev == NULL) {
        lista->Head= curr->next;
    } else {
        curr->prev->next = curr->next;
    }

    if (curr->next == NULL) {
        lista->Tail = curr->prev;
    } else {
        curr->next->prev = curr->prev;
    }

    free(curr);
    lista->size--;
}

void push(Pilas *pila, void *dato){
    PushBack(pila, dato);
}
void* pop(Pilas *pila){
    void *copia=pila->Tail->dato;
    BorrarNodo(pila,pila->Tail->dato);
    return copia;
}
int estaVacia(Pilas *pila){
    return pila->Head==NULL;
}
void imprimirPila(Pilas *pila, void(* func)(void*)){
    Pilas aux;
    InicializarListaDoble(&aux);
    void *dato=NULL;

    while(pila->size != 0){
        dato=pop(pila);
        func(dato);
        push(&aux,dato);
    }
    printf("\n");

    while(aux.size != 0){
        dato=pop(&aux);
        push(pila,dato);
    }
}



/*MATRIZ 4x4
// Función para imprimir una matriz de tamaño fijo 4x4
void imprimirMatriz(int matriz[4][4], int tamano) {
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para realizar el producto de matrices de tamaño fijo 4x4
void productoMatrices(int A[4][4], int B[4][4], int resultado[4][4], int tamano) {
    // Inicializar la matriz resultado a 0
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            resultado[i][j] = 0;
        }
    }
    
    // Realizar el producto de matrices
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            for (int k = 0; k < tamano; k++) {
                resultado[i][j] += A[i][k] * B[k][j]; // Producto-suma
            }
        }
    }
}*/