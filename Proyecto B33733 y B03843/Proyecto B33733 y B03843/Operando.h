#pragma once

#include "Elemento.h"

using namespace std;

class Operando : public Elemento {

protected:
	double operando;

public:
	Operando(double d);
	virtual ~Operando();
	virtual int compareTo(Elemento *);
	virtual void imprimir(ostream &) const;
	double getOperando(); // Devuelve el operando.
};



