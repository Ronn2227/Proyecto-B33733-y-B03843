#pragma once

#include "Operador.h"

class OperadorResta : public Operador {

public:
	OperadorResta();
	virtual ~OperadorResta();

	virtual int compareTo(Elemento *);
	virtual void imprimir(ostream &) const;
	virtual Operando * operar(Operando*, Operando *);
};