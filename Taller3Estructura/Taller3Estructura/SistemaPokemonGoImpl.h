#pragma once
#include <string>
#include "ArbolABB.h"
#include "ArbolB.h"
#include "Pokemon.h"

using namespace std;

class SistemaPokemonGoImpl
{
public:

	SistemaPokemonGoImpl();

	void AgregarPokemon(Pokemon* nuevoPokemon);

	Pokemon* PokemonAleatorio();
	void CapturarPokemon(Pokemon* pokemonACapturar, string PC, string HP, string IV);

	void BuscarPokemonPokedex(int ID);
	void BuscarPokemonPokedex(string nombre);
	void DesplegarPokedex();

	void DesplegarMochila();
	void DesplegarPokemon(int ID);
	void DesplegarPokemon(string nombre);
	void DesplegarEstadisticas();
	void TransferirPokemon(int ID);
	void TransferirPokemon(string nombre);

	~SistemaPokemonGoImpl();

private:

	ArbolB* pokedex;

	int cantPokemonRegistrados; // Indica cuantos pokemon se han registrado en la pokedex
};

