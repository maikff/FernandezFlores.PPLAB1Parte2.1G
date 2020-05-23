#include "mascotas.h"
#include "servicios.h"
#include "trabajos.h"
#include "tipos.h"
#include "colores.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED
int menuInformes();

void informar(sMascota mascota[],int tamMascota,sTipo tipo[],int tamTipo,sColor color[],int tamColor,sServicio servicio[],int tamServicio,sTrabajo trabajo[],int tamTrabajo,sCliente cliente[],int tamCliente);

void informarMascotasXColor(sMascota mascota[],int tamMascota,sTipo tipo[],int tamTipo,sColor color[],int tamColor,sCliente cliente[],int tamCliente);

void informarMascotasTipo(sMascota mascota[],int tamMascota,sTipo tipo[],int tamTipo,sColor color[],int tamColor,sCliente cliente[],int tamCliente);

void informarMascotaDeMenorEdad(sMascota mascota[],int tamMascota,sTipo tipo[],int tamTipo,sCliente cliente[],int tamCliente);

void informarMascotasXTipos(sMascota mascota[],int tamMascota,sTipo tipo[],int tamTipo,sColor color[],int tamColor,sCliente cliente[],int tamCliente);

void informarMascotasColorTipo(sMascota mascota[],int tamMascota,sTipo tipo[],int tamTipo,sColor color[],int tamColor,sCliente cliente[],int tamCliente);

void informarColorConMasMascotas(sMascota mascota[],int tamMascota,sColor color[],int tamColor);

void mascotaTrabajosHechos(sMascota mascota[],int tamMascota,sTipo tipo[],int tamTipo,sCliente cliente[],int tamCliente,sTrabajo trabajo[],int tamTrabajo,sServicio servicio[],int tamServicio);

void informeSumaDeImportes(sMascota mascota[],int tamMascota,sTipo tipo[],int tamTipo,sCliente cliente[],int tamCliente,sTrabajo trabajo[],int tamTrabajo,sServicio servicio[],int tamServicio);

float obtenerTotalImporteServicio(sServicio servicio[],int tamServicio,int idServicio);
