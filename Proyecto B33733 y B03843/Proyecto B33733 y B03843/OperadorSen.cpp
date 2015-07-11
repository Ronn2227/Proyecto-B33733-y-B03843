#include "stdafx.h"
#include "OperadorSen.h"


OperadorSen::OperadorSen() : OperadorUnario()
{
}


OperadorSen::~OperadorSen()
{
}

int OperadorSen::compareTo(Elemento * otro) {
	int cmp = 0; // No es necesario compararlo, siempre devuelve un -1.
	return cmp;
}

void OperadorSen::imprimir(ostream& out) const {
	out << "sen";
}

Operando * OperadorSen::operar(Lista<NodoArbol <Elemento*>> hijos) {
	Operando* a = static_cast<Operando*>(hijos.buscarPorPosicion(0).getActual());
	return new Operando(sin(a->getOperando()));
}