#include "stdafx.h"
#include "OperadorMultiplicacion.h"


OperadorMultiplicacion::OperadorMultiplicacion() :Operador(){
}


OperadorMultiplicacion::~OperadorMultiplicacion(){
}

int OperadorMultiplicacion::compareTo(Elemento * otro) {
	int cmp = -1; // No es necesario compararlo, siempre devuelve un -1.
	return cmp;
}

void OperadorMultiplicacion::imprimir(ostream& out) const {
	out << '*';
}

Operando * OperadorMultiplicacion::operar(Operando * a, Operando * b){
	return new Operando(a->getOperando() * b->getOperando());
}