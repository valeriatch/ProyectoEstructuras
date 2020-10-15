#pragma once
#include <cstdlib>
#include <string>
#include <sstream>
using namespace  std;

class Emergencia
{

	/* Emergencias:
	*  Incendio = 1   , prioridad = 1
	*  AccidenteTransito = 2,  prioridad = 2
	*  FugaGas = 3,  prioridad = 3
	*  PanalAvispas = 4 , prioridad = 4
	*  Inspecciones = 5,  prioridad = 5
	*/

public:

	Emergencia() : emergencia(rand() % 5 + 1), prioridad(0), nombEmerg("") {
	if (emergencia == 1) {
		prioridad = 1;
		nombEmerg = "Incendio";
	}
	if (emergencia == 2) {
		prioridad = 2;
		nombEmerg = "Accidente de Transito";
	}
	if (emergencia == 3) {
		prioridad = 3;
		nombEmerg = "Fuga de gas";
	}
	if (emergencia == 4) {
		prioridad = 4;
		nombEmerg = "Panal de Avispas";
	}
	if (emergencia == 5) {
		prioridad = 5;
		nombEmerg = "Inspecciones ";
	}
}
	string toString()const {
		stringstream s;
			s << "Emergencia: " << nombEmerg << std::endl;
			return s.str();
	}

	int getPrioridad() const { return prioridad; }
	int getEmergencia() { return emergencia; }
	string getNombreEmerg() const { return nombEmerg; }

private:
	int prioridad; 
	int emergencia;
	string nombEmerg;
};

bool operator< (const Emergencia& em1, const Emergencia& em2) {
	return em1.getPrioridad() > em2.getPrioridad();
}
bool operator>(const Emergencia& em1, const Emergencia& em2) {
	return em1.getPrioridad() < em2.getPrioridad();
}
ostream& operator << (ostream& os, const Emergencia& em1) {
	os << em1.toString() << endl;
	return os;
 }
