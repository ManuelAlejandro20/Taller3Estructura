#include "pch.h"
#include "conio.h"
#include "Menu.h"
#include "Utilidades.h"

constexpr auto UP = 72;
constexpr auto DOWN = 80;
constexpr auto ENTER = 13;
constexpr auto LEFT = 75;
constexpr auto RIGHT = 77;
using namespace utilidades;

Menu::Menu()
{
	sistema = SistemaPokemonGoImpl();
}

void Menu::LeerPokedex()
{
	string linea; // Crea un string en el que guarda cada linea de texto
	ifstream archivo;
	archivo.open("Pokedex.txt"); // Abre el archivo Campos.txt

	if (archivo.fail()) { // Si el archivo no existe o no se encuentra registra el error

		cout << "No se pudo abrir el archivo Campos.txt" << endl;

		system("PAUSE");
	}

	while (getline(archivo, linea)) { // Lee el archivo linea por linea


		stringstream ss(linea); // Permite extraer cadenas de texto de la linea

		while (!ss.eof()) { // Minetras la linea no se haya acabado

			string ID;
			string nombre;
			string ataque;
			string probabilidadFija;

			getline(ss, ID, ',');
			getline(ss, nombre, ',');
			getline(ss, ataque, ',');
			getline(ss, probabilidadFija, ',');
			try {

				Pokemon* nuevoPokemon = new Pokemon(stoi(ID), nombre, ataque, stof(probabilidadFija));

				sistema.AgregarPokemon(nuevoPokemon);
			}
			catch (...) {
			}
		}


	}
	archivo.close(); // Se cierra el archivo

}

void Menu::MenuPrincipal()
{
	bool salir = false; // Permite matener el menu en un loop infinito 
	int pos, posact; // variables que nos indican la posicion actual y el valor numero de flecha presionada
	ShowConsoleCursor(false); // oculta el cursor
	while (!salir) {
		system("cls");
		pos = posact = 0;
		int colores[4] = { 12,7,7,7 }; // arreglo con los colores a utilizar, tiene el mismo largo que las opciones disponibles
		while (pos != ENTER) { // mientras no se presione enter
			system("title Pokemon GO - Versi๓n consola de Windows");
			cout << " \t\t\t\t\tษอออออออออออออออออออออออออออออออป\n" <<
				" \t\t\t\t\tบ       Sistema Pokemon GO      บ\n" <<
				" \t\t\t\t\tศอออออออออออออออออออออออออออออออผ\n" << endl;
			string opciones[4] = { "[1] Buscar Pokemon" , // arreglo con las opciones disponibles
								   "[2] Pokedex",
								   "[3] Mochila",
								   "[4] Salir" };
			for (int i = 0; i < 4; i++) {
				SetColor(colores[i]); cout << opciones[i] << endl; SetColor(7); // cada vez que se despliegan las opciones se muestran con el color que le corresponde en el arreglo colores
			}
			pos = _getch(); // obtiene el valor de la flecha presionada
			colores[posact] = 7; // se cambia de color porque en el switch de adelante si o si cambiara de posicion (en caso de ingresar otra tecla se vuelve a poner el color rojo)
			switch (pos) {
			case UP: // si presiona arriba solo se mueve hacia ese lado si su posicion actual es distinta de 0
				if (posact == 0) {
					posact = 0;
				}
				else {
					posact--;
				}
				colores[posact] = 12; //el color de la posicion actual pasara a ser rojo, mostrando al usuario que se ha movido de posicion
				break;
			case DOWN: //si presiono abajo solo se mueve hacia ese lado si su posicion actual es distinta de 3
				if (posact == 3) {
					posact = 3;
				}
				else {
					posact++;
				}
				colores[posact] = 12; //el color de la posicion actual pasara a ser rojo, mostrando al usuario que se ha movido de posicion
				break;
			default: // si presiono cualquier otra tecla el color se mantiene en la opcion 
				colores[posact] = 12;
				break;
			}

			limpiar(); // limpia la consola 
			//el algoritmo mostrado es igual para todos los otros menues que se muestran, algunos sufren variaciones que dependen de la cantidad de opciones que se de al usuario
			//para resumir se podria decir que nos estamos moviendo dentro de un rango de numeros (que corresponden a las opciones) y dependiendo de donde estemos se ira activando un determinado color
		}

		switch (posact) { // segun la ultima posicion que obtuvimos entraremos a una opcion o la otra

		case 0:
			SubMenuBuscarPokemon();
			break;
		case 1:
			SubMenuPokedex();
			break;
		case 2:
			SubMenuMochila();
			break;
		case 3:
			Salir();
			salir = true;
			system("cls");
			cout << "-------- Has cerrado el juego con exito! ------" << endl;
			break;

		}
	}
}

void Menu::SubMenuBuscarPokemon()
{
	int intentos = 0; // Cuenta cuantas veces ha intentado el jugador atrapar al pokemon
	if (rand() % 101 <= 15) {
		system("CLS");
		cout << "-------- NO HAY NINGUN POKEMON CERCA! --------" << endl;
		system("PAUSE");
	}
	else {

		bool salir = false; // Permite matener el menu en un loop infinito para cuando se ingrese una opcion numerica no valida
		int pos, posact;
		pos = posact = 0;
		Pokemon* randomPokemon = sistema.PokemonAleatorio(); // Se busca un pokemon aleatorio

		/*
			Estas son las estadisticas del pokemon encontrado
		*/

		string PC = to_string(rand() % 4000 + 10); // Aleatorio entre 10 y 4000
		string HP = to_string(rand() % 375 + 15); // Aleatorio entre 15 y 375
		string IV = to_string(rand() % 101); // Aleatorio entre 0 y 100

		while (!salir && intentos < 3) {

			system("CLS");
			int colores[2] = { 2,7 };
			while (pos != ENTER) {
				string opciones[2] = { "Capturar" ,"Huir" };
				cout << "Un " << randomPokemon->getNombre() + " salvaje! " << endl;
				cout << "--> PC: " + PC + "\n" << endl;

				cout << "บ Que es lo que deseas hacer บ";
				SetColor(colores[0]);  cout << "\tCAPTURAR"; SetColor(7);
				SetColor(colores[1]);  cout << "\tHUIR" << endl; SetColor(7);
				pos = _getch();
				colores[posact] = 7;
				switch (pos) {
				case LEFT:
					if (posact == 0) {
						posact = 0;
					}
					else {
						posact--;
					}
					colores[posact] = 2;
					break;
				case RIGHT:
					if (posact == 1) {
						posact = 1;
					}
					else {
						posact++;
					}
					colores[posact] = 2;
					break;
				default:
					colores[posact] = 2;
					break;
				}

				limpiar();
			}

			switch (posact) {
			case 0:
				if (randomPokemon->getProbabilidadCaptura() > 45) { // pokemon capturado
					sistema.CapturarPokemon(randomPokemon, PC, HP, IV);
					system("CLS");
					cout << "//// " + randomPokemon->getNombre() + " HA SIDO CAPTURADO! \\\\" << endl;
					system("PAUSE");
					salir = true;
					break;
				}
				else { //pokemon huy๓
					intentos += 1;
					system("CLS");
					cout << "//// HA FALTADO POCO U-U! \\\\" << endl;
					system("PAUSE");
				}
				pos = 0;
				continue;
			case 1://opcion huida
				system("CLS");
				cout << "|| ESCAPASTE SIN PROBLEMAS! ||" << endl;
				system("PAUSE");
				salir = true;
				break;
			}
		}
		if (intentos >= 3) {//si nos excedemos en los intentos el pokemon escapa
			system("CLS");
			cout << "/// EL POKEMON SE HA ESCAPADO D: !\\\\" << endl;
			system("PAUSE");
		}
	}
}

void Menu::SubMenuMochila()
{

	bool salir = false; // Permite matener el menu en un loop infinito para cuando se ingrese una opcion numerica no valida
	int pos, posact;

	while (!salir) {
		system("CLS");
		pos = posact = 0;
		int colores[5] = { 12,7,7,7,7 };
		while (pos != ENTER) {
			cout << "||-------ACCEDISTE A TU MOCHILA-------||\n" << endl;
			string opciones[5] = { "[1] Ver listado de Pokemon" ,
								   "[2] Ver detalles de un Pokemon",
								   "[3] Estadisticas",
								   "[4] Transferir un Pokemon",
								   "[5] Salir" };
			for (int i = 0; i < 5; i++) {
				SetColor(colores[i]); cout << opciones[i] << endl; SetColor(7);
			}
			pos = _getch();
			colores[posact] = 7;
			switch (pos) {
			case UP:
				if (posact == 0) {
					posact = 0;
				}
				else {
					posact--;
				}
				colores[posact] = 12;
				break;
			case DOWN:
				if (posact == 4) {
					posact = 4;
				}
				else {
					posact++;
				}
				colores[posact] = 12;
				break;
			default:
				colores[posact] = 12;
				break;
			}

			limpiar();
		}
		switch (posact) {
		case 0://listado de pokemon capturados
			system("CLS");
			cout << "||-------POKEMON ATRAPADOS HASTA AHORA-------||" << endl;
			sistema.DesplegarMochila();
			system("PAUSE");
			continue;
		case 1:
		{//busca un pokemon capturado por id o nombre
			system("CLS");
			string pokemonIdentifierInput; // Almacena el input del usuario, luego se analiza si es un ID o no
			cout << "\nIngrese la ID o el nombre de un Pokemon: ";
			getline(cin, pokemonIdentifierInput);
			// Si es un ID se llama al metodo que recive como parametro una ID, en caso contrario al que recive como parametro a un string
			if (isNumericalInput(pokemonIdentifierInput)) {
				try {
					sistema.DesplegarPokemon(stoi(pokemonIdentifierInput));
				}
				catch (...) {

				}
			}
			else {
				sistema.DesplegarPokemon(pokemonIdentifierInput);
			}
			system("PAUSE");
		}
		continue;

		case 2: // despliega las estadisticas
			system("cls");
			sistema.DesplegarEstadisticas();
			system("PAUSE");
			continue;

		case 3: // transfiere un pokemon al profesor
		{ //Las llaves estan porque si no se ponen se le es imposible al compilador reservar memoria para las variables creadas en el case
			system("CLS");
			string pokemonIdentifierInput; // Almacena el input del usuario, luego se analiza si es un ID o no
			cout << "\nIngrese la ID o el nombre de un Pokemon: ";
			getline(cin, pokemonIdentifierInput);
			// Si es un ID se llama al metodo que recibe como parametro una ID, en caso contrario al que recive como parametro a un string
			if (isNumericalInput(pokemonIdentifierInput)) {
				try {
					sistema.TransferirPokemon(stoi(pokemonIdentifierInput));
				}
				catch (...) {
				}
			}
			else {
				sistema.TransferirPokemon(pokemonIdentifierInput);
			}
			system("PAUSE");
		}
		continue;
		case 4:
			salir = true;
			break;
		}
	}
}

void Menu::SubMenuPokedex()
{
	bool salir = false; // Permite matener el menu en un loop infinito para cuando se ingrese una opcion numerica no valida
	int pos, posact;
	while (!salir) {
		pos = posact = 0;
		int colores[4] = { 12,7,7,7 };
		while (pos != ENTER) {
			system("CLS");
			cout << "บ -------POKEDEX------- บ\n" << endl;
			string opciones[4] = { "[1] Buscar Pokemon por ID" ,
								   "[2] Buscar Pokemon por nombre",
								   "[3] Desplegar PokeDex",
								   "[4] Salir" };
			for (int i = 0; i < 4; i++) {
				SetColor(colores[i]); cout << opciones[i] << endl; SetColor(7);
			}
			pos = _getch();
			colores[posact] = 7;
			switch (pos) {
			case UP:
				if (posact == 0) {
					posact = 0;
				}
				else {
					posact--;
				}
				colores[posact] = 12;
				break;
			case DOWN:
				if (posact == 3) {
					posact = 3;
				}
				else {
					posact++;
				}
				colores[posact] = 12;
				break;
			default:
				colores[posact] = 12;
				break;
			}

			limpiar();
		}

		switch (posact) {
		case 0: // Las llaves estan porque si no se ponen al compilador le es imposible reservar memoria para las variables creadas dentro del case
		{//busca pokemon por id
			system("CLS");
			string IDPokemon;
			cout << "\nIngrese la ID de un Pokemon: ";
			getline(cin, IDPokemon);
			while (!isNumericalInput(IDPokemon)) {
				system("CLS");
				cout << "\n######### ERROR: INGRESE UN NUMERO POR FAVOR #########\n" << endl;
				system("PAUSE");
				system("CLS");
				cout << "\nIngrese la ID de un Pokemon: ";
				getline(cin, IDPokemon);
			}
			try {
				system("CLS");
				sistema.BuscarPokemonPokedex(stoi(IDPokemon));
			}
			catch (...) {
			}
			system("PAUSE");
		}
		continue;
		case 1: // Las llaves estan porque si no se ponen al compilador le es imposible reservar memoria para las variables creadas dentro del case
		{//busca pokemon por nombre
			system("CLS");
			string nombrePokemon;
			cout << "\nIngrese nombre de un Pokemon: ";
			getline(cin, nombrePokemon);
			sistema.BuscarPokemonPokedex(nombrePokemon);
			system("PAUSE");
		}
		continue;
		case 2://despliega la pokedex nacional
			system("CLS");
			cout << "||-------POKEDEX NACIONAL-------||" << endl;
			sistema.DesplegarPokedex();
			system("PAUSE");
			continue;

		case 3:
			Salir();
			salir = true;
			break;
		}
	}
}

void Menu::Salir()
{
}

Menu::~Menu()
{
}
