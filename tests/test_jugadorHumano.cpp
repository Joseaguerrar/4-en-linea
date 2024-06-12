#include <gtest/gtest.h>
#include <jugadorHumano.hh>
//para simular la entrada del usuario
#include <sstream>
#include <string>
#include <tablero.hh>

Tablero tablero(7, 7);

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

//se prueba las entradas de las columnas y sus excepciones
TEST(pruebaHumano, entradaColumnaCorrecta) {
  Tablero tablero(6,6);
  Ficha ficha = Ficha::Rojo;
  string nombre = "jugador1";
  jugadorHumano persona(nombre, ficha);
  istringstream input("5");
  //se simula la entrada
  cin.rdbuf(input.rdbuf());
  int columnaSeleccionada = persona.seleccionarColumna(tablero);
  EXPECT_EQ(columnaSeleccionada, 4);

}

TEST(pruebaHumano, entradaColumnaIncorrectaConNúmero) {
  Tablero tablero(6,6);
  Ficha ficha = Ficha::Rojo;
  string nombre = "jugador1";
  jugadorHumano persona(nombre, ficha);
  istringstream input("54");
  cin.rdbuf(input.rdbuf());
  EXPECT_THROW(persona.seleccionarColumna(tablero), runtime_error);

}

TEST(pruebaHumano, entradaColumnaIncorrectaConLetras) {
  Tablero tablero(6,6);
  Ficha ficha = Ficha::Rojo;
  string nombre = "jugador1";
  jugadorHumano persona(nombre, ficha);
  istringstream input("ESTA ES UNA COLUMNA INVÁLIDA");
  cin.rdbuf(input.rdbuf());
  EXPECT_THROW(persona.seleccionarColumna(tablero), runtime_error);

}


