#include "informes.h"
#include "mascotas.h"
#include "tipos.h"
#include "colores.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int menuInformes()
{
    int opcion;
    system("cls");
    printf("***** Menu de Informes *****\n");
    printf("1. Informar mascotas segun el color.\n");
    printf("2. Informar mascotas segun su tipo.\n");
    printf("3. Informar la o las mascotas de menor edad.\n");
    printf("4. Informe de las mascotas separadas por tipo.\n");
    printf("5. Informe de cantidad de mascotas segun color y tipo.\n");
    printf("6. Informe del color/es con mas cantidad de mascotas.\n");
    printf("7. Pedir una mascota y mostrar todos los trabajos que se le hicieron a la misma.\n");
    printf("8. Pedir una mascota e informar la suma de los importes de los servicios que se le hicieron a la misma.\n");
    printf("9. Pedir un servicio y mostrar las mascotas a las que se les realizo ese servicio y la fecha.\n");
    printf("10 Pedir una fecha y mostrar todos los servicios realizados en la misma.\n");
    printf("11. Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

void informar(sMascota mascota[],int tamMascota,sTipo tipo[],int tamTipo,sColor color[],int tamColor,sServicio servicio[],int tamServicio,sTrabajo trabajo[],int tamTrabajo,sCliente cliente[],int tamCliente)
{
    char salirInformes='s';
    do
    {
        switch(menuInformes())
        {
        case 1:
            informarMascotasXColor(mascota,tamMascota,tipo,tamTipo,color,tamColor,cliente,tamCliente);
            system("pause");
            break;
        case 2:
            informarMascotasTipo(mascota,tamMascota,tipo,tamTipo,color,tamColor,cliente,tamCliente);
            system("pause");
            break;
        case 3:
            informarMascotaDeMenorEdad(mascota,tamMascota,tipo,tamTipo,cliente,tamCliente);
            system("pause");
            break;
        case 4:
            informarMascotasXTipos(mascota,tamMascota,tipo,tamTipo,color,tamColor,cliente,tamCliente);
            system("pause");
            break;
        case 5:
            informarMascotasColorTipo(mascota,tamMascota,tipo,tamTipo,color,tamColor,cliente,tamCliente);
            system("pause");
            break;
        case 6:
            informarColorConMasMascotas(mascota,tamMascota,color,tamColor);
            system("pause");
            break;
        case 7:
            mascotaTrabajosHechos(mascota,tamMascota,tipo,tamTipo,cliente,tamCliente,trabajo,tamTrabajo,servicio,tamServicio);
            system("pause");
            break;
        case 8:
            informeSumaDeImportes(mascota,tamMascota,tipo,tamTipo,cliente,tamCliente,trabajo,tamTrabajo,servicio,tamServicio);
            system("pause");
            break;
        case 9:
            system("pause");
            break;
        case 10:
            system("pause");
            break;
        case 11:
            salirInformes='n';
            break;
        }
    }
    while (salirInformes!='n');
}

void informarMascotasXColor(sMascota mascota[],int tamMascota,sTipo tipo[],int tamTipo,sColor color[],int tamColor,sCliente cliente[],int tamCliente)
{
    int auxColor,flag=0;
    system("cls");
    printf("***** Informe Mascotas X Color *****\n\n");
    listarColores(color,tamColor);
    printf("Ingrese color: \n");
    fflush(stdin);
    scanf("%d",&auxColor);

    printf("  ID   Nombre      Tipo  Edad  Duenio\n\n");
    for (int i=0; i<tamMascota; i++)
    {
        if(mascota[i].idColor==auxColor)
        {
            mostrarMascota(mascota[i],tipo,tamTipo,cliente,tamCliente);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("No existen mascotas con ese color que listar.\n\n");
    }
}

void informarMascotasTipo(sMascota mascota[],int tamMascota,sTipo tipo[],int tamTipo,sColor color[],int tamColor,sCliente cliente[],int tamCliente)
{
    int auxTipo,flag=0;
    system("cls");
    printf("***** Informe Mascotas X Tipo *****\n\n");
    listarTipos(tipo,tamTipo);
    printf("Ingrese tipo: \n");
    fflush(stdin);
    scanf("%d",&auxTipo);

    printf("  ID   Nombre      Tipo  Edad  Duenio\n\n");
    for (int i=0; i<tamMascota; i++)
    {
        if(mascota[i].idTipo==auxTipo)
        {
            mostrarMascota(mascota[i],tipo,tamTipo,cliente,tamCliente);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("No existen mascotas con ese tipo que listar.\n\n");
    }
}

void informarMascotaDeMenorEdad(sMascota mascota[],int tamMascota,sTipo tipo[],int tamTipo,sCliente cliente[],int tamCliente)
{
    int mascotaMenor,flag=0;
    system("cls");
    printf("\n***** Listado de Mascota/as Mas Joven\n");
    for(int i=0; i<tamMascota; i++)
    {
        if(mascota[i].isEmpty==0&&(mascota[i].edad<mascotaMenor||flag==0))
        {
            mascotaMenor=mascota[i].edad;
            flag=1;
        }
    }
    printf("\nLa menor edad de mascota es de %d anios y pertenece a \n\n",mascotaMenor);
    printf("\n  ID   Nombre      Tipo  Edad  Duenio\n");
    for(int i=0; i<tamMascota; i++)
    {
        if(mascota[i].isEmpty==0&&mascota[i].edad==mascotaMenor)
        {
            mostrarMascota(mascota[i],tipo,tamTipo,cliente,tamCliente);
        }
    }
}


void informarMascotasXTipos(sMascota mascota[],int tamMascota,sTipo tipo[],int tamTipo,sColor color[],int tamColor,sCliente cliente[],int tamCliente)
{
    int flag;
    system("cls");
    printf("***** Informe Mascotas por Tipo *****\n\n");
    for(int s=0; s<tamTipo; s++)
    {
        flag=0;
        printf(" Tipo: %s\n",tipo[s].descripcion);
        printf(" ------\n\n");
        for(int e=0; e<tamMascota; e++)
        {
            if(mascota[e].isEmpty==0&&mascota[e].idTipo==tipo[s].id)
            {
                mostrarMascota(mascota[e],tipo,tamTipo,cliente,tamCliente);
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("No hay mascota en este sector\n\n");
        }
        printf("\n----------------------------------------------------------------------------\n");
    }
}

void informarMascotasColorTipo(sMascota mascota[],int tamMascota,sTipo tipo[],int tamTipo,sColor color[],int tamColor,sCliente cliente[],int tamCliente)
{
    int auxColor,auxTipo,flag=0,contTipoColor=0;
    char auxSColor[10],auxSTipo[10];
    system("cls");
    printf("***** Informe Mascotas X Color y tipo *****\n\n");
    listarColores(color,tamColor);
    printf("Ingrese color: \n");
    fflush(stdin);
    scanf("%d",&auxColor);
    listarTipos(tipo,tamTipo);
    printf("Ingrese tipo: \n");
    fflush(stdin);
    scanf("%d",&auxTipo);

    for (int i=0; i<tamMascota; i++)
    {
        if(mascota[i].idColor==auxColor&&mascota[i].idTipo==auxTipo)
        {
            contTipoColor++;
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("No existen mascotas con ese color o tipo que listar.\n\n");
    }
    else
    {
        cargarDescripcionColor(auxSColor,auxColor,color,tamColor);
        cargarDescripcionTipo(auxSTipo,auxTipo,tipo,tamTipo);
        printf("La cantidad de mascotas con el color %s y tipo %s es: %d.\n",auxSColor,auxSTipo,contTipoColor);
    }
}

void informarColorConMasMascotas(sMascota mascota[],int tamMascota,sColor color[],int tamColor)
{
    int negro=0,blanco=0,gris=0,rojo=0,azul=0,mayor=0;
    for (int i=0; i<tamMascota; i++)
    {
        for(int c=0; c<tamColor; c++)
        {

            if((mascota[i].idColor==color[c].id)&&color[c].id==5000)
            {
                negro++;
            }
            else if((mascota[i].idColor==color[c].id)&&color[c].id==5001)
            {
                blanco++;
            }
            else if((mascota[i].idColor==color[c].id)&&color[c].id==5002)
            {
                gris++;
            }
            else if((mascota[i].idColor==color[c].id)&&color[c].id==5003)
            {
                rojo++;
            }
            else if((mascota[i].idColor==color[c].id)&&color[c].id==5004)
            {
                azul++;
            }
        }
    }
    if(negro>blanco)
    {
        mayor=negro;
    }
    else
    {
        mayor=blanco;
    }
    if(gris>mayor)
    {
        mayor=gris;
    }
    if(rojo>mayor)
    {
        mayor=rojo;
    }
    if(azul>mayor)
    {
        mayor=azul;
    }
    printf("\nEl color con mas cantidad de mascotas es: ");

    if(negro==mayor)
    {
        printf("Negro, ");
    }
    if(blanco==mayor)
    {
        printf("Blanco, ");
    }
    if(gris==mayor)
    {
        printf("Gris, ");
    }
    if(rojo==mayor)
    {
        printf("Rojo, ");
    }
    if(azul==mayor)
    {
        printf("Azul, ");
    }
    printf("\n\n");
}

void mascotaTrabajosHechos(sMascota mascota[],int tamMascota,sTipo tipo[],int tamTipo,sCliente cliente[],int tamCliente,sTrabajo trabajo[],int tamTrabajo,sServicio servicio[],int tamServicio)
{
       int id,indice;

    system("cls");
    printf("***** Trabajos Hechos *****\n\n");
    mostrarMascotas(mascota,tamMascota,tipo,tamTipo,cliente,tamCliente);
    printf("\nIngrese id: ");
    scanf("%d", &id);

    indice = buscarMascota(id,mascota,tamMascota);
    if(indice == -1)
    {
        printf("El id %d no existe en sistema.\n", id);
    }
    else
    {
        system("cls");
        printf("***** Trabajos Hechos *****\n\n");
        printf(" ID   IdMascota     Nombre       Trabajo   Fecha\n");
        printf("---------------------------------------------------\n");

        for (int t=0; t<tamTrabajo; t++)
        {
            if(id==trabajo[t].idMascota)
            {
                listarTrabajo(trabajo[t],mascota,tamMascota,servicio,tamServicio);
            }
        }
    }
}

void informeSumaDeImportes(sMascota mascota[],int tamMascota,sTipo tipo[],int tamTipo,sCliente cliente[],int tamCliente,sTrabajo trabajo[],int tamTrabajo,sServicio servicio[],int tamServicio)
{
       int id,indice;
       float importe;

    system("cls");
    printf("***** Importes de Servicio *****\n\n");
    mostrarMascotas(mascota,tamMascota,tipo,tamTipo,cliente,tamCliente);
    printf("\nIngrese id: ");
    scanf("%d", &id);

    indice = buscarMascota(id,mascota,tamMascota);
    if(indice == -1)
    {
        printf("El id %d no existe en sistema.\n", id);
    }
    else
    {
        system("cls");
        printf("***** Importes de Servicio *****\n\n");

        for (int t=0; t<tamTrabajo; t++)
        {
            if(id==trabajo[t].idMascota)
            {
                importe+=obtenerTotalImporteServicio(servicio,tamServicio,trabajo[t].idServicio);
            }
        }
        printf("La suma de los importes de los servicios que se le hicieron a la mascota es: $%.2f\n\n",importe);
    }
}

float obtenerTotalImporteServicio(sServicio servicio[],int tamServicio,int idServicio)
{
    float totalImporte=0;

    for(int i=0; i<tamServicio; i++)
    {
        if(servicio[i].id==idServicio)
        {
            totalImporte+=servicio[i].precio;
        }
    }
    return totalImporte;
}
