#include <gtest/gtest.h>

#include <jugadorHumano.hh>
#include <sstream>
#include <string>
#include <tablero.hh>

Tablero tablero(7, 7);

// esta función simula la entrada del usuario

int obtenerColumna(std::istream& in = std::cin) {
  int columnaSeleccionada = 0;
  in >> columnaSeleccionada;
  return columnaSeleccionada;
}

// se prueba el constructor
TEST(pruebaHumano, constructorAzul) {
  Ficha ficha = Ficha::Azul;
  string nombre = "jugador1";
  jugadorHumano persona(nombre, ficha);
  EXPECT_EQ(ficha, persona.getColorFicha());
  EXPECT_EQ(nombre, persona.getNombre());
}

TEST(pruebaHumano, constructorRojo) {
  Ficha ficha = Ficha::Rojo;
  string nombre = "jugador1";
  jugadorHumano persona(nombre, ficha);
  EXPECT_EQ(ficha, persona.getColorFicha());
  EXPECT_EQ(nombre, persona.getNombre());
}
