#pragma once

#include "OperadorBinario.h"

class OperadorDivision : public OperadorBinario{

public:
	OperadorDivision();
	virtual ~OperadorDivision();

	virtual int compareTo(Elemento *);
	virtual void imprimir(ostream &) const;
	virtual Operando * operar(Lista<NodoArbol <Elemento*>>);
};