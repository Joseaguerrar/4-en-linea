#include <gtest/gtest.h>
#include <jugadorHumano.hh>
#include <string>
#include <tablero.hh>

Tablero tablero(7,7);

TEST(pruebaHumano, constructor) {
  Ficha ficha = Ficha::Azul;
  string nombre = "jugador1";
  jugadorHumano persona(nombre, ficha);
  EXPECT_EQ(ficha, persona.getColorFicha());
}

TEST(pruebaHumano, colocarFicha){

    
}