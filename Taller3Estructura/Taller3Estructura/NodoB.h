#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "Pokemon.h"

using namespace std;

class NodoB
{
public:
	NodoB(int m);
	void limpiarHijos();
	int retornarPos(Pokemon* pokemon);
	bool esHijo(NodoB* nodo);
	bool tieneHijos();
	~NodoB();

private:
	vector<Pokemon*> pokes;
	vector<NodoB*> hijos;
	friend class ArbolB;
};



