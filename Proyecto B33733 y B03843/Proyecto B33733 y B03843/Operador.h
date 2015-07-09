#pragma once

#include "Elemento.h"
#include "Operando.h"
#include "Lista.h"

using namespace std;

class Operador : public Elemento {

public:
	Operador();
	Operador(Operador &);
	virtual ~Operador();

	//virtual Operando * operar(Lista<Elemento *> operandos) = 0;

	virtual Operando * operar(Operando*, Operando *) = 0; // Hace la operación correspodiente entre dos operandos y deuelve un Operando con el resultado.
	virtual int compareTo(Elemento *) = 0;
	virtual void imprimir(ostream &) const = 0;
};

