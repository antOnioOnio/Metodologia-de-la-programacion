/**
 * @file    jugador.h
 * @brief   Fichero de cabecera que incluye las funciones necesarias para gestionar un objeto de tipo Jugador.
 */

#ifndef REVERSI_JUGADOR_H
#define REVERSI_JUGADOR_H
#include <iostream>
#include "tablero.h"

/**
 * struct ScoreHistory que almacena la puntuación total de un jugador.
 */
struct ScoreHistory{
    int won;
    int lost;
    int tie;
};

/**
 * Clase Jugador, almacena la información necesaria para trabajar con el tipo Jugador.
 */
class Jugador {

private:
    static const int MAX_NOMBRE = 50;
    char nombre[MAX_NOMBRE];
    int real_tam_name;
    int puntuacion_partida;
    ScoreHistory total;
    int turno; 

public:
    /**
     * calcula el tamaño del nombre
     * @param  v vector que contiene el nombre que vamos analizar
     * @return   devuelve el tamaño en un entero del tamaño del nombre
     */
    Jugador(const char name[], int player);

    /**
     * Muestra la puntuacion del jugador
     * @return entero que indica la puntuación que tiene el jugador
     */
    int getPuntuacion() const; // Devuelve la puntuacion en la partida actual.
    
    /**
     * Muestra el turno que tiene el jugador
     * @return 1 para player one 2 para el player two
     */
    int getTurno() const; 
    
    /**
     * Muestra el nombre del jugador
     */
    void imprimirNombre() const ;

    /**
     * @brief      Función que aumenta en uno las partidas ganadas del jugador.
     */
    void unaGanadaMas();

    /**
     * @brief      Función que aumenta en una las partidas perdidas del jugador.
     */
    void unaPerdidaMas();

    /**
     * @brief      Función que aumenta en uno las partidas empatadas del jugador.
     */
    void unaEmpatadaMas();

    /**
     * @brief      Informa de las partidas ganadas en total de un jugador.
     *
     * @return     las partidas ganadas.
     */
    int getGanadas() const;

    /**
     * @brief      Informa de las partidas perdidas en total por un jugador.
     *
     * @return     las partidas perdidas.
     */
    int getPerdidas() const;

    /**
     * @brief      Informa de las partidas perdidas en total por un jugador.
     *
     * @return     las partidas empatadas.
     */
    int getEmpatadas() const;
    /**
     * @brief      Función que devuelve la puntuación del player1. 
     *
     * @param[in]  t     Tablero que se pasa por referencia.
     *
     * @return     El número de puntos del player1.
     */
    
    int puntuacionFinal1(const Tablero& t) const;

    /**
     * @brief      Función que devuelve la puntuación del player1.  
     *
     * @param[in]  t     Tablero que se pasa por referencia.
     *
     * @return     El número de puntos del player2.
     */

    int puntuacionFinal2(const Tablero& t) const;
    

};

#endif //REVERSI_JUGADOR_H
