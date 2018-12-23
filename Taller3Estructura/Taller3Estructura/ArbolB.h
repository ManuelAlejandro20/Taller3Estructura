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
	Pokemon * pokemonAleatorio(NodoB* nodob, int &num);
	Pokemon* buscarPokemonID(int ID); // buscar poke por ID
	Pokemon* buscarPokemonNombre(string nombre); //buscar poke por nombre
	void desplegarArbol(bool desplegarSoloCapturados); //despliega los pokes en orden, recibe true si se quiere imprimir solo los capturados o recibe false para imprimir todos los pokes 
	int getCantTotal();
	/*void imprimir(int i);*///recibe un 0 o un 1 dependiendo si quieres desplegar solo las claves o solo los nombres de los pokes, igual solo sirve para probar el arbol no va en el taller final
	~ArbolB();

private:
	//Todos los metodos a continuacion son de exclusivo uso interno dentro de la clase por eso estan privados
	//la mayoria son recursivos
	Pokemon* buscarPokemonID(int ID, NodoB* nodo);
	Pokemon* buscarPokemonNombre(string nombre, NodoB*nodo);
	bool isOverflow(NodoB* nodo);
	NodoB* buscarNodoAgregacion(NodoB* nodo, Pokemon* pokemon);
	NodoB* buscarNodoAnterior(NodoB * nodo, NodoB * nodo_original);
	void agregarDato(NodoB* nodo, Pokemon* pokemon);
	void llenarPoke(vector<Pokemon*> &vec, NodoB* nodo);
	/*void imprimirArbol(NodoB * nodo); */        //Metodos para probar si todo se inserto bien dentro del arbol
	/*void imprimirArbolNombre(NodoB * nodo);*/	//eliminar antes de enviar el taller	
	
	
	int m;
	NodoB* raiz;
	int cant; // cant de pokes totales dentro de la pokedex
};


