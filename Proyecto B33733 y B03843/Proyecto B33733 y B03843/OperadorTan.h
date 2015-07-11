#pragma once

#include "OperadorUnario.h"

class OperadorTan : public OperadorUnario {

public:
	OperadorTan();
	virtual ~OperadorTan();

	virtual int compareTo(Elemento *);
	virtual void imprimir(ostream &) const;
	virtual Operando * operar(Lista<NodoArbol <Elemento*>>);
};