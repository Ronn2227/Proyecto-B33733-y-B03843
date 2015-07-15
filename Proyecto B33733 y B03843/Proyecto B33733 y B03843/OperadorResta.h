#pragma once

#include "OperadorBinario.h"

class OperadorResta : public OperadorBinario {

public:
	OperadorResta();
	virtual ~OperadorResta();
	virtual int compareTo(Elemento *);
	virtual void imprimir(ostream &) const;
	virtual Operando * operar(Lista<NodoArbol <Elemento*> *> *);
};