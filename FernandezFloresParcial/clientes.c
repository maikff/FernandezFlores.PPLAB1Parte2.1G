#include "clientes.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void inicializarCliente(sCliente cliente[],int tamCliente)
{
    for(int i = 0; i < tamCliente; i++)
    {
        cliente[i].isEmpty = 1;
    }
}

void harcodearClientes(sCliente cliente[],int tamHC)
{
    sCliente auxCliente[] =
    {
        {0, "Carlos",26,0},
        {1, "Mabel",18,0},
        {2, "Ruperto",34,0},
        {3, "Ernesto",44,0},
        {4, "Juan",19,0},
        {5, "Jose",30,0},
        {6, "Alberto",36,0}
    };

    for(int i=0; i<tamHC; i++)
    {
        cliente[i] = auxCliente[i];
    }
}

int cargarNombreCliente(char nombreCliente[],int id,sCliente cliente[],int tamCliente)
{
    int todoOk = 0;

    for(int i=0; i<tamCliente; i++)
    {
        if(cliente[i].id == id&&cliente[i].isEmpty==0)
        {
            strcpy(nombreCliente, cliente[i].nombre);
            todoOk = 1;
        }
    }
    return todoOk;
}
