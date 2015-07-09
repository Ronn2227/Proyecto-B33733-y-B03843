#include "stdafx.h"
#include "Elemento.h"


Elemento::Elemento() {
}

Elemento::Elemento(Elemento & otro) {
}


Elemento::~Elemento() {
}

ostream & operator<<(ostream & out, const Elemento & e) {
	e.imprimir(out);
	return out;
}

ostream & operator<<(ostream & out, const Elemento * e) {
	return out << *e;
}

bool Elemento::operator <(Elemento& otro) {
	return this->compareTo(&otro) < 0;
}

bool Elemento::operator <=(Elemento& otro) {
	return this->compareTo(&otro) <= 0;
}

bool Elemento::operator >(Elemento& otro) {
	return this->compareTo(&otro) > 0;
}

bool Elemento::operator >=(Elemento& otro) {
	return this->compareTo(&otro) >= 0;
}