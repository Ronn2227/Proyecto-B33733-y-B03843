#include "stdafx.h"
#include "OperadorResta.h"


OperadorResta::OperadorResta() :Operador(){
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

Operando * OperadorResta::operar(Operando * a, Operando * b){
	return new Operando(a->getOperando() - b->getOperando());
}