#pragma once

using namespace std;

template<class T>
class NodoLista {

	template<class T>
	friend ostream & operator<<(ostream &, NodoLista<T> &);

private:

	T actual;
	NodoLista<T> *prev, *next; // Anterior y siguiente respectivamente.

public:

	NodoLista(T elemento) { // Estado inicial del Nodo.
		this->actual = elemento;
		prev = NULL;
		next = NULL;
	}

	~NodoLista() {
	}

	T & getActual() {
		return actual;
	}

	NodoLista<T> *& getPrev() {
		return prev;
	}

	NodoLista<T> *& getNext() {
		return next;
	}

	void setPrev(NodoLista<T> * e) {
		this->prev = e;
	}

	void setNext(NodoLista<T> * e) {
		this->next = e;
	}

private:

	void imprimir(ostream & out) {
		out << actual;
	}

};

template<class T>
ostream & operator<<(ostream & out, NodoLista<T> & n) {
	n.imprimir(out);
	return out;
}

