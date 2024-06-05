#include <iostream>
#include <tablero.hh>
#include <jugadorIAFacil.hh>
#include <jugadorIAInteligente.hh>
#include <jugadorHumano.hh>
using namespace std;

int main(){
    Tablero prueba(7,7);
    jugadorIAInteligente jugador1 = jugadorIAInteligente("jugador1", Ficha::Azul, 5);
    jugadorIAInteligente jugador2 = jugadorIAInteligente("jugador2", Ficha::Rojo, 1);
    int columna;
    while(!prueba.comprobarGanador(jugador1.getColorFicha()) && !prueba.comprobarGanador(jugador2.getColorFicha())){
        prueba.soltarFicha(jugador1.seleccionarColumna(prueba), jugador1.getColorFicha());
        prueba.mostrarTablero();
        cout << "-------------" << endl;
        prueba.soltarFicha(jugador2.seleccionarColumna(prueba), jugador2.getColorFicha());
        prueba.mostrarTablero();
        cout << "-------------" << endl;
    }
    prueba.mostrarTablero();
    return 0;
}