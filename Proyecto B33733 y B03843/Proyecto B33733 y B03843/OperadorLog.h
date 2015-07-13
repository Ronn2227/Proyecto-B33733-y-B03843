#pragma once

#include "OperadorUnario.h"

class OperadorLog : public OperadorUnario {

public:
	OperadorLog();
	virtual ~OperadorLog();

	virtual int compareTo(Elemento *);
	virtual void imprimir(ostream &) const;
	virtual Operando * operar(Lista<NodoArbol <Elemento*> *> *);
};