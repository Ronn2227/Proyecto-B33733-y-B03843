#pragma once

#include "Lista.h"

using namespace std;

template<class T>
class NodoArbol {

	template<class T>
	friend ostream & operator<<(ostream &, NodoLista<T> &);

private:

	T actual;
	NodoArbol<T> * padre;
	Lista<NodoArbol<T> *> * hijos;

public:

	NodoArbol (T elemento) { // Estado inicial del Nodo.
		this->actual = elemento;
		hijos = new Lista<NodoArbol<T> *>();
		padre = NULL;
	}	

	~NodoArbol(){
	}

	T & getActual() {
		return actual;
	}

	NodoArbol<T> *& getHijo(int indice) {
		return hijos->buscarPorPosicion(indice);
	}

	void setHijo(NodoArbol<T> * e) {
		hijos->insertarCola(e);
	}

	NodoArbol<T> *& getPadre(){
		return padre;
	}

	void setPadre(NodoArbol<T> *& padre){
		this->padre = padre;
	}

	int getCantHijos() {
		return hijos->getSize();
	}

	Lista<NodoArbol<T> *>*& getHijos() {
		return hijos;
	}

	void imprimir(NodoArbol<T> * nodo, ostream & out) { // Imprime el árbol.
		Operando* posibleOperando = dynamic_cast<Operando*>(nodo->getActual());
		if (posibleOperando != NULL)
		{
			cout << posibleOperando;
		}
		OperadorUnario * uni = dynamic_cast<OperadorUnario*>(nodo->getActual());
		if (uni != NULL) {
			nodo->getActual()->imprimir(out);
			cout << "( ";
			nodo->getHijo(0)->imprimir(nodo->getHijo(0), out);
			cout << " )"; nodo->getHijo(0);
		}
		OperadorBinario * bin = dynamic_cast<OperadorBinario*>(nodo->getActual());
		if (bin != NULL) {

			cout << "(";
			nodo->getHijo(0)->imprimir(nodo->getHijo(0), out);
			cout << ")";
			nodo->getActual()->imprimir(out);
			cout << "(";
			nodo->getHijo(1)->imprimir(nodo->getHijo(1), out);
			cout << ")";

		}
		OperadorTernario * ter = dynamic_cast<OperadorTernario*>(nodo->getActual());
		if (ter != NULL) {
			nodo->getActual()->imprimir(out);
			cout << "[";
			nodo->getHijo(0)->imprimir(nodo->getHijo(0), out);
			cout << ",";
			nodo->getHijo(1)->imprimir(nodo->getHijo(1), out);
			cout << ",";
			nodo->getHijo(2)->imprimir(nodo->getHijo(2), out);
			cout << "]";
		}
	}

};

template<class T>
ostream & operator<<(ostream & out, NodoArbol<T> *& n) {
	n->imprimir(n, out);
	return out;
}

