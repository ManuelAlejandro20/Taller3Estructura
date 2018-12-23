#include "pch.h"
#include "ArbolABB.h"


ArbolABB::ArbolABB()
{
	this->cantActual = 0;
}

void ArbolABB::AgregarPokemon(int ID)
{

	// Si el pokemon no existe
	if (!BuscarPokemon(ID)) {
		
		// Si el arbol esta vacio
		if (raiz) {

			raiz = new NodoABB(ID);
			raiz->setPadre(raiz);
		}
		else { // Si el arbol no esta vacio

			NodoABB* aux = raiz;
			NodoABB* auxPadre = raiz;

			while (aux) {

				// Se ve si el nuevo nodo a agregar esta a la izquierda o a la derecha de aux, luego se sobreescribe aux y su padre
				if (ID < aux->getID()) {

					auxPadre = aux;
					aux = aux->getHijoIzq();
				}
				else {

					auxPadre = aux;
					aux = aux->getHijoDer();
				}
			}

			aux = new NodoABB(ID);
			aux->setPadre(auxPadre);
		}

		this->cantActual += 1;
	}
}

void ArbolABB::LiberarPokemon(int ID)
{

	// Si el pokemon existe
	if (BuscarPokemon(ID)) {

		NodoABB* aux = raiz;

		while (aux && aux->getID() != ID) {

			// Se ve si el nuevo nodo a agregar esta a la izquierda o a la derecha de aux, luego se sobreescribe aux
			if (ID < aux->getID()) {

				aux = aux->getHijoIzq();
			}
			else {

				aux = aux->getHijoDer();
			}
		}
		
		// Si el nodo no tiene hijos
		if (!aux->getHijoIzq() && !aux->getHijoDer()) {

			delete aux;
		}
		else if (!aux->getHijoDer()) { // Si el nodo solo posee un hijo izquierdo

			// Si el nodo a eliminar es la raiz
			if (aux == raiz) {

				raiz = aux->getHijoIzq();
				delete aux;
			}
			else { // Si el nodo a eliminar no es la raiz

				NodoABB* auxPadre = aux->getPadre(); // Se obtiene al padre de aux

				// Se ve si el nodo a eliminar es el hijo derecho o izq del padre
				if (auxPadre->getHijoIzq() == aux) {

					auxPadre->setHijoIzq(aux->getHijoIzq());
				}
				else {

					auxPadre->setHijoDer(aux->getHijoIzq());
				}

				delete aux;
			}

		}
		else if (!aux->getHijoIzq()) { // Si el nodo solo posee un nodo derecho

			// Si el nodo a eliminar es la raiz
			if (aux == raiz) {

				raiz = aux->getHijoDer();
				delete aux;
			}
			else { // Si el nodo a eliminar no es la raiz

				NodoABB* auxPadre = aux->getPadre(); // Se obtiene al padre de aux

				// Se ve si el nodo a eliminar es el hijo derecho o izq del padre
				if (auxPadre->getHijoIzq() == aux) {

					auxPadre->setHijoIzq(aux->getHijoDer());
				}
				else {

					auxPadre->setHijoDer(aux->getHijoDer());
				}

				delete aux;
			}

		}
		else { // Si no es ninguno de los casos anteriores significa que el nodo posee dos hijos

			NodoABB* aux2 = aux->getHijoDer(); // Creamos un auxiliar para buscar al nodo mas pequeño de los mas grandes

			while (aux2->getHijoIzq()) {

				aux2 = aux2->getHijoIzq();
			}

			NodoABB* aux2Padre = aux2->getPadre(); // Obtenemos al padre del nodo mas pequeño de los derechos

			// El nodo mas pequeño de los mas grandes puede tener 0 o 1 hijo derecho
			if (aux2->getHijoDer()) {

				aux2Padre->setHijoIzq(aux2->getHijoDer());
			}

			// Como el nodo mas pequeño de los mas grandes tomara el lugar de aux, se cambian sus hijos

			// Si aux es la raiz
			if (aux == raiz) {

				aux2->setHijoDer(aux->getHijoDer());
				aux2->setHijoIzq(aux->getHijoIzq());
				
				raiz = aux2;
			}
			else {

				aux2->setHijoDer(aux->getHijoDer());
				aux2->setHijoIzq(aux->getHijoIzq());
			}

			delete aux;
		}

		this->cantActual -= 1;
	}
}

bool ArbolABB::BuscarPokemon(int ID)
{

	NodoABB* aux = raiz;

	// Mientras no se termine de recorrer una rama del arbol
	while (aux) {

		// Si lo encuentra retorna True
		if (aux->getID() == ID) {
			
			return true;
		}

		// Pregunta si el ID esta a la izquierda o derecha del nodo actual y sobreescribe aux por el hijo correspondiente
		if (ID < aux->getID()) {

			aux = aux->getHijoIzq();
		}
		else {

			aux = aux->getHijoDer();
		}
	}

	// En cuanto aux sea nullptr no entrara al while o saldra de este y retornara false
	return false;
}

int ArbolABB::getCantActual()
{
	return this->cantActual;
}


ArbolABB::~ArbolABB()
{
}
