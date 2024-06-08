#include <gtest/gtest.h>

#include <jugadorIAFacil.hh>
#include <sstream>
#include <string>
#include <tablero.hh>

TEST(pruebaIAFacil, constructorAzul) {
  Ficha ficha = Ficha::Azul;
  string nombre = "jugador1";
  jugadorIAFacil jugadorIAFacil(nombre, ficha);
  EXPECT_EQ(ficha, jugadorIAFacil.getColorFicha());
  EXPECT_EQ(nombre, jugadorIAFacil.getNombre());
}

TEST(pruebaIAFacil, constructorRojo) {
  Ficha ficha = Ficha::Rojo;
  string nombre = "jugador1";
  jugadorIAFacil jugadorIAFacil(nombre, ficha);
  EXPECT_EQ(ficha, jugadorIAFacil.getColorFicha());
  EXPECT_EQ(nombre, jugadorIAFacil.getNombre());
}

// nota: los test de seleccionar columna pueden tardar un poco más porque el
// tablero se exageró y se prueban 10000 veces

TEST(pruebaIAFacil, seleccionarColumna10x10) {
  Ficha ficha = Ficha::Rojo;
  Tablero tablero(10, 10);
  string nombre = "jugador1";
  jugadorIAFacil jugadorIAFacil(nombre, ficha);
  // se prueba que seleccione columna 10000 veces y que todas sean verdadera
  // para evitar errores, asumiendo que el tablero esté vacío
  for (int i = 0; i < 10000; i++) {
    int columna = jugadorIAFacil.seleccionarColumna(tablero);
    EXPECT_TRUE(columna < 10 && columna >= 0);
  }
}

TEST(pruebaIAFacil, seleccionarColumna100x100) {
  Ficha ficha = Ficha::Rojo;
  Tablero tablero(100, 100);
  string nombre = "jugador1";
  jugadorIAFacil jugadorIAFacil(nombre, ficha);
  // se prueba que seleccione columna 10000 veces y que todas sean verdadera
  // para evitar errores, asumiendo que el tablero esté vacío
  for (int i = 0; i < 10000; i++) {
    int columna = jugadorIAFacil.seleccionarColumna(tablero);
    EXPECT_TRUE(columna < 100 && columna >= 0);
  }
}

TEST(pruebaIAFacil, seleccionarColumna1000x1000) {
  Ficha ficha = Ficha::Rojo;
  Tablero tablero(1000, 1000);
  string nombre = "jugador1";
  jugadorIAFacil jugadorIAFacil(nombre, ficha);
  // se prueba que seleccione columna 10000 veces y que todas sean verdadera
  // para evitar errores, asumiendo que el tablero esté vacío
  for (int i = 0; i < 10000; i++) {
    int columna = jugadorIAFacil.seleccionarColumna(tablero);
    EXPECT_TRUE(columna < 1000 && columna >= 0);
  }
}