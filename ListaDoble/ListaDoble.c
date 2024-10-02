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

void imrpimirCliente(void *cliente) {
    Cliente *c = (Cliente *)cliente;
    printf("Nombre: %s \n Tiempo maximo: %d \n Tiempo actual: %d\n", c->nombre, c->tiempo_maximo_ejecucion, c->tiempo_actual_ejecutando);
}

void ejecutar_cliente(Cliente *cliente) {
    cliente->tiempo_actual_ejecutando++;
}

Cliente *generar_cliente() {
    Cliente *nuevo_cliente = (Cliente *)malloc(sizeof(Cliente));
    if (nuevo_cliente == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo trabajo\n");
        return NULL;
    }
    static int id = 1;
    sprintf(nuevo_cliente->nombre, "cliente %d", id++);
    nuevo_cliente->tiempo_maximo_ejecucion = rand() % 100 + 1; 
    nuevo_cliente->tiempo_actual_ejecutando = 0;
    return nuevo_cliente;

}
void SimularAtencionClientes() {
     FILE *archivo = fopen("milog.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para escritura.\n");
        return;
    }
    
    ListaDoble Principal;
    ListaDoble Emergencia;
    InicializarListaDoble(&Principal);
    InicializarListaDoble(&Emergencia);

    srand(time(NULL));
    int tick_simulacion = 0;
    int limite_principal = 25;
    int limite_emergencia = 25;

    // Bucle principal de la simulación
    while (tick_simulacion < 100000) {
        if (Principal.size == 0 && Emergencia.size != 0) {
            Cliente *nuevo_cliente = (Cliente *)popCola(&Emergencia);
            pushCola(&Principal, nuevo_cliente);
            printf("-> %s entró a ejecución desde la fila de emergencia\n", nuevo_cliente->nombre);
        } else if (Principal.size > 0) {
            Cliente *cliente_actual = (Cliente *)Peek(&Principal);
            if (cliente_actual->tiempo_actual_ejecutando >= cliente_actual->tiempo_maximo_ejecucion) {
                printf("-> %s terminó su ejecución\n", cliente_actual->nombre);
                fprintf(archivo, "Cliente atendido: %s\n", cliente_actual->nombre);
                free(popCola(&Principal));
                if (Emergencia.size != 0) {
                    Cliente *nuevo_cliente = (Cliente *)popCola(&Emergencia);
                    pushCola(&Principal, nuevo_cliente);
                    printf("-> %s entró a ejecución desde la fila de emergencia\n", nuevo_cliente->nombre);
                }
            } else {
                if (cliente_actual->tiempo_actual_ejecutando % 100 == 0) {
                    printf("-> Se está ejecutando en el ciclo %d:\n", cliente_actual->tiempo_actual_ejecutando);
                    printf("      Nombre: %s\n", cliente_actual->nombre);
                    printf("      Tiempo ejecutando: %d u\n", cliente_actual->tiempo_actual_ejecutando);
                    printf("      Tiempo máximo: %d u\n", cliente_actual->tiempo_maximo_ejecucion);
                }
                ejecutar_cliente(cliente_actual);
            }
        }

        // Cada 100 ticks, se genera un nuevo cliente si estamos dentro del límite de 100000 ticks
        if (tick_simulacion < 100000 && tick_simulacion % 100 == 0) {
            if (Principal.size < limite_principal) {
                Cliente *nuevo_cliente = generar_cliente();
                if (nuevo_cliente != NULL) {
                    pushCola(&Principal, nuevo_cliente);
                    printf("-> %s entró a la fila principal\n", nuevo_cliente->nombre);
                }
            } else if (Emergencia.size < limite_emergencia) {
                Cliente *nuevo_cliente = generar_cliente();
                if (nuevo_cliente != NULL) {
                    pushCola(&Emergencia, nuevo_cliente);
                    printf("-> %s entró a la fila de emergencia\n", nuevo_cliente->nombre);
                }
            } else {
                printf("-> No se pudo agregar un nuevo cliente, filas llenas\n");
            }
        }

        tick_simulacion++;
    }

    // A partir de aquí, no se atienden nuevos clientes; solo se atienden los que están en las filas
    while (Principal.size > 0 || Emergencia.size > 0) {
        if (Principal.size > 0) {
            Cliente *cliente_actual = (Cliente *)Peek(&Principal);
            if (cliente_actual->tiempo_actual_ejecutando >= cliente_actual->tiempo_maximo_ejecucion) {
                printf("-> %s terminó su ejecución\n", cliente_actual->nombre);
                fprintf(archivo, "Cliente atendido: %s\n", cliente_actual->nombre);
                free(popCola(&Principal));
            } else {
                ejecutar_cliente(cliente_actual);
            }
        } else if (Emergencia.size > 0) {
            Cliente *nuevo_cliente = (Cliente *)popCola(&Emergencia);
            pushCola(&Principal, nuevo_cliente);
            printf("-> %s entró a ejecución desde la fila de emergencia\n", nuevo_cliente->nombre);
        }
    }

    // Imprimir los ticks finales de la simulación
    printf("La simulación ha finalizado exactamente después de 100,000 ticks.\n");
    fprintf(archivo, "La simulación ha finalizado exactamente después de 100,000 ticks.\n");

    fclose(archivo);
    LiberarLista(&Principal);
    LiberarLista(&Emergencia);
}