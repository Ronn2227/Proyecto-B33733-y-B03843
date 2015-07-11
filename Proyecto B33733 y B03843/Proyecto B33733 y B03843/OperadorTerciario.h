#pragma once

#include "Operador.h"

class OperadorTerciario : public Operador
{
public:
	OperadorTerciario();
	~OperadorTerciario();
	virtual int compareTo(Elemento *) = 0;
	virtual void imprimir(ostream &) const = 0;
	virtual Operando * operar(Lista<NodoArbol <Elemento*>>) = 0;
};

