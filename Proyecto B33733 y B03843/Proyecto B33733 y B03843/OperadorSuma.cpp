#include "stdafx.h"
#include "OperadorSuma.h"


OperadorSuma::OperadorSuma() :Operador(){
}


OperadorSuma::~OperadorSuma(){
}

int OperadorSuma::compareTo(Elemento * otro) {
	int cmp = -1; // No es necesario compararlo, siempre devuelve un -1.
	return cmp;
}

void OperadorSuma::imprimir(ostream& out) const {
	out << '+';
}

Operando * OperadorSuma::operar(Operando * a, Operando * b){
	return new Operando(a->getOperando() + b->getOperando());
}