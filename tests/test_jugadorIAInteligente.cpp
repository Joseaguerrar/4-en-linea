#include <gtest/gtest.h>
#include<iostream>
#include <jugadorIAInteligente.hh>
#include <sstream>
#include <string>
#include <tablero.hh>

TEST(pruebaIAInteligente, constructorAzul) {
  Ficha ficha = Ficha::Azul;
  string nombre = "jugador1";
  jugadorIAInteligente jugadorIAFacil(nombre, ficha, 0);
  EXPECT_EQ(ficha, jugadorIAFacil.getColorFicha());
  EXPECT_EQ(nombre, jugadorIAFacil.getNombre());
}

TEST(pruebaIAInteligente, constructorRojo) {
  Ficha ficha = Ficha::Rojo;
  string nombre = "jugador1";
  jugadorIAInteligente jugadorIAFacil(nombre, ficha, 0);
  EXPECT_EQ(ficha, jugadorIAFacil.getColorFicha());
  EXPECT_EQ(nombre, jugadorIAFacil.getNombre());
}

// a partir de acá es para ver si la IA inteligente es capaz de "bloquear" en un
// caso real de juego, obviando que se le da un caso "ya preparado de juego"
TEST(pruebaIAInteligente, casoTresHorizontal) {
  Tablero tablero(7, 7);
  tablero.soltarFicha(0, Ficha::Azul);
  tablero.soltarFicha(1, Ficha::Azul);
  tablero.soltarFicha(2, Ficha::Azul);
  jugadorIAInteligente bot("jugador1", Ficha::Rojo, 3);
  EXPECT_EQ(bot.seleccionarColumna(tablero), 3);
}

TEST(pruebaIAInteligente, casoTresVertical) {
  Tablero tablero(7, 7);
  tablero.soltarFicha(5, Ficha::Azul);
  tablero.soltarFicha(5, Ficha::Azul);
  tablero.soltarFicha(5, Ficha::Azul);
  jugadorIAInteligente bot("jugador1", Ficha::Rojo, 3);
  EXPECT_EQ(bot.seleccionarColumna(tablero), 5);
}

//se prepara el caso de diagonal en una 5x4
TEST(pruebaIAInteligente, casoTresDiagonal){
    Tablero tablero(6,6);
    tablero.soltarFicha(0,Ficha::Azul);
    tablero.soltarFicha(0,Ficha::Rojo);
    tablero.soltarFicha(0,Ficha::Azul);
    tablero.soltarFicha(0,Ficha::Rojo);
    tablero.soltarFicha(0,Ficha::Azul);
    tablero.soltarFicha(1,Ficha::Rojo);
    tablero.soltarFicha(1,Ficha::Azul);
    tablero.soltarFicha(1,Ficha::Rojo);
    tablero.soltarFicha(1,Ficha::Azul);
    tablero.soltarFicha(1,Ficha::Rojo);
    tablero.soltarFicha(2,Ficha::Rojo);
    tablero.soltarFicha(2,Ficha::Rojo);
    tablero.soltarFicha(2,Ficha::Azul);
    tablero.soltarFicha(2,Ficha::Rojo);
    tablero.soltarFicha(2,Ficha::Azul);
    tablero.soltarFicha(3,Ficha::Azul);

    jugadorIAInteligente bot("jugador1", Ficha::Rojo, 3);
    EXPECT_EQ( bot.seleccionarColumna(tablero), 3);
}

//casos donde la IA tiene que ganar

//se prepara el caso de diagonal en una 5x4
TEST(pruebaIAInteligente, casoTresDiagonaGanadorl){
    Tablero tablero(6,6);
    tablero.soltarFicha(0,Ficha::Azul);
    tablero.soltarFicha(0,Ficha::Rojo);
    tablero.soltarFicha(0,Ficha::Azul);
    tablero.soltarFicha(0,Ficha::Rojo);
    tablero.soltarFicha(0,Ficha::Azul);
    tablero.soltarFicha(1,Ficha::Rojo);
    tablero.soltarFicha(1,Ficha::Azul);
    tablero.soltarFicha(1,Ficha::Rojo);
    tablero.soltarFicha(1,Ficha::Azul);
    tablero.soltarFicha(1,Ficha::Rojo);
    tablero.soltarFicha(2,Ficha::Rojo);
    tablero.soltarFicha(2,Ficha::Rojo);
    tablero.soltarFicha(2,Ficha::Azul);
    tablero.soltarFicha(2,Ficha::Rojo);
    tablero.soltarFicha(2,Ficha::Azul);
    tablero.soltarFicha(3,Ficha::Azul);
    jugadorIAInteligente bot("jugador1", Ficha::Azul, 3);
    cout<< bot.seleccionarColumna(tablero) << endl;
    EXPECT_EQ( bot.seleccionarColumna(tablero), 3);
}