#include <stdio.h>
#include <stdlib.h>

int imprimirMenuPrincipal();
int imprimirMenuComida();
int imprimirMenuSopas();
int imprimirMenuGuisados();
int imprimirMenuBebidas();
int imprimirMenuPostres();
int imprimirMenuInformacion();

int comprobarMesa(int mesas[], int mesa);
float pedirParaMesa(float cuentaActual);
float pedirPrimerTiempo(float cuentaActual);
float pedirSegundoTiempo(float cuentaActual);
float pedirBebidas(float cuentaActual);
float pedirPostres(float cuentaActual);
void mostrarInformacion(float ingresos[], float propinas[], float totalingresos, float totalPropinas);

float obtenerCuenta(int mesas[], float cuentaMesas[], int mesa);
void cobrarCuenta(float cuenta);

void main() {
    int i = 0, cond = 0, mesa=0;
    int mesas[15];
    float totalMesas[15], totalPropinasMesas[15] , cuentaMesas[15], propinaMesas[15], totalIngresos = 0, totalPropinas = 0;
    
    for(i=0;i<15;i++) { mesas[i] = 0; cuentaMesas[i] = 0; propinaMesas[i] = 0; totalMesas[i] = 0; totalPropinasMesas[i] = 0; }

    do {
        cond = imprimirMenuPrincipal();
        system("cls");
        switch(cond) {
            case 1:
                printf("RESERVANDO MESA\n\n");
                printf("Introduzca el numero de mesa a reservar(1 a 15): "); scanf("%d", &mesa);
                if(mesa < 1 || mesa > 15) { 
                    printf("La mesa no existe, favor de verificarlo.\n");
                    system("pause");
                } else {
                    if(!comprobarMesa(mesas, mesa-1)) {
                        printf("La mesa esta ocupada, hasta el momento debe un total de %.2f.\n", cuentaMesas[mesa-1]);
                        system("pause");
                    } else {
                        mesas[mesa-1] = 1;
                        printf("La mesa ha sido ocupada exitosamente.\n");
                        system("pause");
                        system("cls");
                    }
                }
                break;
            case 2:
                printf("PIDIENDO COMIDA\n\n");
                printf("Ingrese la mesa para la que pedira comida: "); scanf("%d", &mesa);
                if(!comprobarMesa(mesas, mesa-1)) {
                    cuentaMesas[mesa-1] = pedirParaMesa(cuentaMesas[mesa-1]);
                    totalMesas[mesa-1] += cuentaMesas[mesa-1];
                    totalIngresos += cuentaMesas[mesa-1];
                } else {
                    printf("La mesa no ha sido ocupada. Recuerde que la mesa debe estar ocupada antes de pedir comida.\n");
                    system("pause");
                }
                break;
            case 3:
                printf("Ingrese la mesa para la que pedira la cuenta: "); scanf("%d", &mesa);
                if(!comprobarMesa(mesas, mesa-1)) {
                    propinaMesas[mesa-1] = obtenerCuenta(mesas, cuentaMesas, mesa-1);
                    totalPropinasMesas[mesa-1] += propinaMesas[mesa-1];
                    totalPropinas += propinaMesas[mesa-1];
                    cuentaMesas[mesa-1] = 0;
                    propinaMesas[mesa-1] = 0;
                    mesas[mesa-1] = 0;
                } else {
                    printf("La mesa no ha sido ocupada.\n");
                    system("pause");
                }
                break;
            case 4:
                mostrarInformacion(totalMesas, totalPropinasMesas, totalIngresos, totalPropinas);
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
    printf("4.Informacion\n");
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
    printf("1.Sopa de Tortilla Precio: $40\n");
    printf("2.Sopa de Fideo Precio: $45\n");
    printf("3.Arroz Precio: $30\n");
    printf("4.Jugo de Carne Precio: $50\n");
    printf("0.Regresar al menu de comida.\n\n");

    printf("Ingrese su seleccion: "); scanf("%d", &seleccion);

    return seleccion;
}

int imprimirMenuGuisados() {
    int seleccion = 0;

    system("cls");
    printf("GUISADOS\n\n");

    printf("1.Pechuga de Pollo Empanizada.\tPrecio: $100\n");
    printf("2.Ensalada Cesar.\tPrecio: $110\n");
    printf("3.Tacos Dorados (Orden de 4).\tPrecio: $90\n");
    printf("4.Enchiladas de Mole.\tPrecio: $150\n");
    printf("0.Regresar al menu de comida");

    printf("Ingrese su seleccion: "); scanf("%d", &seleccion);

    return seleccion;
}

int imprimirMenuBebidas() {
    int seleccion = 0;

    system("cls");
    printf("BEBIDAS\n\n");

    printf("1.Agua de Sabor(355ml.)\tPrecio: $20\n");
    printf("2.Refresco (355ml.).\tPrecio: $25\n");
    printf("3.Malteada (500ml.).\tPrecio: $50\n");
    printf("4.Agua de sabor (500ml.)\tPrecio: $35\n");
    printf("5.Agua de sabor (750ml.)\tPrecio: $40\n");
    printf("0.Volver al menu principal\n");

    printf("Ingrese su seleccion: "); scanf("%d", &seleccion);

    return seleccion;
}

int imprimirMenuPostres() {
    int seleccion=0;

    system("cls");
    printf("POSTRES\n\n");

    printf("1.Pastel de Chocolate.\tPrecio: $100\n");
    printf("2.Fresas con Crema.\tPrecio: $90\n");
    printf("3.Pastel Imposible\tPrecio: $110\n");
    printf("0.Volver al menu de comida.\n");

    printf("Ingrese su seleccion: "); scanf("%d", &seleccion);
    return seleccion;
}

int imprimirMenuInformacion() {
    int seleccion=0;

    system("cls");
    printf("INFORMACION\n\n");

    printf("1.Mostrar ingresos totales.\n");
    printf("2.Mostrar propinas totales\n");
    printf("3.Mostrar ingresos totales por mesa\n");
    printf("4.Mostrar propinas totales por mesa\n");
    printf("0.Volver al menu principal.\n");

    printf("Ingrese su seleccion: "); scanf("%d", &seleccion);
    return seleccion;
}

float pedirParaMesa(float cuentaActual) {
    int cond=0;
    do {
        cond = imprimirMenuComida();
        switch(cond) {
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

    return cuentaActual;
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
            case 0:
                break;
            default:
                printf("Ingrese una opcion valida.\n");
                break;
        }
        printf("La cuenta actual es: $%.2f\n", cuentaActual);
        system("pause");
    } while(cond);

    return cuentaActual;
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
                break;
            default:
                printf("Ingrese una opcion valida.\n");
                system("pause");
                break;
        }
        printf("La cuenta actual es: $%.2f\n", cuentaActual);
        system("pause");
    } while(cond);

    return cuentaActual;
}

float pedirBebidas(float cuentaActual) {
    int cond = 0;
    do{
        cond = imprimirMenuBebidas();
        switch(cond) {
            case 1:
                cuentaActual += 20;
                break;
            case 2:
                cuentaActual += 25;
                break;
            case 3:
                cuentaActual += 50;
                break;
            case 4:
                cuentaActual += 35;
                break;
            case 5:
                cuentaActual += 40;
                break;
            case 0:
                break;
            default:
                printf("Ingrese una opcion valida\n");
                system("pause");
                break;
        }
        printf("La cuenta actual es: $%.2f\n", cuentaActual);
        system("pause");
    } while(cond);

    return cuentaActual;
}

float pedirPostres(float cuentaActual) {
    int cond = 0;
    do {
        cond = imprimirMenuPostres();
        switch(cond) {
            case 1:
                cuentaActual += 100;
                break;
            case 2:
                cuentaActual += 90;
                break;
            case 3:
                cuentaActual += 110;
                break;
            case 0:
                break;
            default:
                printf("Ingrese una opcion valida.\n");
                system("pause");
                break;
        }
        printf("La cuenta actual es: $%.2f\n", cuentaActual);
        system("pause");
    } while(cond);

    return cuentaActual;
}

void mostrarInformacion(float ingresos[], float propinas[], float totalIngresos, float totalPropinas) {
    int cond = 0, mesa = 0;
    do {
        cond = imprimirMenuInformacion();
        switch(cond) {
            case 1:
                printf("El total de ingresos hasta ahora es: $%.2f\n", totalIngresos);
                break;
            case 2:
                printf("El total de propinas hasta ahora es: $%.2f\n", totalPropinas);
                break;
            case 3:
                printf("Ingrese la mesa que desea consultar: "); scanf("%d", &mesa);
                if(mesa < 1 || mesa > 15) {
                    printf("La mesa seleccionada no existe.\n");
                    system("pause");
                } else {
                    printf("El total de ingresos de esta mesa es: $%.2f\n", ingresos[mesa]);
                }
                break;
            case 4:
                printf("Ingrese la mesa que desea consultar: "); scanf("%d", &mesa);
                if(mesa < 1 || mesa > 15) {
                    printf("La mesa seleccionada no existe.\n");
                    system("pause");
                } else {
                    printf("El total de propinas de esta mesa es: $%.2f\n", propinas[mesa]);
                }
                break;
            case 0:
                printf("Saliendo al menu principal...\n");
                break;
            default:
                printf("Seleccione una opcion valida");
                break;
        }
        system("pause");
    } while(cond);
}

int comprobarMesa(int mesas[], int mesa) {
    return !mesas[mesa];
}

float obtenerCuenta(int mesas[], float cuentaMesas[], int mesa) {
    float cuentaMesa = 0;
    int seleccion = 0;
    float propina = 0;
    printf("Obteniendo cuenta para la mesa %d\n", mesa+1);

    if(mesas[mesa]) {
        printf("Como desea agregar su propina:\n\n");
        printf("1.Cantidad Adicional\n");
        printf("2.Porcentaje (15%%)\n\n");

        printf("Ingrese su seleccion: "); scanf("%d", &seleccion);
        switch(seleccion) {
            case 1:
                printf("Ingrese la cantidad a aniadir: "); scanf("%f", &propina);
                cuentaMesas[mesa] += propina;
                break;
            case 2:
                propina = cuentaMesas[mesa] * .15;
                cuentaMesas[mesa] += propina;
                break;
        }
        cobrarCuenta(cuentaMesas[mesa]);
    }

    return propina;
}

void cobrarCuenta(float cuenta) {
    float pagado=0;
    do {
        printf("Faltan por pagar %.2f\n", cuenta);
        printf("Ingrese la cantidad pagada: "); scanf("%f", &pagado);
        cuenta -= pagado;
    } while(cuenta >= 1);
    printf("Su cambio: %.2f. Muchas gracias por su pago.\n", cuenta*-1);
    system("pause");
}
