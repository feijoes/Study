#include "../include/clientesABB.h"

struct rep_clientesABB {
  TCliente cliente;
  TClientesABB izq;
  TClientesABB der;
};

TClientesABB crearTClientesABBVacio() { return NULL; }

void insertarTClienteTClientesABB(TClientesABB &clientesABB, TCliente cliente) {
  if (clientesABB == NULL) {
    clientesABB = new rep_clientesABB;
    clientesABB->izq = NULL;
    clientesABB->der = NULL;
    clientesABB->cliente = cliente;
  } else {
    if (idTCliente(cliente) > idTCliente(clientesABB->cliente)) {
      insertarTClienteTClientesABB(clientesABB->der, cliente);
    } else {
      insertarTClienteTClientesABB(clientesABB->izq, cliente);
    }
  }
}

void imprimirTClientesABB(TClientesABB clientesABB) {
  if (clientesABB != NULL) {
    imprimirTClientesABB(clientesABB->izq);
    imprimirTCliente(clientesABB->cliente);
    imprimirTClientesABB(clientesABB->der);
  }
}

void liberarTClientesABB(TClientesABB &clientesABB) {
  if (clientesABB != NULL) {
    liberarTClientesABB(clientesABB->izq);
    liberarTClientesABB(clientesABB->der);
    liberarTCliente(clientesABB->cliente);
    delete clientesABB;
    clientesABB = NULL;
  }
}

bool existeTClienteTClientesABB(TClientesABB clientesABB, int idCliente) {
  if (clientesABB == NULL) {
    return false;
  } else {
    if (idTCliente(clientesABB->cliente) == idCliente) {
      return true;
    } else {
      if (idCliente > idTCliente(clientesABB->cliente)) {
        return existeTClienteTClientesABB(clientesABB->der, idCliente);
      } else {
        return existeTClienteTClientesABB(clientesABB->izq, idCliente);
      }
    }
  }
}

TCliente obtenerTClienteTClientesABB(TClientesABB clientesABB, int idCliente) {
  if (idTCliente(clientesABB->cliente) == idCliente) {
    return clientesABB->cliente;
  } else if (idCliente > idTCliente(clientesABB->cliente)) {
    return obtenerTClienteTClientesABB(clientesABB->der, idCliente);
  } else {
    return obtenerTClienteTClientesABB(clientesABB->izq, idCliente);
  }
}

nat alturaTClientesABB(TClientesABB clientesABB) {
  if (clientesABB == NULL) {
    return 0;
  } else {
    int izq = alturaTClientesABB(clientesABB->izq);
    int der = alturaTClientesABB(clientesABB->der);
    if (izq > der) {
      return izq + 1;
    } else {
      return der + 1;
    }
  }
}

TCliente maxIdTClienteTClientesABB(TClientesABB clientesABB) {
  if (clientesABB->der == NULL) {
    return clientesABB->cliente;
  } else {
    return maxIdTClienteTClientesABB(clientesABB->der);
  }
}

void removerTClienteTClientesABB(TClientesABB &clientesABB, int idCliente) {
  if (clientesABB != NULL) {
    if (idTCliente(clientesABB->cliente) == idCliente) {
      if (clientesABB->izq != NULL && clientesABB->der != NULL) {
        TCliente max = maxIdTClienteTClientesABB(clientesABB->izq);
        liberarTCliente(clientesABB->cliente);
        clientesABB->cliente = copiarTCliente(max);
        removerTClienteTClientesABB(clientesABB->izq, idTCliente(max));
      } else {
        TClientesABB aux =
            clientesABB->der == NULL ? clientesABB->izq : clientesABB->der;
        liberarTCliente(clientesABB->cliente);
        delete clientesABB;
        clientesABB = aux;
      }
    } else {
      if (idCliente > idTCliente(clientesABB->cliente)) {
        removerTClienteTClientesABB(clientesABB->der, idCliente);
      } else {
        removerTClienteTClientesABB(clientesABB->izq, idCliente);
      }
    }
  }
}

int cantidadClientesTClientesABB(TClientesABB clientesABB) {
  if (clientesABB == NULL) {
    return 0;
  } else {
    return cantidadClientesTClientesABB(clientesABB->izq) +
           cantidadClientesTClientesABB(clientesABB->der) + 1;
  }
}

int sumaEdadesTClientesABB(TClientesABB clientesABB) {
  if (clientesABB == NULL) {
    return 0;
  } else {
    return sumaEdadesTClientesABB(clientesABB->izq) +
           sumaEdadesTClientesABB(clientesABB->der) +
           edadTCliente(clientesABB->cliente);
  }
}

float edadPromedioTClientesABB(TClientesABB clientesABB) {
  int cantidad = cantidadClientesTClientesABB(clientesABB);
  if (cantidad == 0) {
    return 0;
  } else {
    return sumaEdadesTClientesABB(clientesABB) /
           ((float)cantidadClientesTClientesABB(clientesABB));
  }
}

TCliente obtenerNesimoClienteTClientesABB(TClientesABB clientesABB, int n) {
  int cantIzq = cantidadClientesTClientesABB(clientesABB->izq);
  if (cantIzq == n - 1) {
    return clientesABB->cliente;
  } else if (cantIzq > n - 1) {
    return obtenerNesimoClienteTClientesABB(clientesABB->izq, n);
  } else {
    return obtenerNesimoClienteTClientesABB(clientesABB->der, n - cantIzq - 1);
  }
}
