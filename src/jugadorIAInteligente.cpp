#include <IJugador.hh>
#include <algorithm>
#include <iostream>
#include <jugadorIAInteligente.hh>
#include <limits>
#include <memory>
#include <string>
#include <tablero.hh>
#include <vector>
using namespace std;

jugadorIAInteligente::jugadorIAInteligente(string Nombre, Ficha ColorFicha,
                                           int Profundidad)
    : nombre(Nombre),
      colorFichaMax(ColorFicha),
      profundidad(Profundidad),
      colorFichaMin((ColorFicha == Ficha::Azul) ? Ficha::Rojo : Ficha::Azul) {}

string jugadorIAInteligente::getNombre() { return nombre; }

Ficha jugadorIAInteligente::getColorFicha() { return colorFichaMax; }

// funcion que selecciona la con el minimax poda alpha y beta
int jugadorIAInteligente::seleccionarColumna(Tablero& tableroActual) {
  // si hay más de una columna usa el minimax
  if (columnasDisponibles(tableroActual) > 1) {
    int menosInfinito = numeric_limits<int>::min();
    int masInfinito = numeric_limits<int>::max();
    return minimax(tableroActual, profundidad, menosInfinito, masInfinito, true)
        .second;
  } else {
    // si solo queda una columna no tiene sentido hacer el minimax, aparte que
    // se evitar errores de segmentation fault
    int columnaSeleccionada = 0;
    for (int i = 0; i < tableroActual.getColumnas(); i++) {
      if (tableroActual.puedeTirar(i)) {
        columnaSeleccionada = i;
      }
    }
    return columnaSeleccionada;
  }
}
// la función retorna dos valores enteros, la puntuación(se usa dentro del
// minimax) y la mejor columna (se usa en seleccionar columna) respectivamente
pair<int, int> jugadorIAInteligente::minimax(Tablero& tableroActual,
                                             int profundidad, int alfa,
                                             int beta, bool max) {
  // Inicializamos a un valor no válido para asegurarlos que la columna está
  // cambiando
  int mejorColumna = -1;
  // si la profundidad es 0 o en el tablero se comprueba un ganador se retorna
  // el valor dado por la función heuristica
  if (profundidad == 0 || tableroActual.comprobarGanador(colorFichaMax) ||
      tableroActual.comprobarGanador(colorFichaMin)) {
    return make_pair(funcionHeuristica(tableroActual), mejorColumna);
  }
  // si el jugador es max
  if (max) {
    // se inicializa en el número más bajo
    int valor = numeric_limits<int>::min();
    for (int j = 0; j < tableroActual.getColumnas(); j++) {
      // se verifica si se puede hacer una jugada
      if (tableroActual.puedeTirar(j)) {
        // se crea una copia del tablero(importante, esta no puede ser un
        // puntero, porque se estaría modificando el tablero enviado)
        Tablero tableroCopia = tableroActual;
        // se ingresa la ficha en la copia del tablero
        tableroCopia.soltarFicha(j, colorFichaMax);
        // se usa el recursivamente el minimax para obtener el valor actual
        int valorActual =
            minimax(tableroCopia, profundidad - 1, alfa, beta, false).first;
        // si el valor actual supera al valor mínimo se intercambian y se
        // selecciona "la mejor columna en ese momento"
        if (valorActual > valor) {
          valor = valorActual;
          mejorColumna = j;
        }
        // alfa va a ser el mayor número entre el alfa ingresado y el valor
        alfa = std::max(alfa, valor);
        // si alfa es menor o igual que beta se poda beta
        if (alfa >= beta) {
          // Poda beta
          break;
        }
      }
    }
    // se retornan dos valores enteros
    return make_pair(valor, mejorColumna);
  } else {
    // si el jugador no es maximizador pasa lo contrario a lo anterior
    // se inicializa valor en el entero más grande
    int valor = numeric_limits<int>::max();
    for (int j = 0; j < tableroActual.getColumnas(); j++) {
      // si la columna enviada puede tirar se crea una copia del tablero
      if (tableroActual.puedeTirar(j)) {
        // se vuelve a crear una copia del tablero para no afectar ni modificar
        // el actual
        Tablero tableroCopia = tableroActual;
        // se suelta la ficha seleccionada anteriormente verificada
        tableroCopia.soltarFicha(j, colorFichaMin);
        // se llama recursivamente al minimax igual que en el caso anterior, en
        // este caso se llama al primer elemento que es la puntuación
        int valorActual =
            minimax(tableroCopia, profundidad - 1, alfa, beta, true).first;
        // si el valorActual es menor que el valor se intercambian y se
        // selecciona la mejor columna de ese momento
        if (valorActual < valor) {
          valor = valorActual;
          mejorColumna = j;
        }
        // beta va a ser el menor valor entre valor y el beta ingresado
        beta = std::min(beta, valor);
        // si alfa es mayor o igual que beta se poda beta
        if (alfa >= beta) {
          break;
        }
      }
    }
    return make_pair(valor, mejorColumna);
  }
}

int jugadorIAInteligente::funcionHeuristica(Tablero& tableroCopia) {
  // comprueba si MAX ganó o MIN y retorna un valor de acuerdo a eso

  if (tableroCopia.comprobarGanador(colorFichaMax)) {
    return 1000;
  } else if (tableroCopia.comprobarGanador(colorFichaMin)) {
    return -1000;
  }
  // si no se cumple lo anterior se retorna una resta entre la cantidad de
  // lineas ganadoras cuando es max y cuando es min lineasGanadorasMax -
  // lineasGanadorasMin
  return determinarLineasGanadoras(tableroCopia, true) -
         determinarLineasGanadoras(tableroCopia, false);
}

// esta función acarrea la misma lógica que la de tablero sin embargo en este
// caso necesitamos valores diferentes
int jugadorIAInteligente::determinarLineasGanadoras(Tablero& tableroCopia,
                                                    bool isMax) {
  // se verifica si es max o min, si isMax es verdadero se usa la ficha con el
  // color de FichaMax y viceversa
  Ficha ficha;
  if (isMax) {
    ficha = colorFichaMax;
  } else {
    ficha = colorFichaMin;
  }
  // se inicializan valores necesarios para la función lineasGanadoras, filas y
  // columnas del tablero
  int lineasGanadoras = 0;
  int filas = tableroCopia.getFilas();
  int columnas = tableroCopia.getColumnas();
  vector<vector<Ficha>> tablero = tableroCopia.getTablero();
  // Se comprueban las lineas ganadoras en horizontal
  for (int i = 0; i < filas; ++i) {
    for (int j = 0; j < columnas - 3; ++j) {
      if (tablero[i][j] == ficha && tablero[i][j + 1] == ficha &&
          tablero[i][j + 2] == ficha && tablero[i][j + 3] == ficha) {
        lineasGanadoras++;
      }
    }
  }
  // Se comprueban las lineas ganadoras en vertical
  for (int i = 0; i < filas - 3; ++i) {
    for (int j = 0; j < columnas; ++j) {
      if (tablero[i][j] == ficha && tablero[i + 1][j] == ficha &&
          tablero[i + 2][j] == ficha && tablero[i + 3][j] == ficha) {
        lineasGanadoras++;
        ;
      }
    }
  }
  // Se comprueban las lineas ganadoras en diagonal hacia la derecha
  for (int i = 0; i < filas - 3; ++i) {
    for (int j = 0; j < columnas - 3; ++j) {
      if (tablero[i][j] == ficha && tablero[i + 1][j + 1] == ficha &&
          tablero[i + 2][j + 2] == ficha && tablero[i + 3][j + 3] == ficha) {
        lineasGanadoras++;
      }
    }
  }
  // Se comprueban las lineas ganadoras en diagonal hacia la izquierda
  for (int i = 0; i < filas - 3; ++i) {
    for (int j = 3; j < columnas; ++j) {
      if (tablero[i][j] == ficha && tablero[i + 1][j - 1] == ficha &&
          tablero[i + 2][j - 2] == ficha && tablero[i + 3][j - 3] == ficha) {
        lineasGanadoras++;
      }
    }
  }

  // se retorna el valor final de las lineas ganadoras
  return lineasGanadoras;
}

// función que verifica la cantidad de columnas disponibles
int jugadorIAInteligente::columnasDisponibles(Tablero& tableroCopia) {
  int columnasDisponibles = 0;
  for (int i = 0; i < tableroCopia.getColumnas(); i++) {
    if (tableroCopia.puedeTirar(i)) {
      columnasDisponibles++;
    }
  }
  return columnasDisponibles;
}
