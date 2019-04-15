#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

#include <string>
#include <vector>
#include <iostream>
#include "Nodo.h"
#include <sstream>

#include <stdlib.h>
#include <time.h>
#include "Texto.h"
#include "InputManager.h"
class Game
{
private:
	Game();
	~Game();
public:

	static Game &GetInstance(); // singleton
	void initialize();
	void loadContent();
	void unLoadContent();
	void update(ALLEGRO_EVENT ev, bool *done);
	void draw(ALLEGRO_DISPLAY *display);
	int contador = 0;
	bool comenzarContador = false;
	int tiempo = 600; // el tiempo en segundos 600 segundos = 10 minutos

	/*------------- Menu ------------*/
	std::vector<Texto*> *menu; // vector de Texto para el menu
	/*------------- Menu ------------*/

	/*------------Pantalla-----------*/
	void cambiarPantalla(int pantalla); // función para cambiar pantalla
	int pantalla = 0; // pantalla por defecto (menu = 0)
	/*------------Pantalla-----------*/

	/*-----------mapa ptr---------*/
	ALLEGRO_FONT *impmuertes;
	int orientacion;//0 Norte, 1 este,2 sur, 3 oeste
	int muertes; // cuenta el numero de veces que mueres
	bool turno;// true cuando es el turno del jugador, false cuando es la CPU
	bool piensa = false; // variable para saber si piensa (sleep)
	bool mato; // Cuando mata  al menos uno el gato
	bool ganar = false; // variable es true cuando se gana
	Nodo *gato; // nodo que apunta donde esta el gato
	Nodo *ptr; // nodo padre del mapa
	Nodo *select; // nodo seleccionado para mover
	ALLEGRO_BITMAP *mapa; // imagen del fondo/mapa
	ALLEGRO_BITMAP *jugador; // imagen del jugador
	ALLEGRO_BITMAP *iaBitmap; // imagen de la ia
	ALLEGRO_BITMAP *libre; // imagen donde hay un espacio libre para mover
	void CrearCamino(Nodo* a, Nodo* b, int dire); // función para crear caminos de un nodo a otro
	bool esAdyancente(Nodo *select, Nodo* b); // función para saber si un nodo es adyacente de otro o no
	std::vector <ALLEGRO_BITMAP*> choose;
	// matrices temporales del mapa
	std::vector< std::vector<const char*> > matrix;
	std::vector< std::vector<Nodo*> > temp;
	InputManager input;// input manager para las reclas
	void matar(); //esto mata chabon

	/*-----------mapa ptr----------*/

	bool dibujar; // es verdadero cuando se quiere actualizar la pantalla
	ALLEGRO_FONT *fuente; // fuente que se utiliza en el menu
	
};

