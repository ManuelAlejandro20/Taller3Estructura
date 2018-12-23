#include "pch.h"
#include "Pokemon.h"


Pokemon::Pokemon()
{
}

Pokemon::Pokemon(int ID, string nombre, string ataque, float probabilidadFija)
{
	capitalize(nombre);
	this->ID = ID;
	this->nombre = nombre;
	this->ataque = ataque;
	this->probabilidadFija = probabilidadFija * 100; // Se multiplica por 100 porque en el archivo Pokedex.txt las probabilidades fijas tienen valores entre 0 y 1

	this->PC = "0";
	this->HP = "0";
	this->IV = "0";

	this->cantVecesCapturado = 0;
	this->capturado = false;
}

void Pokemon::CambiarEstadisticas(string PC, string HP, string IV)
{

	this->PC = PC;
	this->HP = HP;
	this->IV = IV;
}

void Pokemon::DesplegarPokemonPokedex()
{
	cout << "\n- ID: " + to_string(this->ID) + "; Nombre: " + this->nombre + "; Cantidad de veces capturado: " + to_string(this->cantVecesCapturado) + "\n" << endl;
}

void Pokemon::DesplegarPokemonMochila()
{
	cout << "\n- ID: " + to_string(this->ID) + "; Nombre: " + this->nombre + "\n" << endl;
}

void Pokemon::DesplegarPokemon()
{
	cout
		<< "\n- ID: " + to_string(this->ID) + "\n"
		<< "\n- Nombre: " + this->nombre + "\n"
		<< "\n- Ataque: " + this->ataque + "\n"
		<< "\n- PC: " + this->PC + "\n"
		<< "\n- HP: " + this->HP + "\n"
		<< "\n- IV: " + this->IV + "\n"
		<< endl;
}

void Pokemon::Capturar()
{
	this->capturado = true;
}

void Pokemon::Transferir()
{
	this->capturado = false;
}

void Pokemon::AumentarCantVecesCapturado()
{
	this->cantVecesCapturado += 1;
}

int Pokemon::getID()
{
	return this->ID;
}

string Pokemon::getNombre()
{
	return this->nombre;
}

float Pokemon::getProbabilidadFija()
{
	return this->probabilidadFija;
}

int Pokemon::getCantVecesCapturado()
{
	return this->cantVecesCapturado;
}

bool Pokemon::EstaCapturado()
{
	return this->capturado;
}

float Pokemon::getProbabilidadCaptura()
{

	float probabilidadCaptura = (this->probabilidadFija + (rand() % 101)) / 2;
	return probabilidadCaptura;
}


Pokemon::~Pokemon()
{
}
