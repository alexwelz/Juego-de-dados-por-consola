#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstring>
#include <ctype.h>
#include "rlutil.h"
#include "funciones.h"

using namespace std;

const int RONDAS = 5;
const int BONIFICACION_PERFECTA = 10000;

int main()
{
    bool Juego;
    string NombrePuntajeMaximo;
    setlocale(LC_ALL, "Spanish");
    while(!Juego)
    {
        string Player1, Player2, PlayerMax, PlayerMin;
        int Exit,Dado1,Dado2, Eleccion, Opcion, vDadosIniciales[2], PMaximo;

        bool b;
        ///Color de fondo y letra
        rlutil :: setBackgroundColor(rlutil::BLACK);
        rlutil :: setColor(rlutil :: CYAN);

        /// Para los números "aleatorios"
        srand(time(NULL));

        ///Todo: Menu principal del juego
        Mostrar_Menu();

        ///OPCIÓN PARA EL MENÚ
        rlutil :: setColor(rlutil :: WHITE);
        cout<<"Ingrese una opción: "<<endl;
        cin>>Opcion;
        rlutil :: setColor(rlutil :: CYAN);

        Limpiar_Consola();

        switch (Opcion)
        {
        case 1:
        {
            ///TODO: INGRESO NICKS
            Player1 = Nombre_Jugador1();
            Player2 = Nombre_Jugador2();
            Limpiar_Consola();

            cout<<"Seleccione el tipo de dados ver quíen empieza! "<<endl;
            cout<<" Opción 1: 6 caras \n Opción 2: 12 caras"<<endl;
            cin>>Eleccion;
            Limpiar_Consola();

            if(Eleccion == 1)
            {
                ///TODO: LANZAMIENTO DE DADOS DE 6 CARAS PARA VER QUIEN EMPIEZA

                ///JUGADOR 1
                cout<<"##############################################"<<endl;
                Dado1 = Dado_Inicial(Player1,6);
                cout<<"##############################################"<<endl;

                ///JUGADOR2
                Dado2 = Dado_Inicial(Player2,6);
                cout<<"##############################################"<<endl;

                ///En caso de multiples empates de dados
                while(Dado1 == Dado2)
                {
                    PresionaUnaTecla();
                    Limpiar_Consola();
                    rlutil :: setColor(rlutil :: YELLOW);
                    cout<<"Hay un empate! Vuelvan a tirar los dados"<<endl;
                    rlutil :: setColor(rlutil :: CYAN);
                    ///JUGADOR 1
                    cout<<"##############################################"<<endl;
                    Dado1 = Dado_Inicial(Player1,6);
                    cout<<"##############################################"<<endl;

                    ///JUGADOR2
                    Dado2 = Dado_Inicial(Player2,6);
                    cout<<"##############################################"<<endl;
                }


                ///En caso de no haber empate omite el ciclo while.
                if(Dado1>Dado2)
                {
                    rlutil :: setColor(rlutil :: GREEN);
                    cout<<Player1<<" Empezas primero!"<<endl;
                    rlutil :: setColor(rlutil :: CYAN);
                    PlayerMax = Player1;
                    PlayerMin = Player2;

                }

                else
                {
                    rlutil :: setColor(rlutil :: GREEN);
                    cout<<Player2<<" Empezas primero!"<<endl;
                    rlutil :: setColor(rlutil :: CYAN);
                    PlayerMax = Player2;
                    PlayerMin = Player1;
                }

            }
            else
            {
                ///TODO: LANZAMIENTO DE DADOS DE 12 CARAS PARA VER QUIEN EMPIEZA
                ///JUGADOR 1
                cout<<"##############################################"<<endl;
                Dado1 = Dado_Inicial(Player1,12);
                cout<<"##############################################"<<endl;

                ///JUGADOR2
                Dado2 = Dado_Inicial(Player2,12);
                cout<<"##############################################"<<endl;

                ///En caso de multiples empates de dados
                while(Dado1 == Dado2)
                {
                    rlutil :: setColor(rlutil :: YELLOW);
                    cout<<"Hay un empate! Vuelvan a tirar los dados"<<endl;
                    PresionaUnaTecla();
                    Limpiar_Consola();
                    rlutil :: setColor(rlutil :: CYAN);
                    ///JUGADOR 1
                    cout<<"##############################################"<<endl;
                    Dado1 = Dado_Inicial(Player1,12);
                    cout<<"##############################################"<<endl;

                    ///JUGADOR2
                    Dado2 = Dado_Inicial(Player2,12);
                    cout<<"##############################################"<<endl;

                }

                ///En caso de no haber empate omite el ciclo while.
                if(Dado1>Dado2)
                {
                    rlutil :: setColor(rlutil :: GREEN);
                    cout<<Player1<<" Empezas primero!"<<endl;
                    rlutil :: setColor(rlutil :: CYAN);
                    PlayerMax = Player1;
                    PlayerMin = Player2;

                }
                else
                {
                    rlutil :: setColor(rlutil :: GREEN);
                    cout<<Player2<<" Empezas primero!"<<endl;
                    rlutil :: setColor(rlutil :: CYAN);
                    PlayerMax = Player2;
                    PlayerMin = Player1;
                }

            }

            ///Variables que se reinician.
            int PuntosPlayer1 = 0, PuntosPlayer2 = 0, CantDadosStock1 = 6, CantDadosStock2=6;
            int vDadoStock1[CantDadosStock1]= {}, vDados1[2]= {}, vDadoStock2[CantDadosStock2]= {}, vDados2[2]= {};
            int Suma_Seleccionada, Num_Objetivo1 = 0, Num_Objetivo2 = 0, DadosElegidos, PuntosRondaP1, PuntosRondaP2;
            ///TODO: Ciclo para las rondas
            for(int x=0; x<RONDAS; x++)
            {


                ///TODO: TIRADAS PLAYER 1
                Tirar_Dados(vDados1, 2, 12);
                Mostrar_Dados(vDados1,2);
                Num_Objetivo1 = Sumar_Vector(vDados1,2);

                rlutil :: setColor(rlutil :: GREEN);
                cout<<"RONDA N°"<<x+1<<endl;
                cout<<PlayerMax<<" Tu número objetivo es: "<<Num_Objetivo1<<endl<<endl;
                rlutil :: setColor(rlutil :: CYAN);


                cout<<"Ahora debes tirar tus dados STOCK... Presione una tecla."<<endl;
                PresionaUnaTecla();
                Tirar_Dados(vDadoStock1,CantDadosStock1,6);
                Limpiar_Consola();

                ///TODO: "INTERFAZ RONDA" PLAYER 1
                rlutil :: setColor(rlutil :: GREEN);
                cout<<PlayerMax<< " Su número objetivo es: "<< Num_Objetivo1<<endl;
                rlutil :: setColor(rlutil :: YELLOW);
                cout<<"Sus dados STOCK: "<<endl;
                Mostrar_Dados(vDadoStock1, CantDadosStock1);

                ///TODO: PUNTAJE ACTUAL PLAYER 1
                cout<<"##############################################"<<endl;
                cout<<"     PUNTAJE: "<<PuntosPlayer1<<"    RONDA:"<<x+1<<endl;
                cout<<"##############################################"<<endl<<endl;
                rlutil :: setColor(rlutil :: CYAN);

                cout<<endl<<PlayerMax<<" Seleccioná los dados que sumen su número objetivo.."<<endl<<endl;
                cout<<"En caso de no poder lograrlo, podes pasar tu turno presionando 0"<<endl<<endl;
                cout<<"Cantidad de dados que va a utilizar: "<<endl;
                cin>>DadosElegidos;

                Suma_Seleccionada = Suma_Elegida(DadosElegidos,vDadoStock1);
                PuntosRondaP1 = Suma_Seleccionada * DadosElegidos;

                if(DadosElegidos != 0)
                {
                    if(Suma_Seleccionada == Num_Objetivo1)
                    {
                        CantDadosStock1 -= DadosElegidos;
                        CantDadosStock2 += DadosElegidos;

                        if(CantDadosStock1 == 0)
                        {
                            ///TODO: TIRADA PERFECTA PLAYER 1
                            PuntosPlayer1= Tirada_Perfecta(PuntosRondaP1, BONIFICACION_PERFECTA);
                            cout<<"*****TU PUNTAJE TOTAL ES DE "<< PuntosPlayer1<<" puntos!!!*****"<<endl;
                            rlutil :: setColor(rlutil :: CYAN);

                            if(b)
                            {
                                if(PuntosPlayer1 > PMaximo)
                                {
                                    NombrePuntajeMaximo = PlayerMax;
                                    PMaximo = PuntosPlayer1;
                                    b = false;
                                }
                            }
                            else
                            {
                                if(PuntosPlayer1 > PMaximo)
                                {
                                    NombrePuntajeMaximo = PlayerMax;
                                    PMaximo = PuntosPlayer1;
                                }
                            }
                            Limpiar_Consola();
                            break;
                        }
                        else
                        {
                            ///TODO: TIRADA EXITOSA PLAYER 1
                            Limpiar_Consola();
                            rlutil :: setColor(rlutil :: GREEN);
                            cout<<"TIRADA EXITOSA!! Los "<<DadosElegidos<<" dados que elegiste se tranfieren a "<<PlayerMin<<endl;
                            rlutil :: setColor(rlutil :: CYAN);
                            cout<<endl<<"#############################################################"<<endl;
                            cout<<"   TU PUNTAJE EN ESTA RONDA: "<< PuntosRondaP1<<"        DADOS STOCK: "<<CantDadosStock1<<endl;
                            cout<<"#############################################################"<<endl;
                            PuntosPlayer1 += Suma_Seleccionada * DadosElegidos;
                            cout<<"TU PUNTAJE TOTAL ACUMULADO ES DE "<< PuntosPlayer1<<" PUNTOS!!!"<<endl;
                            cout<<"#################################################"<<endl<<endl<<endl;
                            rlutil :: setColor(rlutil :: CYAN);
                            cout<<"Turno de "<<PlayerMin<<" presione una tecla para continuar la partida!"<<endl;
                            PresionaUnaTecla();
                            Limpiar_Consola();
                        }


                    }
                    else
                    {
                        if(CantDadosStock2 > 1)
                        {
                            ///TODO: Tirada sin éxito y con penalización PLAYER 1
                            Limpiar_Consola();
                            rlutil :: setColor(rlutil :: RED);
                            cout<<endl<<"NO HUBO TIRADA EXITOSA."<<endl;
                            cout<<PlayerMin<<" TIENE MÁS DE 1 DADO, SE TE ENVIARÁ UNO DE SUS DADOS STOCK"<<endl<<endl;
                            rlutil :: setColor(rlutil :: CYAN);
                            CantDadosStock2 -= 1;
                            CantDadosStock1 ++;
                            cout<<"#######################################################################"<<endl;
                            cout<<"Tus dados STOCK actuales son "<<CantDadosStock1<<" y con un puntaje de "<<PuntosPlayer1<<" puntos."<<endl;
                            cout<<"#######################################################################"<<endl<<endl<<endl;
                            cout<<"Turno de "<<PlayerMin<<" presione una tecla para comenzar su turno!"<<endl;
                            rlutil::anykey();
                            Limpiar_Consola();
                        }
                        else
                        {
                            ///TODO: Tirada sin éxito y SIN penalización PLAYER 1
                            Limpiar_Consola();
                            rlutil :: setColor(rlutil :: RED);
                            cout<<endl<<"NO HUBO TIRADA EXITOSA."<<endl;
                            rlutil :: setColor(rlutil :: GREEN);
                            cout<<"NO HAY PENALIZACIÓN POR LA CANTIDAD DE DADOS DEL OPONENTE"<<endl<<endl;
                            rlutil :: setColor(rlutil :: CYAN);
                            cout<<"#######################################################################"<<endl<<endl;
                            cout<<"Tus dados STOCK actuales son "<<CantDadosStock1<<" y con un puntaje de "<<PuntosPlayer1<<" puntos."<<endl;
                            cout<<"#######################################################################"<<endl<<endl<<endl;
                            cout<<"Turno de "<<PlayerMin<<" presione una tecla para comenzar su turno!"<<endl;
                            rlutil::anykey();
                            Limpiar_Consola();
                        }

                    }
                }
                else
                {
                    rlutil :: setColor(rlutil :: RED);
                    Limpiar_Consola();
                    cout<<PlayerMin<<" TIENE MÁS DE 1 DADO, SE TE ENVIARÁ UNO DE SUS DADOS STOCK"<<endl<<endl;
                    rlutil :: setColor(rlutil :: CYAN);
                    CantDadosStock2 -= 1;
                    CantDadosStock1 ++;
                    cout<<"Tus dados STOCK actuales son "<<CantDadosStock1<<endl<<endl;
                    cout<<"Turno de "<<PlayerMin<<" presione una tecla para comenzar su turno!"<<endl;
                    PresionaUnaTecla();
                    Limpiar_Consola();
                }

                ///TODO: TIRADAS PLAYER 2
                Tirar_Dados(vDados2, 2, 12);
                Mostrar_Dados(vDados2,2);
                Num_Objetivo2 = Sumar_Vector(vDados2,2);
                rlutil :: setColor(rlutil :: GREEN);
                cout<<"RONDA N°"<<x+1<<endl;
                cout<<PlayerMin<<" Tu número objetivo es: "<<Num_Objetivo2<<endl;

                rlutil :: setColor(rlutil :: YELLOW);
                cout<<endl<< "-------------------------"<<endl;
                rlutil :: setColor(rlutil :: CYAN);
                cout<<"Ahora debes tirar tus dados STOCK.. Presione una tecla."<<endl;
                rlutil::anykey();
                Limpiar_Consola();
                Tirar_Dados(vDadoStock2,CantDadosStock2,6);

                ///TODO: "INTERFAZ RONDA PLAYER 2"
                rlutil :: setColor(rlutil :: GREEN);
                cout<<PlayerMin<< " Su número objetivo es: "<< Num_Objetivo2<<endl;
                rlutil :: setColor(rlutil :: YELLOW);
                cout<<"Sus dados STOCK:"<<endl;
                Mostrar_Dados(vDadoStock2,CantDadosStock2);
                ///TODO: PUNTAJE ACTUAL PLAYER 2
                cout<<"##########################################"<<endl;
                cout<<"     PUNTAJE: "<<PuntosPlayer2<<"    RONDA:"<<x+1<<endl;
                cout<<"##########################################"<<endl<<endl;
                rlutil :: setColor(rlutil :: CYAN);
                cout<<endl<<"Seleccione los dados que acumulen su número objetivo.."<<endl<<endl;
                cout<<"En caso de no poder lograrlo, podes pasar tu turno presionando 0"<<endl<<endl;///Pasar turno
                cout<<"Cantidad de dados que va a utilizar: "<<endl;
                cin>>DadosElegidos;
                Suma_Seleccionada = Suma_Elegida(DadosElegidos,vDadoStock2);
                //Puntaje de ronda
                PuntosRondaP2 = Suma_Seleccionada * DadosElegidos;

                if(DadosElegidos != 0)//Para saltar turno
                {

                    if(Suma_Seleccionada == Num_Objetivo2)//Para tirada exitosa
                    {
                        CantDadosStock2 -= DadosElegidos;
                        CantDadosStock1 += DadosElegidos;
                        
                        if(CantDadosStock2 == 0)
                        {
                            

                            ///TODO: TIRADA PERFECTA PLAYER 2
                            PuntosPlayer2= Tirada_Perfecta(PuntosRondaP2, BONIFICACION_PERFECTA);
                            cout<<"*****TU PUNTAJE TOTAL ES DE "<< PuntosPlayer2<<" puntos!!!*****"<<endl;
                            rlutil :: setColor(rlutil :: CYAN);

                            if(b)
                            {
                                NombrePuntajeMaximo = PlayerMin;
                                PMaximo = PuntosPlayer2;
                                b = false;
                            }
                            else
                            {
                                if(PuntosPlayer2 > PMaximo)
                                {
                                    NombrePuntajeMaximo = PlayerMin;
                                    PMaximo = PuntosPlayer2;
                                }
                            }
                            rlutil::anykey();
                            Limpiar_Consola();

                            break;
                        }
                        else
                        {
                            ///TODO: TIRADA EXITOSA PLAYER 2
                            Limpiar_Consola();
                            rlutil :: setColor(rlutil :: GREEN);
                            cout<<"TIRADA EXITOSA!! Los "<<DadosElegidos<<" dados que elegiste se tranfieren a "<<PlayerMax<<endl;
                            rlutil :: setColor(rlutil :: CYAN);

                            cout<<endl<<"#############################################################"<<endl;
                            cout<<"   TU PUNTAJE EN ESTA RONDA: "<< PuntosRondaP2<<"        DADOS STOCK: "<<CantDadosStock2<<endl;
                            cout<<"#############################################################"<<endl;
                            PuntosPlayer2 += Suma_Seleccionada * DadosElegidos;
                            cout<<"TU PUNTAJE TOTAL ACUMULADO ES DE "<< PuntosPlayer2<<" PUNTOS!!!"<<endl;
                            cout<<"#############################################################"<<endl<<endl<<endl;
                            rlutil :: setColor(rlutil :: CYAN);
                            cout<<"Turno de "<<PlayerMax<<" presione una tecla para continuar la partida!"<<endl;
                            PresionaUnaTecla();
                            Limpiar_Consola();

                        }
                    }
                    else
                    {
                        if(CantDadosStock1 > 1)
                        {
                            ///TODO: Tirada sin éxito y con penalización PLAYER 2
                            Limpiar_Consola();
                            rlutil :: setColor(rlutil :: RED);
                            cout<<endl<<"NO HUBO TIRADA EXITOSA."<<endl;
                            cout<<PlayerMax<<" TIENE MÁS DE 1 DADO, SE TE ENVIARÁ UNO DE SUS DADOS STOCK"<<endl<<endl;
                            rlutil :: setColor(rlutil :: CYAN);
                            CantDadosStock1 -= 1;
                            CantDadosStock2 ++;
                            cout<<"#######################################################################"<<endl;
                            cout<<"Tus dados STOCK actuales son "<<CantDadosStock2<<" y con un puntaje de "<<PuntosPlayer2<<" puntos."<<endl;
                            cout<<"#######################################################################"<<endl<<endl<<endl;
                            cout<<"Presione una tecla para continuar.."<<endl;
                            PresionaUnaTecla();

                        }
                        else
                        {
                            ///TODO: Tirada sin éxito y sin penalización PLAYER 2
                            Limpiar_Consola();
                            rlutil :: setColor(rlutil :: RED);
                            cout<<endl<<"NO HUBO TIRADA EXITOSA."<<endl;
                            rlutil :: setColor(rlutil :: GREEN);
                            cout<<"NO HAY PENALIZACIÓN POR LA CANTIDAD DE DADOS DEL OPONENTE"<<endl<<endl;
                            rlutil :: setColor(rlutil :: CYAN);
                            cout<<"#######################################################################"<<endl;
                            cout<<"Tus dados STOCK actuales son "<<CantDadosStock2<<" y con un puntaje de "<<PuntosPlayer2<<" puntos."<<endl;
                            cout<<"#######################################################################"<<endl<<endl<<endl;
                            cout<<"Presione una tecla para continuar.."<<endl;
                            PresionaUnaTecla();
                        }

                    }
                }
                else
                {
                    rlutil :: setColor(rlutil :: RED);
                    Limpiar_Consola();
                    cout<<PlayerMax<<" TIENE MÁS DE 1 DADO, SE TE ENVIARÁ UNO DE SUS DADOS STOCK"<<endl<<endl;
                    rlutil :: setColor(rlutil :: CYAN);
                    CantDadosStock1 -= 1;
                    CantDadosStock2 ++;
                    cout<<"Tus dados STOCK actuales son "<<CantDadosStock2<<endl<<endl;
                    cout<<"Turno de "<<PlayerMax<<" presione una tecla para comenzar su turno!"<<endl;
                    PresionaUnaTecla();
                    Limpiar_Consola();
                }
            }
            ///TODO: FIN DE LAS RONDAS
            ///TODO: RESULTADOS FINALES
            Mostrar_Puntaje_Final(PlayerMax, PlayerMin, PuntosPlayer1, PuntosPlayer2);

            ///Comparación para guardar el usuario y el puntaje máximo en caso de superar el actual.
            if(PuntosPlayer1 > PuntosPlayer2 && b == true)
            {
                NombrePuntajeMaximo = PlayerMax;
                PMaximo = PuntosPlayer1;
                b=false;
                rlutil::anykey();
                Limpiar_Consola();
            }
            else
            {
                if(PuntosPlayer2 > PuntosPlayer1 && b == true)
                {
                    NombrePuntajeMaximo = PlayerMin;
                    PMaximo = PuntosPlayer2;
                    b=false;
                    rlutil::anykey();
                    Limpiar_Consola();
                }
                else
                {
                    if(PuntosPlayer1 > PuntosPlayer2)
                    {
                        rlutil::anykey();
                        Limpiar_Consola();

                        if(PuntosPlayer1 > PMaximo)
                        {
                            NombrePuntajeMaximo = PlayerMax;
                            PMaximo = PuntosPlayer1;
                        }
                    }
                    else
                    {
                        rlutil::anykey();
                        Limpiar_Consola();

                        if(PuntosPlayer2 > PMaximo)
                        {
                            NombrePuntajeMaximo = PlayerMin;
                            PMaximo = PuntosPlayer2;
                        }
                    }

                }
            }



        }
        break;

        case 2:
            Mostrar_Estadisticas(NombrePuntajeMaximo, PMaximo, Opcion);
            break;

        case 3:
            Mostrar_Creditos(Opcion);
            break;

        case 4:
            Mostrar_Reglas();
            break;

        case 0:
            cout<<"Estas seguro/a que queres abandonar el juego? \n 1- Menú Principal \n 0- Salir del juego "<<endl<<endl;
            cin >> Exit;
            Limpiar_Consola();
            if(Exit == 0)
            {
                return 0;
            }
            break;
        }

    }


    return 0;
}
