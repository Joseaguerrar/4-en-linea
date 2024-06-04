#include <IJugador.hh>
#include <jugadorHumano.hh>
#include <string>
#include <iostream>
#include <random>

using namespace std;

jugadorHumano::jugadorHumano(string Nombre, Ficha ColorFicha): nombre(Nombre), colorFicha(ColorFicha){}

string jugadorHumano::getNombre(){return nombre;}

Ficha jugadorHumano::getColorFicha(){return colorFicha;}


int jugadorHumano::seleccionarColumna(Tablero tableroActual){
    int columnaSeleccionada = tableroActual.getColumnas();
    cout << "Ingrese la columna donde desea soltar la ficha: " << endl;
    cin >> columnaSeleccionada;
    //TODO: verificar con puede solar del tablero si es valido el movimiento si no pedir otro
    //TODO: hacer throw para que el usuario no ingrese nada raro
    if(tableroActual.puedeTirar(columnaSeleccionada)){
        return columnaSeleccionada;
    }
    throw("Seleccione otra columna");
}
