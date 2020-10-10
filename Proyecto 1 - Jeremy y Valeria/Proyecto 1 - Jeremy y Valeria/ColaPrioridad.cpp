#include "ColaPrioridad.h"

// Constructor a partir de un tamaño definido por el usuario
ColaPrioridad::ColaPrioridad(){
	inicio = nullptr;
	
}

/*ColaPrioridad::ColaPrioridad() {


}*/

// Constructor de copia
ColaPrioridad::ColaPrioridad(ColaPrioridad& c) {
	//cola = nullptr; 
	if (c.inicio == nullptr) {
		inicio = nullptr;
	}
	else {
		inicio = new Nodo(c.inicio->valor);
		Nodo* tmp = inicio;
		Nodo* tmp_obj = c.inicio->sig;
		while (tmp_obj != nullptr) {
			tmp->sig = new Nodo(tmp_obj->valor);
			tmp_obj->anterior = tmp;
			tmp = tmp->sig;
			tmp_obj = tmp_obj->sig;

		}

	}
}

// Destructor - libera toda la memoria asignada a la cola de prioridad
ColaPrioridad::~ColaPrioridad() {
	delete[] inicio;
}

void ColaPrioridad::Agregar(int val) {
	int cont = 0;

	Nodo* nodo = new Nodo();
	nodo->valor = val;
	nodo->sig = nullptr;
	nodo->anterior = nullptr;

	if (inicio == nullptr) {
		inicio = nodo;

	}
	else {
		Nodo* tmp = inicio;
		while (tmp->sig != nullptr) {
			tmp = tmp->sig;
			tmp->sig = nodo;
			nodo->anterior = tmp;
			cont++;
		}

	}


	//SiftUp(tam - 1);
}

// Retorna el valor con mayor prioridad de la cola
int ColaPrioridad::GetMax() {
	if (inicio != nullptr) {
		return inicio ->valor;
	}
	return -1;
}

// Retorna el valor con mayor prioridad de la cola y lo elimina
int ColaPrioridad::ExtraerMax() {
	if (inicio == 0) {
		return -1;
	}

	// Intercambia el elemento con mayor prioridad de la cola con el último
	// y procede a realizar un bubble down para mantener la propiedad de heap
	int conta = 0;
	Nodo* tmp = new Nodo();
	Nodo* tmp2 = new Nodo();
	//tmp->valor=	inicio->valor;
	tmp = inicio;
	int dato;
	while (tmp != nullptr) {
		if (tmp->sig == nullptr) {
			tmp2->valor = inicio->valor;
			dato = inicio->valor;
			inicio->valor = tmp->valor;
			tmp->sig = tmp2->sig;
			delete tmp2;			
		}
		tmp = tmp2;
		tmp2 = tmp2->sig;
	}
	
	MaxHeapify(0);
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
int ColaPrioridad::GetPadre(int i) {

	int contador =0;

	Nodo* tmp = new Nodo();
	tmp = inicio;
	int aux;

	while (tmp!= nullptr) {
		
		if (contador == ((i - 1) / 2)) {
			aux = tmp->valor;
			return aux;
		}
		contador++;
		tmp = tmp->sig;
	}


/*	if (i < 0 || i > tam)
		return -1;

	return (i - 1) / 2;*/
}

// Obtiene el índice del hijo izquierdo para la posición dada
int ColaPrioridad::GetHijoIzquierdo(int i) {

	int contador = 0;

	Nodo* tmp = new Nodo();
	tmp = inicio;
	int aux;

	while (tmp != nullptr) {

		if (contador == ((2*i)+1)) {
			aux = tmp->valor;
			return aux;
		}
		contador++;
		tmp = tmp->sig;
	}

	/*if (i < 0 || i > tam)
		return -1;

	return 2 * i + 1;*/
}

// Obtiene el índice del hijo derecho para la posición dada
int ColaPrioridad::GetHijoDerecho(int i) {
	int contador = 0;

	Nodo* tmp = new Nodo();
	tmp = inicio;
	int aux;

	while (tmp != nullptr) {

		if (contador == ((2*i)+2)) {
			aux = tmp->valor;
			return aux;
		}
		contador++;
		tmp = tmp->sig;
	}



	/*if (i < 0 || i > tam)
		return -1;

	return 2 * i + 2;*/
}

// Intercambia dos elementos de la cola
void ColaPrioridad::Swap(int x, int y) {
	int tmp = cola[x];
	cola[x] = cola[y];
	cola[y] = tmp;
}

// Mantiene la propiedad de Heap - movimiento hacia abajo "bubble down - sift down"
// Revisa que el nodo de la posición dada cumpla la propiedad de Heap. En caso contrario
// Intercambia las llaves para mantener la propiedad de Max Heap
void ColaPrioridad::MaxHeapify(int i) {
	int izq = GetHijoIzquierdo(i);
	int der = GetHijoDerecho(i);
	int tmp = 0;

	// Se comparan los hijos izquierdo y derecho con la posición dada
	// y se almacena el índice mayor
	if (izq < tam && cola[izq] > cola[i]) {
		tmp = izq;
	}
	else {
		tmp = i;
	}

	if (der < tam && cola[der] > cola[tmp]) {
		tmp = der;
	}

	// Si alguno de los hijos es más grande que la posición
	// se intercambia la posición con el hijo mayor. El proceso continúa
	// hacia abajo (bubble down - sift down)
	if (tmp != i) {
		Swap(i, tmp);
		MaxHeapify(tmp);
	}
}

// Intercambia una llave de mayor prioridad con su nodo padre
// hasta que se mantenga la propiedad de Max Heap
void ColaPrioridad::SiftUp(int i) {
	int tmp = GetPadre(i);

	// Bubble up - sift up
	while (i > 0 && cola[tmp] < cola[i]) {
		Swap(i, tmp);
		i = tmp;
		tmp = GetPadre(i);
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