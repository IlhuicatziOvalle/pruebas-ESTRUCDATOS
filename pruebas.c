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
        ImprimirLista(l,printTupla);
        printf("\n");
    }
}
int main(void)
{
    

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



