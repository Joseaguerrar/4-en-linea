/*












*/
#include <IJugador.hh>
#include <jugadorIAFacil.hh>
#include <string>
#include <random>

using namespace std;

jugadorIAFacil::jugadorIAFacil(string Nombre, char ColorFicha): nombre(Nombre), colorFicha(ColorFicha){}

string jugadorIAFacil::getNombre(){return nombre;}

char jugadorIAFacil::getColorFicha(){return colorFicha;}


int jugadorIAFacil::seleccionarColumna(Tablero tableroActual){
    int numeroColumnas = tableroActual.getColumnas();
    random_device rd;
    mt19937 eng(rd()); 
    uniform_int_distribution<int> distr(0, tableroActual.getColumnas());
    return distr(eng);
}
