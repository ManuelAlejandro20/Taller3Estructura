// Taller3Estructura.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include "ArbolB.h"
#include "Menu.h"
#include <iostream>
#include <conio.h>
#include <MMSystem.h>

using namespace std;

int main()
{
	//PlaySound(TEXT("LaCancionDelPokimon.wav"), NULL, SND_SYNC);
	PlaySound(TEXT("Pokimon.wav"), NULL, SND_LOOP | SND_ASYNC);
	
	Menu menu = Menu();
	menu.LeerPokedex();
	menu.MenuPrincipal();


	//ArbolB *b = new ArbolB(7);
	//Pokemon *pika = new Pokemon(24, "Pikachu", "xd", 22);
	//Pokemon *flygon = new Pokemon(350, "Flygon", "xd", 22);
	//Pokemon *chari = new Pokemon(6, "Chorizard", "xd", 22);
	//Pokemon *vena = new Pokemon(3, "Venusaur", "xd", 22);
	//Pokemon *mew = new Pokemon(151, "Mew", "xd", 22);
	//Pokemon *magikarp = new Pokemon(22, "Magikarp", "Aerochorro", 22);
	//Pokemon *hera = new Pokemon(1, "Heracross", "xd", 22);
	//Pokemon *chiko = new Pokemon(50, "chikorita", "xd", 22);
	//Pokemon *blas = new Pokemon(400, "blastoise", "xd", 22);
	//Pokemon *deo = new Pokemon(215, "deoxys", "xd", 22);
	//Pokemon *tro = new Pokemon(20, "tropius", "xd", 22);
	//Pokemon *typlo = new Pokemon(9, "typloshion", "xd", 22);
	//Pokemon *pene = new Pokemon(700, "pene aaaaa", "xd", 22);
	//Pokemon *xd = new Pokemon(51, "xd", "xd", 22);
	//b->agregarDato(pika);
	//b->agregarDato(flygon);
	//b->agregarDato(chari);
	//b->agregarDato(vena);
	//b->agregarDato(mew);
	//b->agregarDato(magikarp);
	//b->agregarDato(hera);
	//b->agregarDato(chiko);
	//b->agregarDato(blas);
	//b->agregarDato(deo);
	//b->agregarDato(tro);
	//b->agregarDato(typlo);
	//b->agregarDato(pene);
	//b->agregarDato(xd);
	//b->imprimir(0);
	//Pokemon *metalgarurumon = b->pokemonAleatorio();
	//while (true) {
	//	cout << metalgarurumon->getID() << "- " << metalgarurumon->getNombre() << endl;
	//	metalgarurumon = b->pokemonAleatorio();
	//}
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
