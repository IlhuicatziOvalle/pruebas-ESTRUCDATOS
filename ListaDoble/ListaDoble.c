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


//crear cliente
Cliente *crearCliente(){
    Cliente *nuevoCliente=(Cliente*)malloc(sizeof(Cliente));
    nuevoCliente->articulos=rand() %20 + 1; //cantidad lista articulos(1-20)
    nuevoCliente->ticks_pagos=rand() % 100 + 1; //cantidad iteraciones(1-100)
    return nuevoCliente;
}
void imprimirCliente(void *data){
    Cliente *cliente = (Cliente*)data;
    printf("Cliente con %d artículos, tardará %d ticks en pagar.\n", cliente->articulos, cliente->ticks_pagos);
}



void Supermercado(){
    ListaDoble Principal;
    ListaDoble Emergencia;
    ListaDoble caja1;
    ListaDoble caja2;
    ListaDoble caja3;

    InicializarListaDoble(&Principal);
    InicializarListaDoble(&Emergencia);
    InicializarListaDoble(&caja1);
    InicializarListaDoble(&caja2);
    InicializarListaDoble(&caja3);


    int ticks=0;
    int clientesAtendidos=0;

    while (ticks < 100000 || Principal.size > 0 || Emergencia.size > 0 || caja1.size > 0 || caja2.size > 0 || caja3.size > 0) {
        // Cada 100 ticks, un cliente nuevo entra
        if(ticks<100000 && ticks %100 == 0){ //max ticks del supermercado 100000
            Cliente *nuevoCliente=crearCliente();
            if(Principal.size<25){ //max clientes fila principal 25
                pushCola(&Principal, nuevoCliente);
                printf("Nuevo cliente entra a fila principal \n");
                
            }else if(Emergencia.size<25){ //max clientes fila emergencia 25
                pushCola(&Emergencia,nuevoCliente);
                printf("Nuevo cliente entra a fila emergencia\n");
                 imprimirCliente(nuevoCliente); 

            }else{
                printf("Supermercado lleno, cliente no puede entrar\n");
                free(nuevoCliente); //Liberar memoria del cliente si no entro
            }
        }
        //revisar cajas
        if(caja1.size < 3 && Principal.size > 0 ){ //max en cola de caja 3 
            Cliente *cliente=(Cliente *)popCola(&Principal);
            pushCola(&caja1, cliente);
            printf("Cliente movido a caja 1\n");
        }
        if(caja2.size<3 && Principal.size > 0 ){
            Cliente *cliente=(Cliente *)popCola(&Principal);
            pushCola(&caja2, cliente);
            printf("Cliente movido a caja 2\n");
        }
        if(caja3.size<3 && Principal.size > 0){
            Cliente *cliente=(Cliente *)popCola(&Principal);
            pushCola(&caja3, cliente);
            printf("Cliente movido a caja 3\n");
        }
        //Procesa a los clientes en cada caja
        if (!EstaVaciaCola(&caja1)) {
            Cliente *cliente = (Cliente*) PeekCola(&caja1);
             imprimirCliente(cliente); 
            cliente->ticks_pagos--;
            if (cliente->ticks_pagos <= 0) {
                popCola(&caja1);
                printf("Cliente atendido en la caja 1.\n");
                clientesAtendidos++;
                free(cliente);  // Liberar memoria después de ser atendido
            }
        }
        if (!EstaVaciaCola(&caja2)) {
            Cliente *cliente = (Cliente*) PeekCola(&caja2);
            imprimirCliente(cliente); 
            cliente->ticks_pagos--;
            if (cliente->ticks_pagos <= 0) {
                popCola(&caja2);
                printf("Cliente atendido en la caja 2.\n");
                clientesAtendidos++;
                free(cliente);  // Liberar memoria después de ser atendido
            }
        }
        if (!EstaVaciaCola(&caja3)) {
            Cliente *cliente = (Cliente*) PeekCola(&caja3);
            imprimirCliente(cliente); 
            cliente->ticks_pagos--;
            if (cliente->ticks_pagos <= 0) {
                popCola(&caja3);
                printf("Cliente atendido en la caja 3.\n");
                clientesAtendidos++;
                free(cliente);  // Liberar memoria después de ser atendido
            }
        }

        // Incrementamos los ticks del supermercado
        ticks++;
    }

    printf("Simulación terminada. Total de clientes atendidos: %d\n", clientesAtendidos);

    // Liberar listas restantes (si quedan clientes)
    LiberarLista(&Principal);
    LiberarLista(&Emergencia);
    LiberarLista(&caja1);
    LiberarLista(&caja2);
    LiberarLista(&caja3);
}
