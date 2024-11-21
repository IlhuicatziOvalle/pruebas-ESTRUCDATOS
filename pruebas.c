#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListaDoble/ListaDoble.h"  // Asegúrate de que este archivo incluya las declaraciones necesarias

// Funciones hash de ejemplo
int hash1(void *llave) {
    return (*(int *)llave) % 31; // Ejemplo de hash simple
}

int hash2(void *llave) {
    return 7 - ((*(int *)llave) % 7); // Segundo hash para double hashing
}

int miHashFunc(void *llave){
    char *ll=(char*)llave;
    int letra=ll[0];
    //letra mod 27-11
    if(letra>='A'&&letra<='Z')
        return letra-'A';


    return letra-'a';
}
void printTupla(void *a){
    Tupla d=*(Tupla*)a;
    printf("(%s,%s),",(char*)d.llave,(char*)d.dato);
}
void printTabla(TablaHash tabla){
    for(int i=0;i<tabla.capacidad;i++){
        ListaDoble l=tabla.slots[i];
        printf("[%d]",i);
        ImprimirLista(&l,printTupla);
        printf("\n");
    }
}
int main(void) {

  
    // Inicialización de la tabla hash
    TablaHash tabla;
    initTableHash(&tabla, 10, hash1, hash2, "double_hashing");

    // Listas predefinidas de nombres y direcciones
    char *nombres[] = {"Juan", "Maria", "Pedro", "Luis", "Ana", "Carla", "Roberto", "Elena"};
    char *direcciones[] = {"Calle 1", "Calle 2", "Avenida 3", "Callejón 4", "Bulevar 5"};
    int num_nombres = sizeof(nombres) / sizeof(nombres[0]);
    int num_direcciones = sizeof(direcciones) / sizeof(direcciones[0]);

    int opcion, opcion2;

    do {
        printf("Menu\n");
        printf("1. Registrar paquetes aleatorios\n");
        printf("2. Buscar paquete\n");
        printf("3. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                /*MANUALMENTE AÑADIR A LA HASH
                int id;
                char destinatario[50];
                float Ancho, Alto, Profundidad;
                printf("Ingrese ID del paquete: ");
                scanf("%d", &id);
                printf("Ingrese nombre del destinatario: ");
                scanf("%s", destinatario);
                printf("Ingrese dimensiones (Ancho Alto Profundidad): ");
                scanf("%f %f %f", &Ancho, &Alto, &Profundidad);

                Tupla *nuevo = (Tupla *)malloc(sizeof(Tupla));
                nuevo->llave = malloc(sizeof(int));
                memcpy(nuevo->llave, &id, sizeof(int));
                char *datosPaquete = malloc(100);
                sprintf(datosPaquete, "Destinatario: %s, Dimensiones: %.2fx%.2fx%.2f", destinatario, Ancho, Alto, Profundidad);
                nuevo->dato = datosPaquete;

                Put(&tabla, nuevo);
                printf("Paquete registrado.\n");
                break;
                }*/
                
                int cantidad;
                printf("Ingrese la cantidad de paquetes a generar: ");
                scanf("%d", &cantidad);
                paqueteRandom(&tabla, cantidad, nombres, direcciones, num_nombres, num_direcciones);
                break;
            }
            case 2: {
                printf("1. Por destinatario\n");
                printf("2. Por dimensiones\n");
                printf("3. Por ID\n");
                printf("Selecciona una opcion: ");
                scanf("%d", &opcion2);

                switch (opcion2) {
                    case 1: {
                        char destinatario[50];
                        printf("Ingrese nombre del destinatario: ");
                        scanf("%s", destinatario);
                        buscar_por_nombre(&tabla, destinatario);
                        break;
                    }
                    case 2: {
                        float Ancho, Alto, Profundidad;
                        printf("Ingrese dimensiones (Ancho Alto Profundidad): ");
                        scanf("%f %f %f", &Ancho, &Alto, &Profundidad);
                        buscar_por_dimensiones(&tabla, Ancho, Alto, Profundidad);
                        break;
                    }
                    case 3: {
                        int id;
                        printf("Ingrese ID del paquete: ");
                        scanf("%d", &id);
                        buscar_por_id(&tabla, id);
                        break;
                    }
                    default:
                        printf("Opción no válida.\n");
                }
                break;
            }
            case 3:
                printf("Terminando programa...\n");
                printTabla(tabla);
                break;
            default:
                printf("Opción inválida. Intente de nuevo.\n");
        }
    } while (opcion != 3);

    return 0;
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructuras iniciales

typedef struct _NodoDoble {
    void *dato;
    struct _NodoDoble *next;
    struct _NodoDoble *prev;
} NodoDoble;

typedef struct _ListaDoble {
    NodoDoble *Head;
    NodoDoble *Tail;
    NodoDoble *Curr;
    int size;
} ListaDoble;

typedef struct _Tupla {
    void *llave;
    void *dato;
} Tupla;

typedef int (*FuncionHash)(void *llave);

typedef struct _TablaHash {
    FuncionHash hash1;
    FuncionHash hash2;
    ListaDoble *slots;
    int size;
    int capacidad;
    char tipo_colision[15];
} TablaHash;

// Inicialización de lista doble
void InicializarListaDoble(ListaDoble *lista) {
    lista->Head = NULL;
    lista->Tail = NULL;
    lista->Curr = NULL;
    lista->size = 0;
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

// Inicialización de tabla hash
void initTableHash(TablaHash *tabla, int capacidad, FuncionHash hash1, FuncionHash hash2, char *colision) {
    tabla->hash1 = hash1;
    tabla->hash2 = hash2;
    tabla->size = 0;
    tabla->capacidad = capacidad;
    strcpy(tabla->tipo_colision, colision);
    tabla->slots = (ListaDoble *)malloc(capacidad * sizeof(ListaDoble));
    for (int i = 0; i < capacidad; i++) {
        InicializarListaDoble(&tabla->slots[i]);
    }
}

void Put(TablaHash *tabla, Tupla *dato) {
    int indice = tabla->hash1(dato->llave) % tabla->capacidad;
    int step = tabla->hash2(dato->llave);
    int original_index = indice;

    // Double hashing para manejar colisiones
    while (tabla->slots[indice].size != 0) {
        indice = (original_index + step) % tabla->capacidad;
        if (indice == original_index) {
            printf("Tabla llena, no se puede insertar\n");
            return;
        }
    }
    PushBack(&tabla->slots[indice], dato);
    tabla->size++;
}

Tupla *Remover(TablaHash *tabla, void *llave, size_t size) {
    int indice = tabla->hash1(llave) % tabla->capacidad;
    int step = tabla->hash2(llave);
    int original_index = indice;

    while (tabla->slots[indice].size != 0) {
        NodoDoble *temp = tabla->slots[indice].Head;
        while (temp != NULL) {
            Tupla *dato = (Tupla *)temp->dato;
            if (memcmp(dato->llave, llave, size) == 0) {
                tabla->slots[indice].Head = tabla->slots[indice].Head->next;
                tabla->size--;
                return dato;
            }
            temp = temp->next;
        }
        indice = (original_index + step) % tabla->capacidad;
        if (indice == original_index) {
            break;
        }
    }
    return NULL;
}

float factor_carga(TablaHash tabla) {
    return (float)tabla.size / tabla.capacidad;
}

// Funciones hash
int hash1(void *llave) {
    char *str = (char *)llave;
    int hash = 0;
    while (*str) {
        hash = (hash * 31 + *str) % 101;
        str++;
    }
    return hash;
}

int hash2(void *llave) {
    char *str = (char *)llave;
    int hash = 0;
    while (*str) {
        hash = (hash * 17 + *str) % 97;
        str++;
    }
    return hash == 0 ? 1 : hash; // Asegurar que no sea 0
}

// Main para pruebas
int main() {
    TablaHash tabla;
    initTableHash(&tabla, 4, hash1, hash2, "double_hashing");

    Tupla t1 = {"A1C1A", "tape"};
    Tupla t2 = {"B2C2B", "tijeras"};
    Tupla t3 = {"C3B3C", "hojas"};
    Tupla t4 = {"A4B4A", "lapiz"};
    Tupla t5 = {"C5A5C", "borrador"};
    Tupla t6 = {"B1A1B", "clips"};

    Put(&tabla, &t1);
    Put(&tabla, &t2);
    Put(&tabla, &t3);
    Put(&tabla, &t4);
    printf("Factor de carga: %.2f\n", factor_carga(tabla));

    Remover(&tabla, "C3B3C", strlen("C3B3C"));
    Put(&tabla, &t5);
    Put(&tabla, &t6);
    printf("Factor de carga: %.2f\n", factor_carga(tabla));

    return 0;
}*/