#include "stdafx.h"
#include "Operacion.h"

const char Operacion::OPERADORES[Operacion::NUM_OPERADORES] = { '+', '-', '*', '/' , '^', 's' , 'c', 't', 'l', 'f'};

Operacion::Operacion(string oper) : Elemento() {
	this->operacion = oper;
}

Operacion::Operacion(Operacion & otro) : Operacion(otro.operacion) {
}

Operacion::~Operacion(){
}

int Operacion::compareTo(Elemento * otro){
	int cmp = 0;
	Operacion * oper = static_cast<Operacion *>(otro);
	if (oper != 0){
		cmp = this->operacion.compare(oper->operacion); // Compara Elementos Operacion por el string.
	}
	return cmp;
}

void Operacion::imprimir(ostream& out) const{
	out << operacion;
}

int Operacion::buscarOperador(){
	int index = -1;
	int parentesis = 0;
	for (int k = 0; k < NUM_OPERADORES && index == -1; k++) {
		for (unsigned int i = 0; i < operacion.length() && index == -1; ++i) {
			char c = operacion[i];
			if (c == '(') {
				parentesis++;
			}
			else if (c == ')') {
				parentesis--;
			}
			else if (parentesis == 0 && c == OPERADORES[k]) {
				index = i;
			}
		}
	}
	return index;
}

int Operacion::buscarParentesis(){
	int respuesta;
	int tamano = operacion.length();
	tamano--;

	if (operacion[0] == '(' && operacion[tamano] == ')'){ // Revisa si debe borrar paréntesis.
		operacion.erase(operacion.begin() + 0); // Borra primer paréntesis,

		tamano = operacion.length();
		tamano--;

		operacion.erase(operacion.begin() + tamano); // Borra último paréntesis. 
	}


	respuesta = buscarOperador();// Llama al normal pero ya sin los paréntesis.
	return respuesta;
}

string Operacion::getOperacion(){
	return operacion;
}