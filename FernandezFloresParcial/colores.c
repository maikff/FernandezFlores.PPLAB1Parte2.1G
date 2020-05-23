#include "colores.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hardcodearColores(sColor color[], int cant)
{
    sColor auxColor[] =
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Gris"},
        {5003, "Rojo"},
        {5004, "Azul"}
    };

    for(int i=0; i<cant; i++)
    {
        color[i] = auxColor[i];
    }
}

void listarColores(sColor color[], int cantidad)
{
    system("cls");
    printf("***** Color de Mascota *****\n");
    printf("  ID  Descripcion \n\n");

    for(int i = 0; i < cantidad; i++)
    {
        printf("  %d   %7s\n",color[i].id,color[i].nombreColor);
    }
}

int cargarDescripcionColor(char descripcion[], int id, sColor color[], int tamColor)//para mostrar la descripcion del sector, no el numero
{
    int todoOk = 0;

    for(int i = 0; i < tamColor; i++)
    {
        if(color[i].id == id) //si el id del sector es igual al id sector que estor buscando(lo pase por parametros)
        {
            strcpy(descripcion, color[i].nombreColor); //copio a descripcion la descripcion que tengo en ese sector
            todoOk = 1; //exito
        }
    }
    return todoOk;
}
