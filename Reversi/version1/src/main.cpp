/**
 * @file main.cpp
 * @brief Gestiona lo necesario para partida de reversi.
 */

#include <iostream>
#include "tablero.h"
#include "jugador.h"
#include "matriz.h"
#include <stdlib.h>

// Función para introducir nombre 

void rellena_nombre(char v[])
{
    char fin = '\n';
    char caracter ;
    int i = 0;

    caracter = std::cin.get();

    while (caracter != fin  ){
        v[i] = caracter;
        i++;
        caracter = std::cin.get();

    }
}
// Función main
int main()
{
    char opcion;
    char v1[30]={'*'} ;
    char v2[30]={'*'};
    char f_char;
    int f;
    char c_char;
    int c;
    int puntuacion1=0;
    int puntuacion2=0;
    bool gameloop= true;


    // Inicializamos a nuestros 2 Jugadores.
    std::cout << "Introduce nombre del primer jugador" << std::endl;
    rellena_nombre(v1);
    
    Jugador a(v1,1);

    std::cout << "Introduce nombre del segundo jugador" << std::endl;
    rellena_nombre(v2);
    Jugador v(v2,2);

    //bucle principal del juego
    while (gameloop){

        do{
            std::cout << " Introduce filas\t" ;
            std::cin>> f_char;
            f = f_char - '0';
            std::cout << std::endl;
            
        }while(f>10 && f<=0);

        do{
            std::cout << " Introduce columnas\t" ;
            std::cin>> c_char;
            c = c_char - '0';
            std::cout << std::endl;

        }while(c>10 && c<=0);

        system("clear");

        //Creamos el Tablero.

        Tablero t(f,c);
        t.iniciaTablero(f, c);
        std::cin.ignore();

        system("clear");

        // Empieza la partida 

        std::cout << "\033[1;34m" << "           COMIENZA LA PARTIDA          \n" << "\033[1;0m"<<"\n" << std::endl;
        int contador = 0;
        int cols= -1;
        char col;


        t.muestraTablero();
        t.set_Turno(2);

        while (contador <2 && !t.tableroFull())
        {
          // CUANDO NO HAY JUGADA CAMBIAMOS TURNO Y AUMENTAMOS EL CONTADOR EN 1 UNIDAD
        	if (!t.hay_jugada()) 
        	{
        		std::cout<<" No hay posible tirada para ";

        		if (t.get_Turno()==1)
        		{
        	  		 std::cout <<"\033[1;31m";
             		 std::cout << std::endl;
             		 a.imprimirNombre();
             		 std::cout << "\033[1;0m" << "\n";
             		 
          		}
          		else if (t.get_Turno()==2)
          		{
          			 std::cout <<"\033[1;32m";
             		 std::cout << std::endl;
             		 v.imprimirNombre();
             		 std::cout << "\033[1;0m" << "\n";
             		
          		}
          	t.cambiaTurno();
            contador++;

        	}
        	else
        	{
        	  contador=0;
              std::cout<<"Introduce columnas y filas ";
              if(t.get_Turno()==1)
               {
              	std::cout << "\033[1;31m";
              	a.imprimirNombre();
           	 	  std::cout << "\033[1;0m" << "\n";
          	   }
          	   else if (t.get_Turno()==2)
          	   {
          	   	std::cout << "\033[1;32m";
              	v.imprimirNombre();
           	   	std::cout << "\033[1;0m" << "\n";
          	   }
              std::cin>>col;
              cols = t.leerColumnas(col);
              std::cin>> f_char;
              f = f_char -'0';
             

              while (!t.posible(f,cols))    // PREGUNTAMOS HASTA QUE SEA VALIDA
              {
                std::cout<<"No valida, introduce de nuevo\n";
                std::cin>>col;
                cols = t.leerColumnas(col);
                std::cin>> f_char;
                f = f_char -'0';
              }
              t.jugada(f,cols);
              t.cambiaTurno();
              system("clear");
              t.muestraTablero();
        	}
      
            
        } // FIN PARTIDA

        //          RECUENTO PUNTUACIONES


        puntuacion1 = a.puntuacionFinal1(t);
        puntuacion2 = v.puntuacionFinal2(t);


        if (puntuacion1 > puntuacion2)
        {
            a.unaGanadaMas();
            v.unaPerdidaMas();

            std::cout << "\nEl ganador es :  " << "\033[1;31m" ;
                a.imprimirNombre();
                std::cout << "\033[1;0m" << " con una puntuación de " << puntuacion1 << " puntos y " << "\033[1;32m" ;
                v.imprimirNombre();
                std::cout << "\033[1;0m" << " ha perdido con una puntuacion de "
                << puntuacion2 << std::endl ;
        }
        else if (puntuacion1 < puntuacion2){
            a.unaPerdidaMas();
            v.unaGanadaMas();

            std::cout << "\nEl ganador es : " << "\033[1;32m";
            v.imprimirNombre();
            std::cout << "\033[1;0m" << " con una puntuación de " << puntuacion2 << " puntos y " << "\033[1;31m";
            a.imprimirNombre();

            std::cout << "\033[1;0m" << " ha perdido con una puntuacion de "
            << puntuacion1 << std::endl ;
        }
        else{
            a.unaEmpatadaMas();
            v.unaEmpatadaMas();

            std::cout << "\n\t" << "\033[1;31m" << "EMPATE" << "\033[0m";
            std::cout << std::endl;
        }
        //Imprimimos por pantalla las estadísticas.
        std::cout << "\nRecuento de victorias : \n" ;
        std::cout << "\nVictorias para  " << "\033[1;31m";
                    a.imprimirNombre();
                    std::cout << "\033[1;0m " << a.getGanadas();

        std::cout << "\nVictorias para  " << "\033[1;32m";
                    v.imprimirNombre();
                    std::cout << "\033[1;0m " << v.getGanadas() << std::endl;


        std::cout << "\n\t ¿ Desea jugar otra partida ? " << std::endl;
        std::cout << "\n\t Pulse cualquier tecla para jugar otra partida o 'N' para finalizar " << std::endl;
        std::cin >> opcion;

        t.muestraTablero();

        if (opcion == 'n' || opcion == 'N'){
            gameloop = false;
        }
    }

    return 0;
}

/****************Fin del fichero main.cpp**************************/