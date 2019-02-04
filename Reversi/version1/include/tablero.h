/**
 * @file    tablero.h
 * @brief   Fichero de cabecera que incluye las funciones necesarias para gestionar un objeto de tipo Tablero.
 */
#ifndef REVERSI_TABLERO_H
#define REVERSI_TABLERO_H
#include "matriz.h"

/**
 * Clase tablero que almacena una matriz de enteros y el turno.
 * Proporciona las funciones necesarias para trabajar con el tipo Tablero.
 */
class Tablero {

private:
    Matriz tablero;     // Por defecto se crea un tablero 8x8
    int turno;      // turno=1 si le toca al jugador1 turno=2 si le toca al jugador2.

public:
    /**
     * Contructor por defecto de tablero, genera un tablero vacio y inicia los turnos a 0 
     */
    Tablero();

    /**
     * Constructor por defecto con parametros
     * @param f numero de filas que contiene el tablero
     * @param c numero de columnas que contiene el tablero
     */
    Tablero(int f, int c);

    /**
     * Inicializa el tablero de juego, pone las cuatro fichas principales
     * @param f filas que contiene el tablero
     * @param c columnas que contiene el tablero
     */
    void iniciaTablero(int f, int c);

    /**
     * Muestra el tamaño en filas del tablero
     * @return numero de fials del tablero
     */
    int getfilasTablero() const;

    /**
     * Muestra el tamaño de las columnas que tiene el tablero
     * @return numero de columnas que tiene el tablero
     */
    int getcolumnasTablero() const;
    
    /**
     * devuelve la ficha en la posicion fila x columna.
     * @param  f número de fila de la ficha
     * @param  c número de columna de la ficha
     * @return   la ficha en la posicion f,c
     */
    int getFicha(int f, int c) const;

    /**
     * establece el turno de un jugador
     * @param x es el siguiente turno.
     */
    void set_Turno(int x);

    /**
     * devuelve el turno del jugador.
     * @return el turno.
     */
    int get_Turno() const ;

    /**
     * Establece una ficha en las filas y columnas.
     * @param f     fila donde poner la ficha
     * @param c     columna donde poner la ficha
     * @param ficha la ficha a poner en f,c
     */
    void setFicha(int f, int c, int ficha);

    /**
     * Nos indica si el tablero esta lleno.
     * @return true si esta lleno, false si no lo está.
     */
    bool tableroFull() const;

    /**
     * Imprime por la salida estándart el tablero.
     */
    void muestraTablero();

    /**
     * Reinicia la partida.
     */
    void reiniciaTablero();

    /**
     * Coloca la ficha en la posición f,c haciendo los pertinentes cambios
     * en el tablero.
     * @param  f la fila donde poner la ficha.
     * @param  c la columna donde poner la ficha
     * 
     */
    void jugada(int f, int c) ;

    /**
     * Le da la vuelta a las fichas en una dirección. 
     * @param dir    indica la dirección a flipear.
     * @param f      indica la fila donde empieza el flip. 
     * @param c      indica la columna donde empieza el flip.
     * @param toflip nos indica el número de fichas a flipear.
     */
    void flip(int dir, int f, int c, int toflip);

    /**
     * Función que nos indica si una ficha es enemiga.
     * @param  f la fila donde voy a checkear si la ficha es enemiga o no.
     * @param  c la columna a checkear si la ficha es enemiga o no.
     * @return   true si es enemiga, false en caso contrario.
     */
    bool enemigo(int f, int c) const ;

    /**
     * devuelve si en la posicion f c hay una ficha aliada (inversa de enemigo). 
     * @param  f la fila donde voy a checkear si la ficha es amiga o no.
     * @param  c la columna a checkear si la ficha es amiga o no.
     * @return   true si es amiga, false en caso contrario.
     */
    bool amigo(int f, int c) const ;

    /**
     * Comprueba en las ocho casillas que rodean a una casilla si hay enemigos.
     * Determina cuantas fichas se van a dar la vuelta y llama a la función toflip.
     * @param  dir dirección a examinar
     * @param  f   fila donde quiero analizar las 8 direcciones
     * @param  c   columna donde quiero analizar las 8 direcciones.
     */
    void checkDirecciones(int dir, int f, int c) ;

    /**
     * Le da la vuelta a la ficha en la posicion f,c.
     * @param f la fila donde se encuentra la ficha.
     * @param c la columna donde se encuentra la ficha.
     */
    void intercambia(int f, int c);

    /**
     * función que informa si hay jugada posible para cualquier jugador.
     * @return true si es posible jugar, false en otro caos.
     */
    bool hay_jugada() const;

    /**
     * función que nos informa si es posible jugar en la posición f,c.
     * @param  f fila donde quiero comprobar si se puede jugar.
     * @param  c columna donde quiero comprobar si es posible jugar.
     * @return   true si se puede, false en caso contrario.
     */
    bool posible (int f, int c) const;

    /**
     * Función auxiliar que nos permite leer las columnas en formato letra.
     * @param  poscol char que le entra a la función para devolverlo como entero.
     * @return        la columna transformada a entero.
     */
    int leerColumnas(char poscol) const;
    void cambiaTurno();
};


#endif //REVERSI_TABLERO_H
