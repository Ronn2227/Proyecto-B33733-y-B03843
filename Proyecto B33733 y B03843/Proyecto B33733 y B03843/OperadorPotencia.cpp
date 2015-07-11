#include "stdafx.h"
#include "OperadorPotencia.h"


OperadorPotencia::OperadorPotencia() : OperadorBinario()
{
}


OperadorPotencia::~OperadorPotencia()
{
}

int OperadorPotencia::compareTo(Elemento * otro) {
	int cmp = 0; // No es necesario compararlo, siempre devuelve un -1.
	return cmp;
}

void OperadorPotencia::imprimir(ostream& out) const {
	out << '^';
}

Operando * OperadorPotencia::operar(Lista<NodoArbol <Elemento*>> hijos) {
	Operando* a = static_cast<Operando*>(hijos.buscarPorPosicion(0).getActual());
	Operando* b = static_cast<Operando*>(hijos.buscarPorPosicion(1).getActual());
	return new Operando(pow(a->getOperando() , b->getOperando()));
}