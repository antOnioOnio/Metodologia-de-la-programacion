/**
 * @file    tablero.cpp
 * @brief   Contiene la definición de las funciones de tablero.h
 */
#include "tablero.h"

Tablero::Tablero()
{
    turno=0;
    turno_inicial=0;
    max_per_turn=1;
    fichas_restantes=1;
    finish=0;

}

/*________________________________________________________________________________________*/

Tablero::Tablero(int f, int c, int inicial, int max)
{
    Matriz t(f,c);

    assert(max >0 && max <= 3);

    tablero = t;
    turno_inicial=inicial;
    max_per_turn = max;
    finish=0;
}

/*________________________________________________________________________________________*/


void Tablero::iniciaTablero(int f, int c)
{
    //Colocamos las fichas negras en el centro del Tablero.
    setFicha( f/2 - 1, c/2  - 1, 2);
    setFicha( f/2 ,  c/2 , 2);

    //Colocamos las fichas blancas en el centro del Tablero.
    setFicha( f/2 - 1,  c / 2 , 1);
    setFicha( f/2, c/2 - 1, 1);
}

/*________________________________________________________________________________________*/

int Tablero::getfilasTablero() const
{
    return tablero.getfilas();
}

/*________________________________________________________________________________________*/


int Tablero::getcolumnasTablero() const
{
    return tablero.getcolumnas();
}

/*________________________________________________________________________________________*/

bool Tablero::partida_finished() const {
    return finish == 1;
}

/*________________________________________________________________________________________*/

int Tablero::getFicha(int f, int c) const
{
    return tablero.get(f, c);
}

/*________________________________________________________________________________________*/


void Tablero::set_Turno(int x)
{
    assert(x==1 || x==2 || x==0);

    turno=x;
}

/*________________________________________________________________________________________*/


int Tablero::get_Fichas_Restantes() const
{
    return fichas_restantes;
}


/*________________________________________________________________________________________*/


void Tablero::una_Ficha_Menos()
{
    fichas_restantes -= 1;
}

/*________________________________________________________________________________________*/


int Tablero::get_Fichas_Max() const
{
    return max_per_turn;
}

void Tablero::set_Fichas_Restantes(int num)
{
    if (num >=0 && num <= 3){
        fichas_restantes = num;
    }
}

/*________________________________________________________________________________________*/


int Tablero::get_Turno() const
{
    return turno;
}

/*________________________________________________________________________________________*/


void Tablero::finish_Partida()
{
    finish=1;
}


/*________________________________________________________________________________________*/


void Tablero::muestraTablero(std::ostream& os=std::cout) const
{
    int f= getfilasTablero();
    int c= getcolumnasTablero();
    char letra = 'a';
    int ficha;

    os << ' ' ;

    for (int i=0;i<=c;i++) {
        if (i == 0) {
            os << ' ';
        } else {
            os << (char) (letra + i - 1) << ' ';
        }
    }


    std::cout << std::endl;
    for (int i = 0; i < f; i++) {
        std::cout << i;
        for (int j = 0; j < c; j++) {
            ficha = getFicha(i, j);
            std::cout << '|';
            if (ficha == 1){
                os << 'x';
            }else if(ficha == 2){
                os << 'o';
            }
            else{
                os << ' ';
            }
        }
        std::cout << '|';
        std::cout << std::endl;

    }
}

/*________________________________________________________________________________________*/


void Tablero::setFicha(int f, int c, int ficha)
{
    assert(f >= 0 && c >= 0 && (ficha==1 || ficha==2 || ficha==0));

    tablero.set(f,c,ficha);

}

/*________________________________________________________________________________________*/

void Tablero::cambiaTurno() 
{
    if ( get_Turno()==1){
        set_Turno(2);
    }
    else if (get_Turno()==2)
    {
        set_Turno(1);
 
    }
}

/*________________________________________________________________________________________*/

void Tablero::reiniciaTablero()
{
    int f= tablero.getfilas();
    int c= tablero.getcolumnas();

    for (int i=0; i < f; i++){
        for (int j=0; j< c; j++){
            setFicha(i , j , 0);
        }
    }
    iniciaTablero(f,c);
    if (turno_inicial == 1){
        set_Turno(2);
    }
    else{
        set_Turno(1);
    }
}

/*________________________________________________________________________________________*/


bool Tablero::tableroFull() const
{
    bool full = true;
    int f= getcolumnasTablero();
    int c= getfilasTablero();
    for (int i=0; i < f; i++){
        for (int j=0; j < c && full; j++){
            if (getFicha(i,j) == 0){
                full = false;
            }
        }
    }
    return full;
}

/*________________________________________________________________________________________*/


bool Tablero::posible (int f, int c) const
{
    const int dir_f[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    const int dir_c[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int actual_f = 0;
    int actual_c = 0;
    bool posible = false;

    if (getFicha(f,c) == 0)
    {
      for ( int i = 0; i< 8 && !posible; i++ ){

          actual_f = f+dir_f[i];
          actual_c = c+dir_c[i];


          while ( enemigo(actual_f, actual_c)){

              actual_f += dir_f[i];
              actual_c += dir_c[i];

              if ( amigo(actual_f, actual_c)){
                  posible = true;

                }
              }
        }

    }
    return posible;
}

/*________________________________________________________________________________________*/


bool Tablero::hay_jugada() const
{
    bool hay = false;
    int f= getfilasTablero();
    int c = getcolumnasTablero();


    for (int i = 0; i < f && !hay;i++){
        for ( int j = 0 ; j < c && !hay ; j++){
            hay = posible(i, j);
        }

    }

    return hay;
}

/*________________________________________________________________________________________*/


bool Tablero::enemigo(int f, int c) const
{
    bool status=false;

    if (turno == 1 && getFicha(f,c) == 2){
        status=true;
    }
    else if(turno == 2 && getFicha(f,c) == 1){
        status=true;
    }
    if (f < 0 || f>getfilasTablero()-1 || c < 0 || c > getcolumnasTablero()-1)
    {
        status=false;
    }
    return status;
}

/*________________________________________________________________________________________*/

bool Tablero::amigo(int f, int c) const
{
    bool status=false;

    if (turno == 1 && getFicha(f,c) == 1){
        status=true;
    }
    else if(turno == 2 && getFicha(f,c) == 2){
        status=true;
    }

    if (f < 0 || f>getfilasTablero()-1 || c < 0 || c> getcolumnasTablero()-1)
    {
        status=false;
    }

    return status;
}

/*________________________________________________________________________________________*/


void Tablero::jugada(int f, int c)
{

    const int dir_f[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    const int dir_c[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int f_actual;
    int c_actual;


    //assert(f>=0 && f < getfilasTablero() && c>=0 && c<getcolumnasTablero());

    if (getFicha(f,c) == 0) {
        for (int i = 0; i < 8; i++) {
            f_actual = f + dir_f[i];
            c_actual = c + dir_c[i];
            if (enemigo(f_actual, c_actual)) {
                checkDirecciones(i, f_actual, c_actual);
            }
        }
    }
}

/*________________________________________________________________________________________*/


void Tablero::flip(int dir, int f, int c, int toflip)
{
    int filas = f;
    int cols = c;

    switch(dir){
        case 0:
            for (int i=0; i<toflip; i++){
                intercambia(filas,cols);
                cols--;
            }
            setFicha(f,c+1,get_Turno());
            break;
        case 1:
            for (int i=0; i<toflip; i++){
                intercambia(filas,cols);
                cols--;
                filas--;
            }
            setFicha(f+1,c+1,get_Turno());
            break;
        case 2:
            for (int i=0; i<toflip; i++){
                intercambia(filas,cols);
                filas--;
            }
            setFicha(f+1,c,get_Turno());
            break;
        case 3:
            for (int i=0; i<toflip; i++){
                intercambia(filas,cols);
                cols++;
                filas--;
            }
            setFicha(f+1,c-1,get_Turno());
            break;
        case 4:
            for (int i=0; i<toflip; i++){
                intercambia(filas,cols);
                cols++;
            }
            setFicha(f,c-1,get_Turno());
            break;
        case 5:
            for (int i=0; i<toflip; i++){
                intercambia(filas,cols);
                cols++;
                filas++;
            }
            setFicha(f-1,c-1,get_Turno());
            break;
        case 6:
            for (int i=0; i<toflip; i++){
                intercambia(filas,cols);
                filas++;
            }
            setFicha(f-1,c,get_Turno());
            break;
        case 7:
            for (int i=0; i<toflip; i++){
                intercambia(filas,cols);
                cols--;
                filas++;
            }
            setFicha(f-1,c+1,get_Turno());
            break;
    }

}

/*________________________________________________________________________________________*/


void Tablero::intercambia(int f, int c)
{
    if (getFicha(f, c) == 1){
        setFicha(f, c, 2);
    }
    else if(getFicha(f,c) == 2){
        setFicha(f, c , 1);
    }
}

/*________________________________________________________________________________________*/


void Tablero::checkDirecciones(int dir, int f, int c)
{

    int cols;
    int fils;
    int toflip = 0;

    switch(dir){
        case 0:
            fils=f;
            cols=c;
            toflip=0;
            while (enemigo(fils,cols)){
                cols--;
                toflip++;
            }
            if (amigo(fils,cols)){

                flip(dir, f, c, toflip);
            }

            break;
        case 1:
            toflip=0;
            fils=f;
            cols=c;
            while (enemigo(fils,cols)){
                fils--;
                cols--;
                toflip++;
            }
            if (amigo(fils,cols)) {

                flip(dir, f, c, toflip);
            }
            break;
        case 2:
            toflip=0;
            fils=f;
            cols=c;
            while (enemigo(fils,cols)){
                fils--;
                toflip++;
            }
            if (amigo(fils,cols)){

                flip(dir, f, c, toflip);
            }
            break;
        case 3:
            toflip=0;
            fils=f;
            cols=c;
            while (enemigo(fils,cols)){
                fils--;
                cols++;
                toflip++;
            }
            if (amigo(fils,cols)){

                flip(dir, f, c, toflip);
            }

            break;
        case 4:
            toflip=0;
            fils=f;
            cols=c;
            while (enemigo(fils,cols)){
                cols++;
                toflip++;
            }
            if (amigo(fils,cols)){

                flip(dir, f, c, toflip);
            }
            break;
        case 5:
            toflip=0;
            fils=f;
            cols=c;
            while (enemigo(fils,cols) ){
                fils++;
                cols++;
                toflip++;
            }
            if (amigo(fils,cols)){

                flip(dir, f, c, toflip);
            }

            break;

        case 6:
            toflip=0;
            fils=f;
            cols=c;
            while (enemigo(fils,cols)){
                fils++;
                toflip++;
            }
            if (amigo(fils,cols)){

                flip(dir, f, c, toflip);
            }
            break;

        case 7:
            toflip=0;
            fils=f;
            cols=c;
            while (enemigo(fils,cols)){
                fils++;
                cols--;
                toflip++;
            }
            if (amigo(fils,cols)){

                flip(dir, f, c, toflip);
            }
            break;
    }


}

/*________________________________________________________________________________________*/


void Tablero::cambiaTurnoInicial()
{
    if (turno_inicial==1){
        turno_inicial=2;
    }
    else{
        turno_inicial = 1;
    }
}

/*________________________________________________________________________________________*/


void Tablero::setTurnoInicial(int turno)
{
    if (turno == 1 || turno==2){
        turno_inicial = turno;
    }
}

/*________________________________________________________________________________________*/


int Tablero::getTurno_Inicial() const
{
    return turno_inicial;
}

/*________________________________________________________________________________________*/


int Tablero::leerColumnas(char poscol) const
{
    int columna= -1;

    switch (poscol){
        case 'a':
            columna=0;
            break;
        case 'b':
            columna=1;
            break;
        case 'c':
            columna=2;
            break;
        case 'd':
            columna=3;
            break;
        case 'e':
            columna=4;
            break;
        case 'f':
            columna=5;
            break;
        case 'g':
            columna=6;
            break;
        case 'h':
            columna=7;
            break;
        case 'i':
            columna=8;
            break;
        case 'j':
            columna=9;
    }
    return columna;
}

/*________________________________________________________________________________________*/

void Tablero::setCFG_Inicial(char *v)
{
    char siguiente;
    int i=0;
    siguiente = v[i];
    while (siguiente != '\0'){
        archivo_config[i] = siguiente;
        i++;
        siguiente=v[i];
    }
}

/*________________________________________________________________________________________*/

const char * Tablero::getCFG_Inicial() const
{
    return archivo_config;
}

/*________________________________________________________________________________________*/

void Tablero::salta_Comentarios(std::istream& is) const
{
    char siguiente = is.peek();

    while (siguiente ==' ' || siguiente == '\n' ){
        is.get(siguiente);
        siguiente= is.peek();
    }

    while (siguiente == '%' ){
        while (siguiente != '\n'){
            is.get(siguiente);
        }
        siguiente=is.peek();
        while (siguiente== ' ' || siguiente == '\n'){
            is.get(siguiente);
            siguiente = is.peek();
        }
    }
}

/*________________________________________________________________________________________*/



std::ostream &operator<<(std::ostream& os, const Tablero &t)
{

    os << t.tablero;
    os << t.get_Turno() << std::endl;
    os << t.get_Fichas_Restantes() << std::endl;
    os << t.max_per_turn << std::endl;
    os << t.finish << std::endl;
    os << t.turno_inicial << std::endl;
    os << t.getCFG_Inicial() << std::endl;


    return os;

}

/*________________________________________________________________________________________*/


std::istream &operator>>(std::istream& is, Tablero &t)
{
    const char cabecera[24] = "#MP-TABLERO-REVERSI-1.0";
    char letra;

    int i=0;
    while (is.peek() != '\n'){
        is >> letra;
        if (letra != cabecera[i]){
            is.fail();
        }
        i++;
    }

    t.salta_Comentarios(is);
    is>>t.tablero;
    t.salta_Comentarios(is);
    is >> t.turno;
    t.salta_Comentarios(is);
    is >> t.fichas_restantes;
    t.salta_Comentarios(is);
    is >> t.max_per_turn;
    t.salta_Comentarios(is);
    is >> t.finish;
    t.salta_Comentarios(is);
    is >> t.turno_inicial;
    t.salta_Comentarios(is);
    is >> t.archivo_config;


    return is;

}




/****************Fin del fichero tablero.cpp**************************/