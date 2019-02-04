/**
 * @file main.cpp
 * @brief Gestiona lo necesario para partida de reversi.
 */

#include <iostream>
#include "tablero.h"
#include "jugador.h"

using namespace std;

void guardaPartida(const Tablero &t, const Jugador &a, const Jugador &v) {

    ofstream f;
    char archivo_destino[60];
    cout << "Introduce el nombre del fichero: ";
    cin >> archivo_destino;
    f.open(archivo_destino);
    f << "#MP-SUPER-REVERSI-1.0" << endl;
    f << t;
    f << '!';
    f << a << std::endl;
    f << a.getGanadas() << ' ' << a.getEmpatadas() << ' ' << a.getPerdidas() << std::endl;
    f << '!';
    f << v << std::endl;
    f << v.getGanadas() << ' ' << v.getEmpatadas() << ' ' << v.getPerdidas() << std::endl;

    f.close();


}

bool cargaPartida(const char *archivo, Tablero &t, Jugador &a, Jugador &v) {

    int comodines;
    int n;
    char letra;
    ifstream f;
    f.open(archivo);
    const char cabecera[22] = "#MP-SUPER-REVERSI-1.0";

    if (!f.good()) {
        //Me salgo de la función
        return false;
    }
    int i=0;
    while (f.peek() != '\n'){
        f >> letra;
        if (letra != cabecera[i]){
            cerr << "\nArchivo no válido " << endl;
            return false;
        }
        i++;
    }

    f >> t;
    f >> a;
    f >> comodines;
    a.setComodines(comodines);
    f >> n;
    a.setGanadas(n);
    f >> n;
    a.setEmpatadas(n);
    f >> n;
    a.setPerdidas(n);

    f >> v;
    f >> comodines;
    v.setComodines(comodines);
    f >> n;
    v.setGanadas(n);
    f >> n;
    v.setEmpatadas(n);
    f >> n;
    v.setPerdidas(n);

    return true;
}


bool dialogoInterrumpir(Tablero &t, const Jugador &a, const Jugador &v) {

    char opcion;
    bool status;
    cout << "\nDeseas guardar la partida? (s/n): ";
    cin >> opcion;

    if (opcion == 's' || opcion == 'S') {
        t.finish_Partida();
        guardaPartida(t, a, v);
        status = true;
    }
    else{
        return false;
    }
    //Si devuelve true se sale del main.
    return status;

}

int main(int argc, char **argv) {

    char opcion;
    int puntuacion1 = 0;
    int puntuacion2 = 0;
    bool gameloop = true;
    int comodines;
    int juega_primero;
    Jugador a, v;
    Tablero t;
    Punto2D p;
    char tablero[60];

    // Inicializamos a nuestros 2 Jugadores.
    if (argc < 2) {

        cout << "\nIntroduzca tablero inicial  ";
        cin >> tablero;

        t.setCFG_Inicial(tablero);

        ifstream f;
        f.open(tablero);

        f >> t;

        cout << "Introduce nombre del primer jugador (@jugador si quiere que sea jugador automático) " << endl;

        cin >> a;

        cout << "Introduce nombre del segundo jugador (@jugador si quiere que sea jugador automático) " << endl;

        cin >> v;

        cout << "\nIntroduzca el numero de comodines  (0-10) ";
        cin >> comodines;

        a.setComodines(comodines);
        v.setComodines(comodines);

        system("clear");

    } else {
        if (!cargaPartida(argv[1], t, a, v)) {
            cerr << "\nNo se reconoce el archivo " << endl;
        }
    }
    t.setTurnoInicial(2);

    //bucle principal del juego
    //Cada partida se puede jugar con un tablero nuevo y con diferentes dimensiones.
    //Por eso creamos en cada iteración un nuevo Tablero t.
    while (gameloop) {
        juega_primero = t.getTurno_Inicial();
        t.set_Turno(juega_primero);

        system("clear");

        cout << "           COMIENZA LA PARTIDA          \n" << "\n" << endl;
        int contador = 0;

        t.muestraTablero(cout);

        while (contador < 2 && !t.tableroFull()) {

            if (!t.hay_jugada()) {
                cout << " No hay posible tirada para ";

                if (t.get_Turno() == 1) {

                    a.imprimirNombre(cout);
                    cout << endl;


                } else if (t.get_Turno() == 2) {

                    v.imprimirNombre(cout);
                    cout << endl;

                }
                t.cambiaTurno();
                contador++;

            }else {

                contador = 0;
                if (t.get_Turno() == 1) {
                    bool status;

                    a.imprimirNombre(cout);
                    cout << endl;

                    status = a.escogePosicion(t,p);

                    while(!status ){
                        if (p.f == '!'){
                            if (!dialogoInterrumpir(t,a,v)){
                                status = a.escogePosicion(t,p);
                            }
                            else{
                                return 0; //Termina el programa
                            }
                        }else{
                            while (t.hay_jugada() && !status) {
                                status = a.escogePosicion(t,p);
                            }
                            if (!t.hay_jugada()){
                                status=true;
                            }
                        }
                    }

                    if(!a.esAutomatic() && t.get_Fichas_Restantes() > 0){
                        t.jugada(p.f, p.c);
                        t.una_Ficha_Menos();
                    }
                    if (t.get_Fichas_Restantes() == 0 && !a.esAutomatic()){
                        t.cambiaTurno();
                        t.set_Fichas_Restantes(t.get_Fichas_Max());
                    }
                    t.muestraTablero(cout);

                }else if (t.get_Turno() == 2) {

                    v.imprimirNombre(cout);

                    bool status2;

                    status2 = v.escogePosicion(t,p);
                    while(!status2){
                        if (p.f == '!'){
                            if (!dialogoInterrumpir(t,a,v)){
                                status2 = v.escogePosicion(t,p);
                            }
                            else{
                                return 0;
                            }
                        }else{
                            while (t.hay_jugada() && !status2){
                                status2 = v.escogePosicion(t,p);
                            }
                            if(!t.hay_jugada()){
                                status2=true;
                            }
                        }
                    }
                    if (!v.esAutomatic() && t.get_Fichas_Restantes()> 0 ){
                        t.jugada(p.f, p.c);
                        t.una_Ficha_Menos();
                    }
                    if (t.get_Fichas_Restantes() == 0 && !v.esAutomatic()){
                        t.cambiaTurno();
                        t.set_Fichas_Restantes(t.get_Fichas_Max());
                    }

                    t.muestraTablero(cout);
                }
            }

        }//bucle principal del juego

        //          RECUENTO PUNTUACIONES

        puntuacion1 = a.puntuacionFinal1(t);
        puntuacion2 = v.puntuacionFinal2(t);

        if (puntuacion1 > puntuacion2) {
            if(!t.partida_finished()) {
                a.unaGanadaMas();
                v.unaPerdidaMas();
            }

            cout << "\nEl ganador es :  ";
            a.imprimirNombre(cout);
            cout << " con una puntuación de " << puntuacion1 << " puntos y ";
            v.imprimirNombre(cout);
            cout << " ha perdido con una puntuacion de "
                 << puntuacion2 << endl;
        } else if (puntuacion1 < puntuacion2) {
            if(!t.partida_finished()) {
                a.unaPerdidaMas();
                v.unaGanadaMas();
            }

            cout << "\nEl ganador es : " ;
            v.imprimirNombre(cout);
            cout << " con una puntuación de " << puntuacion2 << " puntos y ";
            a.imprimirNombre(cout);

            cout << " ha perdido con una puntuacion de "
                 << puntuacion1 << endl;
        } else {
            if(!t.partida_finished()) {
                a.unaEmpatadaMas();
                v.unaEmpatadaMas();
            }

            cout << "\n\t" <<  "EMPATE" ;
            cout << endl;
        }
        //Imprimimos por pantalla las estadísticas.
        cout << "\nRecuento de victorias : \n";
        cout << "\nVictorias para  " ;
        a.imprimirNombre(cout);
        cout << " " << a.getGanadas();

        cout << "\nVictorias para  " ;
        v.imprimirNombre(cout);
        cout << " " <<   v.getGanadas() << endl;

        cout << "\n\t ¿ Desea jugar otra partida ? " << endl;
        cout << "\n\t Pulse cualquier tecla para jugar otra partida o 'N' para finalizar " << endl;
        cin >> opcion;


        if (opcion == 'n' || opcion == 'N') {
            gameloop = false;
            t.finish_Partida();
        }else if( opcion == '!') {
            gameloop = false;
            if (!dialogoInterrumpir(t, a, v)) {
                cerr << "\nError al guardar la configuración el a partida  ...";
            }
        }
        else if( argc < 2){
            ifstream f;
            f.open(tablero);
            f >> t;
            t.cambiaTurnoInicial();
        }
        else if (argc == 2){
            ifstream f;
            f.open(t.getCFG_Inicial());
            f >> t;
            t.cambiaTurnoInicial();
        }

    }

    return 0;
}

/****************Fin del fichero main.cpp**************************/