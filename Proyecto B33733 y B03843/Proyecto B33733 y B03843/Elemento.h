#pragma once

using namespace std;

class Elemento {

	friend ostream & operator<<(ostream &, const Elemento &);
	friend ostream & operator<<(ostream &, const Elemento *);

protected:
	Elemento();
	Elemento(Elemento&);

public:

	virtual ~Elemento();
	virtual int compareTo(Elemento *) = 0; // Compara 2 elementos.
	virtual void imprimir(ostream &) const = 0; // Crea un out que sirve para imprimir el Elemento.

	bool operator<(Elemento &);
	bool operator<=(Elemento &);
	bool operator>(Elemento &);
	bool operator>=(Elemento &);

};

ostream & operator<<(ostream &, const Elemento &);
ostream & operator<<(ostream &, const Elemento *);
