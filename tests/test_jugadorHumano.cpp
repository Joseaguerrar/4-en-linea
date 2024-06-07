#include <gtest/gtest.h>

#include <jugadorHumano.hh>
#include <sstream>
#include <string>
#include <tablero.hh>

Tablero tablero(7, 7);

// esta función simula la entrada del usuario

int obtenerColumna(Tablero tableroActual, std::istream& in = std::cin) {
  int columnaSeleccionada = tableroActual.getColumnas();
  in >> columnaSeleccionada;
  return columnaSeleccionada;
}

//se prueba el constructos
TEST(pruebaHumano, constructor) {
  Ficha ficha = Ficha::Azul;
  string nombre = "jugador1";
  jugadorHumano persona(nombre, ficha);
  EXPECT_EQ(ficha, persona.getColorFicha());
  EXPECT_EQ(nombre, persona.getNombre());
}
