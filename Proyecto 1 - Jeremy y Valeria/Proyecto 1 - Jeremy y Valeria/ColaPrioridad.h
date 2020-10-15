#ifndef COLAPRIORIDAD_H
#define COLAPRIORIDAD_H
#include "Emergencia.h"

template <class T>
struct Nodo {
	Nodo<T>* sig;
	Nodo<T>* anterior;
	T valor;
	Nodo(T v, Nodo<T>* n = nullptr, Nodo<T>* a = nullptr) : valor{ v }, sig{ n }, anterior{a} {}
};

// Cola de prioridad de máximos - almacena únicamente números enteros
// Valor mayor tiene mayor prioridad

template<class T>
class ColaPrioridad {
private:
	//ColaPrioridad();
	//ColaPrioridad(Nodo*);
	//ColaPrioridad(ColaPrioridad&);
	//~ColaPrioridad();

	/*void Agregar(T);
	int GetMax();
	int ExtraerMax();
	void Iniciar();*/
	//void IncrementarLlave(int, int);



public:
	// Estructura para almacenar los elementos de la cola
	Nodo<T>* inicio;

	// Funciones auxiliares
/*	int GetPadre(int);
	int GetHijoIzquierdo(int);
	int GetHijoDerecho(int);
	void Swap(int, int);
	void Heapify(int);
	int getValor(int i);
	void SiftUp(int);
	//void ReasignarMemoria();
	int cantidad();
	void CrearHeap();*/


	// Constructor a partir de un tamaño definido por el usuario
	//template<class T>
	ColaPrioridad() {
		inicio = nullptr;
	}

	/*ColaPrioridad::ColaPrioridad() {


	}*/

	// Constructor de copia
	template<class T>
	ColaPrioridad(ColaPrioridad& c) {
		//cola = nullptr; 
		if (c.inicio == nullptr) {
			inicio = nullptr;
		}
		else {
			inicio = new Nodo(c.inicio->valor);
			Nodo<T>* tmp = inicio;
			Nodo<T>* tmp_obj = c.inicio->sig;
			while (tmp_obj != nullptr) {
				tmp->sig = new Nodo(tmp_obj->valor);
				tmp_obj->anterior = tmp;
				tmp = tmp->sig;
				tmp_obj = tmp_obj->sig;
			}
		}
	}

	// Destructor - libera toda la memoria asignada a la cola de prioridad

	
	~ColaPrioridad() {
		delete[] inicio;
	}

	template<class T>
	void Agregar(T val) {

		Nodo<T>* nodo = new Nodo<T>(val);
		nodo->valor = val;
		nodo->sig = nullptr;
		//nodo->anterior = nullptr;

		if (inicio == nullptr) {
			inicio = nodo;
			inicio->anterior = nullptr;
			return;
		}
		else {
			int cont = 1;

			Nodo<T>* tmp = inicio;
			while (tmp->sig != nullptr) {
				cont++;
				tmp = tmp->sig;
			}
			tmp->sig = nodo;
			nodo->anterior = tmp;
			SiftUp(cont);
		}


		//SiftUp(tam - 1);
	}

	// Retorna el valor con mayor prioridad de la cola
	template<class T>
	int GetMax() {
		if (inicio != nullptr) {
			return inicio->valor;
		}
		return -1;
	}

	// Retorna el valor con mayor prioridad de la cola y lo elimina
	template<class T>
	ColaPrioridad ExtraerMax() {
		if (inicio == nullptr) {
			return -1;
		}

		// Intercambia el elemento con mayor prioridad de la cola con el último
		// y procede a realizar un bubble down para mantener la propiedad de heap
		int conta = 0;
		Nodo<T>* tmp = inicio;
		Nodo<T>* tmp2 = tmp->sig;
		//	Nodo* tmp3 = tmp;
		T dato = tmp->valor;
		T dato2 = 0;

		while (tmp2->sig != nullptr) {
			tmp = tmp2;
			tmp2 = tmp2->sig;

		}
		dato2 = tmp2->valor;
		inicio->valor = dato2;
		tmp->sig = nullptr; /**/
		delete tmp2;

		Heapify(0);
		return dato;
	}

	// Incrementa la prioridad de la llave para una posición dada
	/*void ColaPrioridad::IncrementarLlave(int i, int key) {
		// Verificamos que no excede los límites del arreglo
		// ni que el nuevo valor sea menor que la prioridad actual de la llave
		if (i > tam - 1 || cola[i] > key) {
			return;
		}

		cola[i] = key;

		SiftUp(i);
	}
	*/

	// Obtiene el índice del nodo padre para la posición dada
	template<class T>
	int GetPadre(int i) {

		int contador = 0;

		Nodo<T>* tmp = inicio;

		while (tmp != nullptr) {

			if (contador == ((i - 1) / 2)) {
				return contador;
			}
			contador++;
			tmp = tmp->sig;
		}


		/*	if (i < 0 || i > tam)
				return -1;

			return (i - 1) / 2;*/
	}

	// Obtiene el índice del hijo izquierdo para la posición dada
	template<class T>
	int GetHijoIzquierdo(int i) {

		int contador = (2 * i) + 1;

		Nodo<T>* tmp = inicio;

		for (int j = 0; j < contador; j++) {
			if (tmp == nullptr) {
				return -1;
			}
			tmp = tmp->sig;
		}
		return contador;

	}

	// Obtiene el índice del hijo derecho para la posición dada
	template<class T>
	int GetHijoDerecho(int i) {

		int contador = (2 * i) + 2;

		Nodo<T>* tmp = inicio;

		for (int j = 0; j < contador; j++) {
			if (tmp == nullptr) {
				return -1;
			}
			tmp = tmp->sig;
		}
		return contador;

		/*while (tmp != nullptr) {

			if (contador == ((2*i)+2)) {
				return contador;
			}
			contador++;
			tmp = tmp->sig;
		}*/

		/*if (i < 0 || i > tam)
			return -1;

		return 2 * i + 2;*/
	}

	// Intercambia dos elementos de la cola
	template<class T>
	void Swap(int x, int y) {
		Nodo<T>* tmp = inicio;
		Nodo<T>* actualx = nullptr, * actualy = nullptr;

		for (int i = 0; i <= x; i++) {
			actualx = tmp;
			tmp = tmp->sig;
		}
		tmp = inicio;
		for (int i = 0; i <= y; i++) {
			actualy = tmp;
			tmp = tmp->sig;
		}

		T = actualx->valor;
		actualx->valor = actualy->valor;
		actualy->valor = T;


	}

	// Mantiene la propiedad de Heap - movimiento hacia abajo "bubble down - sift down"
	// Revisa que el nodo de la posición dada cumpla la propiedad de Heap. En caso contrario
	// Intercambia las llaves para mantener la propiedad de Max Heap
	template<class T>
	void Heapify(int i) {
		int izq = GetHijoIzquierdo(i);
		int der = GetHijoDerecho(i);
		int tmp = 0;
		// Se comparan los hijos izquierdo y derecho con la posición dada
		// y se almacena el índice mayor
		if (izq != -1 && getValor(izq) > getValor(i)) {
			tmp = izq;
		}
		else {
			tmp = i;
		}

		if (der != -1 && getValor(der) > getValor(tmp)) {
			tmp = der;
		}

		// Si alguno de los hijos es más grande que la posición
		// se intercambia la posición con el hijo mayor. El proceso continúa
		// hacia abajo (bubble down - sift down)
		if (tmp != i) {
			Swap(i, tmp);
			Heapify(tmp);
		}
	}
	template<class T>
	int getValor(int i)
	{
		int contador = 0;

		Nodo<T>* tmp = inicio;
		int aux;

		while (tmp != nullptr) {

			if (contador == i) {
				return aux = tmp->valor.getPrioridad();
			}
			contador++;
			tmp = tmp->sig;
		}
	}

	// Intercambia una llave de mayor prioridad con su nodo padre
	// hasta que se mantenga la propiedad de Max Heap
	template<class T>
	void SiftUp(int i) {
		int tmp = GetPadre(i);
		Nodo<T>* nodo = inicio;
		// Bubble up - sift up
		while (nodo && getValor(tmp) < getValor(i)) {
			Swap(i, tmp);
			i = tmp;
			tmp = GetPadre(i);
		}
	}

	template<class T>
	int cantidad()
	{
		int cant = 0;
		Nodo<T>* tmp = inicio;
		while (tmp != nullptr) {
			tmp = tmp->sig;
			cant++;
		}
		return cant;
	}
	template<class T>
	void CrearHeap()
	{
		Nodo<T>* tmp = inicio;
		int cant = (cantidad() / 2 - 1);
		for (int i = 0; cant >= i; i++) {
			Heapify(i);
			tmp = tmp->sig;
		}
	}
};

#endif