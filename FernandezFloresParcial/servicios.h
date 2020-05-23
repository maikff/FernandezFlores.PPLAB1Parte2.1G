#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;
} sServicio;

#endif // SERVICIOS_H_INCLUDED

void hardcodearServicios(sServicio servicio[],int cant);
void listarServicios(sServicio servicio[],int tam);
int cargarDescripcionServicio(char descripcionServicio[], int id,sServicio servicios[], int tamServicio);
