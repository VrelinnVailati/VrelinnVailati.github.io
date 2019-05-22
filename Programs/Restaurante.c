#include <stdio.h>
#include <stdlib.h>

int imprimirMenuPrincipal();
int imprimirMenuComida();

int comprobarMesa(int mesas[], int mesa);
float pedirParaMesa(float cuentaActual);
float pedirPrimerTiempo(float cuentaActual);
float pedirSegundoTiempo(float cuentaActual);
float pedirBebidas(float cuentaActual);
float pedirPostres(float cuentaActual);

float obtenerCuenta();

void main() {
    int i = 0, cond = 0, mesa=0;
    int mesas[15];
    float cuentaMesas[15], propinaMesas[15];
    
    for(i=0;i<15;i++) { mesas[i] = 0; cuentaMesas[i] = 0; propinaMesas[i] = 0; }

    printf("Bienvenido/a al restaurante Aleatorio Segundo.\n\n");

    do {
        cond = imprimirMenuPrincipal();
        system("cls");
        switch(cond) {
            case 1:
                printf("RESERVANDO MESA\n\n");
                printf("Introduzca el numero de mesa a reservar(1 a 15): "); scanf("%d", &mesa);
                if(!comprobarMesa(mesas, mesa-1)) {
                    printf("La mesa esta ocupada, intente de nuevo.\n");
                } else {
                    mesas[mesa-1] = 1;
                    printf("La mesa ha sido ocupada exitosamente.\n");
                }
                break;

            case 2:
                printf("PIDIENDO COMIDA\n\n");
                printf("Ingrese la mesa para la que pedira comida: "); scanf("%d", &mesa);
                if(comprobarMesa(mesas, mesa-1)) {
                    cuentaMesas[mesa-1] = pedirParaMesa(cuentaMesas[mesa-1]);
                }
                break;

            default:
                printf("Ingrese una opcion valida.\n");
                break;
        }
    } while(cond);
}

int imprimirMenuPrincipal() {
    int seleccion = 0;
    printf("Menu Principal:\n");
    printf("1.Reservar Mesa\n");
    printf("2.Pedir comida para mesa\n");
    printf("3.Obtener la cuenta de la mesa.\n");
    printf("0.Salir del programa\n");

    printf("Ingrese su seleccion: "); scanf("%d", &seleccion);

    return seleccion;
}

int imprimirMenuComida() {
    system("cls");
    printf("MENU DE COMIDA\n");
}

int comprobarMesa(int mesas[], int mesa) {
    return !mesas[mesa];
}

float pedirParaMesa(float cuentaActual) {

}