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