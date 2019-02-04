/**
 * @file    matriz.cpp 
 * @brief   Contiene la definición de las funciones de matriz.h
 */
#include "matriz.h"
#include <cassert>

Matriz::Matriz()
{
    filas = columnas = 8;
    for (int i = 0;i < filas;i++){
        for(int j = 0;j < columnas;j++){
            matriz[i][j] = 0;
        }
    }
}

/*________________________________________________________________________________________*/


Matriz::Matriz(int f,int c)
{
    assert(f<MAX_TAM && c<MAX_TAM && f>=0 && c>=0);

    if (f <= 0 || c <= 0 ){
        filas = columnas = 0;
    }
    else{
        filas=f;
        columnas=c;
        for (int i = 0;i < f;i++){
            for(int j = 0;j < c;j++){
                matriz[i][j] = 0;
            }
        }
    }

}

/*________________________________________________________________________________________*/


Matriz::Matriz(const Matriz& m)
{
    if ( m.getfilas() == 0 || m.getcolumnas() == 0 ){
        this->filas=0;
        this->columnas=0;
    }
    else{
        this->filas = m.getfilas();
        this->columnas = m.getcolumnas();

        for (int i=0; i< filas;i++){
            for (int j=0; j<  m.getcolumnas(); j++){
                this->matriz[i][j] = m.get(i, j);
            }
        }

    }

}

/*________________________________________________________________________________________*/

int Matriz::getfilas() const
{
    return filas;
}

/*________________________________________________________________________________________*/

int Matriz::getcolumnas() const
{
    return columnas;
}

/*________________________________________________________________________________________*/


int Matriz::get(int f, int c) const
{
    if (f >= 0 && c >= 0){
        return matriz[f][c];
    }
    else{
        return -1;
    }
}

/*________________________________________________________________________________________*/


void Matriz::set(int f, int c, int x)
{
    assert(f >= 0 && c >= 0);

    this->matriz[f][c] = x;

}

/*________________________________________________________________________________________*/


void Matriz::muestraMatriz() const
{
    for (int i=0; i < filas; i++){
        for (int j=0; j< columnas ; j++){
            std::cout << matriz [i][j] << " ";
        }
        std::cout << std::endl;
    }
}


/*________________________________________________________________________________________*/

/****************Fin del fichero matriz.cpp**************************/
