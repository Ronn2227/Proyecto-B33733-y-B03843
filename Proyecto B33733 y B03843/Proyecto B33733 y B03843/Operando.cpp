#include "stdafx.h"
#include "Operando.h"


Operando::Operando(double d) :Elemento() {
	this->operando = d;
}


Operando::~Operando() {
}

int Operando::compareTo(Elemento* otro) {
	int cmp = 0;
	Operando * eDouble = static_cast<Operando *>(otro);
	if (eDouble != 0){
		cmp = this->operando < eDouble->operando ? -1 : this->operando == eDouble->operando ? 0 : 1; // Se compara con otro double.
	}
	return cmp;
}

void Operando::imprimir(ostream& out) const {
	out << operando;
}

double Operando::getOperando() {
	return operando;
}