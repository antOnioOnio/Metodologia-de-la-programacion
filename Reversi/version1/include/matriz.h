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
    static const int MAX_TAM = 10;
    int matriz[MAX_TAM][MAX_TAM];
    int filas;
    int columnas;
public:
    /**
     * @brief      Constructor sin parámetros. Por defecto crea matrix 8x8
     */
    Matriz();

    /**
     * @brief      Constructor con parámetros.  
     *
     * @param[in]  f     número de filas de la matriz.
     * @param[in]  c     número de columnas de la matriz.
     */
    Matriz(int f, int c);

    /**
     * @brief      Constructor de copia.
     *
     * @param[in]  m     la matriz que servirá que se copiará en this.
     */
    Matriz(const Matriz& m);

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
     * @param[in]  f     la fila donde se encuentra el elemento.
     * @param[in]  c     la columna donde se encuentra el elemento.
     *
     * @return     devuelve el elemento en la posicion @f @c y -1 en caso de fallar.
     */
    int get(int f, int c) const; 

    /**
     * @brief      Función para poner un elemento en @f @c
     *
     * @param[in]  f     posición en filas del elento a insertar.
     * @param[in]  c     posición en columnas del elento a insertar.
     * @param[in]  x     elemento a insertar.
     */
    void set(int f, int c, int x);

    /**
     * @brief      Función que imprime por pantalla la matriz.
     */
    void muestraMatriz() const ;

};


#endif //REVERSI_MATRIZ_H
