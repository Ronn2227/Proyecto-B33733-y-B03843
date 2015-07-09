#pragma once

#include "Operador.h"

class OperadorMultiplicacion : public Operador{

public:
	OperadorMultiplicacion();
	virtual ~OperadorMultiplicacion();

	virtual int compareTo(Elemento *);
	virtual void imprimir(ostream &) const;
	virtual Operando * operar(Operando*, Operando *);
};