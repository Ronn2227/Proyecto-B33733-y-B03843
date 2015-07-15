#pragma once


#include "OperadorBinario.h"

class OperadorPotencia : public OperadorBinario {

public:
	OperadorPotencia();
	virtual ~OperadorPotencia();
	virtual int compareTo(Elemento *);
	virtual void imprimir(ostream &) const;
	virtual Operando * operar(Lista<NodoArbol <Elemento*> *> *);
};
