#pragma once

#include "OperadorBinario.h"

class OperadorMultiplicacion : public OperadorBinario{

public:
	OperadorMultiplicacion();
	virtual ~OperadorMultiplicacion();
	virtual int compareTo(Elemento *);
	virtual void imprimir(ostream &) const;
	virtual Operando * operar(Lista<NodoArbol <Elemento*> *> *);
};