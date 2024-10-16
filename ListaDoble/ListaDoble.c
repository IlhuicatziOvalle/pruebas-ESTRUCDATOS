#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "ListaDoble.h"
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



void push(Pilas *pila, void *dato) {
    PushBack(pila, dato);  // Usamos la función PushBack de la lista doblemente enlazada
}
void* pop(Pilas *pila) {
    if (estaVacia(pila)) {
        return NULL;  // Si la pila está vacía
    }
    void *dato = Peek(pila);  // Copia el dato del nodo en el tope de la pila
    BorrarPos(pila, pila->size - 1);  // Elimina el nodo en la posición final
    return dato;  // Regresa el dato copiado
}
int estaVacia(Pilas *pila) {
    return pila->size == 0;
}
void imprimirPila(Pilas *pila, void (*func)(void *)) {
    Pilas aux;
    InicializarListaDoble(&aux);  // Inicializar la pila auxiliar
    
    void *temp = NULL;

    // Extraer e imprimir los elementos de la pila original
    while (!estaVacia(pila)) {
        temp = pop(pila);
        func(temp);  // Llamar a la función para imprimir el dato
        push(&aux, temp);  // Guardar el dato en la pila auxiliar
    }
    
    printf("\n");

    // Restaurar los elementos en la pila original desde la pila auxiliar
    while (!estaVacia(&aux)) {
        temp = pop(&aux);
        push(pila, temp);
    }

    LiberarLista(&aux);  // Liberar la pila auxiliar
}

void* Peek(Pilas *pila) {
    if (pila->Tail != NULL) {
        return pila->Tail->dato;
    }
    return NULL; // Si la pila está vacía
}


void pushCola(Colas *cola, void* dato){
    PushBack(cola, dato); 
}
void* popCola(Colas *cola){
    if (EstaVaciaCola(cola)) {
        printf("Error: La cola está vacía.\n");
        return NULL; // Si la cola está vacía, retornamos NULL
    }
    NodoDoble *nodo = cola->Head;
    void *copia = nodo->dato; // Guardamos el dato del nodo frontal
    cola->Head = nodo->next;  // Movemos la cabeza al siguiente nodo
    if (cola->Head == NULL) { // Si ahora la cabeza es NULL, la cola está vacía
        cola->Tail = NULL;
    } else {
        cola->Head->prev = NULL;
    }
    free(nodo);  // Liberamos el nodo eliminado
    cola->size--; // Decrementamos el tamaño de la cola
    return copia; // Retornamos el dato eliminado
    
}void* PeekCola(Colas *cola){
    if (cola->Head == NULL) {
        printf("Error: La cola está vacía.\n");
        return NULL;
    }
    // Retornamos el dato en la cabeza (sin eliminarlo).
    return cola->Head->dato;
}

int EstaVaciaCola(Colas *cola){
    return cola->Head==NULL;
}
void imprimirCola(Colas *cola, void (*func)(void *)){
    Colas aux;
    void *dato = NULL;
    InicializarListaDoble(&aux);

    while (cola->size != 0) {
        dato=popCola(cola);
        func(dato);  // Se imprime el dato
        pushCola(&aux, dato);  // Se pasa a la cola auxiliar
    }

    // Restaurar la cola original
    while (aux.size != 0) {
        dato=popCola(&aux);
        pushCola(cola, dato);
    }

    LiberarLista(&aux);  // Liberar la cola auxiliar
}

void inicializarArbol(ArbolBinario *arbol) {
    arbol->raiz = NULL;
    arbol->altura = 0;
    arbol->tam = 0;
}
int comparar(void* a, void* b) {
    int valorA = *(int*)a;
    int valorB = *(int*)b;
    return valorA - valorB;  // Valor negativo si a < b, positivo si a > b, y 0 si son iguales
}
int compararPalabras(void* a, void* b) {
    char *palabraA = (char *)a;
    char *palabraB = (char *)b;

    // Si la palabraA empieza entre 'A' y 'C' o tiene menos de 6 letras, debe ir al lado izquierdo
    if ((palabraA[0] >= 'A' && palabraA[0] <= 'C') || strlen(palabraA) < 6) {
        if ((palabraB[0] >= 'A' && palabraB[0] <= 'C') || strlen(palabraB) < 6) {
            return strcmp(palabraA, palabraB);
        }
        return -1;
    }
    // En otro caso, ir al lado derecho
    return 1;
}

void AgregarNodo(NodoBinario **raiz, NodoBinario *nuevo,int (*com)(void*, void*)){
    //si raiz==NULLO
    if(*raiz==NULL){
        //*raiz=nuevo
        *raiz=nuevo;
        return;
    }
    //si el valor de raiz dato es menor que nuevo dato
    if(com((*raiz)->dato, nuevo->dato) > 0){
        AgregarNodo(&(*raiz)->izq,nuevo,comparar);
    //de lo contrario
    }else{
        AgregarNodo(&(*raiz)->der,nuevo,com);
    }
}

void AgregarArbol(ArbolBinario *arbol,void* dato,int (*com)(void*, void*)){
    //crear el nodo nuevo
    NodoBinario *nuevo = (NodoBinario *)malloc(sizeof(NodoBinario));
    //asignar el dato de nodo nuevo a el dato a ingresar
    nuevo->dato = dato;  
    //poner el nodo izquierdo del nodo nuevo en nulo
    nuevo->izq = NULL; 
    //poner el nodo derecho del nodo nuevo en nulo
    nuevo->der = NULL;
    AgregarNodo(&(arbol->raiz),nuevo,com);
    //incrementar tamaño del arbol en 1
    arbol->tam++;
}

void PreOrden(const ArbolBinario *const arbol){
    //si raiz de arbol nulo
    if(arbol->raiz==NULL)
        return;
    //crear una pila
    Pilas pila;
    //inicializar pila
    InicializarListaDoble(&pila);
    //Push raiz a la pila
    push(&pila, arbol->raiz);
    //Mientras pila no vacia
    while(!estaVacia(&pila)){
        //pop de la pila guardar en un nodo temp
        NodoBinario *temp=(NodoBinario *)pop(&pila);
        //print dato del nodo temp
        printfdatodeseado(temp->dato);
        //si temp->derecho existe
        if(temp->der!=NULL){
            //Push temp->derecho a pila
            push(&pila,temp->der);
        }
        //si temp->izquierdo existe
        if(temp->izq!=NULL){
            //Push temp->izquierdo a pila
            push(&pila,temp->izq);
        }
    }
    //liberar pila
    LiberarLista(&pila);
}
void InOrden(const ArbolBinario *const arbol){
    //si raiz del arbol es nulo
    if(arbol->raiz==NULL)
        return;
    //crear pila
    Pilas pila;
    //inciializar la pila
    InicializarListaDoble(&pila);
    //nodo temp=arbol->raiz
    NodoBinario *temp=arbol->raiz;
    //mientras temp diferente de nulo 0 la pila no esta vacia
    while(temp!=NULL || !estaVacia(&pila)){
        //mientras temp diferente a nulo
        while(temp!=NULL){
            //Push a la pila temp
            push(&pila,temp);
            //temp=temp->izq
            temp=temp->izq;
        }
        //temp es igual al pop de la pila
        temp=(NodoBinario *)pop(&pila);
        //imprimir el dato de temp
        printfdatodeseado(temp->dato);
        //temp=temp->der
        temp=temp->der;
    }
    //liberar pil
    LiberarLista(&pila);

}
void PostOrden(const ArbolBinario *const arbol){
    //si arbol->raiz es nulo
    if(arbol->raiz==NULL)
        return;
    //crear pila1
    Pilas pila1;
    //crear pila2
    Pilas pila2;
    //inicializar pila1 y pila2
    InicializarListaDoble(&pila1);
    InicializarListaDoble(&pila2);
    //Push arbol->raiz a pila1
    push(&pila1,arbol->raiz);
    //mientras pila1 no este vacia
    while(!estaVacia(&pila1)){
        //temp igual a Pop de pila1
        NodoBinario *temp=(NodoBinario *)pop(&pila1);
        //Push temp a pila2
        push(&pila2,temp);
        //si temp->izq existe
        if(temp->izq!=NULL){
            //Push temp->izq a pila1
            push(&pila1,temp->izq);
        }
        //si temp->der existe
        if(temp->der!=NULL){
            //Push temp->der a pila1
            push(&pila1,temp->der);
        }
    }
    //mientras pila2 no este vacia
    while(!estaVacia(&pila2)){
        //temp igual a Pop de pila2
        NodoBinario *temp=(NodoBinario *)pop(&pila2);
        //imprimir dato de temp
        printfdatodeseado(temp->dato);
    }
    //liberar pila1 y pila2
    LiberarLista(&pila1);
    LiberarLista(&pila2);
}
void printBFS(const ArbolBinario *const arbol){
    //si arbol->raiz igual a nulo
    if(arbol->raiz==NULL)
        return;

    //crear su cola
    Colas cola;
    //inicializar la cola
    InicializarListaDoble(&cola);
    //Push arbol->raiz a cola
    pushCola(&cola,arbol->raiz);

    //mientras cola no este vacia
    while(!EstaVaciaCola(&cola)){
        //temp igual a Pop de cola
        NodoBinario *temp=(NodoBinario *)popCola(&cola);
        //imprimir dato de temp
        imprimirPalabras(temp->dato);
        //si temp->izq existe
        if(temp->izq!=NULL){
            //Push temp->izq a cola
            pushCola(&cola,temp->izq);
        }
        //si temp->der existe
        if(temp->der!=NULL){
            //Push temp->der a cola
            pushCola(&cola,temp->der);
        }
    }
    //liberar cola
    LiberarLista(&cola);
}
void LiberarArbol(NodoBinario *nodo) {
    if (nodo == NULL) return;
    LiberarArbol(nodo->izq);   // Liberar subárbol izquierdo
    LiberarArbol(nodo->der);   // Liberar subárbol derecho
    free(nodo->dato);          // Liberar dato
    free(nodo);                // Liberar nodo
}
