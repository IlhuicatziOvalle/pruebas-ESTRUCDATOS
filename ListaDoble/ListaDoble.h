
typedef struct _NodoDoble{
    void *dato;
    struct _NodoDoble *next;
    struct _NodoDoble *prev;
}NodoDoble;

typedef struct _ListaDoble{
    NodoDoble *Head;
    NodoDoble *Tail;
    NodoDoble *Curr;
    int size;
} ListaDoble;


typedef struct _Cliente{
    int articulos;
    int ticks_pagos;
}Cliente;


void InicializarListaDoble(ListaDoble *lista);
void PushFront(ListaDoble *lista, void *item);
void PushBack(ListaDoble *lista, void *item);

NodoDoble *GetNodo(ListaDoble *lista, void *item);

NodoDoble *GetNodoPos(ListaDoble *lista, int pos);
void PushPos(ListaDoble *lista, void *item, int pos);
int BorrarPos(ListaDoble *lista, int pos);
void ImprimirLista(const ListaDoble *const, void (*func)(void *));
void LiberarLista(ListaDoble *lista);


typedef ListaDoble Pilas;

void push(Pilas *pila, void *dato);
void* pop(Pilas *pila);
int estaVacia(Pilas *pila);
void imprimirPila(Pilas *pila, void (*func)(void *));
void* Peek(Pilas *pila);

typedef ListaDoble Colas;

void pushCola(Colas *cola, void *dato);
void* popCola(Colas *cola);
void* PeekCola(Colas *cola);
int EstaVaciaCola(Colas *cola);
void imprimirCola(Colas *cola, void (*func)(void *));

Cliente* crearCliente();
void imprimirCliente(void *data);// imprimir los detalles del cliente

void Supermercado(); //logica supermercado
