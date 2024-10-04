#include "../include/clientesSucursalesLDE.h"

struct rep_nodo
{
	TClientesABB grupo;
	int idSucursal;
	rep_nodo *anterior;
	rep_nodo *siguiente;
};

typedef rep_nodo *nodo;

struct rep_clientesSucursalesLDE
{
	nodo primero;
	nodo ultimo;
};

TClientesSucursalesLDE crearTClientesSucursalesLDEVacia()
{
	TClientesSucursalesLDE nuevo;
	nuevo = new rep_clientesSucursalesLDE;

	nuevo->primero = NULL;
	nuevo->ultimo = NULL;
	return nuevo;
}

void insertarClientesABBTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE, TClientesABB clientesABB, int idSucursal)
{
	nodo nuevo = new rep_nodo;
	nuevo->grupo = clientesABB;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
		nuevo->idSucursal = idSucursal;

	if (clientesSucursalesLDE->primero == NULL){
		clientesSucursalesLDE->primero = nuevo;
		clientesSucursalesLDE->ultimo = nuevo;
	}else{
		float edad = edadPromedioTClientesABB(clientesABB);
		nodo actual = clientesSucursalesLDE->primero;
		while (actual->siguiente != NULL && edad >= edadPromedioTClientesABB(actual->grupo)){
			actual = actual->siguiente;
		}

		if (actual->siguiente == NULL && edad >= edadPromedioTClientesABB(actual->grupo)){
            actual->siguiente = nuevo;
            nuevo->anterior = actual;
            clientesSucursalesLDE->ultimo = nuevo;
        } else if (actual->anterior == NULL) {
            nuevo->siguiente = actual;
            actual->anterior = nuevo;
            clientesSucursalesLDE->primero = nuevo;
		} else {
            nuevo->siguiente = actual;
            nuevo->anterior = actual->anterior;
            actual->anterior->siguiente = nuevo;
            actual->anterior = nuevo;
        }
	}
}

void liberarTClientesSucursalesLDE(TClientesSucursalesLDE &clientesSucursalesLDE)
{
	nodo actual = clientesSucursalesLDE->primero;
	while (actual != NULL)
	{
		liberarTClientesABB(actual->grupo);
		nodo temp = actual;
		actual = actual->siguiente;
		delete temp;
	}
	delete clientesSucursalesLDE;
	clientesSucursalesLDE = NULL;
}

void imprimirTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE)
{
	printf("clientesSucursalesLDE de grupos:\n");
	nodo actual = clientesSucursalesLDE->primero;
	while (actual != NULL)
	{
		printf("Grupo con edad promedio %.2f:\n", edadPromedioTClientesABB(actual->grupo));
		imprimirTClientesABB(actual->grupo);
		actual = actual->siguiente;
	}
}

void imprimirInvertidoTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE)
{
	printf("clientesSucursalesLDE de grupos:\n");
	nodo actual = clientesSucursalesLDE->ultimo;
	while (actual != NULL)
	{
		printf("Grupo con edad promedio %.2f:\n", edadPromedioTClientesABB(actual->grupo));
		imprimirTClientesABB(actual->grupo);
		actual = actual->anterior;
	}
}

nat cantidadTClientesABBClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE)
{
	nat cant = 0;
	nodo actual = clientesSucursalesLDE->ultimo;
	while (actual != NULL)
	{
		cant++;
		actual = actual->anterior;
	}
	return cant;
}

TClientesABB obtenerPrimeroClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE)
{
	return clientesSucursalesLDE->primero->grupo;
}

TClientesABB obtenerNesimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE, int n)
{
	nodo actual = clientesSucursalesLDE->primero;
	if (actual == NULL)
		return NULL;

	while (actual->siguiente != NULL && n > 1)
	{
		actual = actual->siguiente;
		n--;
	}
	return actual->grupo;
}

TClientesABB removerUltimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE)
{
	TClientesABB grupo = clientesSucursalesLDE->ultimo->grupo;
	nodo temp = clientesSucursalesLDE->ultimo;
	if (clientesSucursalesLDE->ultimo == clientesSucursalesLDE->primero)
	{
		clientesSucursalesLDE->primero = NULL;
		clientesSucursalesLDE->ultimo = NULL;
	}
	else
	{
		clientesSucursalesLDE->ultimo->anterior->siguiente = NULL;
		clientesSucursalesLDE->ultimo = clientesSucursalesLDE->ultimo->anterior;
	}
	delete temp;
	return grupo;
}

TClientesABB removerNesimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE, int n)
{
	nodo actual = clientesSucursalesLDE->primero;
	while (actual->siguiente != NULL && n > 1)
	{
		actual = actual->siguiente;
		n--;
	}
	TClientesABB grupo = actual->grupo;
	// Es el primero
	if (actual->anterior == NULL)
	{
		clientesSucursalesLDE->primero = actual->siguiente;
		if (clientesSucursalesLDE->primero == NULL)
		{
			clientesSucursalesLDE->ultimo = NULL;
		}
		else
		{
			clientesSucursalesLDE->primero->anterior = NULL;
		}
	}
	else if (actual->siguiente == NULL)
	{
		clientesSucursalesLDE->ultimo = actual->anterior;
		if (clientesSucursalesLDE->ultimo == NULL)
		{
			clientesSucursalesLDE->primero = NULL;
		}
		else
		{
			clientesSucursalesLDE->ultimo->siguiente = NULL;
		}
	}
	else
	{
		actual->anterior->siguiente = actual->siguiente;
		actual->siguiente->anterior = actual->anterior;
	}
	delete actual;
	return grupo;
}

TCliente clienteMasRepetido(TClientesSucursalesLDE clientesSucursalesLDE)
{
	int cantMaxRepetido = 0;
	TCliente masRepetido = NULL;

	nodo actual = clientesSucursalesLDE->primero;
	while (actual != NULL)
	{
		TClientesABB grupoActual = actual->grupo;
		int cantGrupoActual = cantidadClientesTClientesABB(grupoActual);

		for (int i = 0; i < cantGrupoActual; i++)
		{
			TCliente cliente = obtenerNesimoClienteTClientesABB(grupoActual, i + 1);

			int cantRepeticiones = 0;
			if (masRepetido == NULL || idTCliente(cliente) != idTCliente(masRepetido))
			{
				cantRepeticiones++;

				nodo iterBusqueda = actual->siguiente;
				while (iterBusqueda != NULL)
				{
					TClientesABB siguienteGrupo = iterBusqueda->grupo;

					if (existeTClienteTClientesABB(siguienteGrupo, idTCliente(cliente)))
					{
						cantRepeticiones++;
					}
					iterBusqueda = iterBusqueda->siguiente;
				}

				if (cantRepeticiones > cantMaxRepetido ||
					(cantRepeticiones == cantMaxRepetido && idTCliente(cliente) < idTCliente(masRepetido)))
				{
					masRepetido = cliente;
					cantMaxRepetido = cantRepeticiones;
				}
			}
		}

		actual = actual->siguiente;
	}

	return masRepetido;
}

