#pragma once
#include "NodoABB.h"

class ArbolABB
{
public:

	ArbolABB();

	void AgregarPokemon(int ID);
	void LiberarPokemon(int ID);
	bool BuscarPokemon(int ID); // Retorna True si el pokemon esta en el arbol ABB
	int getCantActual();
	~ArbolABB();
private:

	NodoABB* raiz;
	int cantActual;
};

