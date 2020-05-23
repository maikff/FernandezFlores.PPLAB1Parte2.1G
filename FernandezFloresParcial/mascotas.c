#include "mascotas.h"


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void inicializarMascota(sMascota mascota[],int tamMascota)
{
    for(int i = 0; i < tamMascota; i++)
    {
        mascota[i].isEmpty = 1;
    }
}

void harcodearMascotas(sMascota mascota[],int tamHC)
{
    sMascota y[] =
    {
        {0, "Pepe",1001,5001,6,0,0},
        {1, "Rene",1002,5004,8,1,0},
        {2, "Coco",1003,5003,4,2,0},
        {3, "Luky",1004,5004,4,3,0},
        {4, "Botas",1003,5003,8,4,0},
        {5, "Poli",1004,5004,4,5,0},
        {6, "Roko",1003,5003,6,6,0}
    };

    for(int i=0; i<tamHC; i++)
    {
        mascota[i] = y[i];
    }
}




int buscarLibre(sMascota vec[], int tam)
{
    int indice = -1;
    for(int i = 0; i < tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaMascota(int idX, sMascota vec[], int tam,sTipo tipo[],int tamTipo,sColor color[],int tamColor,int idCliente,sCliente cliente[],int tamCliente)
{
    int todoOk = 0;
    int indice = buscarLibre(vec, tam);
    sMascota auxMascota;
    sCliente auxCliente;

    system("cls");
    printf("***** Alta Mascota *****\n");
    if(indice == -1)
    {
        printf("Sistema completo\n\n");
    }
    else
    {
        auxMascota.id = idX;
        auxCliente.id=idCliente;

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxMascota.nombre);

        listarTipos(tipo,tamTipo);
        printf("\nIngrese id del Tipo: ");
        fflush(stdin);
        scanf("%d", &auxMascota.idTipo);

        listarColores(color,tamColor);
        printf("\nIngrese id del Color: ");
        fflush(stdin);
        scanf("%d", &auxMascota.idColor);
        system("cls");

        printf("\nIngrese edad: ");
        fflush(stdin);
        scanf("%d", &auxMascota.edad);

        printf("Ingrese nombre del duenio: \n");
        fflush(stdin);
        gets(auxCliente.nombre);

        printf("Ingrese sexo del duenio: \n");
        fflush(stdin);
        scanf("%c",&auxCliente.sexo);


        auxMascota.isEmpty = 0;
        auxCliente.isEmpty=0;

        vec[indice] = auxMascota;
        cliente[idCliente]=auxCliente;

        todoOk = 1;
    }
    return todoOk;
}




int buscarMascota(int id, sMascota vec[], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(vec[i].id == id && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int menuModificar()
{
    int opcion;

    //system("cls");
    printf("\n***** Menu de Modificaciones *****\n\n");
    printf("1. Modificar Tipo\n");
    printf("2. Modificar Edad\n");
    printf("3. Salir\n\n");
    printf("Ingrese la opcion elegida: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

void modificarMascota(sMascota vec[],int tam, sTipo tipo[], int tamTipo,sCliente cliente[],int tamCliente)
{
    int id,indice;
    char confirma,salir;

    system("cls");
    printf("***** Modificar Mascota *****\n\n");
    mostrarMascotas(vec,tam,tipo,tamTipo,cliente,tamCliente);
    printf("\nIngrese id: ");
    scanf("%d", &id);

    indice = buscarMascota(id, vec, tam);
    if(indice == -1)
    {
        printf("El id %d no existe en sistema.\n", id);
    }
    else
    {
        system("cls");
        printf("***** Modificar Mascota *****\n\n");
        printf("La mascota con el id %d es:\n", id);
        printf("------------------------------\n");
        printf("  ID   Nombre      Tipo  Edad\n");

        mostrarMascota(vec[indice], tipo, tamTipo,cliente,tamCliente);

        printf("\nDesea modificar? 's' o 'n': ");
        fflush(stdin);
        confirma=getche();
        system("cls");

        while(confirma == 's')
        {
            printf("  ID   Nombre      Tipo  Edad\n");
            printf("------------------------------\n");
            mostrarMascota(vec[indice],tipo,tamTipo,cliente,tamCliente);
            switch(menuModificar())
            {
            case 1:
                listarTipos(tipo,tamTipo);
                printf("Ingrese nuevo tipo: ");
                fflush(stdin);
                scanf("%d",&vec[indice].idTipo);
                system("cls");
                break;
            case 2:
                printf("Ingrese nueva edad: ");
                fflush(stdin);
                scanf("%d",&vec[indice].edad);
                system("cls");
                break;
            case 3:
                printf("Confirma salida? s/n: ");
                fflush(stdin);
                salir=getche();
                if(salir == 's')
                {
                    confirma = 'n';
                }
                break;
            }
        }
        if(confirma!='s')
        {
            printf("\n\nSe ha cancelado la operacion.\n");
        }
    }
}

void mostrarMascota(sMascota x, sTipo tipo[], int tamTipo,sCliente cliente[],int tamCliente)
{
    char nombreTipo[20],nombreCliente[20];

    cargarDescripcionTipo(nombreTipo, x.idTipo, tipo, tamTipo);
    cargarNombreCliente(nombreCliente,x.idCliente,cliente,tamCliente);
    printf("  %d   %7s%10s    %d   %7s\n", x.id, x.nombre, nombreTipo, x.edad,nombreCliente);

}

void mostrarMascotas(sMascota lista[], int cantidad, sTipo tipo[], int tamTipo,sCliente cliente[],int tamCliente)
{
    int flag = 0;

    //system("cls");
    printf("***** Listado de Mascotas *****\n\n");
    printf("  ID   Nombre      Tipo  Edad  Duenio\n\n");
    for(int i = 0; i < cantidad; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            mostrarMascota(lista[i], tipo, tamTipo,cliente,tamCliente);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("No hay Mascotas que listar\n");
    }
}


void bajaMascota(sMascota vec[], int tam, sTipo tipo[], int tamTipo,sCliente cliente[],int tamCliente)
{
    int id,indice;
    char confirma;

    system("cls");
    printf("***** Baja Tipo *****\n\n");
    mostrarMascotas(vec,tam,tipo,tamTipo,cliente,tamCliente);
    printf("\nIngrese id: ");
    scanf("%d", &id);

    indice = buscarMascota(id, vec, tam);
    if(indice == -1)
    {
        printf("El id %d no existe en sistema.\n", id);
    }
    else
    {
        system("cls");
        printf("***** Modificar Mascota *****\n\n");
        printf("La mascota con el id %d es:\n", id);
        printf("------------------------------\n");
        printf("  ID   Nombre      Tipo  Edad\n");
        mostrarMascota(vec[indice], tipo, tamTipo,cliente,tamCliente);

        printf("Confirma la baja? 's' o 'n': ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {
            vec[indice].isEmpty = 1;
            printf("Se ha realizado la baja con exito\n\n");
        }
        else
        {
            printf("Se cancelo la operacion.\n");
        }
    }
}

void ordenarMascotas(sMascota list[],int tam,sTipo tipo[],int tamTipo,sCliente cliente[],int tamCliente)
{
    sMascota mascota;
    int order;
    char salir='s';
    mostrarMascotas(list,tam,tipo,tamTipo,cliente,tamCliente);
    printf("\n1. Ordenar mascotas por tipo y nombre.");

    do
    {
        printf("\n2. Salir \nSeleccione una opcion: ");
        fflush(stdin);
        scanf("%d",&order);
        switch(order)
        {
        case 1:
            for(int i=0; i<tam-1; i++) ///ASCENDENTE
            {
                for(int j=i+1; j<tam; j++)
                {
                    if(list[j].idTipo<list[i].idTipo)
                    {
                        mascota = list[i];
                        list[i] = list[j];
                        list[j] = mascota;
                    }
                    else if((list[j].idTipo==list[i].idTipo) && strcmp(list[j].nombre, list[i].nombre) < 0)
                    {
                        mascota = list[i];
                        list[i] = list[j];
                        list[j] = mascota;
                    }
                }
            }
            system("cls");
            mostrarMascotas(list,tam,tipo,tamTipo,cliente,tamCliente);
            break;
        case 2:
            salir='n';
            break;
        }
    }
    while(salir!='n');
}

int cargarNombreMascota(char nombre[], int id, sMascota mascotas[], int tamMascotas)//para mostrar la descripcion del sector, no el numero
{
    int todoOk = 0;

    for(int i = 0; i < tamMascotas; i++)
    {
        if(mascotas[i].id == id&&mascotas[i].isEmpty==0) //si el id del sector es igual al id sector que estor buscando(lo pase por parametros)
        {
            strcpy(nombre, mascotas[i].nombre); //copio a descripcion la descripcion que tengo en ese sector
            todoOk = 1; //exito
        }
    }
    return todoOk;
}

