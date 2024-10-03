#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListaDoble/ListaDoble.h"  // Asegúrate de que este archivo incluya las declaraciones necesarias
#include <unistd.h>




int main() {
    ListaDoble FilaPrincipal;
    InicializarListaDoble(&FilaPrincipal);
 

    Clinica clinica[1];
        InicializarListaDoble(&clinica[i].pacientes_en_espera);
        clinica[i].paciente_atendiendo = NULL;
    }

    srand(time(NULL));
    int tick_simulacion = 0;
    int limite_Recepcion = 50;

    // Bucle principal de la simulación
    while (tick_simulacion < 1000) {
        if (tick_simulacion % 10 == 0) {
            Paciente *nuevo_paciente = generar_paciente();
            if (FilaPrincipal.size < limite_Recepcion) {
                pushCola(&FilaPrincipal, nuevo_paciente);
                printf(">> %s entró a la fila principal\n", nuevo_paciente->nombre);
                
            } 
            else {
                printf(">> No se pudo agregar un nuevo cliente, filas llenas\n");
                free(nuevo_paciente);
            }
        }

        // Asignar clientes a las clinica
        for (int i = 0; i < 1; i++) {
            if (clinica[i].paciente_atendiendo == NULL && FilaPrincipal.size > 0) {
                clinica[i].paciente_atendiendo = (Paciente *)popCola(&FilaPrincipal);
                printf(" %s está siendo atendido en la clinica %d\n", clinica[i].paciente_atendiendo->nombre, i + 1);
        
                printf(" Nivel de severidad: %d \n", clinica[i].paciente_atendiendo->tiempo_maximo_despacho);
            }
        }
   
        // Ejecutar clientes en las clinica
        for (int i = 0; i < 1; i++) {
            if (clinica[i].paciente_atendiendo != NULL) {
                ejecutar_paciente(clinica[i].paciente_atendiendo);
                if (clinica[i].paciente_atendiendo->severidad_padecimiento <= 0) {
                    printf("<> %s fue atendido en la clinica %d\n", clinica[i].paciente_atendiendo->nombre, i + 1);
                    free(clinica[i].paciente_atendiendo);
                    clinica[i].paciente_atendiendo = NULL;
                    if (clinica[i].pacientes_en_espera.size > 0) {
                        clinica[i].paciente_atendiendo = (Paciente *)popCola(&clinica[i].pacientes_en_espera);
                    }
                }
            }
        }

        tick_simulacion++;
    }

    // Termina el supermercado, limpiar filas y clinica
    printf("La clinica ha cerrado\n");

    return 0;
}