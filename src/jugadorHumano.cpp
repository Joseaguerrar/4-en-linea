#include <IJugador.hh>
#include <iostream>
#include <jugadorHumano.hh>
#include <string>
using namespace std;
// Constructor sin inicializar
jugadorHumano::jugadorHumano() {}
// Constructor inicializado
jugadorHumano::jugadorHumano(string Nombre, Ficha ColorFicha)
    : nombre(Nombre), colorFicha(ColorFicha) {}
// Método que devuelve el nombre del jugador
string jugadorHumano::getNombre() { return nombre; }
// Método que devuelve el color de la ficha
Ficha jugadorHumano::getColorFicha() { return colorFicha; }
// Método que selecciona la columna en la que quiere poner la ficha en el
// tablero
int jugadorHumano::seleccionarColumna(Tablero& tableroActual) {
  string entradaUsuario;
  int controlIteraciones = 0;
  cout << "Ingrese la columna donde desea soltar la ficha: " << endl;
  cin >> entradaUsuario;

  // se comprueba que la entrada del usuario no contenga letras, es decir que
  // solamente contenga números
  for (int i = 0; i < entradaUsuario.length(); i++) {
    if (!(entradaUsuario[i] >= '0' && entradaUsuario[i] <= '9')) {
      throw runtime_error(
          "No puede ingresar nada que no sea un número, solamente números, "
          "pruebe de nuevo: ");
    }
  }

  // luego de comprobar que la entrada del usuario no contenga nada que no sea
  // un número entero, se comprueba que la columna seleccionada esté disponible
  int columnaSeleccionada = stoi(entradaUsuario) - 1;
  if (!tableroActual.puedeTirar(columnaSeleccionada)) {
    throw runtime_error("Número de columna inválida, seleccione otra: ");
  }
  return columnaSeleccionada;
}
