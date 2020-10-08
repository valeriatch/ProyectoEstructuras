#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Nodo {
	Nodo* siguiente;
	Nodo* anterior;
	int valor = 0;
};

class ColaPrioridad
{

private:
	Nodo* inicio;

public:
	ColaPrioridad();
	~ColaPrioridad();
	int insertar(int);
	void eliminar();
};

