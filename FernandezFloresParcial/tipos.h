#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
} sTipo;

#endif // TIPOS_H_INCLUDED

void hardcodearTipos(sTipo tipo[], int cant);
void listarTipos(sTipo tipos[], int cantidad);
int cargarDescripcionTipo(char descripcion[], int id, sTipo tipo[], int tam);//para mostrar la descripcion del sector, no el numero
