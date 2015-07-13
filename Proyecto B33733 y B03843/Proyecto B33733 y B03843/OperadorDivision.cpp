#include "stdafx.h"
#include "OperadorDivision.h"


OperadorDivision::OperadorDivision() :OperadorBinario() {
}


OperadorDivision::~OperadorDivision() {
}

int OperadorDivision::compareTo(Elemento * otro) {
	int cmp = 0; // No es necesario compararlo, siempre devuelve un -1.
	return cmp;
}

void OperadorDivision::imprimir(ostream& out) const {
	out << '/';
}

Operando * OperadorDivision::operar(Lista<NodoArbol <Elemento*> *> * hijos) {
	Operando* a = static_cast<Operando*>(hijos->buscarPorPosicion(0)->getActual());
	Operando* b = static_cast<Operando*>(hijos->buscarPorPosicion(1)->getActual());
	return new Operando(a->getOperando() * b->getOperando());
}