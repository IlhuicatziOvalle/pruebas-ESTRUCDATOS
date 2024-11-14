
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

typedef int (*FuncionHash)(void *llave);
typedef struct _Tupla{
    void *llave;
    void *dato;
}Tupla;
typedef struct _TablaHash{
    FuncionHash hash1;
    FuncionHash hash2;
    ListaDoble *slots;
    int size;
    int capacidad;
    char tipo_colision[15];
}TablaHash;


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


void swapDatoValue(Dato *a, Dato *b);
void bubblingUp(PQueue *pq, int k, int min, int (*comparar)(void *, void *));
void bubblingDown(PQueue *pq, int k, int min, int (*comparar)(void *, void *));
void insercionHeap(PQueue *pq, void *dato, int min,int (*comparar)(void *, void *));
void *pq_pop(PQueue *pq, int min, int (*comparar)(void *, void *));
void initPQueue(PQueue *pq, int tam);
void *remover(PQueue *pq, int (*comparar)(void *, void *));
int compararSeveridad(void *a, void *b);

typedef NodoBinario NodoExpr;
int JerarquiaOperadores(char a, char b);
int EsOperador(char a);
char *PostInfixPtr(char *expresion);
void AgregarNodoExpr(NodoExpr **arbol, char *postinfix);


Tupla *Get(TablaHash *tabla, void *llave, size_t size);
//colision
void initTableHash(TablaHash *tabla, int capacidad,FuncionHash hash1,FuncionHash hash2,char *colision);
void Put(TablaHash *tabla,Tupla *dato);
float factor_carga(TablaHash tabla);
//functions colision
int linear_probing(void *index);
int quadratic_probing(int index, int time);
int heuristica_double_hash(int a,int b,int times);


void buscar_por_id(TablaHash *tabla, int id);
void buscar_por_nombre(TablaHash *tabla, char *nombre);
void buscar_por_dimensiones(TablaHash *tabla, float largo, float ancho, float alto);