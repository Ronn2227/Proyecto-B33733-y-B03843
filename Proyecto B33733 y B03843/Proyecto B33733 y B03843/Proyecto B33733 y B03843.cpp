// Proyecto B33733 y B03843.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Lista.h"


int _tmain(int argc, _TCHAR* argv[]) {
	srand((unsigned int)time(NULL));

	int cantidadElementos = rand() % 41 + 15; // Setea cantidad de Elementos de la Lista en un valor aleatorio entre 15 y 50.
	Lista<int> enteros;
	for (int i = 0; i < cantidadElementos; i++){

		int cualInsercion = rand() % 3;

		if (cualInsercion == 0){ // Elige de manera aleatoria si incertar en la cabeza, en una posicion o en la cola.
			enteros.insertarCabeza(rand() % 100);
		}
		else if (cualInsercion == 1){
			enteros.insertarNodo(rand() % 100, rand() % (enteros.getSize() + 1)); // Incerta en una posicion aleatoria entre 0 y el tamaño de la lista.
		}
		else {
			enteros.insertarCola(rand() % 100);
		}
	}

	cout << "Lista de enteros:" << endl;
	cout << enteros << endl;

	for (int i = 0; i < 10; i++){
		int cualRemocion = rand() % 3;

		if (cualRemocion == 0){ // Elige de manera aleatoria si remover la cabeza, una posicion o la cola.
			enteros.removerCabeza();
		}
		else if (cualRemocion == 1){
			enteros.removerNodo(rand() % (enteros.getSize() + 1)); // Renueve en una posicion aleatoria entre 0 y el tamaño de la lista.
		}
		else {
			enteros.removerCola();
		}
	}

	cout << "Lista de enteros con 10 remociones aleatorias:" << endl;
	cout << enteros << endl;

	NodoLista<int> * eleInt = enteros.buscarPorPosicion(2);
	cout << "en la posicion " << 2 << " hay un: " << *eleInt << endl;
	eleInt = enteros.buscarPorPosicion(enteros.getSize() - 3);
	cout << "en la posicion " << enteros.getSize() - 3 << " hay un: " << *eleInt << endl;

	cout << "el tamaño de la lista es de: " << enteros.getSize() << endl;
	cout << endl;


	return 0;
}

