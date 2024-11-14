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
int main(void)
{

    TablaHash tabla;
    initTableHash(&tabla, 10, hash1, hash2, "linear_probing");
    int opcion,opcion2;

    do{
        printf("Menu\n");
        printf("1. Registrar paquete\n");
        printf("2. Buscar paquete\n");
        printf("3. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);
    
    switch(opcion){
        case 1: {
                int id;
                char destinatario[50];
                float largo, ancho, alto;
                printf("Ingrese ID del paquete: ");
                scanf("%d", &id);
                printf("Ingrese nombre del destinatario: ");
                scanf("%s", destinatario);
                printf("Ingrese dimensiones (Largo Ancho Alto): ");
                scanf("%f %f %f", &largo, &ancho, &alto);

                Tupla *nuevo = (Tupla *)malloc(sizeof(Tupla));
                nuevo->llave = malloc(sizeof(int));
                memcpy(nuevo->llave, &id, sizeof(int));

                char *datosPaquete = malloc(100);
                sprintf(datosPaquete, "Destinatario: %s, Dimensiones: %.2fx%.2fx%.2f", destinatario, largo, ancho, alto);
                nuevo->dato = datosPaquete;

                Put(&tabla, nuevo);
                printf("Paquete registrado.\n");
                break;
            }
        case 2:{
            printf("1. Por destinatario\n");
            printf("2. Por dimensaiones\n");
            printf("3. Por ID\n");
            printf("Selecciona una opcion ");
            scanf("%d", &opcion2);
            switch(opcion2){
                case 1: {
                    char destinatario[50];
                    printf("Ingrese nombre del destinatario: ");
                    scanf("%s", destinatario);
                    buscar_por_nombre(&tabla, destinatario);
                    break;
                }
                case 2: {
                    float largo, ancho, alto;
                    printf("Ingrese dimensiones (Largo Ancho Alto): ");
                    scanf("%f %f %f", &largo, &ancho, &alto);
                    buscar_por_dimensiones(&tabla, largo, ancho, alto);
                    break;
                }
                case 3: {
                int id;
                printf("Ingrese ID del paquete: ");
                scanf("%d", &id);
                buscar_por_id(&tabla, id);
                break;
                }
            }
        }       
        case 3:{
            printf("Terminando programa...\n");
            break;
        }
        default:
            printf("Opcion invalida. Intente denuevo.\n");

    }
    }while(opcion!=3);


    return 0;
}