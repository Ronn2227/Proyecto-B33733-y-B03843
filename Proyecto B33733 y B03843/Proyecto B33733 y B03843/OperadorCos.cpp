#include "stdafx.h"
#include "OperadorCos.h"


OperadorCos::OperadorCos() : OperadorUnario()
{
}


OperadorCos::~OperadorCos()
{
}

int OperadorCos::compareTo(Elemento * otro) {
	int cmp = 0; // No es necesario compararlo, siempre devuelve un -1.
	return cmp;
}

void OperadorCos::imprimir(ostream& out) const {
	out << "cos";
}

Operando * OperadorCos::operar(Lista<NodoArbol <Elemento*>> hijos) {
	Operando* a = static_cast<Operando*>(hijos.buscarPorPosicion(0).getActual());
	return new Operando(cos(a->getOperando()));
}