#include "pch.h"
#include "ArbolB.h"
#include "Utilidades.h"

using namespace utilidades;

ArbolB::ArbolB(int m)
{
	this->cant = 0;
	this->raiz = new NodoB(m);
	this->m = m;
}

NodoB * ArbolB::buscarNodoAgregacion(NodoB* nodo, Pokemon* pokemon) // su funcion es buscar dentro del arbol b el nodo en el que se va a agregar el dato  
{
	if (!nodo->tieneHijos()) {//su condicion de termino es que el nodo no tenga hijos
		return nodo;
	}
	if (pokemon->getID() > nodo->pokes[nodo->pokes.size() - 1]->getID()) { //si el ID del poke es mayor al ultimo ID quiere decir que el nodo al que hay que agregar esta en su hijo mas a la derecha
		return buscarNodoAgregacion(nodo->hijos[nodo->pokes.size()], pokemon);//esto se hace porque en el for que esta mas abajo no alcanza a llegar al ultimo elemento de los hijos
	}
	for (int i = 0; i < nodo->pokes.size(); i++) // si pasa el filtro anterior quiere decir que el ID a agregar esta entre las claves, por lo que se busca el hijo correspondiente
	{
		if (pokemon->getID() < nodo->pokes[i]->getID()) {// si quiero agregar 22 a [20,24,30], se recorre hasta que el id a agregar sea menor a la clave[i] recorrida en el for, cuando pase esto retorna el hijo en la i-esima posicion
			return buscarNodoAgregacion(nodo->hijos[i], pokemon);
		}
	}
}

NodoB * ArbolB::buscarNodoAnterior(NodoB * nodo, NodoB* nodo_original) // retorna el nodo anterior al nodo de agregacion
{
	if (nodo != nullptr) {
		if (nodo->esHijo(nodo_original)) { //la condicion de termino es que el nodo tenga de hijo al nodo original
			return nodo;
		}
		if (nodo->tieneHijos()) {
			for (int i = 0; i < m; i++) {
				if (buscarNodoAnterior(nodo->hijos[i], nodo_original) == nodo->hijos[i]) {
					return nodo->hijos[i];
				}
			}
			return nullptr;
		}
	}
	return nullptr;

}

void ArbolB::agregarDato(Pokemon* pokemon)
{
	agregarDato(buscarNodoAgregacion(this->raiz, pokemon), pokemon); // antes de agregar el dato se busca el nodo de agregacion 
}

void ArbolB::agregarDato(NodoB* nodo, Pokemon* pokemon)
{
	if (isOverflow(nodo)) { // pregunta si esta lleno
		NodoB * nodoaux = nullptr;
		NodoB * nodoaux2 = nullptr;
		vector<Pokemon*> aux = nodo->pokes; // se copian los pokes del nodo de agregacion a un nuevo vector y se agregan
		aux.push_back(pokemon);
		sort(aux.begin(), aux.end(), [](Pokemon * p1, Pokemon * p2) {return p1->getID() < p2->getID(); }); //operacion lambda que ordena lo pokes segun su id, de menor a mayor
		int n = ceil((double)m / 2) - 1; // funcion techo, se le resta 1 para facilitar la busqueda dentro del arreglo
		if (nodo == this->raiz) {
			nodoaux = new NodoB(m);
			nodoaux2 = new NodoB(m);
			for (int i = 0; i < n; i++) // se copian los datos izquierdos al nodo izquierdo
			{
				nodoaux->pokes.push_back(aux[i]);
				nodoaux->hijos[i] = nodo->hijos[i];
			}
			nodoaux->hijos[n] = nodo->hijos[n]; // como el for anterior no alcanza a llegar al final de los hijos se copia de esta manera
			for (int i = n + 1; i < m; i++) { // se copian los datos derechos al nodo derecho
				nodoaux2->pokes.push_back(aux[i]);
				nodoaux2->hijos[i - (n + 1)] = nodo->hijos[i];
			}
			this->cant++;
			nodoaux2->hijos[nodoaux->pokes.size()] = nodo->hijos[m - 1]; // el for no alcanza llegar al final de la lista de hijos, asi que el ultimo hijo se copia de esta manera
			nodo->pokes.clear(); // se borran los elemetnos e hijos del nodo orignal
			nodo->limpiarHijos();
			nodo->pokes.push_back(aux[n]); // se agrega el elemento n dentro del arreglo aux 
			nodo->hijos[0] = nodoaux;//si es la raiz, el hijo 0 siempre sera el nodo izquierdo y el 1 sera el derecho
			nodo->hijos[1] = nodoaux2;
			//de esta manera +22 [20,24,30]--->[24]
			//								  /   \
			//						   [20,22]    [30]
		}
		else {
			nodoaux = buscarNodoAnterior(this->raiz, nodo); //si el dato no es la raiz se tiene que buscar el anterior
			int ind = 0;
			agregarDato(nodoaux, aux[n]);
			nodoaux = buscarNodoAnterior(this->raiz, nodo);//se busca de nuevo por que en caso de que la agergacion anterior de como resultado otro overflow, el nodo anterior se separara y ya no sera el mismo
			nodoaux2 = new NodoB(this->m);
			for (int i = n + 1; i < m; i++) // se copian los datos del lado derecho al nuevo nodo
			{
				nodo->pokes.pop_back();//al mismo tiempo se elimnan los datos que estan mas a la derecha del nodo
				nodoaux2->pokes.push_back(aux[i]);
				ind = i - (n + 1);
				nodoaux2->hijos[ind] = nodo->hijos[i];
				nodo->hijos[i] = nullptr;
			}
			int pos = nodoaux->retornarPos(aux[n]);
			for (int i = nodoaux->pokes.size() - 1; i > pos - 1; i--) { // se van copiando las nuevas referencias en el nodo anterior solo hasta llegar al nuevo dato agregado
				if (i == pos) {
					nodoaux->hijos[i + 1] = nodoaux2;
					break;
				}
				nodoaux->hijos[i + 1] = nodoaux->hijos[i];
			}
		}
		nodoaux = nodoaux2 = NULL;
		delete nodoaux, nodoaux2;
		return;
	}
	this->cant++;
	nodo->pokes.push_back(pokemon); // si no esta lleno se agrega
	sort(nodo->pokes.begin(), nodo->pokes.end(), [](Pokemon * p1, Pokemon * p2) {return p1->getID() < p2->getID(); });
	return;
}

Pokemon * ArbolB::pokemonAleatorio() // metodo aleatorio
{
	int numrandom = rand() % ((this->cant - 1 - 1) + 1) + 1;
	return pokemonAleatorio(this->raiz, numrandom);


	//vector<Pokemon*> vec;
	
	//llenarPoke(vec, this->raiz); 
	//return vec[numrandom - 1];

	//return buscarPokemonID(numrandom);
}

Pokemon * ArbolB::pokemonAleatorio(NodoB* nodob , int &num) {
	if (nodob != nullptr) {
		for (int i = 0; i < nodob->pokes.size(); i++) {
			if (num == 0) {
				return nodob->pokes[i];
			}
			num--;
		}
		for (int i = 0; i < nodob->pokes.size() + 1; i++) {
			Pokemon *pokeaux = pokemonAleatorio(nodob->hijos[i], num);
			if (pokeaux == nullptr) {
				continue;
			}
			return pokeaux;
		}
	}
	return nullptr;
}

Pokemon * ArbolB::buscarPokemonID(int ID) // es el metodo publico de busca poke por id
{
	return buscarPokemonID(ID, this->raiz);
}

Pokemon * ArbolB::buscarPokemonNombre(string nombre) // es el metodo publico de busca poke por nombre
{
	toUpper(nombre);
	string nombreMay = nombre;
	return buscarPokemonNombre(nombreMay, this->raiz);
}

void ArbolB::desplegarArbol(bool desplegarSoloCapturados) // despliega los pokes depeniendo del booleano
{
	vector<Pokemon*> pokes;
	llenarPoke(pokes, this->raiz);
	sort(pokes.begin(), pokes.end(), [](Pokemon * p1, Pokemon * p2) {return p1->getID() < p2->getID(); }); // despues de retornar el vector se ordena de menor a mayori por id
	if (desplegarSoloCapturados) {
		for (int i = 0; i < pokes.size(); i++) {
			if (pokes[i]->EstaCapturado()) {
				pokes[i]->DesplegarPokemonMochila();
			}
		}
	}
	else {
		for (int i = 0; i < pokes.size(); i++) {
			pokes[i]->DesplegarPokemonMochila();
		}
	}
}
int ArbolB::getCantTotal()
{
	return this->cant;
}

void ArbolB::llenarPoke(vector<Pokemon*> &vec, NodoB* nodo) // metodo que pone dentro todos los pokes del arbol dentro del vector ingresado por parametro (no lo hace en orden)
{
	if (nodo != nullptr) {
		for (int i = 0; i < nodo->pokes.size(); i++) {
			vec.push_back(nodo->pokes[i]);
		}
		for (int i = 0; i < nodo->hijos.size(); i++) {
			llenarPoke(vec, nodo->hijos[i]);
		}
	}

}

Pokemon * ArbolB::buscarPokemonID(int ID, NodoB * nodo) // metodo recursivo que devuelve el poke segun su id 
{
	if (nodo != nullptr) {
		if (ID > nodo->pokes[nodo->pokes.size() - 1]->getID()) return buscarPokemonID(ID, nodo->hijos[nodo->pokes.size()]); // si el id a evaluar es mayor a la id de la ultima clave se devuelve el utlimo hijo
		for (int i = 0; i < nodo->pokes.size(); i++) { 
			if (ID == nodo->pokes[i]->getID()) return nodo->pokes[i]; // condicion de termino
			else if (ID < nodo->pokes[i]->getID()) return buscarPokemonID(ID, nodo->hijos[i]); // si este entre medio de las claves devuelve el nodo hijo que esta entremedio, mismo procedimiento que se usa para buscar el nodo agregacion
		}
		return nullptr;
	}
	return nullptr;
}

Pokemon * ArbolB::buscarPokemonNombre(string nombre, NodoB * nodo) // busca al poke por nombre
{
	string str;
	if (nodo != nullptr) {
		for (int i = 0; i < nodo->pokes.size(); i++) {//primero busca en el nodo
			str = nodo->pokes[i]->getNombre();
			toUpper(str);
			if (nombre == str) return nodo->pokes[i];
		}
		for (int i = 0; i < nodo->hijos.size(); i++) {
			Pokemon *poke = buscarPokemonNombre(nombre, nodo->hijos[i]); // luego busca en los hijos
			if (poke != nullptr) {
				str = poke->getNombre();
				toUpper(str);
				if (str == nombre) return poke; // condicion de termino
			}
			continue;
		}
	}
	return nullptr;
}

bool ArbolB::isOverflow(NodoB * nodo) // devuelve true si el nodo esta lleno, devuelve false si aun queda espacio
{
	return (nodo->pokes.size() == (m - 1)) ? true : false;
}

//void ArbolB::imprimir(int i)
//{
//	cout << "" << endl;
//	if (i == 0) { imprimirArbol(this->raiz); }
//	else { imprimirArbolNombre(this->raiz); }
//	cout << "La cantidad de pokes agregados fue: " << this->cant << endl;
//}
//
//void ArbolB::imprimirArbol(NodoB* nodo)
//{
//	if (nodo == nullptr) {
//		return;
//	}
//
//	cout << "[";
//	for (int i = 0; i < nodo->pokes.size(); i++) {
//		cout << nodo->pokes[i]->getID();
//		cout << ",";
//	}
//	for (int i = 0; i < nodo->hijos.size(); i++) {
//		imprimirArbol(nodo->hijos[i]);
//	}
//	cout << "]";
//}
//
//void ArbolB::imprimirArbolNombre(NodoB * nodo)
//{
//	if (nodo == nullptr) {
//		return;
//	}
//
//	cout << "[";
//	for (int i = 0; i < nodo->pokes.size(); i++) {
//		cout << nodo->pokes[i]->getNombre();
//		cout << ",";
//	}
//	for (int i = 0; i < nodo->hijos.size(); i++) {
//		imprimirArbolNombre(nodo->hijos[i]);
//	}
//	cout << "]";
//}

ArbolB::~ArbolB()
{
}
