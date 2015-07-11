#pragma once

#include "OperadorBinario.h"

class OperadorSuma : public OperadorBinario {

public:
	OperadorSuma();
	virtual ~OperadorSuma();

	virtual int compareTo(Elemento *);
	virtual void imprimir(ostream &) const;
	virtual Operando * operar(Lista<NodoArbol <Elemento*>>);
};