#pragma once
#include "NodoLista.h"

using namespace std;

template<class T>
class IteradorLista {

private:
	NodoLista<T> * actual;

public:
	IteradorLista(NodoLista<T> * actual) {
		this->actual = actual;
	}

	~IteradorLista() {
	}

	IteradorLista<T>& operator++() { // Preincremento.
		if (actual->getNext() != NULL) {
			actual = actual->getNext();
		}
		else {
			actual = NULL;
		}
		return *this;
	}

	IteradorLista<T>& operator++(int) { // Posincremento.
		IteradorLista<T> tmp(this->actual);
		++(*this);
		return tmp;
	}

	IteradorLista<T>& operator--() { // Predecremento.
		if (actual->getPrev() != NULL) {
			actual = actual->getPrev();
		}
		else {
			actual = NULL;
		}
		return *this;
	}

	IteradorLista<T>& operator--(int) { // Posdecremento.
		IteradorLista<T> tmp(this->actual);
		--(*this);
		return tmp;
	}

	T operator*() {
		return actual->getActual();
	}

	bool operator!=(IteradorLista<T> & otro) {
		return this->actual != otro.actual;
	}

	bool operator==(IteradorLista<T> & otro) {
		return this->actual == otro.actual;
	}
};