#include "stdafx.h"
#include "OperadorFuncion.h"


OperadorFuncion::OperadorFuncion() : OperadorTernario() {
}


OperadorFuncion::~OperadorFuncion() {
}


int OperadorFuncion::compareTo(Elemento * otro) {
	int cmp = 0; // No es necesario compararlo, siempre devuelve un -1.
	return cmp;
}

void OperadorFuncion::imprimir(ostream& out) const {
	out << "f";
}

Operando * OperadorFuncion::operar(Lista<NodoArbol <Elemento*> *> * hijos) {
	Operando* a = static_cast<Operando*>(hijos->buscarPorPosicion(0)->getActual());
	Operando* b = static_cast<Operando*>(hijos->buscarPorPosicion(1)->getActual());
	Operando* c = static_cast<Operando*>(hijos->buscarPorPosicion(2)->getActual());
	return new Operando(b->getOperando()*c->getOperando()/a->getOperando());
}