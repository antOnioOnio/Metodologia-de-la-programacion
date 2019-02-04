/**
 * @file    jugador.cpp 
 * @brief   Contine la definición de las funciones de jugador.h
 */

#include "jugador.h"



int tamNAME(const char *v){
    int tam=0;

    while (v[tam] != '\0'){
        tam++;
    }
    return tam;
}

/*________________________________________________________________________________________*/

Jugador::Jugador()
{
    real_tam_name=0;
    comodines = 0;
    nombre=0;
    reservados=0;
    turno=0;
    total.won=0;
    total.lost=0;
    total.tie=0;
    puntuacion_partida=0;
    automatic = false;
}

/*________________________________________________________________________________________*/

Jugador::Jugador(const char *name, int player, int comodin)
{
    int len;
    turno = player ;
    total.lost = 0;
    total.won = 0;
    total.tie = 0;
    comodines = comodin;

    len = tamNAME(name);
    nombre = new char[len];
    real_tam_name = len;

    for (int i=0;i < len ; i++)
        nombre[i] = name[i];
}

/*________________________________________________________________________________________*/

Jugador::~Jugador()
{
    delete [] nombre;
}

/*________________________________________________________________________________________*/

Jugador::Jugador(const Jugador& j)
{
    if (j.nombre == 0){
        this->nombre = 0;
        this->real_tam_name = 0;
        this->puntuacion_partida = 0;
        this->turno = 0;
        total=j.total;

    }
    else{
        real_tam_name = j.real_tam_name;
        puntuacion_partida = j.puntuacion_partida;
        total = j.total;
        turno = j.turno;

        nombre = new char[real_tam_name];

        for (int i=0; i<real_tam_name ; ++i)
            nombre[i] = j.nombre[i];

    }
}

/*________________________________________________________________________________________*/

Jugador& Jugador::operator=(Jugador& j)
{
    Jugador aux(j);

    std::swap(this->nombre, aux.nombre);
    std::swap(this->total, aux.total);
    std::swap(this->real_tam_name, aux.real_tam_name);
    std::swap(this->puntuacion_partida, aux.puntuacion_partida);
    std::swap(this->turno, aux.turno);

    return *this;

}

int Jugador::getTam()
{
    return real_tam_name;
}

/*________________________________________________________________________________________*/

void Jugador::reSize(int m)
{
    char *newname = new char[m];
    int min= real_tam_name  < m ? real_tam_name : m ;
    for (int i=0; i< min ; i++)
      newname [i] = nombre[i];

    real_tam_name=m;

    delete[] nombre;
    nombre = newname;
}

/*________________________________________________________________________________________*/

void Jugador::setComodines(int num)
{
    assert(num<=10 && num>=0);

    comodines=num;
}

/*________________________________________________________________________________________*/

int Jugador::getComodines() const
{
    return comodines;
}

/*________________________________________________________________________________________*/

int Jugador::getPuntuacion() const
{
    return puntuacion_partida;
}

/*________________________________________________________________________________________*/

void Jugador::setTurno(int n)
{
    assert(n==0 || n ==1 || n==2);

    turno = n;
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

void Jugador::imprimirNombre(std::ostream& os) const
{
    for (int i=0; i < real_tam_name ; i++) {
        if (nombre[i] != '!') {
            os << nombre[i];
        }
    }

}

/*________________________________________________________________________________________*/

void Jugador::unaGanadaMas()
{
   total.won++;
}

/*________________________________________________________________________________________*/

void Jugador::setGanadas(int n)
{
    if (n >= 0)
        total.won = n;
}

/*________________________________________________________________________________________*/

void Jugador::setPerdidas(int n)
{
    if (n>=0){
        total.lost = n;
    }
}

/*________________________________________________________________________________________*/

void Jugador::setEmpatadas(int n)
{
    if (n>=0)
        total.tie = n;
}

/*________________________________________________________________________________________*/


void Jugador::unaPerdidaMas()
{
    total.lost++;
}

/*________________________________________________________________________________________*/

bool Jugador::esAutomatic() const
{
    return automatic;
}

/*________________________________________________________________________________________*/

void Jugador::unaEmpatadaMas()
{
    total.tie++;
}

/*________________________________________________________________________________________*/

void Jugador::unComodinMenos()
{
    if (comodines >0){
        comodines -= 1;
    }
    else{
        comodines=0;
    }
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

void Jugador::push_back(char letra) {
    if (reservados > real_tam_name) {
        nombre[real_tam_name] = letra;

        real_tam_name++;
    } else { // Redimensionamos el vector.
        int newtam = reservados == 0 ? 1 : (2 * reservados);
        reservados = newtam;
        char *aux = new char[newtam];

        for (int i = 0; i < real_tam_name ; ++i) {
            aux[i] = nombre[i];
        }

        delete[] nombre;

        nombre = aux;
        nombre[real_tam_name] = letra;
        real_tam_name++;
    }
}

/*________________________________________________________________________________________*/

void Jugador::muestraPosibles(const Tablero &t) const
{
    int f= t.getfilasTablero();
    int c= t.getcolumnasTablero();
    char letra = 'a';
    int ficha;

    std::cout << ' ' ;

    for (int i=0;i<=c;i++) {
        if (i == 0) {
            std::cout << ' ';
        } else {
            std::cout << (char) (letra + i - 1) << ' ';
        }
    }


    std::cout << std::endl;
    for (int i = 0; i < f; i++) {
        std::cout << i;
        for (int j = 0; j < c; j++) {
            ficha = t.getFicha(i, j);
            if(t.posible(i,j)){
                std::cout << '|';
                std::cout << '.';
            }
            else{
                std::cout << '|';
                if (ficha == 1){
                    std::cout << 'x';
                }else if(ficha == 2){
                    std::cout << 'o';
                }
                else{
                    std::cout << ' ';
                }
            }

        }
        std::cout << '|';
        std::cout << std::endl;

    }
}

/*________________________________________________________________________________________*/

bool Jugador::jugadaIA(Tablero &t)
{
    bool status;
    int f = t.getfilasTablero();
    int c = t.getcolumnasTablero();
    status=false;

    Punto2D v[f*c];

    int contador=0;

    if (t.hay_jugada()) {
        status=true;
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                if (t.posible(i, j)) {
                    v[contador].f = i;
                    v[contador].c = j;
                    contador++;
                }
            }
        }


        // Elegir el mejor movimiento.
        int max = 0;
        Punto2D mejor;
        int actual;

        for (int i = 0; i < contador; ++i) {
            actual = howmanyflip(t, v[i].f, v[i].c);
            if (actual > max) {
                max = actual;
                mejor = v[i];
            }
        }

        //Jugamos con la mejor Jugada.

        t.jugada(mejor.f, mejor.c);
    }

    return status;
}

/*________________________________________________________________________________________*/

void Jugador::setAutomatic()
{
    automatic = true;
}

/*________________________________________________________________________________________*/

int Jugador::howmanyflip(const Tablero &t, int f, int c) const
{
    const int dir_f[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    const int dir_c[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int actual_f = 0;
    int actual_c = 0;
    int acumuladas=0;
    int contador=0;

    if (t.getFicha(f,c) == 0)
    {
        for ( int i = 0; i< 8 ; i++ ){


            actual_f = f+dir_f[i];
            actual_c = c+dir_c[i];
            contador=0;


            while ( t.enemigo(actual_f, actual_c)){

                actual_f += dir_f[i];
                actual_c += dir_c[i];
                contador++;

                if ( t.amigo(actual_f, actual_c)){
                    contador++;
                }
                else{
                    contador=0;
                }
            }
            acumuladas+=contador;
        }

    }
    return acumuladas;
}

/*________________________________________________________________________________________*/

bool Jugador::escogePosicion( Tablero &t, Punto2D &p)
{
    int f;
    char f_char;
    char col;
    int cols;
    bool posible= true;


    if (automatic && t.get_Fichas_Restantes() > 0){
        posible = jugadaIA(t);
        if(posible){
            t.una_Ficha_Menos();
        }else{
            t.set_Fichas_Restantes(t.get_Fichas_Max());
            t.cambiaTurno();
        }

    }
    else{
        std::cout << "\n introduzca la posición en formato fila-columna ";
        std::cout << "\n le quedan  " << t.get_Fichas_Restantes() << " fichas restantes  de  " << t.get_Fichas_Max() ;
        std::cout << "\n y " << getComodines() << " comodines";

        std::cin >> f_char;

        if (f_char == '?'){
            if (getComodines() == 0){

                std::cout << "\nOops, te has quedado sin comodines ";

                std::cout << "\n introduzca la posición en formato fila-columna ";

                std::cin>>f_char;
                if (f_char == '!') {
                    p.f = '!';
                    return false;
                }
                f = f_char -'0';
                std::cin>>col;
                cols = t.leerColumnas(col);
            }else {
                muestraPosibles(t);
                unComodinMenos();

                std::cout << "\n introduzca la posición en formato fila-columna ";
                std::cin >> f_char;
                if (f_char == '!') {
                    p.f = '!';
                    return false;
                }
                std::cin >> col;
                f = f_char - '0';
                cols = t.leerColumnas(col);
            }
        }
        else if(f_char == '!'){
            p.f='!';
            return false;
            //Salimos de la función
        }
        else{
            //Leemos columnas.
            std::cin>>col;
            cols = t.leerColumnas(col);
            f=f_char-'0';
        }



        if (t.posible(f,cols)){
            p.f = f;
            p.c  = cols;
        }else{
            posible = false;
        }
    }

    if(t.get_Fichas_Restantes() == 0){
        t.set_Fichas_Restantes(t.get_Fichas_Max());
        t.cambiaTurno();
    }

    return posible;
}

/*________________________________________________________________________________________*/

std::ostream &operator<<(std::ostream& os, const Jugador& j)
{
    j.imprimirNombre(os);
    os << std::endl;
    if(os.good()){
        os << j.getComodines() << std::endl;
    }
}

/*________________________________________________________________________________________*/

std::istream &operator>>(std::istream &is, Jugador& j)
{
    //Solo vamos a leer el turno y el nombre, los demas parámetros se iniciarán a 0.
    char fin = '\n';
    char letra;

    is >> letra;
    if(letra == '!'){
        is >> letra;
        if (letra == '@') {
            j.setAutomatic();
        }
        j.push_back(letra);
    }else {
        if (letra == '@') {
            j.setAutomatic();
        }
        j.push_back(letra);
    }

    while (is.peek() != fin){
        is >> letra;
        if (is.good()){
            j.push_back(letra);
        }
    }

    return is;
}
/*________________________________________________________________________________________*/

/****************Fin del fichero jugador.cpp**************************/