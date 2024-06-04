#include <IJugador.hh>
#include <jugadorIAFacil.hh>
#include <string>
#include <random>

using namespace std;

jugadorIAFacil::jugadorIAFacil(string Nombre, Ficha ColorFicha): nombre(Nombre), colorFicha(ColorFicha){}

string jugadorIAFacil::getNombre(){return nombre;}

Ficha jugadorIAFacil::getColorFicha(){return colorFicha;}


int jugadorIAFacil::seleccionarColumna(Tablero tableroActual){
    int numeroColumnas = tableroActual.getColumnas();
    random_device rd;
    mt19937 eng(rd()); 
    //TODO: comprobar si se puede tirar antes de hacer el return
    uniform_int_distribution<int> distr(0, tableroActual.getColumnas());
    int columnaSeleccionada = distr(eng);
    if(tableroActual.puedeTirar(columnaSeleccionada)){
        return columnaSeleccionada;
    }
    throw("Seleccione otra columna"); 
    return columnaSeleccionada;
}
