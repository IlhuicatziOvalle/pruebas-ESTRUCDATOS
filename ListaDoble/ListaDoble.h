
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




// Función para crear una submatriz de tamaño dim x dim e inicializarla con valores aleatorios
int** crearSubmatriz(int dim);
// Función para liberar la memoria de una matriz
void liberarMatriz(int** matriz, int dim);
// Función para imprimir una matriz
void imprimirMatriz(int** matriz, int dim);
// Producto suma de dos matrices de tamaño dim x dim
int** productoSuma(int dim, int** A, int** B);

/*MATRICES 4x4
// Función para imprimir una matriz de tamaño fijo 4x4
void imprimirMatriz(int matriz[4][4], int tamano);

// Función para realizar el producto de matrices de tamaño fijo 4x4
void productoMatrices(int A[4][4], int B[4][4], int resultado[4][4], int tamano);*/