#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "ListaDoble.h"
#include <unistd.h>

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



void ejecutar_cliente(Cliente *cliente) {
    if (cliente->tiempo_restante > 0) {
        cliente->tiempo_restante--;  // Reducimos 1 tick en cada iteración
    }
}
Cliente *generar_cliente() {
    Cliente *nuevo_cliente = (Cliente *)malloc(sizeof(Cliente));
    if (nuevo_cliente == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo cliente\n");
        return NULL;
    }
    static int id = 1;
    sprintf(nuevo_cliente->nombre, "Cliente %d", id++);
    nuevo_cliente->num_articulos = rand() % 10 + 1; // Entre 1 y 10 artículos
    nuevo_cliente->tiempo_por_articulo = rand() % 100 + 1; // Entre 1 y 100 ticks por artículo
    nuevo_cliente->tiempo_restante = nuevo_cliente->num_articulos * nuevo_cliente->tiempo_por_articulo;
    return nuevo_cliente;
}
void SimularAtencionClientes() {
    ListaDoble FilaPrincipal;
    ListaDoble FilaEmergencia;
    InicializarListaDoble(&FilaPrincipal);
    InicializarListaDoble(&FilaEmergencia);

    Caja cajas[3];
    for (int i = 0; i < 3; i++) {
        InicializarListaDoble(&cajas[i].clientes_en_espera);
        cajas[i].cliente_atendiendo = NULL;
    }

    srand(time(NULL));
    int tick_simulacion = 0;
    int limite_principal = 25;
    int limite_emergencia = 25;

    // Bucle principal de la simulación
    while (tick_simulacion < 1000) {
        // Cada 100 ticks, generamos un nuevo cliente
        if (tick_simulacion % 100 == 0) {
            Cliente *nuevo_cliente = generar_cliente();
            if (FilaPrincipal.size < limite_principal) {
                pushCola(&FilaPrincipal, nuevo_cliente);
                printf(">> %s entró a la fila principal\n", nuevo_cliente->nombre);
            } else if (FilaEmergencia.size < limite_emergencia) {
                pushCola(&FilaEmergencia, nuevo_cliente);
                printf(">> %s entró a la fila de emergencia\n", nuevo_cliente->nombre);
            } else {
                printf(">> No se pudo agregar un nuevo cliente, filas llenas\n");
                free(nuevo_cliente);
            }
        }

        // Asignar clientes a las cajas
        for (int i = 0; i < 3; i++) {
            if (cajas[i].cliente_atendiendo == NULL && FilaPrincipal.size > 0) {
                cajas[i].cliente_atendiendo = (Cliente *)popCola(&FilaPrincipal);
                printf(" %s está siendo atendido en la caja %d\n", cajas[i].cliente_atendiendo->nombre, i + 1);
                printf(" Numero de articulos: %d \n", cajas[i].cliente_atendiendo->tiempo_por_articulo);
                printf(" Ticks: %d \n", cajas[i].cliente_atendiendo->tiempo_por_articulo);
            }
        }
   
        // Ejecutar clientes en las cajas
        for (int i = 0; i < 3; i++) {
            if (cajas[i].cliente_atendiendo != NULL) {
                ejecutar_cliente(cajas[i].cliente_atendiendo);
                if (cajas[i].cliente_atendiendo->tiempo_restante <= 0) {
                    printf("<> %s terminó en la caja %d\n", cajas[i].cliente_atendiendo->nombre, i + 1);
                    free(cajas[i].cliente_atendiendo);
                    cajas[i].cliente_atendiendo = NULL;
                    if (cajas[i].clientes_en_espera.size > 0) {
                        cajas[i].cliente_atendiendo = (Cliente *)popCola(&cajas[i].clientes_en_espera);
                    }
                }
            }
        }

        tick_simulacion++;
    }

    // Termina el supermercado, limpiar filas y cajas
    printf("El supermercado ha cerrado\n");
}