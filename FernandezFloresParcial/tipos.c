#include "tipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hardcodearTipos(sTipo tipo[], int cant)
{
    sTipo auxTipo[] =
    {
        {1000, "Ave"},
        {1001, "Perro"},
        {1002, "Gato"},
        {1003, "Roedor"},
        {1004, "Pez"}
    };

    for(int i=0; i<cant; i++)
    {
        tipo[i] = auxTipo[i];
    }
}

void listarTipos(sTipo tipos[], int cantidad)
{
    system("cls");
    printf("***** Tipos de Mascota *****\n");
    printf("  ID  Descripcion \n\n");

    for(int i = 0; i < cantidad; i++)
    {
        printf("  %d   %7s\n",tipos[i].id,tipos[i].descripcion);
    }
}
int cargarDescripcionTipo(char descripcion[], int id, sTipo tipo[], int tam)//para mostrar la descripcion del sector, no el numero
{
    int todoOk = 0;

    for(int i = 0; i < tam; i++)
    {
        if(tipo[i].id == id) //si el id del sector es igual al id sector que estor buscando(lo pase por parametros)
        {
            strcpy(descripcion, tipo[i].descripcion); //copio a descripcion la descripcion que tengo en ese sector
            todoOk = 1; //exito
        }
    }
    return todoOk;
}
