#include "servicios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hardcodearServicios(sServicio servicio[], int cant)
{
    sServicio auxServicio[] =
    {
        {20000, "Corte",250},
        {20001, "Desparasitado",300},
        {20002, "Castrado",400}
    };

    for(int i=0; i<cant; i++)
    {
        servicio[i] = auxServicio[i];
    }
}
void listarServicios(sServicio servicio[],int tam)
{
    system("cls");
    printf("***** Listado de Servicios *****\n");
    printf("  id \t  Descripcion \t Precio\n\n");
    for(int i=0; i<tam; i++)
    {
        printf(" %d   %13s   $%5.2f\n",servicio[i].id,servicio[i].descripcion,servicio[i].precio);
    }
    printf("\n");
}
int buscarServicio(int id, sServicio vec[], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(vec[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int cargarDescripcionServicio(char descripcionServicio[], int id,sServicio servicios[], int tamServicio)//para mostrar la descripcion del sector, no el numero
{
    int todoOk = 0;

    for(int i = 0; i < tamServicio; i++)
    {
        if(servicios[i].id == id) //si el id del sector es igual al id sector que estor buscando(lo pase por parametros)
        {
            strcpy(descripcionServicio,servicios[i].descripcion); //copio a descripcion la descripcion que tengo en ese sector
            todoOk = 1; //exito
        }
    }
    return todoOk;
}
