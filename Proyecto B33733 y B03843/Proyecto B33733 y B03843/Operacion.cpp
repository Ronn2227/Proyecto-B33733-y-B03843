#include "stdafx.h"
#include "Operacion.h"


Operacion::Operacion(string oper) : Elemento(){
	this->operacion = oper;
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
	bool encontrado = false;
	int contadorParentesis = 0;
	int tamano = operacion.length();
	int contador = tamano - 1;
	int respuesta = -1; // Posición a devolver, si no lo encuentra devuelve un -1.
	// Recorre el string buscando el operador con menor precedencia una vez por cada 
	// posible grupo de tipo de operador (+ y -) o (* y /) hasta que encuentre alguno, ignorando los paréntesis.
	while (encontrado == false && contador >= 0){
		if (operacion[contador] == ')'){
			contadorParentesis++;
			contador--;
			while (contadorParentesis != 0){
				if (operacion[contador] == ')'){
					contadorParentesis++;
				}
				else if (operacion[contador] == '('){
					contadorParentesis--;
				}
				contador--;
			}
			contador++;
		}
		else if (operacion[contador] == '-'){
			respuesta = contador;
			encontrado = true;
		}
		else if (operacion[contador] == '+'){
			respuesta = contador;
			encontrado = true;
		}
		contador--;
	}

	contador = tamano - 1;
	while (encontrado == false && contador >= 0){
		if (operacion[contador] == ')'){
			contadorParentesis++;
			contador--;
			while (contadorParentesis != 0){
				if (operacion[contador] == ')'){
					contadorParentesis++;
				}
				else if (operacion[contador] == '('){
					contadorParentesis--;
				}
				contador--;
			}
			contador++;
		}
		else if (operacion[contador] == '/'){
			respuesta = contador;
			encontrado = true;
		}
		else if (operacion[contador] == '*'){
			respuesta = contador;
			encontrado = true;
		}
		contador--;
	}

	return respuesta;
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