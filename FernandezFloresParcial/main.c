#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "mascotas.h"
#include "tipos.h"
#include "colores.h"
#include "servicios.h"
#include "trabajos.h"
#include "clientes.h"
#include "informes.h"

#define TAMTIPO 5
#define TAMCOLOR 5
#define TAMSERVICIOS 3

#define TAMMASCOTAS 9
#define TAMTRABAJOS 9
#define TAMCLIENTES 9

#define CANTHARDCODEMASCOTAS 7
#define CANTHARDCODETRABAJOS 5
#define CANTHARDCODECLIENTES 7

char menu();

int main()
{
    char confirma,seguir='s';
    int proximoIdMascota=CANTHARDCODEMASCOTAS,proximoIdTrabajo=100+CANTHARDCODETRABAJOS,idCliente=CANTHARDCODECLIENTES;

    sMascota mascota[TAMMASCOTAS];
    sTipo tipo[TAMTIPO];
    sColor color[TAMCOLOR];
    sServicio servicio[TAMSERVICIOS];
    sTrabajo trabajo[TAMTRABAJOS];
    sCliente cliente[TAMCLIENTES];

    inicializarMascota(mascota,TAMMASCOTAS);
    inicializarTrabajos(trabajo,TAMTRABAJOS);
    inicializarCliente(cliente,TAMCLIENTES);

    hardcodearTipos(tipo,TAMTIPO);
    hardcodearColores(color,TAMCOLOR);
    hardcodearServicios(servicio,TAMSERVICIOS);

    harcodearMascotas(mascota,CANTHARDCODEMASCOTAS);
    hardcodearTrabajos(trabajo,CANTHARDCODETRABAJOS);
    harcodearClientes(cliente,CANTHARDCODECLIENTES);

    do
    {
        switch(menu())
        {
        case 'a':
            if(altaMascota(proximoIdMascota,mascota,TAMMASCOTAS,tipo,TAMTIPO,color,TAMCOLOR,idCliente,cliente,TAMCLIENTES))
            {
                proximoIdMascota++;
                idCliente++;
            }
            system("pause");
            break;
        case 'b':
            modificarMascota(mascota, TAMMASCOTAS, tipo,TAMTIPO,cliente,TAMCLIENTES);
            system("pause");
            break;
        case 'c':
            bajaMascota(mascota, TAMMASCOTAS, tipo, TAMTIPO,cliente,TAMCLIENTES);
            break;
        case 'd':
            system("cls");
            ordenarMascotas(mascota,TAMMASCOTAS,tipo,TAMTIPO,cliente,TAMCLIENTES);
            break;
        case 'e':
            system("cls");
            listarTipos(tipo,TAMTIPO);
            system("pause");
            break;
        case 'f':
            system("cls");
            listarColores(color,TAMCOLOR);
            system("pause");
            break;
        case 'g':
            system("cls");
            listarServicios(servicio,TAMSERVICIOS);
            system("pause");
            break;
        case 'h':
            if(altaTrabajo(proximoIdTrabajo,trabajo,TAMTRABAJOS,mascota,TAMMASCOTAS,servicio,TAMSERVICIOS,tipo,TAMTIPO,cliente,TAMCLIENTES))
            {
                proximoIdTrabajo++;
            }
            system("pause");
            break;
        case 'i':
            ListarTrabajos(trabajo,TAMTRABAJOS,mascota,TAMMASCOTAS,servicio,TAMSERVICIOS);
            system("pause");
            break;
        case 'j':
            informar(mascota,TAMMASCOTAS,tipo,TAMTIPO,color,TAMCOLOR,servicio,TAMSERVICIOS,trabajo,TAMTRABAJOS,cliente,TAMCLIENTES);
            break;
        case 'k':
            printf("Confirma salida? s/n: ");
            fflush(stdin);
            confirma=getche();
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        }
    }
    while(seguir == 's');

    return 0;
}

char menu()
{
    char opcion;

    system("cls");
    printf("***** Menu de Opciones *****\n");
    printf("A. Alta Mascota\n");
    printf("B. Modificar Mascota\n");
    printf("C. Baja Mascota\n");
    printf("D. Listar Mascotas\n");
    printf("E. Listar Tipos\n");
    printf("F. Listar Colores\n");
    printf("G. Listar Servicios\n");
    printf("H. Alta Trabajo\n");
    printf("I. Listar Trabajo\n");
    printf("J. Informes\n");
    printf("K. Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}




