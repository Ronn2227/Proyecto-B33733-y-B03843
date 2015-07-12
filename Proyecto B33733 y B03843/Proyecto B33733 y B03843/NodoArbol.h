#pragma once

#include "Lista.h"

using namespace std;

template<class T>
class NodoArbol {

	template<class T>
	friend ostream & operator<<(ostream &, NodoLista<T> &);

private:

	T actual;
	Lista<NodoArbol<T>> hijos;

public:

	NodoArbol (T elemento) { // Estado inicial del Nodo.
		this->actual = elemento;
		hijoIzq = NULL;
		hijoDer = NULL;
	}	

	~NodoArbol(){
	}

	T & getActual() {
		return actual;
	}

	NodoArbol<T> *& getHijo(int indice) {
		return hijos.buscarPorPosicion(indice);
	}

	void setHijo(NodoArbol<T> * e) {
		hijos.insertarCola(e);
	}

	int getCantHijos() {
		return hijos.getSize();
	}

	Lista<NodoArbol<T>> getHijos() {
		return hijos;
	}

private:

	void imprimir(ostream & out) {
		out << actual;
	}

};

template<class T>
ostream & operator<<(ostream & out, NodoArbol<T> & n) {
	n.imprimir(out);
	return out;
}
