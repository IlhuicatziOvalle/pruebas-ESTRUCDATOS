#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListaDoble/ListaDoble.h"  // Asegúrate de que este archivo incluya las declaraciones necesarias
#include <unistd.h>




int main() {
    ListaDoble Recepcion;
    InicializarListaDoble(&Recepcion);
 

    Clinica clinica;
    InicializarListaDoble(&clinica.pacientes_en_espera);
    clinica.paciente_atendiendo = NULL;
    

    srand(time(NULL));
    int tick_simulacion = 0;
    int limite_Recepcion = 50;

    // Bucle principal de la simulación
    while (tick_simulacion < 1000) {
        if (tick_simulacion % 10 == 0) {
            Paciente *nuevo_paciente = generar_paciente();
            if (Recepcion.size < limite_Recepcion) {
                pushCola(&Recepcion, nuevo_paciente);
                printf(">> %s entró a recepcion\n", nuevo_paciente->nombre);
                
            } 
            else {
                printf(">> No se pudo agregar un nuevo cliente, filas llenas\n");
                free(nuevo_paciente);
            }
        }
                 


        // Asignar clientes a las clinica
        if (clinica.paciente_atendiendo == NULL && Recepcion.size > 0) {
            clinica.paciente_atendiendo = (Paciente *)popCola(&Recepcion);
            printf(" %s está siendo atendido en la clinica \n", clinica.paciente_atendiendo->nombre);
            printf(" Nivel de severidad: %d \n", clinica.paciente_atendiendo->tiempo_maximo_despacho);
        }
        
   
        // Ejecutar clientes en las clinica
        if (clinica.paciente_atendiendo != NULL) {
            ejecutar_paciente(clinica.paciente_atendiendo);
            if(clinica.paciente_atendiendo->severidad_padecimiento <= 0) {
                printf("<> %s fue atendido en la clinica \n", clinica.paciente_atendiendo->nombre);
                free(clinica.paciente_atendiendo);
                clinica.paciente_atendiendo = NULL;
                if (clinica.pacientes_en_espera.size > 0) {
                    clinica.paciente_atendiendo = (Paciente *)popCola(&clinica.pacientes_en_espera);
                }
            }
        }

        tick_simulacion++;
    }
              
    // Termina el supermercado, limpiar filas y clinica
    printf("La clinica ha cerrado\n");
    
  
    LiberarLista(&Recepcion); 
    LiberarLista(&clinica.pacientes_en_espera);  
   
    return 0;
}