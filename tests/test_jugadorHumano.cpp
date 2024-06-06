#include <gtest/gtest.h>
#include <tablero.hh>
#include <jugadorHumano.hh>
#include <string>
TEST(pruebaHumano, constructor) {
    Ficha ficha = Ficha::Azul;
    string nombre = "jugador1";
    jugadorHumano persona(nombre, ficha);
    EXPECT_EQ(ficha, persona.getColorFicha());
}