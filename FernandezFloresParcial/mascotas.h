#include "tipos.h"
#include "colores.h"
#include "clientes.h"
#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int idTipo;//validar
    int idColor;//validar
    int edad;
    int idCliente;
    int isEmpty;
} sMascota;

#endif // MASCOTAS_H_INCLUDED

void inicializarMascota(sMascota mascota[],int tamMascota);

void harcodearMascotas(sMascota mascota[],int tamHC);

int buscarLibre(sMascota vec[], int tam);

int altaMascota(int idX, sMascota vec[], int tam,sTipo tipo[],int tamTipo,sColor color[],int tamColor,int idCliente,sCliente cliente[],int tamCliente);

int buscarMascota(int id, sMascota vec[], int tam);

void modificarMascota(sMascota vec[],int tam, sTipo tipo[], int tamTipo,sCliente cliente[],int tamCliente);

void mostrarMascota(sMascota x, sTipo tipo[], int tamTipo,sCliente cliente[],int tamCliente);

void mostrarMascotas(sMascota lista[], int cantidad, sTipo tipo[], int tamSec,sCliente cliente[],int tamCliente);

void bajaMascota(sMascota vec[], int tam, sTipo tipo[], int tamTipo,sCliente cliente[],int tamCliente);

void ordenarMascotas(sMascota list[],int tam,sTipo tipo[],int tamTipo,sCliente cliente[],int tamCliente);

int cargarNombreMascota(char nombre[], int id, sMascota mascotas[], int tamMascotas);
