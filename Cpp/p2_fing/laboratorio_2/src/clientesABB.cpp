#include "../include/clientesABB.h"

struct rep_clientesABB
{
    TCliente cliente;
    TClientesABB left;
    TClientesABB right;
};

TClientesABB crearTClientesABBVacio()
{
    TClientesABB cliente_abb = new rep_clientesABB;
    cliente_abb->left = NULL;
    cliente_abb->right = NULL;
    cliente_abb->cliente = NULL;
    return cliente_abb;
}
TClientesABB crearTClientesABBConCliente(TCliente cliente)
{
    TClientesABB cliente_abb = crearTClientesABBVacio();
    cliente_abb->cliente = cliente;
    return cliente_abb;
}
void insertarTClienteTClientesABB(TClientesABB &clientesABB, TCliente cliente)
{

    if (clientesABB == NULL)
    {
        clientesABB = crearTClientesABBConCliente(cliente);
        return;
    }
    if (clientesABB->cliente == NULL)
    {
        clientesABB->cliente = cliente;
        return;
    }
    if (idTCliente(clientesABB->cliente) > idTCliente(cliente))
    {
        insertarTClienteTClientesABB(clientesABB->left, cliente);
        return;
    }
    insertarTClienteTClientesABB(clientesABB->right, cliente);
}

void imprimirTClientesABB(TClientesABB clientesABB)
{
    if (clientesABB == NULL)
    {
        return;
    }
    imprimirTClientesABB(clientesABB->left);
    imprimirTCliente(clientesABB->cliente);
    imprimirTClientesABB(clientesABB->right);
}

void liberarTClientesABB(TClientesABB &clientesABB)
{
    if (clientesABB == NULL)
    {
        return;
    }
    liberarTClientesABB(clientesABB->left);
    liberarTClientesABB(clientesABB->right);
    liberarTCliente(clientesABB->cliente);
    delete clientesABB;
    clientesABB = NULL;
}
void liberarSoloTClientesABB(TClientesABB &clientesABB)
{
    if (clientesABB == NULL)
    {
        return;
    }
    liberarTCliente(clientesABB->cliente);
    delete clientesABB;
    clientesABB = NULL;
}

bool existeTClienteTClientesABB(TClientesABB clientesABB, int idCliente)
{

    if (clientesABB == NULL || clientesABB->cliente == NULL)
    {
        return false;
    }
    if (idTCliente(clientesABB->cliente) == idCliente)
    {
        return true;
    }
    if (idTCliente(clientesABB->cliente) > idCliente)
    {
        return existeTClienteTClientesABB(clientesABB->left, idCliente);
    }
    return existeTClienteTClientesABB(clientesABB->right, idCliente);
}

TCliente obtenerTClienteTClientesABB(TClientesABB clientesABB, int idCliente)
{
    if (clientesABB == NULL || clientesABB->cliente == NULL)
    {
        return NULL;
    }
    if (idTCliente(clientesABB->cliente) == idCliente)
    {
        return clientesABB->cliente;
    }
    if (idTCliente(clientesABB->cliente) > idCliente)
    {
        return obtenerTClienteTClientesABB(clientesABB->left, idCliente);
    }
    return obtenerTClienteTClientesABB(clientesABB->right, idCliente);
}

nat alturaTClientesABB(TClientesABB clientesABB)
{
    if (clientesABB == NULL || clientesABB->cliente == NULL)
    {
        return 0;
    }
    nat left = alturaTClientesABB(clientesABB->left) + 1;
    nat right = alturaTClientesABB(clientesABB->right) + 1;
    if (left > right)
    {
        return left;
    }
    return right;
}

TCliente maxIdTClienteTClientesABB(TClientesABB clientesABB)
{
    if (clientesABB->right == NULL && clientesABB->cliente != NULL)
    {
        return clientesABB->cliente;
    }

    return maxIdTClienteTClientesABB(clientesABB->right);
}

void removerTClienteTClientesABB(TClientesABB &clientesABB, int idCliente)
{
    if (clientesABB == NULL)
    {
        return;
    }

    if (idTCliente(clientesABB->cliente) > idCliente)
    {
        return removerTClienteTClientesABB(clientesABB->left, idCliente);
    }
    else if (idTCliente(clientesABB->cliente) < idCliente)
    {
        return removerTClienteTClientesABB(clientesABB->right, idCliente);
    }

    if (clientesABB->left == NULL && clientesABB->right == NULL)
    {
        return liberarTClientesABB(clientesABB);
    }

    if (clientesABB->left == NULL)
    {
        TClientesABB temp = clientesABB;
        clientesABB = clientesABB->right;
        return liberarSoloTClientesABB(temp);
    }

    if (clientesABB->right == NULL)
    {
        TClientesABB temp = clientesABB;
        clientesABB = clientesABB->left;
        return liberarSoloTClientesABB(temp);
    }

    TCliente copy_cliente = copiarTCliente(maxIdTClienteTClientesABB(clientesABB->left));
    removerTClienteTClientesABB(clientesABB->left, idTCliente(copy_cliente));
    liberarTCliente(clientesABB->cliente);
    clientesABB->cliente = copy_cliente;
}

int cantidadClientesTClientesABB(TClientesABB clientesABB)
{
    if (clientesABB == NULL || clientesABB->cliente == NULL)
    {
        return 0;
    }

    return 1 + cantidadClientesTClientesABB(clientesABB->left) + cantidadClientesTClientesABB(clientesABB->right);
}
int SomaClientesEdadesTClientesABB(TClientesABB clientesABB)
{
    if (clientesABB == NULL || clientesABB->cliente == NULL)
    {
        return 0;
    }

    return edadTCliente(clientesABB->cliente) + SomaClientesEdadesTClientesABB(clientesABB->left) + SomaClientesEdadesTClientesABB(clientesABB->right);
}

float edadPromedioTClientesABB(TClientesABB clientesABB)
{
    if (clientesABB == NULL || clientesABB->cliente == NULL)
    {
        return 0;
    }
    return (float) SomaClientesEdadesTClientesABB(clientesABB) / cantidadClientesTClientesABB(clientesABB);
}
TCliente obtenerNesimoClienteTClientesABB(TClientesABB clientesABB, int n)
{
    int num_left = cantidadClientesTClientesABB(clientesABB->left) + 1; 
    if (n < num_left)
    {
        return obtenerNesimoClienteTClientesABB(clientesABB->left, n);
    }
    else if (n == num_left)
    {
        return clientesABB->cliente;
    }
    else
    {
        return obtenerNesimoClienteTClientesABB(clientesABB->right, n - num_left);
    }
}