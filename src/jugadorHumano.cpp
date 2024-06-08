#include <IJugador.hh>
#include <iostream>
#include <jugadorHumano.hh>
#include <random>
#include <string>

using namespace std;
jugadorHumano::jugadorHumano() {}
jugadorHumano::jugadorHumano(string Nombre, Ficha ColorFicha)
    : nombre(Nombre), colorFicha(ColorFicha) {}

string jugadorHumano::getNombre() { return nombre; }

Ficha jugadorHumano::getColorFicha() { return colorFicha; }

int jugadorHumano::seleccionarColumna(Tablero& tableroActual) {
  int columnaSeleccionada;
    cout << "Ingrese la columna donde desea soltar la ficha: " << endl;
    while (true) {
        cin >> columnaSeleccionada;
        if (cin.fail()) {
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta
            cout << "Entrada inválida, por favor ingrese un número entero: " << endl;
        } else {
            columnaSeleccionada--; // Ajustar para el índice basado en 0
            if (tableroActual.puedeTirar(columnaSeleccionada)) {
                break; // Salir del bucle si la columna es válida
            } else {
                cout << "La columna seleccionada no es válida, ingrese otra: " << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar cualquier entrada extraña
            }
        }
    }
    return columnaSeleccionada;
}
