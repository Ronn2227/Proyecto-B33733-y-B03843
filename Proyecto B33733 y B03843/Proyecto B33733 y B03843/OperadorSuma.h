#pragma once

#include "Operador.h"

class OperadorSuma : public Operador {

public:
	OperadorSuma();
	virtual ~OperadorSuma();

	virtual int compareTo(Elemento *);
	virtual void imprimir(ostream &) const;
	virtual Operando * operar(Operando*, Operando *);
};