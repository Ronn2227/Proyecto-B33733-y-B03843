#pragma once

using namespace std;

template<class T>
class NodoArbol {

	template<class T>
	friend ostream & operator<<(ostream &, NodoLista<T> &);

private:

	T actual;
	NodoArbol<T> *hijoIzq, *hijoDer; // Hijo izquierdo y derecho del nodo respectivamente.

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

	NodoArbol<T> *& getHijoIzq() {
		return hijoIzq;
	}

	NodoArbol<T> *& getHijoDer() {
		return hijoDer;
	}

	void setHijoIzq(NodoArbol<T> * e) {
		this->hijoIzq = e;
	}

	void setHijoDer(NodoArbol<T> * e) {
		this->hijoDer = e;
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
