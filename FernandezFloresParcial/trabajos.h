#include "fecha.h"
#include "mascotas.h"
#include "servicios.h"
#include "tipos.h"
#include "clientes.h"
#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED

typedef struct
{
    int id;//autoincremental
    int idMascota;//validar debe existir
    int idServicio;//Validar debe existir
    sFecha fecha;//Validar dia,mes,anio
    int isEmpty;
} sTrabajo;

#endif // TRABAJOS_H_INCLUDED

void inicializarTrabajos(sTrabajo trabajo[],int tamTrabajo);
void hardcodearTrabajos(sTrabajo trabajo[],int cant);
int buscarLibreTrabajo(sTrabajo trabajo[], int tamTrabajo);
int altaTrabajo(int idTrabajo,sTrabajo trabajo[],int tamTrabajo,sMascota mascotas[],int tamMascotas,sServicio servicio[],int tamServicio,sTipo tipo[],int tamTipo,sCliente cliente[],int tamCliente);
int buscarServicio(int id, sServicio vec[], int tam);
void listarTrabajo(sTrabajo trabajo,sMascota mascotas[],int tamMascotas,sServicio servicio[],int tamServicio);
void ListarTrabajos(sTrabajo trabajos[],int tamTrabajos,sMascota mascotas[],int tamMascotas,sServicio servicio[],int tamServicio);
