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
	int buscarOperador(); // Busca dónde está el operador de menor precedencia en la operación y devuelve la posición donde lo encontró, ignorando paréntesis.
	int buscarParentesis(); // Busca dónde está el operador de menor precedencia en la operación y develve la posición donde lo encontro, dentro de paréntesis.
	string getOperacion(); // Devuelve la operación.
	static const int NUM_OPERADORES =10;
	static const char OPERADORES[NUM_OPERADORES];
};

