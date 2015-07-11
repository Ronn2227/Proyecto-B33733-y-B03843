#pragma once

#include "Elemento.h"

using namespace std;

class Operacion : public Elemento {

protected:

	string operacion;

public:

	Operacion(string oper);
	Operacion(Operacion &);

	virtual ~Operacion();
	virtual int compareTo(Elemento *);
	virtual void imprimir(ostream &) const;
	int buscarOperador(); // Busca d�nde est� el operador de menor precedencia en la operaci�n y devuelve la posici�n donde lo encontr�, ignorando par�ntesis.
	int buscarParentesis(); // Busca d�nde est� el operador de menor precedencia en la operaci�n y develve la posici�n donde lo encontro, dentro de par�ntesis.
	string getOperacion(); // Devuelve la operaci�n.
	static const int NUM_OPERADORES =10;
	static const char OPERADORES[NUM_OPERADORES];
};

