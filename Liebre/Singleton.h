#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

#include <string>
#include <vector>
#include <iostream>
#include "vertice.h"
#include <sstream>

#include <stdlib.h>
#include <time.h>
#include "Texto.h"
#include "InputManager.h"
class Singleton
{
private:
	Singleton();
	~Singleton();
public:

	static Singleton &recuperarSingleton(); // singleton
	void IniciarValiarbles();
	void traerContenido();
	void destruirContenido();
	void refrescar(ALLEGRO_EVENT evenetos_de_allegro, bool *done);
	void refrescarPantalla(ALLEGRO_DISPLAY *display);
	int contador = 0;
	bool comenzarContador = false;
	int tiempo = 600; // el tiempo en segundos 600 segundos = 10 minutos

	/*------------- Menu ------------*/
	std::vector<Texto*> *menu; // vector de Texto para el menu
	ALLEGRO_BITMAP *fondo;
	ALLEGRO_FONT *fuente2;
	/*------------- Menu ------------*/

	/*------------Pantalla-----------*/
	void ControladorScreen(int screen); // función para cambiar pantalla
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
	Vertice *gato; // nodo que apunta donde esta el gato
	Vertice *ptr; // nodo padre del mapa
	Vertice *select; // nodo seleccionado para mover
	ALLEGRO_BITMAP *mapa; // imagen del fondo/mapa
	ALLEGRO_BITMAP *jugador; // imagen del jugador
	ALLEGRO_BITMAP *iaBitmap; // imagen de la ia
	ALLEGRO_BITMAP *libre; // imagen donde hay un espacio libre para mover
	void ConectarApuntadores(Vertice* ficha1, Vertice* ficha2, int direccion); // función para crear caminos de un nodo a otro
	bool isConectado(Vertice *select, Vertice* b); // función para saber si un nodo es adyacente de otro o no
	// matrices temporales del mapa
	std::vector< std::vector<const char*> > matrix;
	std::vector< std::vector<Vertice*> > temp;
	InputManager input;// input manager para las reclas
	void robar(); //esto mata chabon

	ALLEGRO_BITMAP *ganaste;
	ALLEGRO_BITMAP *perdiste;
	ALLEGRO_BITMAP *mapa2; // imagen de mapa cuando pasa el mouse sobre el boton atras
	ALLEGRO_BITMAP *orienta; // mapa de fondo de orientacion
	ALLEGRO_BITMAP *fondoCrea;
	bool atras;
	/*-----------mapa ptr----------*/

	bool dibujar; // es verdadero cuando se quiere actualizar la pantalla
	ALLEGRO_FONT *fuente; // fuente que se utiliza en el menu
	
};

