#pragma once

#include "Operador.h"

class OperadorTernario : public Operador {

public:
	OperadorTernario();
	~OperadorTernario();
	virtual int compareTo(Elemento *) = 0;
	virtual void imprimir(ostream &) const = 0;
	virtual Operando * operar(Lista<NodoArbol <Elemento*> *> *) = 0;
};

