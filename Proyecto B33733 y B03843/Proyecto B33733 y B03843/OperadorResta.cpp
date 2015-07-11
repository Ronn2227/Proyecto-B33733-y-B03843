#include "stdafx.h"
#include "OperadorResta.h"


OperadorResta::OperadorResta() :OperadorBinario(){
}


OperadorResta::~OperadorResta(){
}

int OperadorResta::compareTo(Elemento * otro) {
	int cmp = -1; // No es necesario compararlo, siempre devuelve un -1.
	return cmp;
}

void OperadorResta::imprimir(ostream& out) const {
	out << '-';
}

Operando * OperadorResta::operar(Lista<NodoArbol <Elemento*>> hijos) {
	Operando* a = static_cast<Operando*>(hijos.buscarPorPosicion(0).getActual());
	Operando* b = static_cast<Operando*>(hijos.buscarPorPosicion(1).getActual());
	return new Operando(a->getOperando() - b->getOperando());
}