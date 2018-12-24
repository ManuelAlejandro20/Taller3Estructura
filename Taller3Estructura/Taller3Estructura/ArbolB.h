#pragma once
#include "NodoB.h"
#include "Pokemon.h"
#include <iostream>

using namespace std;

class ArbolB
{
public:
	ArbolB(int m);
	void agregarDato(Pokemon* pokemon);
	Pokemon* pokemonAleatorio();
	Pokemon* buscarPokemonID(int ID); // buscar poke por ID
	Pokemon* buscarPokemonNombre(string nombre); //buscar poke por nombre
	void desplegarArbol(bool desplegarSoloCapturados); //despliega los pokes en orden, recibe true si se quiere 
	int getCantTotal();				//imprimir solo los capturados o recibe false para imprimir todos los pokemon 
	~ArbolB();

private:
	//Todos los metodos a continuacion son de exclusivo uso interno dentro de la clase por eso estan privados
	//la mayoria son recursivos
	Pokemon* buscarPokemonID(int ID, NodoB* nodo);
	Pokemon* buscarPokemonNombre(string nombre, NodoB*nodo);
	bool isOverflow(NodoB* nodo);
	Pokemon * pokemonAleatorio(NodoB* nodob, int &num);
	NodoB* buscarNodoAgregacion(NodoB* nodo, Pokemon* pokemon);
	NodoB* buscarNodoAnterior(NodoB * nodo, NodoB * nodo_original);
	void agregarDato(NodoB* nodo, Pokemon* pokemon);
	void llenarPoke(vector<Pokemon*> &vec, NodoB* nodo);
	
	int m;
	NodoB* raiz;
	int cant; // cant de pokes totales dentro de la pokedex
};


