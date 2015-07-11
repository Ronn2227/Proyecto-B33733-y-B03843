#pragma once

#include "OperadorTerciario.h"

class OperadorFuncion : public OperadorTerciario {

public:
	OperadorFuncion();
	virtual ~OperadorFuncion();

	virtual int compareTo(Elemento *);
	virtual void imprimir(ostream &) const;
	virtual Operando * operar(Lista<NodoArbol <Elemento*>>);
};