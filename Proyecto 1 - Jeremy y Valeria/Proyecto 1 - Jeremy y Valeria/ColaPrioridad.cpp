#include "ColaPrioridad.h"

ColaPrioridad::ColaPrioridad()
{
}

ColaPrioridad::~ColaPrioridad()
{
}


int ColaPrioridad::insertar(int item)
{
	Nodo* nuevo = new Nodo;

	nuevo->valor = item;
	nuevo->siguiente = nullptr;
	nuevo->anterior = nullptr;

	if (inicio == nullptr)
		inicio = nuevo;
	else {
		Nodo* tmp = inicio;
		while (tmp->siguiente != nullptr)
			tmp = tmp->siguiente;
		tmp->siguiente = nuevo;
		nuevo->anterior = tmp;
	}

	return 0;
}

void ColaPrioridad::eliminar()
{
	Nodo* tmp;
	while (inicio != nullptr) {
		tmp = inicio;
		inicio = inicio->siguiente;
		delete tmp;
	}
}
