#pragma once

#include "OperadorUnario.h"

class OperadorSen : public OperadorUnario {

public:
	OperadorSen();
	virtual ~OperadorSen();

	virtual int compareTo(Elemento *);
	virtual void imprimir(ostream &) const;
	virtual Operando * operar(Lista<NodoArbol <Elemento*> *> *);
};