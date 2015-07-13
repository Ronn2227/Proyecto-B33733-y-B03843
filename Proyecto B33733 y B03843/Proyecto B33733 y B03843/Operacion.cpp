#include "stdafx.h"
#include "Operacion.h"

const char Operacion::OPERADORES[Operacion::NUM_OPERADORES] = { 'f', '+', '-', '*' , '/', '^', 'c', 't', 'l', 's'};
const string Operacion::OPERADORES_LARGOS[Operacion::NUM_OPERADORES_LARGOS] = {"sen", "cos", "tan", "log", "regla_tres"};
const string Operacion::OPERADORES_CORTOS[Operacion::NUM_OPERADORES_LARGOS] = {"s", "c", "t", "l", "f"};

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
	int tam = operacion.length();
	tam--;
	for (int k = 0; k < NUM_OPERADORES && index == -1; k++) {
		for (int i = tam ; i >= 0 && index == -1; --i) {
			char c = operacion[i];
			if (c == ')') {
				parentesis++;
			}
			else if (c == '(') {
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
		operacion.erase(operacion.begin() + tamano); // Borra último paréntesis. 
		operacion.erase(operacion.begin()); // Borra primer paréntesis,
	}

	respuesta = buscarOperador(); // Llama al normal pero ya sin los paréntesis.
	return respuesta;
}

string Operacion::getOperacion(){
	return operacion;
}

void Operacion::replaceAll(string from, string to){
	while (operacion.find(from) != -1) {
		int a = operacion.find(from);
		operacion.replace(a, from.length(), to);
	}
}

void Operacion::acortarOperadores(){
	for (int i = 0; i < NUM_OPERADORES_LARGOS; ++i) {
		replaceAll(OPERADORES_LARGOS[i], OPERADORES_CORTOS[i]);
	}
}