#pragma once

#include "NodoLista.h"
#include "IteradorLista.h"

using namespace std;

template<class T>
class Lista {

	template<class T>
	friend ostream & operator<<(ostream &, Lista<T> &);

private:

	NodoLista<T> * cabeza;
	NodoLista<T> * cola;
	int size;

public:

	Lista() { // Estado inicial de la lista.
		size = 0;
		cabeza = NULL;
		cola = NULL;
	}

	~Lista() {
		if (cabeza != NULL) {
			destruirLista();
		}
	}

	void insertarCabeza(T elemento) {
		NodoLista<T> * nodo = new NodoLista<T>(elemento);
		if (cabeza == NULL) { // Si la cabeza est� vac�a solo asigna (si solo hay un Nodo la cabeza y la cola aputan al mimo lugar).
			cabeza = nodo;
			cabeza->setPrev(NULL);
			cabeza->setNext(NULL);
			cola = nodo;
			cola->setPrev(NULL);
			cola->setNext(NULL);
		}
		else { // Si no est� vac�a mueve a todos los Nodos.
			cabeza->setPrev(nodo);
			nodo->setNext(cabeza);
			cabeza = nodo;
			cabeza->setPrev(NULL);
		}
		size++;
	}

	void insertarCola(T elemento) {
		NodoLista<T> * nodo = new NodoLista<T>(elemento);
		if (cola == NULL) { // Si la cola est� vac�a solo asigna.
			cola = nodo;
			cola->setPrev(NULL);
			cola->setNext(NULL);
			cabeza = nodo;
			cabeza->setPrev(NULL);
			cabeza->setNext(NULL);
		}
		else { // Si no lo inserta al final.
			cola->setNext(nodo);
			nodo->setPrev(cola);
			cola = nodo;
			cola->setNext(NULL);
		}
		size++;
	}

	void insertarNodo(T elemento, int donde) { // Inserta un Nodo de la lista seg�n una posici�n.
		NodoLista<T> * nodo = new NodoLista<T>(elemento);
		if (donde <= 0 || size == 0) { // Si la direcci�n es 0 (o menos para evitar excepciones) o si no hay ning�n Nodo en la lista (tambi�n para evitar excepciones) se inserta el Nodo en la cabeza.
			insertarCabeza(elemento);
		}
		else if (donde >= size) { // Si la direcci�n es igual al tama�o (posicion siguiente a la ultima) o mayor (tambi�n para evitar excepciones) se inserta el Nodo en la cola.
			insertarCola(elemento);
		}
		else if (donde == size - 1) { // si la direcci�n es igual al tama�o-1 (posici�n actual de la cola) se inserta ahi y se mueve la cola.
			cola->getPrev()->setNext(nodo);
			nodo->setPrev(cola->getPrev());
			nodo->setNext(cola);
			cola->setPrev(nodo);
			size++;
		}
		else { // Si no avanza hasta la posicion deseada y lo inserta en ese lugar.
			if (donde <= size / 2) {
				NodoLista<T> * actual = cabeza;
				for (int i = 0; i < donde - 1; i++) { // Avanza en la lista hasta el Nodo anterior a donde se quiere insertar.
					actual = actual->getNext();
				}
				NodoLista<T> * temp = actual->getNext();
				actual->setNext(nodo);
				nodo->setPrev(actual);
				nodo->setNext(temp);
				temp->setPrev(nodo);
			}
			else {
				NodoLista<T> * actual = cola;
				for (int i = size - 1; i > donde + 1; i--) { // Avanza en la lista hasta el Nodo siguiente a donde se quiere insertar.
					actual = actual->getPrev();
				}
				NodoLista<T> * temp = actual->getPrev();
				actual->setPrev(nodo);
				nodo->setNext(actual);
				nodo->setPrev(temp);
				temp->setNext(nodo);
			}
			size++;
		}
	}

	void removerCabeza() {
		if (cabeza != NULL) {
			if (cabeza->getNext() != NULL) { // Si hay m�s de un Nodo elimina la cabeza y asigna la cabeza a la siguiente posici�n.
				NodoLista<T> * temp = cabeza;
				cabeza = cabeza->getNext();
				cabeza->setPrev(NULL);
				delete temp;
			}
			else { // Si solo hay uno, lo borra y vuelve al estado inicial.
				NodoLista<T> * temp = cabeza;
				cabeza = NULL;
				cola = NULL;
				delete temp;
			}
			size--;
		}
	}

	void removerCola() {
		if (cola != NULL) {
			if (size == 1) { // Si solo hay un Nodo lo borra y vuelve al estado inicial.
				NodoLista<T> * temp = cola;
				cola = NULL;
				cabeza = NULL;
				delete temp;
			}
			else { // Si hay m�s de uno elimina la cola y asigna la cola al pen�ltimo.
				NodoLista<T> * temp = cola;
				cola = cola->getPrev();
				cola->setNext(NULL);
				delete temp;
			}
			size--;
		}
	}

	void removerNodo(int donde) { // Remueve un Nodo de la lista seg�n una posici�n.
		if (cabeza != NULL) {
			if (donde <= 0 || size == 1) { // Si la direcci�n es 0 (o menor) o solo hay un Nodo se elimina la cabeza.
				removerCabeza();
			}
			else if (donde >= size - 1) { // Si la direcci�n es igual al tama�o-1 o mayor se elimina la cola.
				removerCola();
			}
			else { // Si no avanza hasta la posici�n del Nodo a elmininar y se elimina.
				if (donde <= size / 2) {
					NodoLista<T> * actual = cabeza;
					for (int i = 0; i < donde - 1; i++) { // Avanza en la lista hasta el Nodo anterior al que se quiere eliminar.
						actual = actual->getNext();
					}
					NodoLista<T> * borrar = actual->getNext();
					actual->setNext(actual->getNext()->getNext());
					actual->getNext()->setPrev(actual);
					delete borrar;
				}
				else {
					NodoLista<T> * actual = cola;
					for (int i = size - 1; i > donde + 1; i--) { // Avanza en la lista hasta el Nodo siguiente al que se quiere eliminar.
						actual = actual->getPrev();
					}
					NodoLista<T> * borrar = actual->getPrev();
					actual->setPrev(actual->getPrev()->getPrev());
					actual->getPrev()->setNext(actual);
					delete borrar;
				}
				size--;
			}
		}
	}

	int buscarPorNodo(T elemento) { // Busca un Nodo en la lista y devuelve la posici�n donde lo encontr� (El primero que encuentra).
		NodoLista<T> * nodo = new NodoLista<T>(elemento);
		bool encontrado = false;
		int posicion = -1; // Posici�n a devolver, si no lo encuentra devuelve un -1.
		int contador = 0;
		NodoLista<T> * actual = cabeza;
		while (encontrado == false && actual->getNext() != NULL) { // Avanza buscando hasta que lo encuentre o ya no haya m�s Nodos.
			if (actual->compareTo(nodo) == 0) {
				posicion = contador;
				encontrado = true;
			}
			else {
				actual = actual->getNext();
				contador++;
			}
		}
		if (actual->compareTo(nodo) == 0) { // Se sale del ciclo antes de comprobar el �ltimo as� que se comprueba afuera.
			posicion = contador;
		}
		return posicion;
	}

	T buscarPorPosicion(int posicion) { // Devuelve el Nodo seg�n una posici�n.
		NodoLista<T> * actual = cabeza; // Nodo a devolver.
		if (posicion <= 0){ // Si la direcci�n es 0 (o menor) se devuelve la cabeza.
			actual = cabeza;
		}
		else if (posicion >= size - 1) { // Si la direcci�n es igual al tama�o-1 o mayor se devuelve la cola.
			actual = cola;
		}
		else {
			if (posicion <= size / 2) {
				for (int i = 0; i < posicion; i++) { // Si es menor que la mitad avanza hasta la posici�n solicitada y la devuelve.
					actual = actual->getNext();
				}
			}
			else {
				actual = cola;
				for (int i = size - 1; i > posicion; i--) { // Si no retrocede hasta la posici�n solicitada y la devuelve.
					actual = actual->getPrev();
				}
			}
		}
		return actual->getActual();
	}

	int getSize() { // Devuelve el tama�o de la lista (cantidad de Nodos).
		return size;
	}

	IteradorLista<T> begin() { // Devuelve itarador que apunta a la cabeza para que recorra hacia adelante.
		return IteradorLista<T>(cabeza);
	}

	IteradorLista<T> rBegin() { // Devuelve iterador que apunta a la cola para que recorra hacia atras.
		return IteradorLista<T>(cola);
	}

	IteradorLista<T> end() {
		return IteradorLista<T>(NULL);
	}

	IteradorLista<T> rEnd() {
		return IteradorLista<T>(NULL);
	}
	

private:

	void imprimir(NodoLista<T> * nodo, ostream & out) { // Devuelve un out que sirve para imprimir la lista.
		NodoLista<T> * actual = nodo;
		while (actual->getNext() != NULL) {
			out << *actual << endl;
			actual = actual->getNext();
		}
		out << *actual << endl;
	}

	void destruirLista() { // Destruye la lista.
		int tam = size;
		for (int i = 0; i < tam; i++) {
			removerCabeza();
		}
	}
};

template<class T>
ostream & operator<<(ostream & out, Lista<T> & l) {
	l.imprimir(l.cabeza, out);
	return out;
}