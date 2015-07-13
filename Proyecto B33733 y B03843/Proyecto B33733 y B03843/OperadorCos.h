#pragma once

#include "OperadorUnario.h"

class OperadorCos : public OperadorUnario {

public:
	OperadorCos();
	virtual ~OperadorCos();

	virtual int compareTo(Elemento *);
	virtual void imprimir(ostream &) const;
	virtual Operando * operar(Lista<NodoArbol <Elemento*> *> *);
};