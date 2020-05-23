#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
} sColor;

#endif // COLORES_H_INCLUDED

void hardcodearColores(sColor color[],int cant);

void listarColores(sColor color[], int cantidad);

int cargarDescripcionColor(char descripcion[], int id, sColor color[], int tamColor);
