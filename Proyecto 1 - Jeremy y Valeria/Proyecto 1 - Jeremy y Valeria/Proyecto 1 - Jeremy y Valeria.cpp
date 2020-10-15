// Proyecto 1 - Jeremy y Valeria.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "ColaPrioridad.h"
#include "Emergencia.h"


int main()
{
	ColaPrioridad<Emergencia> cola;
	Emergencia emg;

//	cola.Iniciar();

	for (int i = 0; i < 10; i++) {
		cola.Agregar(emg);
	}

/*	cola.Agregar();
	cola.Agregar();
	cola.Agregar(22);
	cola.Agregar(3);
	cola.Agregar(11);
	cola.Agregar(18);
	cola.Agregar(40);
	cola.Agregar(8);
	cola.Agregar(23);
	cola.Agregar(34);
	cola.Agregar(4); */

	/*std::cout << cola.ExtraerMax() << "\n";
	std::cout << cola.ExtraerMax() << "\n";
	std::cout << cola.ExtraerMax() << "\n";
	std::cout << cola.ExtraerMax() << "\n";*/

}