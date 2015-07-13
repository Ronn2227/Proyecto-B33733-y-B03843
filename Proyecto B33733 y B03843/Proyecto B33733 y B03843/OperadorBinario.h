#pragma once

#include "Operador.h"

class OperadorBinario : public Operador {

public:
	OperadorBinario();
	virtual ~OperadorBinario();
	virtual int compareTo(Elemento *) = 0;
	virtual void imprimir(ostream &) const = 0;
	virtual Operando * operar(Lista<NodoArbol <Elemento*> *> *) = 0;
};