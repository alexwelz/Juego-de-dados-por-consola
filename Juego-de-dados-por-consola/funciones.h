#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

using namespace std;

void PresionaUnaTecla();

void Limpiar_Consola();

void Mostrar_Menu();

string Nombre_Jugador1();

string Nombre_Jugador2();

void Inicio_Juego();

int Mostrar_Creditos(int Opcion);

int TirarDado(int caras);

int Dado_Inicial(string Player, int CarasDados);

void Tirar_Dados(int v[], int cant, int caras);

void Mostrar_Dados(int v[], int cant);

int Sumar_Vector(int v[],int cant);

int Suma_Elegida(int cantDados, int v[]);

int Mostrar_Estadisticas(string NombrePuntajeMaximo, int PMaximo,int Opcion);

void Mostrar_Puntaje_Final(string PlayerMax, string PlayerMin, int PuntosPlayer1, int PuntosPlayer2);

int Tirada_Perfecta(int puntosplayer, int bonificacion);

void Mostrar_Reglas();

#endif // FUNCIONES_H_INCLUDED
