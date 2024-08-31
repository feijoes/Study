#include "../include/clientesSucursalesLDE.h"

struct rep_clientesSucursalesLDE
{
	TClientesABB abb;
	TClientesSucursalesLDE ant, sig;
	int id;
};

TClientesSucursalesLDE crearTClientesSucursalesLDEVacia()
{
	TClientesSucursalesLDE surcusal = new rep_clientesSucursalesLDE;
	surcusal->abb = NULL;
	surcusal->ant = NULL;
	surcusal->sig = NULL;
	return surcusal;
}
TClientesSucursalesLDE crearTClientesSucursalesLDEConCliente(TClientesABB clientesABB)
{
	TClientesSucursalesLDE surcusal = crearTClientesSucursalesLDEVacia();
	surcusal->abb = clientesABB;
	return surcusal;
}

void insertarClientesABBTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE, TClientesABB clientesABB, int idSucursal)
{
	if (clientesSucursalesLDE->abb == NULL)
	{
		clientesSucursalesLDE->abb = clientesABB;
		clientesSucursalesLDE->id = idSucursal;
		return;
	}
	TClientesSucursalesLDE temp = clientesSucursalesLDE;
	TClientesSucursalesLDE new_sucursal = crearTClientesSucursalesLDEConCliente(clientesABB);
	new_sucursal->id = idSucursal;
	if (edadPromedioTClientesABB(temp->abb) > edadPromedioTClientesABB(clientesABB))
	{
		while (temp->ant != NULL && edadPromedioTClientesABB(temp->ant->abb) > edadPromedioTClientesABB(clientesABB))
		{
			temp = temp->ant;
		}
		new_sucursal->sig = temp;
		new_sucursal->ant = temp->ant;
		if (temp->ant != NULL)
		{
			temp->ant->sig = new_sucursal;
		}
		temp->ant = new_sucursal;
	}
	else
	{
		while (temp->sig != NULL && edadPromedioTClientesABB(temp->sig->abb) <= edadPromedioTClientesABB(clientesABB))
		{
			temp = temp->sig;
		}
		new_sucursal->ant = temp;
		new_sucursal->sig = temp->sig;
		if (temp->sig != NULL)
		{
			temp->sig->ant = new_sucursal;
		}
		temp->sig = new_sucursal;
	}
}
// Funciones axiliales de liberar
void liberarNodoTClientesSucursalesLDE(TClientesSucursalesLDE &clientesSucursalesLDE)
{
	if (clientesSucursalesLDE == NULL)
	{
		return;
	}
	if (clientesSucursalesLDE->abb != NULL)
	{
		liberarTClientesABB(clientesSucursalesLDE->abb);
	}
	delete clientesSucursalesLDE;
	clientesSucursalesLDE = NULL;
}
void liberarSoloTClientesSucursalesLDE(TClientesSucursalesLDE &clientesSucursalesLDE)
{
	if (clientesSucursalesLDE == NULL)
	{
		return;
	}
	delete clientesSucursalesLDE;
	clientesSucursalesLDE = NULL;
}
void liberarSigTClientesSucursalesLDE(TClientesSucursalesLDE &clientesSucursalesLDE)
{
	if (clientesSucursalesLDE == NULL)
	{
		return;
	}
	liberarSigTClientesSucursalesLDE(clientesSucursalesLDE->sig);
	liberarNodoTClientesSucursalesLDE(clientesSucursalesLDE);
}
void liberarAntTClientesSucursalesLDE(TClientesSucursalesLDE &clientesSucursalesLDE)
{
	if (clientesSucursalesLDE == NULL)
	{
		return;
	}
	liberarAntTClientesSucursalesLDE(clientesSucursalesLDE->ant);
	liberarNodoTClientesSucursalesLDE(clientesSucursalesLDE);
}

void liberarTClientesSucursalesLDE(TClientesSucursalesLDE &clientesSucursalesLDE)
{
	liberarAntTClientesSucursalesLDE(clientesSucursalesLDE->ant);
	liberarSigTClientesSucursalesLDE(clientesSucursalesLDE->sig);
	liberarNodoTClientesSucursalesLDE(clientesSucursalesLDE);
}
// Funciones axiliales de imprimir
TClientesSucursalesLDE irHastaPrincipioTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE)
{
	if (clientesSucursalesLDE->ant == NULL)
	{
		return clientesSucursalesLDE;
	}
	return irHastaPrincipioTClientesSucursalesLDE(clientesSucursalesLDE->ant);
}
TClientesSucursalesLDE irHastaFinalTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE)
{
	if (clientesSucursalesLDE->sig == NULL)
	{
		return clientesSucursalesLDE;
	}
	return irHastaFinalTClientesSucursalesLDE(clientesSucursalesLDE->sig);
}
void imprimirSoloTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE)
{
	if (clientesSucursalesLDE->abb == NULL)
	{
		return;
	}
	printf("Grupo con edad promedio %.2f:\n", edadPromedioTClientesABB(clientesSucursalesLDE->abb));
	imprimirTClientesABB(clientesSucursalesLDE->abb);
}
void imprimirTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE)
{
	printf("clientesSucursalesLDE de grupos:\n");
	TClientesSucursalesLDE inicio = irHastaPrincipioTClientesSucursalesLDE(clientesSucursalesLDE);

	while (inicio != NULL)
	{
		imprimirSoloTClientesSucursalesLDE(inicio);
		inicio = inicio->sig;
	}
}

void imprimirInvertidoTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE)
{
	printf("clientesSucursalesLDE de grupos:\n");
	TClientesSucursalesLDE final = irHastaFinalTClientesSucursalesLDE(clientesSucursalesLDE);
	while (final != NULL)
	{
		imprimirSoloTClientesSucursalesLDE(final);
		final = final->ant;
	}
}

nat cantidadTClientesABBClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE)
{
	if (clientesSucursalesLDE == NULL || clientesSucursalesLDE->abb == NULL)
	{
		return 0;
	}
	TClientesSucursalesLDE inicio = irHastaPrincipioTClientesSucursalesLDE(clientesSucursalesLDE);
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
	
	return irHastaPrincipioTClientesSucursalesLDE(clientesSucursalesLDE)->abb;
}

TClientesABB obtenerNesimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE, int n)
{
	if (clientesSucursalesLDE == NULL || cantidadTClientesABBClientesSucursalesLDE(clientesSucursalesLDE) < (nat)n)
	{
		return NULL;
	}
	TClientesSucursalesLDE inicio = irHastaPrincipioTClientesSucursalesLDE(clientesSucursalesLDE);
	while (n > 1)
	{
		n--;
		inicio = inicio->sig;
	}
	return inicio->abb;
}

TClientesSucursalesLDE obtenerNesimoClientesSucursalesLDEInstancia(TClientesSucursalesLDE clientesSucursalesLDE, int n)
{
	if (clientesSucursalesLDE == NULL || cantidadTClientesABBClientesSucursalesLDE(clientesSucursalesLDE) < (nat)n)
	{
		return NULL;
	}
	TClientesSucursalesLDE inicio = irHastaPrincipioTClientesSucursalesLDE(clientesSucursalesLDE);
	while (n > 1)
	{
		n--;
		inicio = inicio->sig;
	}
	return inicio;
}

TClientesABB removerUltimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE)
{
	if (clientesSucursalesLDE == NULL || clientesSucursalesLDE->abb == NULL)
	{
		return NULL;
	}

	TClientesSucursalesLDE final = irHastaFinalTClientesSucursalesLDE(clientesSucursalesLDE);
	TClientesABB clienteAbb = final->abb;

	if (final == clientesSucursalesLDE){
		clientesSucursalesLDE->abb = NULL;
		return clienteAbb;
	}
	if (final->ant != NULL)
	{
		final->ant->sig = NULL;
	}
	liberarSoloTClientesSucursalesLDE(final);
	
	return clienteAbb;
}

TClientesABB removerNesimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE, int n)
{
	if (clientesSucursalesLDE == NULL || clientesSucursalesLDE->abb == NULL)
	{
		return NULL;
	}
	TClientesSucursalesLDE sucursal_a_remover = obtenerNesimoClientesSucursalesLDEInstancia(clientesSucursalesLDE, n);
	TClientesABB clienteAbb = sucursal_a_remover->abb;

	if (sucursal_a_remover == clientesSucursalesLDE){
		clientesSucursalesLDE->abb = NULL;
		return clienteAbb;
	}
	if (sucursal_a_remover->ant != NULL){
		sucursal_a_remover->ant->sig = sucursal_a_remover->sig;
	}
	if (sucursal_a_remover->sig != NULL){
		sucursal_a_remover->sig->ant = sucursal_a_remover->ant;
	}
	liberarSoloTClientesSucursalesLDE(sucursal_a_remover);
	return clienteAbb;
}

TCliente clienteMasRepetido(TClientesSucursalesLDE clientesSucursalesLDE)
{
	if (clientesSucursalesLDE == NULL || clientesSucursalesLDE->abb == NULL){
		return NULL;
	}
	int cantidad[1000] = {0};
	int tope = 0;

	TClientesSucursalesLDE inicio = irHastaPrincipioTClientesSucursalesLDE(clientesSucursalesLDE);
	TClientesSucursalesLDE temp = inicio;
	while (inicio != NULL){
		int cantidad_abb = cantidadClientesTClientesABB(inicio->abb);

		for (int j = 1; j <= cantidad_abb; ++j){
			TCliente cliente = obtenerNesimoClienteTClientesABB(inicio->abb,j);
			int client_id = idTCliente(cliente);
			if (client_id > tope ){
				tope = client_id;
			}
			cantidad[client_id] = cantidad[client_id] + 1;
		}
		inicio = inicio->sig;
	}
	int max = 0;
	int index = 0;
	for (int i = 1; i <= tope; i++){
		if (cantidad[i] > max){
			max = cantidad[i];
			index = i;
		}
	}
	
	while (!existeTClienteTClientesABB(temp->abb, index)){
		temp = temp->sig;
	}

	
	return obtenerTClienteTClientesABB(temp->abb, index);
}
