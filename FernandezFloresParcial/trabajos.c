#include "trabajos.h"

#include <stdio.h>
#include <stdlib.h>

void inicializarTrabajos(sTrabajo trabajo[],int tamTrabajo)
{
    for(int i = 0; i < tamTrabajo; i++)
    {
        trabajo[i].isEmpty = 1; //esta vacio
    }
}

void hardcodearTrabajos(sTrabajo trabajo[], int cant)
{
    sTrabajo auxTrabajo[] =
    {
        {100, 3, 20000, {12, 4, 2020}, 0},
        {101, 2, 20001, {13, 5, 1996}, 0},
        {102, 3, 20002, {1, 11, 2007}, 0},
        {103, 4, 20002, {3, 5, 1997}, 0},
        {104, 5, 20001, {4, 3, 2019}, 0}
    };

    for(int i=0; i<cant; i++)
    {
        trabajo[i] = auxTrabajo[i];
    }
}

int buscarLibreTrabajo(sTrabajo trabajo[], int tamTrabajo)
{
    //-1 no consiguio lugar
    int indice = -1;//-1 no es una posicion en el vec
    for(int i = 0; i < tamTrabajo; i++)
    {
        if(trabajo[i].isEmpty == 1)
        {
            indice = i; //devuelvo el valor que tiene el indice
            break;
        }
    }
    return indice;
}
int altaTrabajo(int idTrabajo,sTrabajo trabajo[],int tamTrabajo,sMascota mascotas[],int tamMascotas,sServicio servicio[],int tamServicio,sTipo tipo[],int tamTipo,sCliente cliente[],int tamCliente)
{
    int todoOk=0,indiceTrabajo,indiceMascota;
    sTrabajo auxTrabajo;

    system("cls");
    printf("***** Alta Trabajo *****\n\n");
    indiceTrabajo=buscarLibreTrabajo(trabajo,tamTrabajo);

    if(indiceTrabajo==-1)
    {
        printf("Sistema completo no se pueden de alta mas trabajos\n");
    }
    else
    {
        mostrarMascotas(mascotas,tamMascotas,tipo,tamTipo,cliente,tamCliente);
        printf("Ingrese Id de la mascota: ");
        scanf("%d",&auxTrabajo.idMascota);
        indiceMascota=buscarMascota(auxTrabajo.idMascota,mascotas,tamMascotas);
        if(indiceMascota==-1)
        {
            printf("Mascota ingresada no dada de alta!\n");
        }
        else
        {
            printf("La mascota con el id %d es:\n",auxTrabajo.idMascota);
            printf("------------------------------\n");
            printf("  ID   Nombre      Tipo  Edad\n");

            mostrarMascota(mascotas[indiceMascota], tipo, tamTipo,cliente,tamCliente);
            system("pause");

            listarServicios(servicio,tamServicio);
            printf("Ingrese Id del servicio: ");
            scanf("%d",&auxTrabajo.idServicio);
            if(buscarServicio(auxTrabajo.idServicio,servicio,tamServicio)==-1)
            {
                printf("Servicio ingresado inexistente!\n");
            }
            else
            {
                printf("Ingrese fecha dd/mm/aaaa: ");
                fflush(stdin);
                scanf("%d/%d/%d",&auxTrabajo.fecha.dia,&auxTrabajo.fecha.mes,&auxTrabajo.fecha.anio);

                auxTrabajo.id=idTrabajo;
                auxTrabajo.isEmpty=0;

                trabajo[indiceTrabajo]=auxTrabajo;

                todoOk=1;

                printf("\nAlta Trabajo exitosa!!!\n");
            }
        }
    }
    return todoOk;
}
void listarTrabajo(sTrabajo trabajo,sMascota mascotas[],int tamMascotas,sServicio servicio[],int tamServicio)
{
    char descripcionServicio[20],nombreMascota[20];

    cargarNombreMascota(nombreMascota,trabajo.idMascota,mascotas,tamMascotas);
    cargarDescripcionServicio(descripcionServicio,trabajo.idServicio,servicio,tamServicio);
    printf(" %d     %d     %10s %14s    %d/%d/%d\n",trabajo.id,trabajo.idMascota,nombreMascota,descripcionServicio,trabajo.fecha.dia,trabajo.fecha.mes,trabajo.fecha.anio);
}
void ListarTrabajos(sTrabajo trabajos[],int tamTrabajos,sMascota mascotas[],int tamMascotas,sServicio servicio[],int tamServicio)
{
    int flag=0;

    system("cls");
    printf("***** Listado Trabajos *****\n");
    printf("  Id  Id Mascota   Nombre      Servicio    Fecha\n");
    for(int i=0; i<tamTrabajos; i++)
    {
        if(trabajos[i].isEmpty==0)
        {
            listarTrabajo(trabajos[i],mascotas,tamMascotas,servicio,tamServicio);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("No hay trabajos que mostrar\n");
    }
    printf("\n");
}
