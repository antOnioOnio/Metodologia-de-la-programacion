/**
 * @file    matriz.h
 * @brief   Archivo de cabecera  que incluye las funciones necesarias para trabajar con un objeto de tipo Matriz.
 */

#ifndef REVERSI_MATRIZ_H
#define REVERSI_MATRIZ_H
#include <iostream>
#include <assert.h>

/**
 * @brief      Clase MAtriz con lo necesario para trabajar con datos del tipo Matriz.
 */
class Matriz {
private:
    int *datos;
    int filas;
    int columnas;
public:

    /**
     * @brief      Constructor sin parámetros. Por defecto crea matrix 8x8
     */
    Matriz();

    /**
     * @brief      Destruye el objeto.
     */
    ~Matriz();

    /**
     * @brief      Constructor con parámetros.  
     *
     * @param  f     número de filas de la matriz.
     * @param  c     número de columnas de la matriz.
     */
    Matriz(int f, int c);

    /**
     * @brief      Constructor de copia.
     *
     * @param  m     la matriz que servirá que se copiará en this.
     */
    Matriz(const Matriz& m);

    /**
     * @brief      Permite hacer asignación de dos objetos del tipo Matriz.
     *
     * @param      m     matriz que pasa por referencia para ser asignada.
     *
     * @return     devuelve la matriz.
     */
    Matriz& operator=(Matriz& m);

    /**
     * @brief      Función que informa de las filas de la matriz.
     *
     * @return     devuelve un entero con el número de filas.
     */
    int getfilas() const ;

    /**
     * @brief      Función que informa de las columnas d ela matriz.
     *
     * @return     devuelve un entero con las columnas de la matriz.
     */
    int getcolumnas() const ;

    /**
     * @brief      Función que sirve para obtener el elemento en la posicion @f @c
     *
     * @param f     la fila donde se encuentra el elemento.
     * @param  c     la columna donde se encuentra el elemento.
     *
     * @return     devuelve el elemento en la posicion @f @c y -1 en caso de fallar.
     */
    int get(int f, int c) const; 

    /**
     * @brief      Función para poner un elemento en @f @c
     *
     * @param  f     posición en filas del elento a insertar.
     * @param  c     posición en columnas del elento a insertar.
     * @param  x     elemento a insertar.
     */
    void set(int f, int c, int x);

    /**
     * @brief      Función que imprime por pantalla la matriz.
     */
    void muestraMatriz(std::ostream& os) const;


};

/**
 * @brief Sobrecarga del operador << para poder imprimir objetos de tipo matriz.
 * @param os flujo de tipo ostream.
 * @param m matriz que va a ser impresa por pantalla.
 * @return el flujo os de tipo ostream.
 */
std::ostream &operator<<(std::ostream &os, const Matriz &m);

/**
 * @brief Sobrecarga del operador >> para poder leer objetos de tipo Matriz.
 * @param is flujo de tipo istream de entrada.
 * @param m matriz m donde se van a almacenar los datos obtenidos por el objeto is.
 * @return el flujo is de tipo istream.
 */
std::istream &operator>>(std::istream &is, Matriz &m);


#endif //REVERSI_MATRIZ_H
