#include "stdafx.h"
#include "OperadorLog.h"


OperadorLog::OperadorLog() : OperadorUnario() {
}


OperadorLog::~OperadorLog() {
}

int OperadorLog::compareTo(Elemento * otro) {
	int cmp = 0; // No es necesario compararlo, siempre devuelve un -1.
	return cmp;
}

void OperadorLog::imprimir(ostream& out) const {
	out << "ln";
}

Operando * OperadorLog::operar(Lista<NodoArbol <Elemento*> *> * hijos) {
	Operando* a = static_cast<Operando*>(hijos->buscarPorPosicion(0)->getActual());
	return new Operando(log(a->getOperando()));
}