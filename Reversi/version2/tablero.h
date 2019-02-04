/**
 * @file    tablero.h
 * @brief   Fichero de cabecera que incluye las funciones necesarias para gestionar un objeto de tipo Tablero.
 */
#ifndef REVERSI_TABLERO_H
#define REVERSI_TABLERO_H
#include "matriz.h"
#include <fstream>

/**
 * @brief Clase tablero que almacena una matriz de enteros y el turno.
 * Proporciona las funciones necesarias para trabajar con el tipo Tablero.
 */
class Tablero {

private:
    Matriz tablero;     // Por defecto se crea un tablero 8x8
    int turno;      // turno=1 si le toca al jugador1 turno=2 si le toca al jugador2.
    int turno_inicial;
    int max_per_turn;
    int fichas_restantes;
    int finish;
    char archivo_config[40];

public:
    /**
     * @brief Contructor por defecto de tablero, genera un tablero vacio y inicia los turnos a 0
     */
    Tablero();

    /**
     * @brief Constructor por defecto con parametros
     * @param f numero de filas que contiene el tablero
     * @param c numero de columnas que contiene el tablero
     */
    Tablero(int f, int c, int inicial, int max);

    /**
     * @brief Inicializa el tablero de juego, pone las cuatro fichas principales
     * @param f filas que contiene el tablero
     * @param c columnas que contiene el tablero
     */
    void iniciaTablero(int f, int c);

    /**
     * @brief Muestra el tamaño en filas del tablero
     * @return numero de fials del tablero
     */
    int getfilasTablero() const;

    /**
     * @brief Pone el estado de la variable finish a 1, quiere decir que ha terminado la partida.
     */
    bool partida_finished() const;

    /**
     * @brief Pone el estado de la variable finish a 1, quiere decir que ha terminado la partida.
     */
    void finish_Partida();

    /**
     * Muestra el tamaño de las columnas que tiene el tablero
     * @return numero de columnas que tiene el tablero
     */
    int getcolumnasTablero() const;
    
    /**
     * @brief devuelve la ficha en la posicion fila x columna.
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
     * @brief función que devuelve el número de fichas que puedo jugar cada turno
     * @return fichas que puedo jugar cada turno.
     */
    int get_Fichas_Restantes() const;

    /**
     * @brief función que devuelve la posición inicial donde empieza el nombre del fichero con la configuración inicial.
     */
    const char * getCFG_Inicial() const;

    /**
     * @brief Funcion para conocer el máximo número de fichas que puede poner un jugador por turno.
     * @return el máximo número de fichas por turno.
     */
    int get_Fichas_Max() const;

    /**
     * @brief función que resta uno a las ficahs que puedo usar.
     */
    void una_Ficha_Menos();

    /**
     * devuelve el turno del jugador.
     * @return el turno.
     */
    int get_Turno() const ;

    /**
     * @brief Salta comentarios de una linea.
     */
    void salta_Comentarios(std::istream& is) const;

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
    void muestraTablero(std::ostream& os) const;

    /**
     * @brief función que pone el tablero en posición inicial. No utilizada en esta versión.
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
     * @return el numero de fichas que va a dar la vuelta.
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

    /**
     * @brief función que establece el fichero donde se encutra la configuración inicial para reiniciar el tablero.
     * @param v nombre del fichero con la configuración.
     */
    void setCFG_Inicial(char *v);

    /**
     * @brief      Función que cambia el turno en el tablero.
     */
    void cambiaTurno();

    /**
     * @brief cambia el turno del jugador que comienza colocando ficha.
     */
    void cambiaTurnoInicial();

    /**
     * @brief Función que setea el número de fichas restantes por poner en el tablero.
     * @param num
     */
    void set_Fichas_Restantes(int num);

    /**
     * @brief función que sirve para establecer quien ha jugado primero en la partida.
     * @param turno
     */
    void setTurnoInicial(int turno);

    /**
     * @brief Función que devuelve el turno del jugador que comenzo tirando en la partida actual.
     * @return
     */
    int getTurno_Inicial() const;

    /**
     * @brief sobrecarga del operador << para poder mostrar por pantalla un tablero.
     * Gracias a la sobrecarga del operador<< en matriz.h esta implementación es muy sencilla
     * @param os flujo de salida.
     * @param t tablero que se va a imprimir por pantalla.
     * @return el flujo de tipo ostream os.
     */
    friend std::ostream &operator<<(std::ostream& os, const Tablero &t);


    /**
     * @brief sobrecarga del operador << para poder leer objetos de tipo tablero.
     * Gracias a la sobrecarga del operador>> en matriz.h esta implementación es muy sencilla.
     * @param is flujo de tipo istream de entrada.
     * @param t tablero donde se van a almacenar los datos.
     * @return el flujo de tipo istream is.
     */
    friend std::istream &operator>>(std::istream &is, Tablero &t );



};

#endif //REVERSI_TABLERO_H
