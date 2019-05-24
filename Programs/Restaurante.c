#include <stdio.h>
#include <stdlib.h>

int imprimirMenuPrincipal();
int imprimirMenuComida();
int imprimirMenuSopas();
int imprimirMenuGuisados();
int imprimirMenuBebidas();
int imprimirMenuPostres();

int comprobarMesa(int mesas[], int mesa);
float pedirParaMesa(float cuentaActual);
float pedirPrimerTiempo(float cuentaActual);
float pedirSegundoTiempo(float cuentaActual);
float pedirBebidas(float cuentaActual);
float pedirPostres(float cuentaActual);

void obtenerCuenta(float cuentaMesas[], int mesa);

void main() {
    int i = 0, cond = 0, mesa=0;
    int mesas[15];
    float cuentaMesas[15], propinaMesas[15];
    
    for(i=0;i<15;i++) { mesas[i] = 0; cuentaMesas[i] = 0; propinaMesas[i] = 0; }

    do {
        cond = imprimirMenuPrincipal();
        system("cls");
        switch(cond) {
            case 1:
                printf("RESERVANDO MESA\n\n");
                printf("Introduzca el numero de mesa a reservar(1 a 15): "); scanf("%d", &mesa);
                if(!comprobarMesa(mesas, mesa-1)) {
                    printf("La mesa esta ocupada, hasta el momento debe un total de %.2f.\n", cuentaMesas[mesa-1]);
                    system("pause");
                } else {
                    mesas[mesa-1] = 1;
                    printf("La mesa ha sido ocupada exitosamente.\n");
                    system("pause");
                    system("cls");
                }
                break;
            case 2:
                printf("PIDIENDO COMIDA\n\n");
                printf("Ingrese la mesa para la que pedira comida: "); scanf("%d", &mesa);
                if(comprobarMesa(mesas, mesa-1)) {
                    cuentaMesas[mesa-1] = pedirParaMesa(cuentaMesas[mesa-1]);
                }
                break;
            case 3:
                printf("Ingrese la mesa para la que pedira comida: "); scanf("%d", &mesa);
                if(!comprobarMesa(mesas, mesa-1)) {
                    obtenerCuenta(cuentaMesas, mesa);
                }
                break;
            case 0:
                printf("Programa terminado.\n");
                system("pause");
                system("cls");
                break;
            default:
                printf("Ingrese una opcion valida.\n");
                system("pause");
                break;
        }
    } while(cond);
}

int imprimirMenuPrincipal() {
    int seleccion = 0;
    system("cls");

    printf("Bienvenido/a al restaurante Aleatorio Segundo.\n\n");
    
    printf("MENU PRINCIPAL\n");
    printf("1.Reservar Mesa\n");
    printf("2.Pedir comida para mesa\n");
    printf("3.Obtener la cuenta de la mesa.\n");
    printf("0.Salir del programa\n");

    printf("Ingrese su seleccion: "); scanf("%d", &seleccion);

    return seleccion;
}

int imprimirMenuComida() {
    int seleccion = 0;

    system("cls");
    printf("MENU DE COMIDA\n");
    printf("1.Sopas.\n");
    printf("2.Guisados.\n");
    printf("3.Bebidas.\n");
    printf("4.Postre.\n");
    printf("0.Regresar al menu principal.\n\n");
    
    printf("Ingrese su seleccion: "); scanf("%d", &seleccion);
    
    return seleccion;
}

int imprimirMenuSopas() {
    int seleccion = 0;

    system("cls");

    printf("SOPAS\n");
    printf("1.Sopa de Tortilla\tPrecio: $40\n");
    printf("2.Sopa de Fideo\tPrecio: $45\n");
    printf("3.Arroz\tPrecio: $30\n");
    printf("4.Jugo de Carne\tPrecio: $50\n");
    printf("0.Regresar al menu de comida.\n\n");

    printf("Ingrese su seleccion: "); scanf("%d", &seleccion);

    return seleccion;
}

int imprimirMenuGuisados() {
    int seleccion = 0;

    system("cls");
    printf("GUISADOS\n\n");

    printf("1.Guisado 1\tPrecio: $100\n");
    printf("2.Guisado 2\tPrecio: $110\n");
    printf("3.Guisado 3\tPrecio: $90\n");
    printf("4.Guisado 4\tPrecio: $150\n");
    printf("0.Regresar al menu de comida");

    printf("Ingrese su seleccion: "); scanf("%d", &seleccion);

    return seleccion;
}

int imprimirMenuBebidas() {
    int seleccion = 0;

    system("cls");
    printf("BEBIDAS\n\n");

    printf("1.Bebida 1\tPrecio: $20\n");
    printf("2.Bebida 2\tPrecio: $25\n");
    printf("3.Bebida 3\tPrecio: $50\n");
    printf("4.Bebida 4\tPrecio: $35\n");
    printf("5.Bebida 5\tPrecio: $40\n");
    printf("0.Volver al menu principal\n");

    printf("Ingrese su seleccion: "); scanf("%d", &seleccion);

    return seleccion;
}

int imprimirMenuPostres() {
    int seleccion=0;

    system("cls");
    printf("POSTRES\n\n");

    printf("1.Postre 1\tPrecio: $100\n");
    printf("2.Postre 2\tPrecio: $90\n");
    printf("3.Postre 3\tPrecio: $110\n");
    printf("0.Volver al menu de comida.\n");

    printf("Ingrese su seleccion: "); scanf("%d", &seleccion);
    return seleccion;
}

float pedirParaMesa(float cuentaActual) {
    int cond=0;
    do {
        cond = imprimirMenuComida();
        switch(imprimirMenuComida()) {
            case 1:
                cuentaActual = pedirPrimerTiempo(cuentaActual);
                break;
            case 2:
                cuentaActual = pedirSegundoTiempo(cuentaActual);
                break;
            case 3:
                cuentaActual = pedirBebidas(cuentaActual);
                break;
            case 4:
                cuentaActual = pedirPostres(cuentaActual);
                break;
            case 0:
                printf("Saliendo al menu principal...\n");
                system("pause");
                break;
            default:
                printf("Seleccione una opcion valida.\n");
                system("pause");
                break;
        }
    } while(cond);
}

float pedirPrimerTiempo(float cuentaActual) {
    int cond=0;
    do {
        cond = imprimirMenuSopas();
        switch(cond) {
            case 1:
                cuentaActual += 40;
                break;
            case 2:
                cuentaActual += 45;
                break;
            case 3:
                cuentaActual += 30;
                break;
            case 4:
                cuentaActual += 50;
                break;
            default:
                printf("Ingrese una opcion valida.\n");
                break;
        }
    } while(cond);
}

float pedirSegundoTiempo(float cuentaActual) {
    int cond = 0;
    do {
        cond = imprimirMenuGuisados();
        switch(cond) {
            case 1:
                cuentaActual += 100;
                break;
            case 2:
                cuentaActual += 110;
                break;
            case 3:
                cuentaActual += 90;
                break;
            case 4:
                cuentaActual += 150;
                break;
            case 0:
                printf("Volviendo al menu de comida...\n");
                system("pause");
                break;
            default:
                printf("Ingrese una opcion valida.\n");
                system("pause");
                break;
        }
    } while(cond);
}

float pedirBebidas(float cuentaActual) {

}

float pedirPostres(float cuentaActual) {
    system("cls");
    printf("POSTRES\n\n");
}

int comprobarMesa(int mesas[], int mesa) {
    return !mesas[mesa];
}

void obtenerCuenta(float cuentaMesas[], int mesa) {

}
