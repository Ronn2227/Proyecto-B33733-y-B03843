#include "stdafx.h"
#include "OperadorSuma.h"


OperadorSuma::OperadorSuma() :OperadorBinario(){

}


OperadorSuma::~OperadorSuma(){
}

int OperadorSuma::compareTo(Elemento * otro) {
	int cmp = 0; 
	return cmp;
}

void OperadorSuma::imprimir(ostream& out) const {
	out << '+';
}

Operando * OperadorSuma::operar(Lista<NodoArbol <Elemento*>> hijos){
	Operando* a = static_cast<Operando*>(hijos.buscarPorPosicion(0).getActual());
	Operando* b = static_cast<Operando*>(hijos.buscarPorPosicion(1).getActual());
	return new Operando(a->getOperando() + b->getOperando());
}