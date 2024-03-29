#include "pch.h"
#include "Singleton.h"
Singleton::Singleton() {}
Singleton::~Singleton() {}

// mata 
void Singleton::robar() {
	if (this->gato->este != NULL && mato == false) {
		if (this->gato->este->personaje == 1) {
			if (this->gato->este->este != NULL) {
				if (this->gato->este->este->personaje == 0) {
					this->gato->este->personaje = 0;
					this->gato->personaje = 0;
					this->gato->este->este->personaje = 2;
					this->gato = this->gato->este->este;
					this->turno = true;
					this->mato = true;
				}
			}
		}
	}
	if (this->gato->sureste != NULL && mato == false) {
		if (this->gato->sureste->personaje == 1) {
			if (this->gato->sureste->sureste != NULL) {
				if (this->gato->sureste->sureste->personaje == 0) {
					this->gato->sureste->personaje = 0;
					this->gato->personaje = 0;
					this->gato->sureste->sureste->personaje = 2;
					this->gato = this->gato->sureste->sureste;
					this->turno = true;
					this->mato = true;
				}
			}
		}
	}
	if (this->gato->sur != NULL && mato == false) {
		if (this->gato->sur->personaje == 1) {
			if (this->gato->sur->sur != NULL) {
				if (this->gato->sur->sur->personaje == 0) {
					this->gato->sur->personaje = 0;
					this->gato->personaje = 0;
					this->gato->sur->sur->personaje = 2;
					this->gato = this->gato->sur->sur;
					this->turno = true;
					this->mato = true;
				}
			}
		}
	}
	if (this->gato->suroeste != NULL && mato == false) {
		if (this->gato->suroeste->personaje == 1) {
			if (this->gato->suroeste->suroeste != NULL) {
				if (this->gato->suroeste->suroeste->personaje == 0) {
					this->gato->suroeste->personaje = 0;
					this->gato->personaje = 0;
					this->gato->suroeste->suroeste->personaje = 2;
					this->gato = this->gato->suroeste->suroeste;
					this->turno = true;
					this->mato = true;
				}
			}
		}
	}
	if (this->gato->oeste != NULL && mato == false) {
		if (this->gato->oeste->personaje == 1) {
			if (this->gato->oeste->oeste != NULL) {
				if (this->gato->oeste->oeste->personaje == 0) {
					this->gato->oeste->personaje = 0;
					this->gato->personaje = 0;
					this->gato->oeste->oeste->personaje = 2;
					this->gato = this->gato->oeste->oeste;
					this->turno = true;
					this->mato = true;
				}
			}
		}
	}
	if (this->gato->noroeste != NULL && mato == false) {
		if (this->gato->noroeste->personaje == 1) {
			if (this->gato->noroeste->noroeste != NULL) {
				if (this->gato->noroeste->noroeste->personaje == 0) {
					this->gato->noroeste->personaje = 0;
					this->gato->personaje = 0;
					this->gato->noroeste->noroeste->personaje = 2;
					this->gato = this->gato->noroeste->noroeste;
					this->turno = true;
					this->mato = true;
				}
			}
		}
	}
	if (this->gato->norte != NULL && mato == false) {
		if (this->gato->norte->personaje == 1) {
			if (this->gato->norte->norte != NULL) {
				if (this->gato->norte->norte->personaje == 0) {
					this->gato->norte->personaje = 0;
					this->gato->personaje = 0;
					this->gato->norte->norte->personaje = 2;
					this->gato = this->gato->norte->norte;
					this->turno = true;
					this->mato = true;
				}
			}
		}
	}
	if (this->gato->noreste != NULL && mato == false) {
		if (this->gato->noreste->personaje == 1) {
			if (this->gato->noreste->noreste != NULL) {
				if (this->gato->noreste->noreste->personaje == 0) {
					this->gato->noreste->personaje = 0;
					this->gato->personaje = 0;
					this->gato->noreste->noreste->personaje = 2;
					this->gato = this->gato->noreste->noreste;
					this->turno = true;
					this->mato = true;
				}
			}
		}
	}
	if (mato) {
		muertes++;
	}
}

// recuperar el singleton
Singleton& Singleton::recuperarSingleton()
{
	static Singleton instance;
	return instance;
}

// funci�n para cambiar screen
void Singleton::ControladorScreen(int screen) {
	this->destruirContenido();
	this->pantalla = screen;
	this->IniciarValiarbles();
	this->traerContenido();
	pintar = true;
}

// funci�n para crear un camino de doble v�a
void Singleton::ConectarApuntadores(Vertice* vertice1, Vertice* vertice2, int direccion) {
	switch (direccion)
	{
	case 0:
		vertice1->este = vertice2;
		vertice2->oeste = vertice1;
		break;
	case 1:
		vertice1->sureste = vertice2;
		vertice2->noroeste = vertice1;
		break;
	case 2:
		vertice1->sur = vertice2;
		vertice2->norte = vertice1;
		break;
	case 3:
		vertice1->suroeste = vertice2;
		vertice2->noreste = vertice1;
		break;
	case 4:
		vertice1->oeste = vertice2;
		vertice2->este = vertice1;
		break;
	case 5:
		vertice1->noroeste = vertice2;
		vertice2->sureste = vertice1;
		break;
	case 6:
		vertice1->norte = vertice2;
		vertice2->sur = vertice1;
		break;
	case 7:
		vertice1->noreste = vertice2;
		vertice2->suroeste = vertice1;
		break;
	default:
		break;
	}
}

void Singleton::IniciarValiarbles() {
	pintar = true;
	comenzarContador = false;
	contador = 0;
	switch (pantalla) {
	case 0:
		this->menu = new std::vector<Texto*>();
		tipodeletra = al_load_font("earwig factory rg.ttf", 36, NULL);
		tipoDeLetra2 = al_load_font("earwig factory rg.ttf", 45, NULL);
		fondo = al_load_bitmap("fondo.png");
		break;
	case 1:
		impmuertes = al_load_font("big_noodle_titling.ttf", 25, NULL);
		tipodeletra = al_load_font("earwig factory rg.ttf", 66, NULL);
		arregloMapa = std::vector< std::vector<const char*> >(5);
		listadevertices = std::vector< std::vector<Vertice*> >(5);
		mapa = al_load_bitmap("tablero.png");
		mapa2 = al_load_bitmap("tablero1.png");
		jugador = al_load_bitmap("police.png");
		iaBitmap = al_load_bitmap("ladron.png");
		libre = al_load_bitmap("libre.png");
		ganaste = al_load_bitmap("ganaste.png");
		perdiste = al_load_bitmap("perdiste.png");
		select = NULL;
		turno = true;
		atras = false;
		muertes = 0;
		comenzarContador = true;
		break;

	case 2:
		tipodeletra = al_load_font("big_noodle_titling.ttf", 30, NULL);
		fondoCrea = al_load_bitmap("crea.png");
		break;
	case 3:
		orientacion = 0;
		orienta = al_load_bitmap("orienta.png");

		break;
	}
}

void Singleton::refrescar(ALLEGRO_EVENT evenetos_de_allegro, bool *done) {
	switch (pantalla) {
		case 0: // Menu
		{
			if (evenetos_de_allegro.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				if (evenetos_de_allegro.mouse.button & 1)
				{
					// evenetos_de_allegro.mouse.x evenetos_de_allegro.mouse.pociciony evento del mouse
					int mouseY = evenetos_de_allegro.mouse.y;
					int i = 0;
					for (auto texto : *menu) {
						if (mouseY >= texto->y && mouseY <= texto->y + 35) {
							switch (i) {
							case 0:
								this->ControladorScreen(3);
								break;
							case 1:
								this->ControladorScreen(2);
								break;
							case 2:
								*done = true;
								break;
							}
						}
						i++;
					}
				}
			}
			if (evenetos_de_allegro.type == ALLEGRO_EVENT_MOUSE_AXES) {
				int mouseY = evenetos_de_allegro.mouse.y;
				int i = 0;
				for (auto texto : *menu) {
					if (mouseY >= texto->y && mouseY <= texto->y + 35) {
						texto->select = true;
						pintar = true;
					}
					else {
						texto->select = false;
					}
				}
			}
			break;
		}
		case 1:
		{
			if (evenetos_de_allegro.type == ALLEGRO_EVENT_MOUSE_AXES) {
				int mouseX = evenetos_de_allegro.mouse.x;
				int mouseY = evenetos_de_allegro.mouse.y;
				if (mouseX > 552 && mouseX < 625 && mouseY > 440 && mouseY < 470) {
					atras = true;
					pintar = true;
				}
				else {
					atras = false;
				}
			}
			if ( this->turno == true && this->mato==false)
			{
				if (evenetos_de_allegro.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (evenetos_de_allegro.mouse.button & 1)
					{
						int mouseX = evenetos_de_allegro.mouse.x;
						int mouseY = evenetos_de_allegro.mouse.y;
						Vertice* auxiliar = this->ptr, * aux2 = NULL;
						while (auxiliar != NULL) {
							while (auxiliar != NULL) {
								if (auxiliar->personaje == 1) {
									if (mouseX > auxiliar->pocicionX && mouseX < auxiliar->pocicionX + 46 && mouseY > auxiliar->pociciony && mouseY < auxiliar->pociciony + 34) {
										select = auxiliar;
										pintar = true;
									}
								}
								else if (auxiliar->personaje == 0 && select != NULL && isConectado(select, auxiliar)) {
									if (mouseX > auxiliar->pocicionX && mouseX < auxiliar->pocicionX + 46 && mouseY > auxiliar->pociciony && mouseY < auxiliar->pociciony + 34) {
										auxiliar->personaje = select->personaje;
										select->personaje = 0;
										select = NULL;
										pintar = true;
										this->turno = false;
									}
								}
								aux2 = auxiliar;
								auxiliar = auxiliar->este;
							}
							auxiliar = aux2;
							if (auxiliar->sur == NULL)break;
							auxiliar = auxiliar->sur;
							while (auxiliar != NULL) {
								if (auxiliar->personaje == 1) {
									if (mouseX > auxiliar->pocicionX && mouseX < auxiliar->pocicionX + 46 && mouseY > auxiliar->pociciony && mouseY < auxiliar->pociciony + 34) {
										select = auxiliar;
										pintar = true;
									}
								}
								else if (auxiliar->personaje == 0 && select != NULL && isConectado(select, auxiliar)) {
									if (mouseX > auxiliar->pocicionX && mouseX < auxiliar->pocicionX + 46 && mouseY > auxiliar->pociciony && mouseY < auxiliar->pociciony + 34) {
										auxiliar->personaje = select->personaje;
										select->personaje = 0;
										select = NULL;
										pintar = true;
										this->turno = false;
									}
								}
								aux2 = auxiliar;
								auxiliar = auxiliar->oeste;
							}
							auxiliar = aux2;
							auxiliar = auxiliar->sur;
						}
						if (select != NULL && !pintar) {
							select = NULL;
							pintar = true;
						}

						if (mouseX > 552 && mouseX < 625 && mouseY > 440 && mouseY < 470)
							ControladorScreen(0);
					}
				}
			}
			else {
				this->mato = false;
				robar();
				if (this->mato == false && turno == false) {

					std::vector<Vertice*> aleatorio = std::vector<Vertice*>();
					if (this->gato->este != NULL) {
						if (this->gato->este->personaje == 0) {
							aleatorio.push_back(this->gato->este);
						}
					}
					if (this->gato->sureste != NULL) {
						if (this->gato->sureste->personaje == 0) {
							aleatorio.push_back(this->gato->sureste);
						}
					}
					if (this->gato->sur != NULL) {
						if (this->gato->sur->personaje == 0) {
							aleatorio.push_back(this->gato->sur);
						}
					}
					if (this->gato->suroeste != NULL) {
						if (this->gato->suroeste->personaje == 0) {
							aleatorio.push_back(this->gato->suroeste);
						}
					}
					if (this->gato->oeste != NULL) {
						if (this->gato->oeste->personaje == 0) {
							aleatorio.push_back(this->gato->oeste);
						}
					}
					if (this->gato->noroeste != NULL) {
						if (this->gato->noroeste->personaje == 0) {
							aleatorio.push_back(this->gato->noroeste);
						}
					}
					if (this->gato->norte != NULL) {
						if (this->gato->norte->personaje == 0) {
							aleatorio.push_back(this->gato->norte);
						}
					}
					if (this->gato->noreste != NULL) {
						if (this->gato->noreste->personaje == 0) {
							aleatorio.push_back(this->gato->noreste);
						}
					}
					if (aleatorio.size() != 0) {
						this->gato->personaje = 0;
						int indice = rand() % aleatorio.size();
						aleatorio[indice]->personaje = 2;
						this->gato = aleatorio[indice];
					}
					else {
						al_rest(0.5);
						al_draw_bitmap(ganaste, 0, 0, NULL);
						al_flip_display();
						al_rest(5);
						ControladorScreen(0);
					}
				}
				this->piensa = true;
				this->pintar = true;
				this->turno = true;

			}
			if (contador >= tiempo)
				pintar = true;
			break;
		}
		case 2:
		{
			if (input.isKeyPressed(evenetos_de_allegro, ALLEGRO_KEY_BACKSPACE)) {
				ControladorScreen(0);
			}
			break;
		}
		case 3:
		{
			if (input.isKeyPressed(evenetos_de_allegro, ALLEGRO_KEY_Q)) {
				orientacion = 0;
				ControladorScreen(1);
			}
			else if(input.isKeyPressed(evenetos_de_allegro, ALLEGRO_KEY_W)){
				orientacion = 1;
				ControladorScreen(1);

			}
			else if (input.isKeyPressed(evenetos_de_allegro, ALLEGRO_KEY_E)) {
				orientacion = 2;
				ControladorScreen(1);
			}
			else if (input.isKeyPressed(evenetos_de_allegro, ALLEGRO_KEY_R)) {
				orientacion = 3;
				ControladorScreen(1);
			}
			break;
		}
	}
}

void Singleton::refrescarPantalla(ALLEGRO_DISPLAY *display) {
	switch (pantalla) {
	case 0: {
		al_draw_bitmap(fondo, 0, 0, NULL);
		al_draw_filled_rectangle(220, 100, 420, 350, al_map_rgba(0, 0, 0, 255*0.5));
		int i = 0;
		// recorrer el menu
		for (auto texto : *menu) {
			// se pinta de diferente color si esta seleccionado 
			if(texto->select)
				texto->draw(tipoDeLetra2, 214, 19, 36, ALLEGRO_ALIGN_CENTER);
			else
				texto->draw(tipodeletra, 255, 255, 255, ALLEGRO_ALIGN_CENTER);
			i++;
		}
		break;
	}
	case 1: {
		// dibujo el fondo
		if(!atras)al_draw_bitmap(mapa, 0, 0, NULL);
		else al_draw_bitmap(mapa2, 0, 0, NULL);
		Vertice* aux = this->ptr, *aux2 = NULL;
		if (this->piensa == true) {
			al_rest(0.8);
			piensa = false;
		}
		// recorro los nodos pociciony los dibujo 
		while (aux != NULL) {
			while (aux != NULL) {
				if (aux->personaje == 1) {
					al_draw_bitmap(jugador, aux->pocicionX, aux->pociciony, ALLEGRO_ALIGN_CENTER);
				}
				else if (aux->personaje == 2) {
					al_draw_bitmap(iaBitmap, aux->pocicionX, aux->pociciony, ALLEGRO_ALIGN_CENTER);
				}
				else if (select != NULL) {
					if (isConectado(select, aux))
						al_draw_bitmap(libre, aux->pocicionX, aux->pociciony, ALLEGRO_ALIGN_CENTER);
				}
				aux2 = aux;
				aux = aux->este;
			}
			aux = aux2;
			if (aux->sur == NULL)break;
			aux = aux->sur;
			while (aux != NULL) {
				if (aux->personaje == 1) {
					al_draw_bitmap(jugador, aux->pocicionX, aux->pociciony, ALLEGRO_ALIGN_CENTER);
				}
				else if (aux->personaje == 2) {
					al_draw_bitmap(iaBitmap, aux->pocicionX, aux->pociciony, ALLEGRO_ALIGN_CENTER);
				}
				else if (select != NULL) {
					if (isConectado(select, aux))
						al_draw_bitmap(libre, aux->pocicionX, aux->pociciony, ALLEGRO_ALIGN_CENTER);
				}
				aux2 = aux;
				aux = aux->oeste;
			}
			aux = aux2;
			aux = aux->sur;
		}
		al_draw_textf(impmuertes, al_map_rgb(0, 0, 0), 355, 10, ALLEGRO_ALIGN_LEFT, "Robados: %d", this->muertes);
		if (muertes >= 3) {
			al_flip_display();
			al_rest(0.5);
			al_draw_bitmap(perdiste, 0, 0, NULL);
			al_flip_display();
			al_rest(4);
			al_clear_to_color(al_map_rgb(0, 0, 0));
			ControladorScreen(0);
			this->refrescarPantalla(display);
		}

		if (contador > tiempo) {
			al_draw_text(tipodeletra, al_map_rgb(0, 0, 0), 300, 200, ALLEGRO_ALIGN_CENTER, "TIME OUT!");
			al_flip_display();
			al_rest(2);
			ControladorScreen(0);
		}
		break;
	}
	case 2: {
		al_draw_bitmap(fondoCrea, 0, 0, NULL);
		al_draw_multiline_text(tipodeletra, al_map_rgb(0, 0, 0), 320, 80, 550, 25, ALLEGRO_ALIGN_CENTER, "Integrantes \n\n Ernesto García Fernandez de castro 2018114029 \n Dailer Ebrath 2017114035 \n Eliecer Zúñiga Ortiz 2017114120 \n Rubén Darío Fernández de castro 2018114024");
		break;
	}
	case 3: {
		al_draw_bitmap(orienta, 0, 0, NULL);
		break;
	}
	}

}

void Singleton::traerContenido(){
	switch (pantalla) {
	case 0: {
		// creando las opciones del menu
		menu->push_back(new Texto("Comenzar"));
		menu->push_back(new Texto("Creadores"));
		menu->push_back(new Texto("Salir"));
		int i = 0;
		// colocando la posici�n de las opciones de menu
		for (auto texto : *menu) {
			texto->pocicionX = 320;
			texto->y = 140 + 70 * i;
			i++;
		}
		break;
	}
	case 1:
	{
		for (int i = 0; i < 5; i++)
			arregloMapa[i].resize(5);
		for (int i = 0; i < 5; i++)
			listadevertices[i].resize(5);
		int margin = 96, posX = 16, posY = 36;

		// creaci�n del mapa
		switch (this->orientacion)
		{
		case 0:
		{
			arregloMapa[0][2] = "1.";
			arregloMapa[1][2] = "0 ";
			arregloMapa[2][2] = "2.";
			arregloMapa[3][2] = "0 ";
			arregloMapa[4][2] = "1.";
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++) {
					if (i < 2) {
						if ((j + i) % 2 == 0) {
							arregloMapa[j][i] = "1.";
						}
						else {
							arregloMapa[j][i] = "1 ";
						}
					}
					else
					{
						if ((i + j) % 2 == 0) {
							arregloMapa[j][i] = "0.";
						}
						else {
							arregloMapa[j][i] = "0 ";
						}
					}
				}
			}
			
			break;

		}
		case 1:
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++) {
					if (i > 2) {
						if ((i + j) % 2 == 0) {
							arregloMapa[i][j] = "1.";
						}
						else {
							arregloMapa[i][j] = "1 ";
						}
					}
					else
					{
						if ((i + j) % 2 == 0) {
							arregloMapa[i][j] = "0.";
						}
						else {
							arregloMapa[i][j] = "0 ";
						}
					}
				}
			}
			arregloMapa[2][0] = "1.";
			arregloMapa[2][1] = "0 ";
			arregloMapa[2][2] = "2.";
			arregloMapa[2][3] = "0 ";
			arregloMapa[2][4] = "1.";
			break;
		}
		case 2:
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++) {
					if (i < 2) {
						if ((i + j) % 2 == 0) {
							arregloMapa[i][j] = "1.";
						}
						else {
							arregloMapa[i][j] = "1 ";
						}
					}
					else
					{
						if ((i + j) % 2 == 0) {
							arregloMapa[i][j] = "0.";
						}
						else {
							arregloMapa[i][j] = "0 ";
						}
					}
				}
			}
			arregloMapa[2][0] = "1.";
			arregloMapa[2][1] = "0 ";
			arregloMapa[2][2] = "2.";
			arregloMapa[2][3] = "0 ";
			arregloMapa[2][4] = "1.";
			break;
		}
		case 3:
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++) {
					if (i > 2) {
						if ((i + j) % 2 == 0) {
							arregloMapa[j][i] = "1.";
						}
						else {
							arregloMapa[j][i] = "1 ";
						}
					}
					else
					{
						if ((i + j) % 2 == 0) {
							arregloMapa[j][i] = "0.";
						}
						else {
							arregloMapa[j][i] = "0 ";
						}
					}
				}
			}
			arregloMapa[0][2] = "1.";
			arregloMapa[1][2] = "0 ";
			arregloMapa[2][2] = "2.";
			arregloMapa[3][2] = "0 ";
			arregloMapa[4][2] = "1.";

			break;


		}

		}
		// creaci�n de nodos
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++) {
				// conversi�n de string vertice1 entero de la arregloMapa
				std::stringstream strValue;
				strValue << arregloMapa[i][j][0];
				int intValue;
				strValue >> intValue;
				// creaci�n del nodo su distancia(margin) pociciony su posici�n de la esquina
				listadevertices[i][j] = new Vertice((j * margin) + posX, (i * margin) + posY, intValue);
			}
		}
		this->gato = listadevertices[2][2];
		// conectando caminos entre nodos
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (arregloMapa[i][j][1] == '.') {
					//derecha
					if (j + 1 < 5) { 
						ConectarApuntadores(listadevertices[i][j], listadevertices[i][j + 1], 0);
					}
					//diagonal derecha inferior
					if ((j + 1 < 5) && (i + 1 < 5)) {
						ConectarApuntadores(listadevertices[i][j], listadevertices[i + 1][j + 1], 1);
					}
					//abajo
					if (i + 1 < 5) {
						ConectarApuntadores(listadevertices[i][j], listadevertices[i + 1][j], 2);
					}
					//diagonal inferior izquierda
					if ((i + 1) < 5 && (j - 1) > -1) {
						ConectarApuntadores(listadevertices[i][j], listadevertices[i + 1][j - 1], 3);
					}
				}
				else {
					//derecha
					if (j + 1 < 5) {
						ConectarApuntadores(listadevertices[i][j], listadevertices[i][j + 1], 0);
					}
					//abajo
					if (i + 1 < 5) {
						ConectarApuntadores(listadevertices[i][j], listadevertices[i + 1][j], 2);
					}
				}
			}
		}
		// imprimir arregloMapa temporal
		
		// colocando el primer nodo como padre
		this->ptr = listadevertices[0][0];
		break;
	}
	}
}

//quitar el contenido
void Singleton::destruirContenido() {
	switch (pantalla) {
	case 0:
		free(menu);
		al_destroy_font(tipodeletra);
		al_destroy_bitmap(fondo);
		al_destroy_font(tipoDeLetra2);
		break;
	case 1:
		al_destroy_bitmap(mapa);
		al_destroy_bitmap(jugador);
		al_destroy_bitmap(iaBitmap);
		al_destroy_bitmap(libre);
		al_destroy_font(tipodeletra);
		al_destroy_bitmap(ganaste);
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				delete listadevertices[i][j];
			}
		}
		arregloMapa.clear();
		listadevertices.clear();

		break;
	case 2:
		al_destroy_font(tipodeletra);
		al_destroy_bitmap(fondoCrea);
		break;
	case 3: {
		al_destroy_bitmap(orienta);
		break;
	}
	}
}

bool Singleton::isConectado(Vertice *seleccionada, Vertice *otro) {
	return (seleccionada->sur == otro || seleccionada->este == otro || seleccionada->oeste == otro ||  seleccionada->norte == otro || seleccionada->sureste == otro || seleccionada->suroeste == otro || seleccionada->noreste == otro || seleccionada->noroeste == otro);
}