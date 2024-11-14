#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListaDoble/ListaDoble.h"  // Asegúrate de que este archivo incluya las declaraciones necesarias


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
    initTableHash(&tabla, 10, miHashFunc, NULL, "linear_probing");
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

        }
        case 2:{
            printf("1. Por destinatario\n");
            printf("2. Por dimensaiones\n");
            printf("3. Por ID\n");
            printf("Selecciona una opcion ");
            scanf("%d", &opcion2);
            switch(opcion2){
                case 1: {
                    
                }
                case 2: {

                }
                case 3: {

                }
            }
        }       
        case 3:{
            printf("Terminando programa...");
            break;
        }
        default:
            printf("Opcion invalida. Intente denuevo.\n");

    }
    }while(opcion!=3);


    return 0;
}
   

/*int main(void)
{
    TablaHash tabla;
    initTableHash(&tabla,26,miHashFunc,NULL,"chain");
    Tupla ejemplo[]={{"AB12","UNO"},{"VP99","DOS"},{"RK32","TRES"},{"CG45","CUATRO"},
                    {"KL78","CINCO"},{"AA11","OMAR"},{"AC13","GUS"}};
    for(int i=0;i<7;i++){
        Put(&tabla,&ejemplo[i]);
    }
    printf("factor de carga %f\n",factor_carga(tabla));
    printTabla(tabla);
    return 0;
}*/



