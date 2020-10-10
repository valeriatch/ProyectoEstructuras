#ifndef COLAPRIORIDAD_H
#define COLAPRIORIDAD_H


//template <class T>

struct Nodo {
	Nodo* sig;
	Nodo* anterior;
	int valor;
	Nodo(int v = 0, Nodo* n = nullptr, Nodo* a) : valor{ v }, sig{ n }, anterior{a} {}
};


// Cola de prioridad de máximos - almacena únicamente números enteros
// Valor mayor tiene mayor prioridad

class ColaPrioridad {
public:
	ColaPrioridad();
	//ColaPrioridad(Nodo*);
	ColaPrioridad(ColaPrioridad&);
	~ColaPrioridad();

	void Agregar(int);
	int GetMax();
	int ExtraerMax();
	void IncrementarLlave(int, int);



private:
	// Estructura para almacenar los elementos de la cola
	Nodo* inicio;

	// Funciones auxiliares
	int GetPadre(int);
	int GetHijoIzquierdo(int);
	int GetHijoDerecho(int);
	void Swap(int, int);
	void MaxHeapify(int);
	void SiftUp(int);
	void ReasignarMemoria();
	int pop(Nodo, )
};
#endif