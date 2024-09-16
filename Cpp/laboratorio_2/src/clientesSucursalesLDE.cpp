#include "../include/clientesSucursalesLDE.h"

typedef struct rep_nodo *TNodo;

struct rep_nodo
{
	TClientesABB abb;
	TNodo ant, sig;
};
struct rep_clientesSucursalesLDE
{
	TNodo inicio, final;
};

TClientesSucursalesLDE crearTClientesSucursalesLDEVacia()
{
	TClientesSucursalesLDE surcusal = new rep_clientesSucursalesLDE;
	surcusal->inicio = NULL;
	surcusal->final = NULL;
	return surcusal;
}
TNodo crearTNodoConClientesABB(TClientesABB clientesABB)
{
	TNodo nodo = new rep_nodo;
	nodo->ant = NULL;
	nodo->sig = NULL;
	nodo->abb = clientesABB;
	return nodo;
}

void insertarClientesABBTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE, TClientesABB clientesABB, int idSucursal)
{
	TNodo new_nodo = crearTNodoConClientesABB(clientesABB);
	if (clientesSucursalesLDE->inicio == NULL)
	{
		clientesSucursalesLDE->inicio = new_nodo;
		clientesSucursalesLDE->final = new_nodo;
		return;
	}
	TNodo temp = clientesSucursalesLDE->inicio;

	while (temp != NULL && edadPromedioTClientesABB(temp->abb) <= edadPromedioTClientesABB(clientesABB))
	{
		temp = temp->sig;
	}
	if (temp == NULL){
		clientesSucursalesLDE->final->sig = new_nodo;
		new_nodo->ant = clientesSucursalesLDE->final;
		clientesSucursalesLDE->final = new_nodo;
		return;
	}
	if (temp == clientesSucursalesLDE->inicio){
		clientesSucursalesLDE->inicio = new_nodo;
	} else {
		temp->ant->sig = new_nodo;
	}
	new_nodo->sig = temp;
	new_nodo->ant = temp->ant;
	temp->ant = new_nodo;
	return;
}
// Funciones axiliales de liberar
void liberarSoloTNodo(TNodo &nodo)
{
	if (nodo == NULL)
	{
		return;
	}
	delete nodo;
	nodo = NULL;
}
void liberarSigTNodo(TNodo &nodo)
{
	if (nodo == NULL)
	{
		return;
	}
	liberarSigTNodo(nodo->sig);
	liberarTClientesABB(nodo->abb);
	liberarSoloTNodo(nodo);
}

void liberarTClientesSucursalesLDE(TClientesSucursalesLDE &clientesSucursalesLDE)
{
	liberarSigTNodo(clientesSucursalesLDE->inicio);
	delete clientesSucursalesLDE;
	clientesSucursalesLDE = NULL;
}
// Funciones axiliales de imprimir
void imprimirSoloTNodo(TNodo nodo)
{
	if (nodo->abb == NULL)
	{
		return;
	}
	printf("Grupo con edad promedio %.2f:\n", edadPromedioTClientesABB(nodo->abb));
	imprimirTClientesABB(nodo->abb);
}
void imprimirTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE)
{
	printf("clientesSucursalesLDE de grupos:\n");
	TNodo inicio = clientesSucursalesLDE->inicio;
	while (inicio != NULL)
	{
		imprimirSoloTNodo(inicio);
		inicio = inicio->sig;
	}
}

void imprimirInvertidoTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE)
{
	printf("clientesSucursalesLDE de grupos:\n");
	TNodo final = clientesSucursalesLDE->final;
	while (final != NULL)
	{
		imprimirSoloTNodo(final);
		final = final->ant;
	}
}

nat cantidadTClientesABBClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE)
{
	if (clientesSucursalesLDE == NULL || clientesSucursalesLDE->inicio == NULL)
	{
		return 0;
	}
	TNodo inicio = clientesSucursalesLDE->inicio;
	int i = 0;
	while (inicio != NULL)
	{
		i++;
		inicio = inicio->sig;
	}
	return i;
}

TClientesABB obtenerPrimeroClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE)
{

	return clientesSucursalesLDE->inicio->abb;
}

TClientesABB obtenerNesimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE, int n)
{
	if (clientesSucursalesLDE == NULL || cantidadTClientesABBClientesSucursalesLDE(clientesSucursalesLDE) < (nat)n)
	{
		return NULL;
	}
	TNodo inicio = clientesSucursalesLDE->inicio;
	while (n > 1)
	{
		n--;
		inicio = inicio->sig;
	}
	return inicio->abb;
}

TNodo obtenerNesimoTNodoInstancia(TClientesSucursalesLDE clientesSucursalesLDE, int n)
{
	if (clientesSucursalesLDE == NULL || cantidadTClientesABBClientesSucursalesLDE(clientesSucursalesLDE) < (nat)n)
	{
		return NULL;
	}
	TNodo inicio = clientesSucursalesLDE->inicio;
	while (n > 1)
	{
		n--;
		inicio = inicio->sig;
	}
	return inicio;
}

TClientesABB removerUltimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE)
{
	if (clientesSucursalesLDE == NULL || clientesSucursalesLDE->inicio == NULL)
	{
		return NULL;
	}

	TNodo final = clientesSucursalesLDE->final;
	TClientesABB clienteAbb = final->abb;
	
	if (final == clientesSucursalesLDE->inicio)
	{
		clientesSucursalesLDE->final = NULL;
		clientesSucursalesLDE->inicio = NULL;
		liberarSoloTNodo(final);
		return clienteAbb;
	}
	clientesSucursalesLDE->final = final->ant;
	clientesSucursalesLDE->final->sig = NULL;

	liberarSoloTNodo(final);

	return clienteAbb;
}

TClientesABB removerNesimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE, int n)
{
	if (clientesSucursalesLDE == NULL || clientesSucursalesLDE->inicio == NULL)
	{
		return NULL;
	}
	TNodo nodo_a_remover = obtenerNesimoTNodoInstancia(clientesSucursalesLDE, n);
	TClientesABB clienteAbb = nodo_a_remover->abb;

	if (nodo_a_remover->ant != NULL)
	{
		nodo_a_remover->ant->sig = nodo_a_remover->sig;
	}
	if (nodo_a_remover->sig != NULL)
	{
		nodo_a_remover->sig->ant = nodo_a_remover->ant;
	}

	if (nodo_a_remover == clientesSucursalesLDE->inicio)
	{
		clientesSucursalesLDE->inicio = nodo_a_remover->sig;
	}
	if (nodo_a_remover == clientesSucursalesLDE->final)
	{
		clientesSucursalesLDE->final = nodo_a_remover->ant;
	}

	liberarSoloTNodo(nodo_a_remover);
	return clienteAbb;
}

TCliente clienteMasRepetido(TClientesSucursalesLDE clientesSucursalesLDE)
{
	if (clientesSucursalesLDE == NULL || clientesSucursalesLDE->inicio == NULL)
	{
		return NULL;
	}
	int cantidad[1000] = {0};
	int tope = 0;

	TNodo inicio = clientesSucursalesLDE->inicio;
	TNodo temp = inicio;
	while (inicio != NULL)
	{
		int cantidad_abb = cantidadClientesTClientesABB(inicio->abb);

		for (int j = 1; j <= cantidad_abb; ++j)
		{
			TCliente cliente = obtenerNesimoClienteTClientesABB(inicio->abb, j);
			int client_id = idTCliente(cliente);
			if (client_id > tope)
			{
				tope = client_id;
			}
			cantidad[client_id] = cantidad[client_id] + 1;
		}
		inicio = inicio->sig;
	}
	int max = 0;
	int index = 0;
	for (int i = 1; i <= tope; i++)
	{
		if (cantidad[i] > max)
		{
			max = cantidad[i];
			index = i;
		}
	}

	while (!existeTClienteTClientesABB(temp->abb, index))
	{
		temp = temp->sig;
	}

	return obtenerTClienteTClientesABB(temp->abb, index);
}
