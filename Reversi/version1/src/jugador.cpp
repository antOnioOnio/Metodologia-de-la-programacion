/**
 * @file    jugador.cpp 
 * @brief   Contine la definición de las funciones de jugador.h
 */

#include "jugador.h"

int tamNAME(const char v[]){
    int tam=0;

    while (v[tam] != '\0'){
        tam++;
    }
    return tam;
}

/*________________________________________________________________________________________*/


Jugador::Jugador(const char *name, int player)
{
    int len;
    turno = player ;
    total.lost = 0;
    total.won = 0;
    total.tie = 0;

    len = tamNAME(name);
    real_tam_name = len;
    for (int i=0;i < len ; i++)
        nombre[i] = name[i];
}

/*________________________________________________________________________________________*/

int Jugador::getPuntuacion() const
{
    return puntuacion_partida;
}

/*________________________________________________________________________________________*/


int Jugador::getTurno() const
{
    return turno;
}

/*________________________________________________________________________________________*/

int Jugador::puntuacionFinal1(const Tablero& t) const
{
    int f= t.getfilasTablero();
    int c= t.getcolumnasTablero();
    int puntuacion = 0 ;

    for (int i=0; i< f ; i++){
        for (int j=0; j < c ; j++){
            if (t.getFicha(i,j) == 1){
                puntuacion++;
            }
        }
    }
    return puntuacion;
}

/*________________________________________________________________________________________*/

int Jugador::puntuacionFinal2(const Tablero& t) const
{
    int f= t.getfilasTablero();
    int c= t.getcolumnasTablero();
    int puntuacion = 0 ;

    for (int i=0; i< f ; i++){
        for (int j=0; j < c ; j++){
            if (t.getFicha(i,j) == 2){
                puntuacion++;
            }
        }
    }
    return puntuacion;
}

/*________________________________________________________________________________________*/


void Jugador::imprimirNombre() const
{
    for (int i=0; i < real_tam_name ; i++)
        std::cout << nombre[i] ;

    std::cout << ' ';
}

/*________________________________________________________________________________________*/


void Jugador::unaGanadaMas()
{
   total.won++;
}


/*________________________________________________________________________________________*/


void Jugador::unaPerdidaMas()
{
    total.lost++;
}

/*________________________________________________________________________________________*/


void Jugador::unaEmpatadaMas()
{
    total.tie++;
}


/*________________________________________________________________________________________*/


int Jugador::getGanadas() const 
{
    return total.won;
}


/*________________________________________________________________________________________*/


int Jugador::getEmpatadas() const
{
    return total.tie;
}

/*________________________________________________________________________________________*/

int Jugador::getPerdidas() const
{
    return total.lost;
}

/*________________________________________________________________________________________*/

/****************Fin del fichero jugador.cpp**************************/