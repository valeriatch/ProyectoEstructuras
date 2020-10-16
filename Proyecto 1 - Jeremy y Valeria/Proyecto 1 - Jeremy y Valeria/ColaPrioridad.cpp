/*#include "ColaPrioridad.h"

// Constructor a partir de un tamaño definido por el usuario
template<class T>
ColaPrioridad<T>::ColaPrioridad(){
	inicio = nullptr;
}

/*ColaPrioridad::ColaPrioridad() {


}

// Constructor de copia
template<class T>
ColaPrioridad<T>::ColaPrioridad(ColaPrioridad& c) {
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
template<class T>
ColaPrioridad<T>::~ColaPrioridad() {
	delete[] inicio;
}

template<class T>
void ColaPrioridad<T>::Agregar(T val) {
	
	Nodo<T>* nodo = new Nodo<T>();
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
int ColaPrioridad<T>::GetMax() {
	if (inicio != nullptr) {
		return inicio ->valor;
	}
	return -1;
}

// Retorna el valor con mayor prioridad de la cola y lo elimina
template<class T>
int ColaPrioridad<T>::ExtraerMax() {
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
	tmp->sig = nullptr; /*
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


// Obtiene el índice del nodo padre para la posición dada
template<class T>
int ColaPrioridad<T>::GetPadre(int i) {

	int contador =0;

	Nodo<T>* tmp = inicio;

	while (tmp!= nullptr) {
		
		if (contador == ((i - 1) / 2)) {	
			return contador;
		}
		contador++;
		tmp = tmp->sig;
	}


/*	if (i < 0 || i > tam)
		return -1;

	return (i - 1) / 2;
}

// Obtiene el índice del hijo izquierdo para la posición dada
template<class T>
int ColaPrioridad<T>::GetHijoIzquierdo(int i) {

<<<<<<< HEAD
	int contador = (2 * i) + 1;

<<<<<<< HEAD
	Nodo<T>* tmp = inicio;
=======
=======
>>>>>>> parent of 57fc4d9... arreglo de metodos
	int contador = 0;//((2*i)+1))

	Nodo* tmp = inicio;


	//Probar con for j=0, j<contador, j++
	while (tmp != nullptr) {
<<<<<<< HEAD
>>>>>>> parent of 57fc4d9... arreglo de metodos
=======
>>>>>>> parent of 57fc4d9... arreglo de metodos

		if (contador == ((2*i)+1)) {  //
			return contador;
		}
<<<<<<< HEAD
<<<<<<< HEAD
		tmp = tmp->sig;
	}
	return contador;

}

// Obtiene el índice del hijo derecho para la posición dada
template<class T>
int ColaPrioridad<T>::GetHijoDerecho(int i) {

	int contador = (2 * i) + 2;
=======

		contador++;
		tmp = tmp->sig;

=======

		contador++;
		tmp = tmp->sig;

>>>>>>> parent of 57fc4d9... arreglo de metodos
	}

	/*if (i < 0 || i > tam)
		return -1;

	return 2 * i + 1;*/
}

// Obtiene el índice del hijo derecho para la posición dada
int ColaPrioridad::GetHijoDerecho(int i) {
	int contador = 0;
<<<<<<< HEAD
>>>>>>> parent of 57fc4d9... arreglo de metodos
=======
>>>>>>> parent of 57fc4d9... arreglo de metodos

	Nodo<T>* tmp = inicio;

	while (tmp != nullptr) {

		if (contador == ((2*i)+2)) {
			return contador;
		}
		contador++;
		tmp = tmp->sig;
	}

	/*if (i < 0 || i > tam)
		return -1;

	return 2 * i + 2;
}

// Intercambia dos elementos de la cola
template<class T>
void ColaPrioridad<T>::Swap(int x, int y) {
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
void ColaPrioridad<T>::Heapify(int i) {
	int izq = GetHijoIzquierdo(i);
	int der = GetHijoDerecho(i);
	int tmp = 0;
	// Se comparan los hijos izquierdo y derecho con la posición dada
	// y se almacena el índice mayor
	if (inicio!= nullptr && getValor(izq) > getValor(i)) {
		tmp = izq;
	}
	else {
		tmp = i;
	}

	if (inicio != nullptr && getValor(der) > getValor(tmp)) {
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
int ColaPrioridad<T>::getValor(int i)
{
	int contador = 0;

	Nodo<T>* tmp = inicio;
	int aux;

	while (tmp != nullptr) {

		if (contador == i) {
			return aux = tmp->valor->getPrioridad();
		}
		contador++;
		tmp = tmp->sig;
	}
}

// Intercambia una llave de mayor prioridad con su nodo padre
// hasta que se mantenga la propiedad de Max Heap
template<class T>
void ColaPrioridad<T>::SiftUp(int i) {
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
int ColaPrioridad<T>::cantidad()
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
void ColaPrioridad<T>::CrearHeap()
{
	Nodo<T>* tmp = inicio;
	int cant = (cantidad()/2 - 1);
	for (int i = 0; cant >= i; i++) {
		Heapify(i);
		tmp = tmp->sig;
	}
}

/*template<class T>
void ColaPrioridad<T>::Iniciar()
{
	for (int i = 0; i < 10; i++) {
		Agregar(T);
	}
}



/*void ColaPrioridad::ReasignarMemoria() {
	int* tmp = cola;

	capacidad += 5;
	cola = new int[capacidad];

	for (int i = 0; i < tam; ++i) {
		cola[i] = tmp[i];
	}
	delete[] tmp;
}*/