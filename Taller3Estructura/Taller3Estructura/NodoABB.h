#pragma once
class NodoABB
{
public:

	NodoABB();
	NodoABB(int ID);

	int getID();
	NodoABB* getHijoIzq();
	NodoABB* getHijoDer();
	NodoABB* getPadre();

	void setHijoIzq(NodoABB* nuevoHijoIzq);
	void setHijoDer(NodoABB* nuevoHijoDer);
	void setPadre(NodoABB* nuevoPadre);

	~NodoABB();
private:

	int ID;

	NodoABB* hijoIzq;
	NodoABB* hijoDer;
	NodoABB* padre;
};

