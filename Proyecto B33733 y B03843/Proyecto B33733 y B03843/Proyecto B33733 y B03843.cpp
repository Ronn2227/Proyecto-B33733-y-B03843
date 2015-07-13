// Proyecto B33733 y B03843.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Lista.h"
#include "Arbol.h"
#include "Operacion.h"


int _tmain(int argc, _TCHAR* argv[]){
	string linea; // Guarda temporalmente cada linea del archivo de operaciones.
	ifstream fileOperaciones;
	ofstream fileResultados;
	fileOperaciones.open("Operaciones.txt");// Archivo de operaciones.
	fileResultados.open("Resultados.txt");// Archivo de resultados.

	Lista<Elemento*> operaciones;
	Lista<Elemento*> resultados;

	if (fileOperaciones.is_open()){ // Lee el archivo y crea la lista de operaciones.
		while (getline(fileOperaciones, linea)){
			operaciones.insertarCola(new Operacion(linea));
		}
		fileOperaciones.close();
	}
	else {
		cout << "No se pudo abrir el archivo" << endl;
	}

	for (int i = 0; i < operaciones.getSize(); i++){ // Resuelve cada operacion con un árbol.
		Arbol<Elemento*> a;
		Elemento *temp1 = operaciones.buscarPorPosicion(i); // Elemento temporal con la operación a resolver para insertarlo al arbol y que cuando se elimine, no afecte la lista de operaciones.
		a.insertarElemento(temp1);
		a.descomponerOperacion();
		a.resolverArbol();
		Elemento * temp2 = a.getRaiz(); // Elemento temporal para insertar en la lista de resultados para que no se vea afectado con la eliminacion del árbol.
		resultados.insertarCola(temp2);
	}

	fileResultados << resultados << endl; // Agrega los resultados al archivo de resultados.
	cout << resultados << endl;
	fileResultados.close();

	system("pause");
	return 0;
}
