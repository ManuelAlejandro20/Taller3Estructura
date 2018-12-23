#include "pch.h"
#include "NodoB.h"


NodoB::NodoB(int m)
{
	for (int i = 0; i < m; i++) {
		this->hijos.push_back(nullptr);
	}
}

void NodoB::limpiarHijos()
{
	int largo = this->hijos.size();
	this->hijos.clear();
	for (int i = 0; i < largo; i++) {
		this->hijos.push_back(nullptr);
	}
}

int NodoB::retornarPos(Pokemon* pokemon)
{
	for (int i = 0; i < this->pokes.size(); i++) {
		if (this->pokes[i] == pokemon) return i;
	}
	return -1;
}

bool NodoB::esHijo(NodoB * nodo)
{
	if (nodo == nullptr) {
		return false;
	}
	for (int i = 0; i < this->hijos.size(); i++) {
		if (this->hijos[i] == nodo) {
			return true;
		}
	}
	return false;
}

bool NodoB::tieneHijos()
{
	for (int i = 0; i < this->hijos.size(); i++) {
		if (this->hijos[i] != nullptr) {
			return true;
		}
	}
	return false;
}




NodoB::~NodoB()
{
}
