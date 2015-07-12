#pragma once

#include "NodoArbol.h"
#include "Operacion.h"
#include "Operador.h"
#include "Operando.h"
#include "OperadorSuma.h"
#include "OperadorResta.h"
#include "OperadorMultiplicacion.h"
#include "OperadorDivision.h"
#include "OperadorBinario.h"
#include "OperadorUnario.h"
#include "OperadorTernario.h"

using namespace std;

template<class T>
class Arbol {

	template<class T>
	friend ostream & operator<<(ostream &, Arbol<T> &);

private:

	NodoArbol<T> * raiz;

public:

	Arbol() { // Estado inicial del árbol.
		raiz = NULL;
	}

	~Arbol() {
		if (raiz != NULL) {
			destruirRec(raiz);
		}
	}

	void insertarElemento(T elemento) {
		if (raiz == NULL) {
			raiz = new NodoArbol<T>(elemento);
		}
	}

	void descomponerOperacion() {
		descomponerOperacion(raiz);
	}

	void resolverArbol() {
		resolverArbol(raiz);
	}

	T getRaiz() {
		return raiz->getActual();
	}

private:
	void descomponerOperacion(NodoArbol<T> *& nodo) { // Descompone la operación en operaciones más sencillas a resolver; recursivamente.
		Operacion * actual = dynamic_cast<Operacion *>(nodo->getActual()); // Intenta convertir el nodo en una "Operacion".
		if (actual != 0){ // Si era una Operacion quita el nodo y lo remplaza por un árbol que divide la operacion en dos partes.
			NodoArbol<T> * temp = crearArbol(actual);
			delete nodo;
			nodo = temp;
		}

		// Se descompone él y luego descompone a sus hijos ,

		for (int i = 0; i < nodo->getCantHijos(); i++) {
			descomponerOperacion(nodo->getHijo(i));
		}
	}

	void resolverArbol(NodoArbol<T> *& nodo) { // Resuelve el árbol cuando solo tiene operaciones sencillas; recursivamente
		for (int i = 0; i < nodo->getCantHijos(); i++) {
			resolverArbol(nodo->getHijo(i));
		}

		//Resuelve primero los hijos y luego se resuelve él.

		if (nodo->getHijoIzq() != NULL && nodo->getHijoDer() != NULL){ // Si no tiene hijos entonces es una operador y no hace nada.

			Operando * hIzq = dynamic_cast<Operando*>(nodo->getHijoIzq()->getActual());
			Operando * hDer = dynamic_cast<Operando*>(nodo->getHijoDer()->getActual());

			Operador* actual = dynamic_cast<Operador*>(nodo->getActual()); // Convierte al nodo en un operador .
			// Quita el nodo y lo remplaza con en el resultado correspondiente al tipo de operador con sus dos hijos.
			NodoArbol<T> * temp = new NodoArbol<T>(actual->operar(hIzq, hDer));
			delete nodo;
			nodo = temp;
		}
	}

	void imprimir(NodoArbol<T> * nodo, ostream & out, int profundidad) { // Imprime el árbol.
		if (nodo->getHijoIzq() != NULL) {
			imprimir(nodo->getHijoIzq(), out, profundidad + 1);
		}
		for (int i = 0; i < profundidad; ++i) {
			cout << "\t";
		}
		out << *nodo << endl;
		if (nodo->getHijoDer() != NULL) {
			imprimir(nodo->getHijoDer(), out, profundidad + 1);
		}
	}

	void destruirRec(NodoArbol<T> * nodo) { // Destruye el árbol recursivamente.
		if (nodo->getHijoIzq() != NULL) {
			destruirRec(nodo->getHijoIzq());
		}
		if (nodo->getHijoDer() != NULL) {
			destruirRec(nodo->getHijoDer());
		}
		// Primero se destruye a los hijos y luego al padre.
		delete nodo;
	}

	bool puedeParseDouble(string numero) { // Revisa si un string se puede convertir en double.
		bool respuesta = true;
		Operacion * a = new Operacion(numero);
		int b = a->buscarParentesis();
		if (b != -1){ // Si encuentra un operador entonces no puede convertir a string.
			respuesta = false;
		}
		delete a;
		return respuesta;
	}

	int buscarCaracterFuera(string oper, int inicio, char c, char tipoParentesis) {
		char abierto;
		char cerrado;
		if (tipoParentesis == '(' || tipoParentesis == ')')
		{
			abierto = '(';
			cerrado = ')';
		}
		else {
			abierto = '[';
			cerrado = ']';
		}

		int index = -1;
		int contador = inicio;
		int contadorParentesis = 0;
		while (contador < oper.length && index = -1) {
			if (oper[contador] == abierto) {
				contadorParentesis++;
				contador++;
				while (contadorParentesis != 0) {
					if (oper[contador] == abierto) {
						contadorParentesis++;
					}
					else if (oper[contador] == cerrado) {
						contadorParentesis--;
					}	
					contador++
				}
				contador--
			}
			else if (oper[contador] == c){
				index = contador;
			}
			contador++
		}
		return index;
	}

	double parseDouble(string numero) { // Convierte un string a double.
		double respuesta = 0;
		if (numero != ""){ // Si está vacío no puede convertir pero devuelve un 0 (controla el ingreso de numeros negativos)
			respuesta = stod(numero); // Método de la clase string que convierte de string a double (En clase mencionó que si se podía usar).
		}
		return respuesta;
	}

	NodoArbol<T> * crearArbol(Operacion * nodo) { // Crea un arbol pequeño al dividir una operacion en 2 partes.
		NodoArbol<T> * nuevo = new NodoArbol<T>(nodo); // Elemento a devolver, si no puede crear el árbol devuelve el mismo nodo que entró como parámetro.
		int posicion = nodo->buscarOperador(); // Posición donde se encontraría el operador con menor precedencia (fuera de paréntesis).
		if (posicion != -1){ // Si encontró una operación crea el arbol a partir de ella.
			string oper = nodo->getOperacion();
			nuevo = asignarHijos(oper, posicion);
		}
		else { // Si no encontró una operación revisa si hay paréntesis.
			posicion = nodo->buscarParentesis();
			if (posicion != -1) {
				string oper = nodo->getOperacion();
				nuevo = asignarHijos(oper, posicion);
			}
			else if (puedeParseDouble(nodo->getOperacion())) { // Si no encontró un operador ni dentro de paréntesis intenta convertir la operacion a un operador.
				nuevo = new NodoArbol<T>(new Operando(parseDouble(nodo->getOperacion())));
			}
		}

		return nuevo;
	}

	NodoArbol<T> * asignarHijos(string oper, int posicion) { // Crea un arbol segun un string y una posicion (reducir lineas de codigo).
		NodoArbol<T> * nuevo;
		switch (oper[posicion]) {
		case '-':
			nuevo = new NodoArbol<T>(new OperadorResta());
			break;
		case '+':
			nuevo = new NodoArbol<T>(new OperadorSuma());
			break;
		case '/':
			nuevo = new NodoArbol<T>(new OperadorDivision());
			break;
		case '*':
			nuevo = new NodoArbol<T>(new OperadorMultiplicacion());
			break;
		case 'l':
			nuevo = new NodoArbol<T>(new OperadorResta());
			break;
		case 's':
			nuevo = new NodoArbol<T>(new OperadorResta());
			break;
		case 'c':
			nuevo = new NodoArbol<T>(new OperadorResta());
			break;
		case 't':
			nuevo = new NodoArbol<T>(new OperadorResta());
			break;
		case '^':
			nuevo = new NodoArbol<T>(new OperadorResta());
			break;
		default:
			nuevo = new NodoArbol<T>(new OperadorResta());
			break;
		}

		OperadorUnario * uni = dynamic_cast<OperadorUnario*>(nuevo);
		if (uni != NULL) {
			string hijo = oper.substr(posicion + 2, buscarCaracterFuera(oper, posicion + 2, ')', '(') - posicion - 2);
			if (puedeParseDouble(hijo)){ // Si la parte izquierda es un operando la convierte.
				nuevo->setHijo(new NodoArbol<T>(new Operando(parseDouble(hijo))));
			}
			else{
				nuevo->setHijo(new NodoArbol<T>(new Operacion(hijo)));
			}
		}

		OperadorBinario * bin = dynamic_cast<OperadorBinario*>(nuevo);
		if (bin != NULL) {
			string hijo1 = oper.substr(0, posicion); // Lo que hay a la izquiera del operador.
			string hijo2 = oper.substr(posicion + 1, oper.length() - 1 - posicion) // Lo que hay a la derecha del operador.

			if (puedeParseDouble(hijo1)){ // Si la parte izquierda es un operando la convierte.
				nuevo->setHijo(new NodoArbol<T>((new Operando(parseDouble(hijo1));
			}
			else{
				nuevo->setHijo(new NodoArbol<T>(new Operacion(hijo1)));
			}

			if (puedeParseDouble(hijo2)){ // Si la parte izquierda es un operando la convierte.
				nuevo->setHijo(new NodoArbol<T>(new Operando(parseDouble(hijo2))));
			}
			else{
				nuevo->setHijo(new NodoArbol<T>(new Operacion(hijo2)));
			}
		}

		OperadorTernario * ter = dynamic_cast<OperadorTernario*>(nuevo);

		if (ter != NULL) {
			int primeraComa = buscarCaracterFuera(oper, posicion + 1, ',', '[');
			int segundaComa = buscarCaracterFuera(oper, primeraComa + 1, ',', '[');
			string hijo1 = oper.substr(posicion + 2, primeraComa - posicion - 2);
			string hijo2 = oper.substr(primeraComa + 1, segundaComa - primeraComa - 1);
			string hijo3 = oper.substr(segundaComa + 1, buscarCaracterFuera(oper, segundaComa + 1, ']', '[') - segundaComa - 1);

			if (puedeParseDouble(hijo1)){ // Si la parte izquierda es un operando la convierte.
				nuevo->setHijo(new NodoArbol<T>(new Operando(parseDouble(hijo1))));
			}
			else{
				nuevo->setHijo(new NodoArbol<T>(new Operacion(hijo1)));
			}

			if (puedeParseDouble(hijo2)){ // Si la parte izquierda es un operando la convierte.
				nuevo->setHijo(new NodoArbol<T>(new Operando(parseDouble(hijo2))));
			}
			else{
				nuevo->setHijo(new NodoArbol<T>(new Operacion(hijo2)));
			}

			if (puedeParseDouble(hijo3)){ // Si la parte izquierda es un operando la convierte.
				nuevo->setHijo(new NodoArbol<T>(new Operando(parseDouble(hijo3))));
			}
			else{
				nuevo->setHijo(new NodoArbol<T>(new Operacion(hijo3)));
			}
		}
		return nuevo;
	}
};

template<class T>
ostream & operator<<(ostream & out, Arbol<T> & a) {
	a.imprimir(a.raiz, out, 0);
	return out;
}