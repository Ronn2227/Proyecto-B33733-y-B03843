#include "stdafx.h"
#include "OperadorTan.h"


OperadorTan::OperadorTan() : OperadorUnario() {
}


OperadorTan::~OperadorTan() {
}

int OperadorTan::compareTo(Elemento * otro) {
	int cmp = 0; // No es necesario compararlo, siempre devuelve un -1.
	return cmp;
}

void OperadorTan::imprimir(ostream& out) const {
	out << "tan";
}

Operando * OperadorTan::operar(Lista<NodoArbol <Elemento*> *> * hijos) {
	Operando* a = static_cast<Operando*>(hijos->buscarPorPosicion(0)->getActual());
	return new Operando(tan(a->getOperando()));
}