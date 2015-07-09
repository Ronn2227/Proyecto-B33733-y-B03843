#pragma once

#include "Elemento.h"
#include "Operando.h"

using namespace std;

class Operador : public Elemento {

public:
	Operador();
	virtual ~Operador();

	virtual Operando * operar(Operando*, Operando *) = 0; // Hace la operaci�n correspodiente entre dos operandos y deuelve un Operando con el resultado.
	virtual int compareTo(Elemento *) = 0;
	virtual void imprimir(ostream &) const = 0;
};
