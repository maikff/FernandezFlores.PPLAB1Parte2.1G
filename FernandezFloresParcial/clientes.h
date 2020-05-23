#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    int isEmpty;
} sCliente;

#endif // CLIENTE_H_INCLUDED

void inicializarCliente(sCliente cliente[],int tamCliente);

void harcodearClientes(sCliente cliente[],int tamHC);

int cargarNombreCliente(char nombreCliente[],int id,sCliente cliente[],int tamCliente);
