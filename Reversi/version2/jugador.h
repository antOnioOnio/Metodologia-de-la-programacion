/**
 * @file    jugador.h
 * @brief   Fichero de cabecera que incluye las funciones necesarias para gestionar un objeto de tipo Jugador.
 */

#ifndef REVERSI_JUGADOR_H
#define REVERSI_JUGADOR_H
#include <iostream>
#include "tablero.h"

/**
 * @brief struct Punto2D, necesario para manejar las posiciones del tablero en formato (fila, columna).
 */
struct Punto2D{
    int f;
    int c;
};

/**
 * @brief struct ScoreHistory, almacena el historial de un objeto jugador concreto con sus partidas ganadas/empatadas/perdidas.
 */
struct ScoreHistory{
    int won;
    int lost;
    int tie;
};

/**
 * @brief Clase Jugador, almacena la información necesaria para trabajar con el tipo Jugador.
 */
class Jugador {

private:
    char *nombre;
    int real_tam_name;
    int reservados;
    int puntuacion_partida;
    ScoreHistory total;
    int turno;
    int comodines;
    bool automatic;

public:

    /**
     * @brief      Crea un dato de tipo Jugador con todos sus miembros a 0.
     */
    Jugador();


    /**
     * @brief Constructor con parámetros.
     * @param name puntero a char con el nombre del jugador
     * @param player el turno del jugador. 1 o 2.
     */
    Jugador(const char *name, int player, int comodin);

    /**
     * @brief      Destructor.
     */
    ~Jugador();

    /**
     * @brief      Constructor de copia para los objetos de tipo Jugador.
     *
     * @param[in]  m     Matriz que se va a copiar en this.
     */
    Jugador(const Jugador &j);

    /**
     * @brief      Operador para asignar objetos de tipo Jugador
     *
     * @param      j     Jugador que entra por referencia para ser asignado;
     *
     * @return     devuelve el jugador a asignar.
     */
    Jugador &operator=(Jugador &j);

    /**
     * @brief      Redimensiona el vector
     *
     * @param[in]  m     Tamaño nuevo del vector.
     */
    void reSize(int m);

    /**
     * @brief Función para asignar los comodines a un objeto de la clase jugador.
     */
    void setComodines(int num);

    /**
     * @brief función que devuelve los comodines actuales del jugador.
     * @return los comodines.
     */
    int getComodines() const;

    /**
     * Pone a un objeto del tipo jugador en modo automatico.
     */
    void setAutomatic();
    /**
     * @brief      Devuelve el tamaño del nombre del Jugador.
     *
     * @return     El tamaño.
     */
    int getTam();

    /**
     * Muestra la puntuacion del jugador
     * @return entero que indica la puntuación que tiene el jugador
     */
    int getPuntuacion() const;

    /**
     * Muestra el turno que tiene el jugador
     * @return 1 para player one 2 para el player two
     */
    int getTurno() const;

    /**
     * @brief Función que nos indica si un jugador es automatico o no.
     * @return true en caso de que sea automámtico y false en caso contrario.
     */
    bool esAutomatic() const;

    /**
     * @brief      Asigna al dato privado de la clase Jugador turno el valor n.
     *
     * @param[in]  n     valor a asignar en turno.
     *
     */
    void setTurno(int n);

    /**
     * Muestra el nombre del jugador
     */
    void imprimirNombre(std::ostream& os) const;

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

    void setEmpatadas(int n);

    /**
     * @brief      Informa de las partidas ganadas en total de un jugador.
     *
     * @return     las partidas ganadas.
     */
    int getGanadas() const;

    void setGanadas(int n);

    /**
     * @brief      Informa de las partidas perdidas en total por un jugador.
     *
     * @return     las partidas perdidas.
     */
    int getPerdidas() const;

    /**
     * @brief Función set para establecer unas partidas perdidas.
     * @param n
     */
    void setPerdidas(int n);

    /**
     * @brief      Informa de las partidas perdidas en total por un jugador.
     *
     * @return     las partidas empatadas.
     */
    int getEmpatadas() const;

    /**
     * @brief Función que resta un comodin al objeto jugador.
     */
    void unComodinMenos();


    /**
     * @brief      Función que devuelve la puntuación del player1. 
     *
     * @param[in]  t     Tablero que se pasa por referencia.
     *
     * @return     El número de puntos del player1.
     */

    int puntuacionFinal1(const Tablero &t) const;

    /**
     * @brief      Función que devuelve la puntuación del player1.  
     *
     * @param[in]  t     Tablero que se pasa por referencia.
     *
     * @return     El número de puntos del player2.
     */

    int puntuacionFinal2(const Tablero &t) const;

    /**
     * @brief      Rellena el vector por el final.
     *
     * @param[in]  letra  La letra a introducir en el vector.
     */

    void push_back(char letra);


    /**
     * @brief Función que muestra las posibles jugadas en un tablero dado por referencia. Muestra . donde se puede jugar.
     * @param t tablero de la partida actual.
     */
    void muestraPosibles(const Tablero &t) const;

    /**
     * Función que hace una jugada en el tablero t, elige la jugada que más fichas puede conseguir
     * @param t tablero que entra por referencia para ser modificado.
     * @return true si ha conseguido la jugada con éxito.
     */
    bool jugadaIA(Tablero &t);

    /**
     * Función que nos indica cuantas fichas vamos a conseguir jugando en una posición determinada.
     * @param t tablero de la partida en un momento dado. Pasa por referencia ya que éste será modificado.
     * @param f posición de filas de el movimiento.
     * @param c posición en columnas de el movimiento.
     * @return la cantidad de fichas que va a conseguir el movimiento en cuestión.
     */
    int howmanyflip(const Tablero &t, int f, int c) const;
    /**
     * @brief función que sirve tanto para leer las filas y las columnas como para identificar
     * si estamos jugando contra un jugador automático y realiza la jugada.
     * @param t tablero que entra por referencia. Puede ser modificado por el jugador automático.
     * @param p punto 2d que representa una posición en el tablero.
     * @return devuelve true en caso de realizarlo con éxito false en caso contrario.
     */
    bool escogePosicion( Tablero &t, Punto2D &p);

};
/**
 * @brief Sobrecarga del operador <<
 * @param os flujo de salida
 * @param j jugador que vamos a escribir por pantalla.
 * @return devuelve el flujo por referencia.
 */
std::ostream &operator<<(std::ostream &os, const Jugador& j);
/**
 * @brief Sobrecarga del operador >>
 * @param is flujo de entrada tipo istream.
 * @param j Jugador que vamos a leer desde el flujo.
 * @return devuelve el flujo is por referencia.
 */
std::istream &operator>>(std::istream &is, Jugador& j);


#endif //REVERSI_JUGADOR_H
