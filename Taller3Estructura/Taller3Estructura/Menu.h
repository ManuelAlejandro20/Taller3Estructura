#pragma once
#include "SistemaPokemonGoImpl.h"
#include "Utilidades.h"
#include <string>
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>

using namespace utilidades;

class Menu
{
public:

	Menu();
	void LeerPokedex();
	void MenuPrincipal();
	void SubMenuBuscarPokemon();
	void SubMenuMochila();
	void SubMenuPokedex();
	void Salir();
	~Menu();
	
private:

	SistemaPokemonGoImpl sistema;
};

