
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

typedef struct _NodoBinario{
    void* dato;
    struct _NodoBinario* izq;
    struct _NodoBinario* der;

}NodoBinario;

typedef struct _ArbolBinario{
    NodoBinario *raiz;
    int altura;
    int tam;
}ArbolBinario;

typedef struct _DATO{
    void *valor;
}Dato;

typedef struct _PQueue{
    int heap_size;
    int heap_capacidad;
    Dato *heap;
}PQueue;

typedef struct _Lesion{
    int severidad;
    char descripcion[100];
}Lesion;

typedef struct _Paciente{
    char nombre[50];
    int edad;
    Lesion *informacion;    
}Paciente;



void ImprimirNumeros(void *dato);
void printfdatodeseado(void *dato);
void imprimirPalabras(void *dato);
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


int compararEnteros(void *a, void *b);
int comparar(void *a,void *b);
int compararPalabras(void* a, void* b);
void AgregarNodo(NodoBinario **raiz, NodoBinario *nuevo,int (*com)(void*, void*));
void AgregarArbol(ArbolBinario *arbol,void* dato,int (*com)(void*, void*));
void PreOrden(const ArbolBinario *const arbol,void (*func)(void*));
void InOrden(const ArbolBinario *const arbol, void (*func)(void*));
void PostOrden(const ArbolBinario *const arbo,void (*func)(void*));
void printBFS(const ArbolBinario *const arbol,void (*func)(void*));

NodoBinario **BuscarMinimo(NodoBinario **raiz, int (*comp)(void *, void *));
NodoBinario **BuscarNodo(NodoBinario **raiz,void* dato, int (*comp)(void*,void*));
int eliminarNodo(NodoBinario **raiz,void * dato, int(*comparar)(void *,void *));
void InOrdenDescendente(const ArbolBinario *const arbol, void (*func)(void*));


void bubblingUP(PQueue *pq, int k, int min, int (*comparar)(void *, void *));
void bubblingDown(PQueue *pq, int k, int min, int (*comparar)(void *, void *));
void insercionHeap(PQueue *pq, void *dato, int min,int (*comparar)(void *, void *));
void *pq_pop(PQueue *pq, int min, int (*comparar)(void *, void *));
void swapDatoValue(Dato *a, Dato *b);
void initPQueue(PQueue *pq, int tam);
void pushPQueue(PQueue *queue, void *data, int (*compar)(void *, void *));
void *popPQueue(PQueue *pq, int (*compar)(void *, void *));
void liberarPQueue(PQueue *queue);