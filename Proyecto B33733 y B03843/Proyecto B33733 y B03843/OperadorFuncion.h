#pragma once

#include "OperadorTernario.h"

class OperadorFuncion : public OperadorTernario {

public:
	OperadorFuncion();
	virtual ~OperadorFuncion();

	virtual int compareTo(Elemento *);
	virtual void imprimir(ostream &) const;
	virtual Operando * operar(Lista<NodoArbol <Elemento*> *> *);
};