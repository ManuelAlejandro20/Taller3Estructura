#pragma once
#include <iostream>
#include <string>
#include "Utilidades.h"

using namespace std;
using namespace utilidades;

class Pokemon
{
public:

	Pokemon();
	Pokemon(int ID, string nombre, string ataque, float probabilidadFija);

	void CambiarEstadisticas(string PC, string HP, string IV);

	void DesplegarPokemonPokedex();
	void DesplegarPokemonMochila();
	void DesplegarPokemon();

	void Capturar();
	void Transferir();
	void AumentarCantVecesCapturado();

	int getID();
	string getNombre();
	float getProbabilidadFija();
	int getCantVecesCapturado();
	bool EstaCapturado();

	float getProbabilidadCaptura(); // Hace el calculo de la probabilidad de captura y lo retorna

	~Pokemon();
private:

	int ID;
	string nombre;
	string ataque;
	float probabilidadFija;

	/*
		Los siguientes atributos, a pesar de que la logica nos dice que deberian ser de tipo int
		estan como string porque no se hacen operaciones matematicas con ellos, ademas asi no sera
		necesario pasarlos a string cada vez que se quieran desplegar
	*/
	string PC;
	string HP;
	string IV;

	int cantVecesCapturado;
	bool capturado;
};

