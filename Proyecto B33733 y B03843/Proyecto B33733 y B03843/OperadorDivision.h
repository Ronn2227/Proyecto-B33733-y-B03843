#pragma once

#include "Operador.h"

class OperadorDivision : public Operador{

public:
	OperadorDivision();
	virtual ~OperadorDivision();

	virtual int compareTo(Elemento *);
	virtual void imprimir(ostream &) const;
	virtual Operando * operar(Operando*, Operando *);
};