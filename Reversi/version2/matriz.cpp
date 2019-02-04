/**
 * @file    matriz.cpp 
 * @brief   Contiene la definición de las funciones de matriz.h
 */
#include "matriz.h"
#include <cassert>
#include <iostream> //ostream istream

Matriz::Matriz()
{
    datos=0;
    filas = columnas = 0;
}

/*________________________________________________________________________________________*/

Matriz::~Matriz()
{
    delete[] datos;
}

/*________________________________________________________________________________________*/

Matriz::Matriz(int f,int c)
{
    if (f <= 0 || c <= 0){

        datos=0;
        filas = columnas = 0;

    }
    else{

        filas=f;
        columnas=c;
        datos = new int [f*c];

        for(int i=0;i<f*c;i++)
          datos[i] = 0;
    }


}

/*________________________________________________________________________________________*/

Matriz::Matriz(const Matriz& m)
{
    if (m.datos == 0){
        this->datos=0;
        this->filas=0;
        this->columnas=0;
    }
    else{
        filas = m.filas;
        columnas = m.columnas;
        datos = new int [filas*columnas];

        for (int i=0; i< filas*columnas ; ++i)
            datos[i] = m.datos[i];
    }
}

/*________________________________________________________________________________________*/

Matriz& Matriz::operator=(Matriz& m)
{
    Matriz aux(m);

    std::swap(this->filas, aux.filas);
    std::swap(this->columnas, aux.columnas);
    std::swap(this->datos, aux.datos);

    return *this;
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
    if (f>=0 && c>=0){
        return datos[f*columnas+c];
    }
    else{
        return -1;
    }
}

/*________________________________________________________________________________________*/

void Matriz::set(int f, int c, int x)
{
    assert(f >= 0 && c >= 0);

    this->datos[f*columnas+c] = x;

}

/*________________________________________________________________________________________*/

void Matriz::muestraMatriz(std::ostream &os) const
{
    for (int i=0; i < filas; i++){
        for (int j=0; j< columnas ; j++){
            os << datos[i] << " ";
        }
        os << std::endl;
    }
}

std::ostream &operator<<(std::ostream& os, const Matriz &m)
{
    int f = m.getfilas();
    int c = m.getcolumnas();

    os << f << " " << c << std::endl;

    for (int i = 0; i < f ; ++i){
        for (int j=0 ; j< c; ++j){
            os << m.get(i,j) << " ";
        }
        os << std::endl;
    }

    return os;

}

/*________________________________________________________________________________________*/

std::istream &operator>>(std::istream& is, Matriz &m)
{
    int f, c;
    int num;

    is >> f;
    is >> c;

    assert( f > 0 && c > 0);

    Matriz aux(f,c);

    for (int i=0; i< f; ++i){
        for (int j=0; j<c ;++j){
            is >> num;
            aux.set(i,j,num);
        }
    }

    if (is.good()){
        m=aux;
        return is;
    }

}

/*________________________________________________________________________________________*/

/****************Fin del fichero matriz.cpp**************************/
