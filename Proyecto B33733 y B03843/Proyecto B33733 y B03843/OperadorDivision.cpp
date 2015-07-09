#include "stdafx.h"
#include "OperadorDivision.h"


OperadorDivision::OperadorDivision() :Operador(){
}


OperadorDivision::~OperadorDivision(){
}

int OperadorDivision::compareTo(Elemento * otro) {
	int cmp = -1; // No es necesario compararlo, siempre devuelve un -1.
	return cmp;
}

void OperadorDivision::imprimir(ostream& out) const {
	out << '/';
}

Operando * OperadorDivision::operar(Operando * a, Operando * b){
	return new Operando(a->getOperando() / b->getOperando());
}