#include "pch.h"
#include "NodoABB.h"


NodoABB::NodoABB()
{
}

NodoABB::NodoABB(int ID)
{

	this->ID = ID;
	this->hijoDer = nullptr;
	this->hijoIzq = nullptr;
	this->padre = nullptr;
}


int NodoABB::getID()
{
	return this->ID;
}

NodoABB * NodoABB::getHijoIzq()
{
	return this->hijoIzq;
}

NodoABB * NodoABB::getHijoDer()
{
	return this->hijoDer;
}

NodoABB * NodoABB::getPadre()
{
	return this->padre;
}

void NodoABB::setHijoIzq(NodoABB * nuevoHijoIzq)
{
	this->hijoIzq = nuevoHijoIzq;
}

void NodoABB::setHijoDer(NodoABB * nuevoHijoDer)
{
	this->hijoDer = nuevoHijoDer;
}

void NodoABB::setPadre(NodoABB * nuevoPadre)
{
	this->padre = nuevoPadre;
}

NodoABB::~NodoABB()
{
}
