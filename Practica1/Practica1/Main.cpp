#include <stdio.h>
#include <conio.h>
#include <Windows.h>

#define TAMANIO_MAPA 70

//int leerTecla(); //Ver que tecla se ha pulsado, devuelve el ASCII de la tecla pulsada
void dibujarMapaYJugador(int posicionJugador); //Dibuja el mapa y el jugador
void moverJugador(int tecla, int &posicionJugador); //Cambia la posicion del jugador en función de la tecla pulsada

													//SI PULSAS LA Q LANZA UNA BALA (<) A LA IZQUIERDA, Y SI PULSAS (W) LANZA UNA BALA HACIA LA DERECHA
void main()
{
	int posicionJugador = 30;
	int tecla;

	dibujarMapaYJugador(posicionJugador);

	while (1)
	{
		if (_kbhit() == 0) //Si se ha pulsado alguna tecla
		{
			tecla = _getch(); //Ver que tecla se ha pulsado, devuelve el ASCII de la tecla pulsada

			moverJugador(tecla, posicionJugador);

			dibujarMapaYJugador(posicionJugador);
		}

		Sleep(5); //Retardo de 50 milisegundos
	}
}

void moverJugador(int tecla, int &posicionJugador)
{
	//printf("%d", tecla);

	if (tecla == 'l' && posicionJugador < TAMANIO_MAPA - 1)
	{
		posicionJugador = posicionJugador + 1;
	}

	if (tecla == 'j' && posicionJugador > 0)
	{
		posicionJugador = posicionJugador - 1;
	}
}

//Dibuja el mapa y el jugador
void dibujarMapaYJugador(int posicionJugador)
{
	for (int i = 0; i < TAMANIO_MAPA; i++)
	{
		if (posicionJugador == i)
		{
			printf("X");
		}
		else
		{
			printf("_");
		}
	}
	printf("\r");
}