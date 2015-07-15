#pragma once

#include "NodoArbol.h"

using namespace std;

template<class T>
class IteradorArbol {

private:
	NodoArbol<T> * anterior;
	NodoArbol<T> * actual;

public:

	IteradorArbol(NodoArbol<T> * actual) {
		this->actual = actual;
		this->anterior = actual;
	}

	~IteradorArbol() {
	}

	// Preincremento
	IteradorArbol<T> & operator ++() {
		bool continuar = true;
		while (continuar && actual != NULL) {
			continuar = false;
			NodoArbol<T> * tmp = actual;
			if (actual->getCantHijos() == 3){
				if (anterior == actual->getHijo(0)) {
					actual = actual->getHijo(1);
				}
				else if (anterior == actual->getHijo(1)) {
					actual = actual->getHijo(2);
				}
				else if (anterior == actual->getHijo(2)) {
					actual = actual->getPadre();
					continuar = true;
				}
				else if (anterior == actual->getPadre()) {
					actual = actual->getHijo(0);
				}
				anterior = tmp;
			}
			else if (actual->getCantHijos() == 2) {
				if (anterior == actual->getHijo(0)){
					actual = actual->getHijo(1);
				}
				else if (anterior == actual->getHijo(1)) {
					actual = actual->getPadre();
					continuar = true;
				}
				else {
					actual = actual->getHijo(0);
				}
				anterior = tmp;
			}
			else if (actual->getCantHijos() == 1) {
				if (anterior == actual->getHijo(0)) {
					actual = actual->getPadre();
					continuar = true;
				}
				else if (anterior == actual->getPadre()) {
					actual = actual->getHijo(0);
				}
				anterior = tmp;
			}
			else {
				actual = actual->getPadre();
				continuar = true;
				anterior = tmp;
			}
		}
		return *this;
	}

	// Posincremento
	IteradorArbol<T>& operator++(int) {
		IteradorArbol<T> tmp(this->actual);
		++(*this);
		return tmp;
	}

	T operator*() {
		return actual->getActual();
	}

	bool operator!=(IteradorArbol<T> & otro) {
		return this->actual != otro.actual;
	}

	bool operator==(IteradorArbol<T> & otro) {
		return this->actual == otro.actual;
	}
};

