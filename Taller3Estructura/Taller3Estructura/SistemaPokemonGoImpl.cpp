#include "pch.h"
#include "SistemaPokemonGoImpl.h"
#include "Utilidades.h"

using namespace utilidades;

SistemaPokemonGoImpl::SistemaPokemonGoImpl()
{
	// this->mochila = new ArbolABB();
	this->pokedex = new ArbolB(9);
	this->cantPokemonRegistrados = 0;
}

void SistemaPokemonGoImpl::AgregarPokemon(Pokemon * nuevoPokemon)
{
	this->pokedex->agregarDato(nuevoPokemon);
}

Pokemon * SistemaPokemonGoImpl::PokemonAleatorio()
{
	return this->pokedex->pokemonAleatorio();
}

void SistemaPokemonGoImpl::CapturarPokemon(Pokemon* pokemonACapturar, string PC, string HP, string IV)
{

	// Si es la primera vez que se captura al pokemon el contador de pokemon registrados aumenta
	if (pokemonACapturar->getCantVecesCapturado() <= 0) {

		this->cantPokemonRegistrados += 1;
	}

	pokemonACapturar->CambiarEstadisticas(PC, HP, IV);
	pokemonACapturar->Capturar();
	pokemonACapturar->AumentarCantVecesCapturado();
}

void SistemaPokemonGoImpl::BuscarPokemonPokedex(int ID)
{
	Pokemon* pokemonBuscado = this->pokedex->buscarPokemonID(ID);
	
	if (pokemonBuscado != nullptr)
	{
		pokemonBuscado->DesplegarPokemonPokedex();
	}
	else
	{
		system("CLS");
		cout << "####### ERROR: ESE POKEMON NO EXISTE #######" << endl;
	}
}

void SistemaPokemonGoImpl::BuscarPokemonPokedex(string nombre)
{
	Pokemon* pokemonBuscado = this->pokedex->buscarPokemonNombre(nombre);
	
	if (pokemonBuscado != nullptr)
	{
		pokemonBuscado->DesplegarPokemonPokedex();
	}
	else
	{
		system("CLS");
		cout << "####### ERROR: ESE POKEMON NO EXISTE #######" << endl;
	}


}

void SistemaPokemonGoImpl::DesplegarPokedex()
{
	this->pokedex->desplegarArbol(false);
}


void SistemaPokemonGoImpl::DesplegarMochila()
{
	this->pokedex->desplegarArbol(true);
}

void SistemaPokemonGoImpl::DesplegarPokemon(int ID)
{

	Pokemon* pokemonBuscado = this->pokedex->buscarPokemonID(ID);

	if (pokemonBuscado != nullptr)
	{

		if (pokemonBuscado->EstaCapturado())
		{
			pokemonBuscado->DesplegarPokemon();
		}
		else
		{
			system("CLS");
			cout << "####### ERROR: NO HAS CAPTURADO A ESE POKEMON #######" << endl;
		}
	}
	else
	{
		system("CLS");
		cout << "####### ERROR: ESE POKEMON NO EXISTE #######" << endl;
	}


}

void SistemaPokemonGoImpl::DesplegarPokemon(string nombre)
{
	Pokemon* pokemonBuscado = this->pokedex->buscarPokemonNombre(nombre);
	
	if (pokemonBuscado != nullptr)
	{
		if (pokemonBuscado->EstaCapturado())
		{
			pokemonBuscado->DesplegarPokemon();
		}
		else
		{
			system("CLS");
			cout << "####### ERROR: NO HAS CAPTURADO A ESE POKEMON #######" << endl;
		}
	}
	else
	{
		system("CLS");
		cout << "####### ERROR: ESE POKEMON NO EXISTE #######" << endl;
	}
}

void SistemaPokemonGoImpl::DesplegarEstadisticas()
{
	float completado = int(round((this->cantPokemonRegistrados*100.0) / this->pokedex->getCantTotal()));
	int completado2 = (int)floor(completado / 2);
	cout << "\n";
	SetColor(2);
	for (int i = 0; i < completado2; i++)
	{
		cout << char(219);
	}
	SetColor(4);
	for (int i = 0; i < 50 - completado2; i++) {

		cout << char(219);
	}
	SetColor(7);
	cout << " " << completado << "% Completado";
	cout << "\nHas capturado " << this->cantPokemonRegistrados << " Pokemon de un total de " << this->pokedex->getCantTotal() << endl;
	cout << "\n" << endl;
}

void SistemaPokemonGoImpl::TransferirPokemon(int ID)
{


	Pokemon* pokemonATransferir = this->pokedex->buscarPokemonID(ID);
	if (pokemonATransferir != nullptr)
	{
		if (pokemonATransferir->EstaCapturado())
		{
			pokemonATransferir->Transferir();

			system("CLS");

			cout << "/// POKEMON TRANSFERIDO AL PROFESOR! \\\"  " << endl;
		}
		else
		{
			system("CLS");
			cout << "####### ERROR: NO HAS CAPTURADO A ESE POKEMON #######" << endl;
		}
	}
	else
	{
		system("CLS");
		cout << "####### ERROR: ESE POKEMON NO EXISTE #######" << endl;
	}

}

void SistemaPokemonGoImpl::TransferirPokemon(string nombre)
{



	Pokemon* pokemonATransferir = this->pokedex->buscarPokemonNombre(nombre);

	if (pokemonATransferir != nullptr)
	{

		if (pokemonATransferir->EstaCapturado())
		{

			pokemonATransferir->Transferir();

			system("CLS");

			cout << "/// POKEMON TRANSFERIDO AL PROFESOR! \\\"  " << endl;
		}
		else
		{

			system("CLS");

			cout << "####### ERROR: NO HAS CAPTURADO A ESE POKEMON #######" << endl;
		}

	}
	else {


		system("CLS");

		cout << "####### ERROR: ESE POKEMON NO EXISTE #######" << endl;
	}
}

SistemaPokemonGoImpl::~SistemaPokemonGoImpl()
{
}
