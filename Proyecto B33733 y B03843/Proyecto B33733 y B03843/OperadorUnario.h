#pragma once

#include "Operador.h"

class OperadorUnario : public Operador {

public:
	OperadorUnario();
	virtual ~OperadorUnario();
	virtual int compareTo(Elemento *) = 0;
	virtual void imprimir(ostream &) const = 0;
	virtual Operando * operar(Lista<NodoArbol <Elemento*>>) = 0;
};
