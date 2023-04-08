#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstring>
#include <ctype.h>
#include "rlutil.h"
#include "funciones.h"

using namespace std;

void PresionaUnaTecla()
{
    rlutil::anykey();
}

void Limpiar_Consola()
{
    rlutil::cls();
}

void Mostrar_Menu()
{
    rlutil :: setColor(rlutil :: WHITE);
    cout<<"BIENVENIDOS A REVENGE "<<endl;
    rlutil :: setColor(rlutil :: CYAN);
    cout<<"-------------------"<<endl;
    cout<<" 1- JUGAR "<<endl;
    cout<<" 2- ESTADÍSTICAS "<<endl;
    cout<<" 3- CRÉDITOS "<<endl;
    cout<<" 4- CÓMO JUGAR "<<endl;
    cout<<"-------------------"<<endl;
    cout<<" 0- SALIR "<<endl<<endl;
}

string Nombre_Jugador1()
{
    string jugador1;
    cout<<"Ingrese el nombre de los jugadores.."<<endl<<endl;
    cout<<"Nombre Player 1:"<<endl;
    cin>>jugador1;
    return jugador1;
}

string Nombre_Jugador2()
{
    string jugador2;
    cout<<"Nombre Player 2:"<<endl;
    cin>>jugador2;
    return jugador2;
}

int Mostrar_Creditos(int Opcion)
{
    cout<<endl<< "--------------------------" << endl;
    cout<<"Desarrollador del juego: ";
    cout<<endl<< "--------------------------";
    cout<<endl<<"Welz Alex Gustavo"<<endl;
    cout<< "--------------------------"<<endl<<endl<<endl;
    cout << "------------------------- Presione una tecla para regresar al menú -------------------------"<<endl;
    rlutil::anykey();
    Limpiar_Consola();
}

void Inicio_Juego()
{
    cout<<"VAMOS A COMENZAR CON EL JUEGO!"<<endl<<endl;
    cout<<"#####################################################################"<<endl;
    cout<<"# EL JUGADOR QUE SAQUE EL DADO CON MAYOR VALOR COMIENZA LA PARTIDA!!#"<<endl;
    cout<<"#####################################################################"<<endl;
    rlutil::anykey();
    Limpiar_Consola();
    cout<<"Seleccionen el dado para su primera tirada!!"<<endl;
}

void Mostrar_Dados(int v[], int cant)
{
    rlutil :: setColor(rlutil :: YELLOW);
    cout<< "-------------------------"<<endl;
    for(int x=0; x<cant; x++)
    {
        cout<<"Dado "<<x+1<<": "<< v[x]<<endl;
    }
    cout<< "-------------------------"<<endl;

}

int Sumar_Vector(int v[],int cant)
{
    int suma=0;
    for(int x=0; x<cant; x++)
    {
        suma+=v[x];
    }
    return suma;
}

int Suma_Elegida(int cantDados, int v[])
{
    int DadoElegido, Suma_Seleccionada = 0;
    bool vBandera[cantDados]={};
    for(int x=0; x<cantDados; x++)
    {
        cout<<"Elija un dado "<<" ";
        cin>>DadoElegido;
        if(vBandera[DadoElegido-1] == false)
        {
            Suma_Seleccionada+=v[DadoElegido-1];
            vBandera[DadoElegido-1]=true;
        }
        else
        {
            cout<<"Dado repetido, vuelva a ingresar otro dado"<<endl;
            cantDados++;
        }
    }
    cout<<"Tus dados seleccionados dan un valor de: "<<Suma_Seleccionada<<"."<<endl<<endl;
    return Suma_Seleccionada;
}

void Tirar_Dados(int v[], int cant, int caras)
{
    for(int x=0; x<cant; x++)
    {
        v[x]= 1 + rand()%caras;

    }
}

int TirarDado(int caras)
{
    int DadoAleatorio;
    DadoAleatorio = 1 + rand()%caras;
    return DadoAleatorio;
}
int Dado_Inicial(string Player, int CarasDados)
{
    int dado1;
    cout<<Player<<" Presione una tecla para arrojar su dado..."<<endl;
    rlutil::anykey();
    dado1=TirarDado(CarasDados);
    rlutil :: setColor(rlutil :: YELLOW);
    cout<<"Obtuviste un "<<dado1<<endl<<endl;
    rlutil :: setColor(rlutil :: CYAN);
    return dado1;
    rlutil::anykey();
    Limpiar_Consola();
}

int Mostrar_Estadisticas(string NombrePuntajeMaximo, int PMaximo,int Opcion)
{
    cout<<endl<< "-------------------------"<<endl;
    cout<< "Nombre de Usuario: " << NombrePuntajeMaximo
    << endl << "Puntuacion máxima: " << PMaximo << endl << endl;
    cout<< "-------------------------"<<endl<<endl<<endl;
    cout << "------------------------- Presione una tecla para regresar al menú -------------------------"<<endl;
    rlutil::anykey();
    Limpiar_Consola();
    {
        return 0;
    }
    Limpiar_Consola();
}

void Mostrar_Puntaje_Final(string PlayerMax, string PlayerMin, int PuntosPlayer1, int PuntosPlayer2)
{
    rlutil :: setColor(rlutil :: WHITE);
    cout<<" PUNTUACIÓN FINAL "<<endl<<endl;
    rlutil :: setColor(rlutil :: CYAN);
    cout<<PlayerMax<<": "<<PuntosPlayer1<<" PUNTOS"<<endl<<endl;
    cout<<PlayerMin<<": "<<PuntosPlayer2<<" PUNTOS"<<endl<<endl;

    if(PuntosPlayer1 > PuntosPlayer2)
    {
        rlutil :: setColor(rlutil :: GREEN);
        cout<<"El ganador es "<<PlayerMax<<" con "<<PuntosPlayer1<<" puntos!!!"<<endl;
        rlutil :: setColor(rlutil :: CYAN);
        rlutil::anykey();
        Limpiar_Consola();
    }
    else
    {
        if(PuntosPlayer2 > PuntosPlayer1)
        {
            rlutil :: setColor(rlutil :: GREEN);
            cout<<"El ganador es "<<PlayerMin<<" con "<<PuntosPlayer2<<" puntos!!!"<<endl;
            rlutil :: setColor(rlutil :: CYAN);
            rlutil::anykey();
            Limpiar_Consola();
        }
        else
        {
            rlutil :: setColor(rlutil :: RED);
            cout<<"OCURRIO UN EMPATE!!!! "<<endl;
            rlutil :: setColor(rlutil :: CYAN);
            rlutil::anykey();
            Limpiar_Consola();
        }
    }
}

int Tirada_Perfecta(int puntosplayer, int bonificacion)
{
    rlutil :: setColor(rlutil :: YELLOW);
    int puntajeFinal;
    puntajeFinal = puntosplayer+=bonificacion;
    cout<<"#################################################"<<endl;
    cout<<"#################################################"<<endl;
    cout<<"###   TE QUEDASTE SIN DADOS, SOS EL GANADOR!! ###"<<endl;
    cout<<"#################################################"<<endl;
    cout<<"#################################################"<<endl<<endl;
    PresionaUnaTecla();
    return puntajeFinal;

}

void Mostrar_Reglas()
{
    rlutil :: setColor(rlutil :: GREEN);
    cout << "COMIENZO DE PARTIDA"<<endl;
    rlutil :: setColor(rlutil :: CYAN);
    cout <<endl<< "--------------------------------------------------------------------------------------------------------------------------"<<endl;
    rlutil :: setColor(rlutil :: WHITE);
    cout << "Al comenzar un juego y por única vez deben tirar cada uno un dado." << endl;
    cout << "Previo a eso, se debe seleccionar que dado en especial quieren tirar, si el de 6 o 12 caras."<<endl;
    cout << "Quien obtenga el valor mayor comienza la partida." << endl <<endl;
    cout << "En caso de empate se debe repetir la tirada hasta que alguno obtenga el mayor dado." << endl;
    rlutil :: setColor(rlutil :: CYAN);
    cout <<endl<< "--------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout <<endl<< "--------------------------------------------------------------------------------------------------------------------------"<<endl;
    rlutil :: setColor(rlutil :: WHITE);
    cout << "Comienza la partida y el jugador 1 (el primero en tirar) lanza los dos dados para sumar su número objetivo(12 caras)." << endl;
    cout << "Luego de tirar éstos dados deberá tirar los dados de seis caras que tenga en su poder" << endl;
    cout << "(al comenzar la partida serán seis dados pero luego puede variar)." << endl;
    cout << "Los dados que cada jugador tiene en su poder los llamaremos dados stock." << endl;
    cout << " Y habrá dados stock para el jugador 1 y dados stock para el jugador 2." << endl;
    cout << "Luego de hacer ambos lanzamientos es momento de confiar en el azar y en las destrezas" << endl;
    cout << "matemáticas ya que los puntajes ocurren de la siguiente manera:" << endl;
    rlutil :: setColor(rlutil :: CYAN);
    cout <<endl<< "--------------------------------------------------------------------------------------------------------------------------"<<endl;
    rlutil :: setColor(rlutil :: WHITE);
    PresionaUnaTecla();
    Limpiar_Consola();
    rlutil :: setColor(rlutil :: CYAN);
    cout <<endl<< "--------------------------------------------------------------------------------------------------------------------------"<<endl;
    rlutil :: setColor(rlutil :: WHITE);
    cout << "Primero, deberá sumar ambas caras de los dados de doce caras. Esto dará un valor" << endl;
    cout << "numérico entre 2 y 24. Este resultado de la suma lo llamaremos número objetivo." << endl;
    cout << "Luego deberá seleccionar, del lanzamiento de sus dados stock, los que desee para que al" << endl;
    cout << "sumar todas sus caras iguale el valor del número objetivo. A la suma de los dados" << endl;
    cout << "seleccionados por el jugador luego del lanzamiento lo llamaremos suma seleccionada y a" << endl;
    cout << "los dados seleccionados para ser sumados los llamaremos dados elegidos." << endl;
    cout << "Si ocurre que la suma seleccionada por el jugador es igual al número objetivo entonces se" << endl;
    cout << "logra una tirada exitosa y ocurren las siguientes situaciones:" << endl;
    rlutil :: setColor(rlutil :: CYAN);
    cout <<endl<< "--------------------------------------------------------------------------------------------------------------------------"<<endl;
    rlutil :: setColor(rlutil :: WHITE);
    cout << "- El puntaje de esa ronda para el jugador es igual a la suma seleccionada multiplicado" << endl;
    cout << "por la cantidad de dados elegidos y se suma al total general que viene acumulando" << endl;
    cout << "en las demás rondas." << endl<<endl;
    cout << "- El jugador se resta la cantidad de dados elegidos de sus dados stock y se los envía al" << endl;
    cout << "contrincante aumentando la cantidad de dados stock de este último." << endl;
    cout << "Si además ocurre que el jugador que realiza la tirada exitosa se queda sin dados. Gana" << endl;
    cout << "automáticamente la partida acumulando diez mil puntos a lo que venía acumulando." << endl;
    rlutil :: setColor(rlutil :: CYAN);
    cout <<endl<< "--------------------------------------------------------------------------------------------------------------------------"<<endl;
    rlutil :: setColor(rlutil :: WHITE);
    PresionaUnaTecla();
    Limpiar_Consola();
    rlutil :: setColor(rlutil :: CYAN);
    cout <<endl<< "--------------------------------------------------------------------------------------------------------------------------"<<endl;
    rlutil :: setColor(rlutil :: WHITE);
    cout << "Por el contrario, si en el lanzamiento de la ronda no logra una tirada exitosa. Es decir, no" << endl;
    cout << "puede realizar ninguna suma correcta entre su lanzamiento de dados stock y el número" << endl;
    cout << "objetivo. Entonces es el contrario el que le enviará un dado de sus dados stock sólo si tiene" << endl;
    cout << "una cantidad mayor a uno de dados. De lo contrario no habrá penalidad por no lograr una" << endl;
    cout << "tirada exitosa." << endl;
    cout << "Luego, será turno del siguiente jugador que deberá tirar con la cantidad de dados stock" << endl;
    cout << "correspondiente." << endl;
    rlutil :: setColor(rlutil :: CYAN);
    cout <<endl<< "--------------------------------------------------------------------------------------------------------------------------"<<endl;
    rlutil :: setColor(rlutil :: WHITE);
    cout << "------------------------- Presione una tecla para regresar al menú -------------------------"<<endl;
    rlutil :: setColor(rlutil :: CYAN);
    rlutil::anykey();
    Limpiar_Consola();
    //return Mostrar_Menu();
}



