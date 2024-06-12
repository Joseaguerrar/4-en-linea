#include <iostream>
#include <jugadorHumano.hh>
#include <jugadorIAFacil.hh>
#include <jugadorIAInteligente.hh>
#include <stdexcept>
#include <string>
#include <tablero.hh>
// Para manejar errores
#include <limits>
// Para límites de un tipo de dato específico en el sistema

using namespace std;

// Prototipos de las funciones
void jugar();
// crear los diferentes juegos
void crearHyH();
void crearHyB();
void crearHyIA();
void crearByB();
void crearByIA();
void crearIAyIA();
// Ciclos
void CiclohumanoContraHumano(jugadorHumano, jugadorHumano, Tablero);
void CiclohumanoContraBot(jugadorHumano, jugadorIAFacil, Tablero);
void CiclohumanoContraIA(jugadorHumano, jugadorIAInteligente, Tablero);
void CiclobotContrabot(jugadorIAFacil, jugadorIAFacil, Tablero);
void CiclobotContraIA(jugadorIAFacil, jugadorIAInteligente, Tablero);
void CicloIAContraIA(jugadorIAInteligente, jugadorIAInteligente, Tablero);
// Funciones para Datos
void mostrarOpciones();
bool volveraJugar();
int seleccionOpcion();
int pedirColumnas();
int pedirFilas();
int seleccionColumna();
int pedirProfundidadIA();
string pedirNombre(int);
Tablero crearTablero();
jugadorHumano crearJugadorH(int);
jugadorIAFacil crearJugadorB(int);
jugadorIAInteligente crearJugadorIA(int);

int main() {
  int opcion;
  bool juegoactivo = true;
  // Mientras el juego esté activo se va a mostrar el menú para jugar hasta que
  // quiera salir
  while (juegoactivo) {
    cout << "Seleccione una opción: " << endl;
    cout << "1. Jugar" << endl;
    cout << "2. Salir" << endl;
    opcion = seleccionOpcion();
    // Con 1 juega con 2 sale y con algo más le sigue pidiendo opción
    switch (opcion) {
      case 1:
        jugar();
        break;
      case 2:
        cout << "Tenga buen día..." << endl;
        return 0;
        // Salir del programa
      default:
        cout << "Opción no válida. Por favor, seleccione una opción válida."
             << endl;
    }
  }
  // return 0 aquí también para que se deje de ejecutar el main
  return 0;
}

// Definición de la función que simula el juego
void jugar() {
  int opcionJuego;
  bool juegoactivo = true;
  while (juegoactivo) {
    // Mientras el juego esté activo se va a mostrar el menú para las opciones
    // jugar hasta que quiera salir
    mostrarOpciones();
    opcionJuego = seleccionOpcion();
    switch (opcionJuego) {
      case 1:
        // Crear ciclo humano-humano
        crearHyH();
        break;
      case 2:
        // Crear ciclo humano-bot
        crearHyB();
        break;
      case 3:
        // Crear ciclo humano-IA
        crearHyIA();
        break;
      case 4:
        // Crear ciclo bot-bot
        crearByB();
        break;
      case 5:
        // Crear ciclo bot-IA
        crearByIA();
        break;
      case 6:
        // Crear ciclo IA-IA
        crearIAyIA();
        break;
      case 7:
        return;
        // Volver al menú principal
      default:
        // Tira mensaje de error y sigue el ciclo while
        cout << "Opción no válida. Por favor, seleccione una opción válida."
             << endl;
        break;
    }
  }
}
// Juegos
void crearHyH() {
  // Le pide los datos al usuario para crear los tipos jugadores y se ejecuta el
  // ciclo respectivo
  jugadorHumano jugador1 = crearJugadorH(1);
  jugadorHumano jugador2 = crearJugadorH(2);
  Tablero tablero = crearTablero();
  CiclohumanoContraHumano(jugador1, jugador2, tablero);
}
void crearHyB() {
  // Le pide los datos al usuario para crear los tipos jugadores y se ejecuta el
  // ciclo respectivo
  jugadorHumano jugador1 = crearJugadorH(1);
  jugadorIAFacil jugador2 = crearJugadorB(2);
  Tablero tablero = crearTablero();
  CiclohumanoContraBot(jugador1, jugador2, tablero);
}
void crearHyIA() {
  // Le pide los datos al usuario para crear los tipos jugadores y se ejecuta el
  // ciclo respectivo
  jugadorHumano jugador1 = crearJugadorH(1);
  jugadorIAInteligente jugador2 = crearJugadorIA(2);
  Tablero tablero = crearTablero();
  CiclohumanoContraIA(jugador1, jugador2, tablero);
}
void crearByB() {
  // Le pide los datos al usuario para crear los tipos jugadores y se ejecuta el
  // ciclo respectivo
  jugadorIAFacil jugador1 = crearJugadorB(1);
  jugadorIAFacil jugador2 = crearJugadorB(2);
  Tablero tablero = crearTablero();
  CiclobotContrabot(jugador1, jugador2, tablero);
}
void crearByIA() {
  // Le pide los datos al usuario para crear los tipos jugadores y se ejecuta el
  // ciclo respectivo
  jugadorIAFacil jugador1 = crearJugadorB(1);
  jugadorIAInteligente jugador2 = crearJugadorIA(2);
  Tablero tablero = crearTablero();
  CiclobotContraIA(jugador1, jugador2, tablero);
}
void crearIAyIA() {
  // Le pide los datos al usuario para crear los tipos jugadores y se ejecuta el
  // ciclo respectivo
  jugadorIAInteligente jugador1 = crearJugadorIA(1);
  jugadorIAInteligente jugador2 = crearJugadorIA(2);
  Tablero tablero = crearTablero();
  CicloIAContraIA(jugador1, jugador2, tablero);
}
// Ciclos//
void CiclohumanoContraHumano(jugadorHumano jugador1, jugadorHumano jugador2,
                             Tablero tablero) {
  // Ciclo de humano contra humano
  int columna;
  tablero.setvictoriasA(0);
  tablero.setvictoriasR(0);
  cout << "¡Que gane el mejor!" << endl;
  while (!tablero.comprobarEmpate()) {
    tablero.mostrarTablero();
    cout << "Turno de: " << jugador1.getNombre() << endl;
    // excepciones del jugador humano
    bool columnaValida = false;
    while (!columnaValida) {
      try {
        columna = jugador1.seleccionarColumna(tablero);
        columnaValida = true;
      } catch (runtime_error e) {
        cout << e.what() << endl;
      }
    }
    tablero.soltarFicha(columna, jugador1.getColorFicha());
    if (tablero.comprobarGanador(jugador1.getColorFicha())) {
      tablero.mostrarTablero();
      cout << "Ganó: " << jugador1.getNombre() << ", ¡Se terminó el juego!"
           << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
    if (tablero.comprobarEmpate()) {
      tablero.mostrarTablero();
      cout << "Se terminó el juego, es un empate! " << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
    tablero.mostrarTablero();
    cout << "Turno de: " << jugador2.getNombre() << endl;
    // excepciones del jugador humano
    columnaValida = false;
    while (!columnaValida) {
      try {
        columna = jugador2.seleccionarColumna(tablero);
        columnaValida = true;
      } catch (runtime_error e) {
        cout << e.what() << endl;
      }
    }
    tablero.soltarFicha(columna, jugador2.getColorFicha());
    if (tablero.comprobarGanador(jugador2.getColorFicha())) {
      tablero.mostrarTablero();
      cout << "Ganó: " << jugador2.getNombre() << ", ¡Se terminó el juego!"
           << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
    if (tablero.comprobarEmpate()) {
      tablero.mostrarTablero();
      cout << "Se terminó el juego, es un empate! " << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
  }
}
void CiclohumanoContraBot(jugadorHumano jugador1, jugadorIAFacil jugador2,
                          Tablero tablero) {
  // Ciclo de humano contra bot
  int columna;
  tablero.setvictoriasA(0);
  tablero.setvictoriasR(0);
  cout << "¡Que gane el mejor!" << endl;
  while (!tablero.comprobarEmpate()) {
    tablero.mostrarTablero();
    cout << "Turno de: " << jugador1.getNombre() << endl;
    // para capturar las posibles excepciones que puede tener el jugador Humano
    bool columnaValida = false;
    while (!columnaValida) {
      try {
        columna = jugador1.seleccionarColumna(tablero);
        columnaValida = true;
      } catch (runtime_error e) {
        cout << e.what() << endl;
      }
    }
    tablero.soltarFicha(columna, jugador1.getColorFicha());
    if (tablero.comprobarGanador(jugador1.getColorFicha())) {
      tablero.mostrarTablero();
      cout << "Ganó: " << jugador1.getNombre() << ", ¡Se terminó el juego!"
           << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
    if (tablero.comprobarEmpate()) {
      tablero.mostrarTablero();
      cout << "Se terminó el juego, es un empate! " << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
    tablero.mostrarTablero();
    cout << "Turno de: " << jugador2.getNombre() << endl;
    columna = jugador2.seleccionarColumna(tablero);
    tablero.soltarFicha(columna, jugador2.getColorFicha());
    if (tablero.comprobarGanador(jugador2.getColorFicha())) {
      tablero.mostrarTablero();
      cout << "Ganó: " << jugador2.getNombre() << ", ¡Se terminó el juego!"
           << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
    if (tablero.comprobarEmpate()) {
      tablero.mostrarTablero();
      cout << "Se terminó el juego, es un empate! " << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
  }
}
void CiclohumanoContraIA(jugadorHumano jugador1, jugadorIAInteligente jugador2,
                         Tablero tablero) {
  // Ciclo de humano contra IA
  int columna;
  tablero.setvictoriasA(0);
  tablero.setvictoriasR(0);
  cout << "¡Que gane el mejor!" << endl;
  while (!tablero.comprobarEmpate()) {
    tablero.mostrarTablero();
    cout << "Turno de: " << jugador1.getNombre() << endl;
    // excepciones del jugador humano
    bool columnaValida = false;
    while (!columnaValida) {
      try {
        columna = jugador1.seleccionarColumna(tablero);
        columnaValida = true;
      } catch (runtime_error e) {
        cout << e.what() << endl;
      }
    }
    tablero.soltarFicha(columna, jugador1.getColorFicha());
    if (tablero.comprobarGanador(jugador1.getColorFicha())) {
      tablero.mostrarTablero();
      cout << "Ganó: " << jugador1.getNombre() << ", ¡Se terminó el juego!"
           << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
    if (tablero.comprobarEmpate()) {
      tablero.mostrarTablero();
      cout << "Se terminó el juego, es un empate! " << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
    tablero.mostrarTablero();
    cout << "Turno de: " << jugador2.getNombre() << endl;
    columna = jugador2.seleccionarColumna(tablero);
    tablero.soltarFicha(columna, jugador2.getColorFicha());
    if (tablero.comprobarGanador(jugador2.getColorFicha())) {
      tablero.mostrarTablero();
      cout << "Ganó: " << jugador2.getNombre() << ", ¡Se terminó el juego!"
           << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
    if (tablero.comprobarEmpate()) {
      tablero.mostrarTablero();
      cout << "Se terminó el juego, es un empate! " << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
  }
}
void CiclobotContrabot(jugadorIAFacil jugador1, jugadorIAFacil jugador2,
                       Tablero tablero) {
  // Ciclo de bot contra bot
  int columna;
  tablero.setvictoriasA(0);
  tablero.setvictoriasR(0);
  cout << "¡Que gane el mejor!" << endl;
  while (!tablero.comprobarEmpate()) {
    tablero.mostrarTablero();
    cout << "Turno de: " << jugador1.getNombre() << endl;
    columna = jugador1.seleccionarColumna(tablero);
    tablero.soltarFicha(columna, jugador1.getColorFicha());
    if (tablero.comprobarGanador(jugador1.getColorFicha())) {
      tablero.mostrarTablero();
      cout << "Ganó: " << jugador1.getNombre() << ", ¡Se terminó el juego!"
           << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
    if (tablero.comprobarEmpate()) {
      tablero.mostrarTablero();
      cout << "Se terminó el juego, es un empate! " << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
    tablero.mostrarTablero();
    cout << "Turno de: " << jugador2.getNombre() << endl;
    columna = jugador2.seleccionarColumna(tablero);
    tablero.soltarFicha(columna, jugador2.getColorFicha());
    if (tablero.comprobarGanador(jugador2.getColorFicha())) {
      tablero.mostrarTablero();
      cout << "Ganó: " << jugador2.getNombre() << ", ¡Se terminó el juego!"
           << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
    if (tablero.comprobarEmpate()) {
      tablero.mostrarTablero();
      cout << "Se terminó el juego, es un empate! " << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
  }
}
void CiclobotContraIA(jugadorIAFacil jugador1, jugadorIAInteligente jugador2,
                      Tablero tablero) {
  // Ciclo de bot contra IA
  int columna;
  tablero.setvictoriasA(0);
  tablero.setvictoriasR(0);
  cout << "¡Que gane el mejor!" << endl;
  while (!tablero.comprobarEmpate()) {
    tablero.mostrarTablero();
    cout << "Turno de: " << jugador1.getNombre() << endl;
    columna = jugador1.seleccionarColumna(tablero);
    tablero.soltarFicha(columna, jugador1.getColorFicha());
    if (tablero.comprobarGanador(jugador1.getColorFicha())) {
      tablero.mostrarTablero();
      cout << "Ganó: " << jugador1.getNombre() << ", ¡Se terminó el juego!"
           << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
    if (tablero.comprobarEmpate()) {
      tablero.mostrarTablero();
      cout << "Se terminó el juego, es un empate! " << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
    tablero.mostrarTablero();
    cout << "Turno de: " << jugador2.getNombre() << endl;
    columna = jugador2.seleccionarColumna(tablero);
    tablero.soltarFicha(columna, jugador2.getColorFicha());
    if (tablero.comprobarGanador(jugador2.getColorFicha())) {
      tablero.mostrarTablero();
      cout << "Ganó: " << jugador2.getNombre() << ", ¡Se terminó el juego!"
           << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
    if (tablero.comprobarEmpate()) {
      tablero.mostrarTablero();
      cout << "Se terminó el juego, es un empate! " << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
  }
}
void CicloIAContraIA(jugadorIAInteligente jugador1,
                     jugadorIAInteligente jugador2, Tablero tablero) {
  // Ciclo de IA contra IA
  int columna;
  tablero.setvictoriasA(0);
  tablero.setvictoriasR(0);
  cout << "¡Que gane el mejor!" << endl;
  while (!tablero.comprobarEmpate()) {
    tablero.mostrarTablero();
    cout << "Turno de: " << jugador1.getNombre() << endl;
    columna = jugador1.seleccionarColumna(tablero);
    tablero.soltarFicha(columna, jugador1.getColorFicha());
    if (tablero.comprobarGanador(jugador1.getColorFicha())) {
      tablero.mostrarTablero();
      cout << "Ganó: " << jugador1.getNombre() << ", ¡Se terminó el juego!"
           << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
    if (tablero.comprobarEmpate()) {
      tablero.mostrarTablero();
      cout << "Se terminó el juego, es un empate! " << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
    tablero.mostrarTablero();
    cout << "Turno de: " << jugador2.getNombre() << endl;
    columna = jugador2.seleccionarColumna(tablero);
    tablero.soltarFicha(columna, jugador2.getColorFicha());
    if (tablero.comprobarGanador(jugador2.getColorFicha())) {
      tablero.mostrarTablero();
      cout << "Ganó: " << jugador2.getNombre() << ", ¡Se terminó el juego!"
           << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
    if (tablero.comprobarEmpate()) {
      tablero.mostrarTablero();
      cout << "Se terminó el juego, es un empate! " << endl;
      cout << "Marcador Global: " << endl;
      cout << jugador1.getNombre() << " : " << tablero.getVictoriasAzul() << " "
           << jugador2.getNombre() << " : " << tablero.getVictoriasRojas()
           << endl;
      if (volveraJugar()) {
        tablero.reiniciarTablero();
      } else {
        break;
      }
    }
  }
}
// Funciones para los datos//
void mostrarOpciones() {
  // Función para mostrar el menu de opciones de juego
  cout << "\t Seleccione una opción:" << endl;
  cout << "1. Humano contra Humano" << endl;
  cout << "2. Humano contra Bot" << endl;
  cout << "3. Humano contra IA " << endl;
  cout << "4. Bot contra Bot" << endl;
  cout << "5. Bot contra IA " << endl;
  cout << "6. IA contra IA " << endl;
  cout << "7. Volver al menú principal" << endl;
}
Tablero crearTablero() {
  // Función que devuelve el tablero con los datos ingresados por el usuario
  int columnas = pedirColumnas();
  int filas = pedirFilas();
  Tablero tablero = Tablero(filas, columnas);
  return tablero;
}
jugadorHumano crearJugadorH(int n) {
  // Función para crear el jugador humano con su número de jugador respectivo
  Ficha ficha;
  string nombre = pedirNombre(n);
  if (n == 1) {
    ficha = Ficha::Azul;
  } else if (n == 2) {
    ficha = Ficha::Rojo;
  }
  jugadorHumano jugador = jugadorHumano(nombre, ficha);
  return jugador;
}
jugadorIAFacil crearJugadorB(int n) {
  // Función para crear el jugador bot con su número de jugador respectivo
  Ficha ficha;
  string nombre = pedirNombre(n);
  if (n == 1) {
    ficha = Ficha::Azul;
  } else if (n == 2) {
    ficha = Ficha::Rojo;
  }
  jugadorIAFacil jugador = jugadorIAFacil(nombre, ficha);
  return jugador;
}
jugadorIAInteligente crearJugadorIA(int n) {
  // Función para crear el jugador IA con su número de jugador respectivo
  Ficha ficha;
  string nombre = pedirNombre(n);
  int deep = pedirProfundidadIA();
  if (n == 1) {
    ficha = Ficha::Azul;
  } else if (n == 2) {
    ficha = Ficha::Rojo;
  }
  jugadorIAInteligente jugador = jugadorIAInteligente(nombre, ficha, deep);
  return jugador;
}
string pedirNombre(int n) {
  // Pedir el nombre para el jugador respectivo
  string nombre;
  switch (n) {
    case 1:
      cout << "Digite el nombre para Jugador" << n << "-(X): " << endl;
      cin >> nombre;
      break;
    case 2:
      cout << "Digite el nombre para Jugador" << n << "-(O): " << endl;
      cin >> nombre;
      break;
  }
  return nombre;
}
int pedirColumnas() {
  // Pregunta para pedir cantidad de Columnas
  int columnas;
  cout << "Digite la cantidad de columnas: " << endl;
  columnas = seleccionOpcion();
  return columnas;
}
int pedirFilas() {
  // Pregunta para pedir cantidad de Filas
  int filas;
  cout << "Digite la cantidad de filas: " << endl;
  filas = seleccionOpcion();
  return filas;
}
int pedirProfundidadIA() {
  int deep;
  cout << "Digite la dificultad de la IA(Mayor=más difícil): " << endl;
  cin >> deep;
  return deep;
}
int seleccionColumna() {
  // Pregunta para seleccionar columna
  int columnas;
  cout << "Digite la cantidad de columnas: " << endl;
  columnas = seleccionOpcion();
  return columnas;
}
bool volveraJugar() {
  // Pregunta para volver a jugar en el mismo juego actual, no uno nuevo...
  int opcion;
  cout << "Quiere volver a jugar? " << endl;
  cout << "Digite 1 para sí o 2 para no: " << endl;
  opcion = seleccionOpcion();
  while (opcion < 1 || opcion > 2) {
    cout << "Opción inválida" << endl;
    cout << "Quiere volver a jugar? " << endl;
    cout << "Digite 1 para sí o 2 para no: " << endl;
    opcion = seleccionOpcion();
  }
  return opcion == 1;
}
int seleccionOpcion() {
  // una función genérica para detectar errores de usuario para no tener
  // escribir estas líneas todo el tiempo
  int opcion;
  bool valido = true;
  while (valido) {
    cin >> opcion;
    if (cin.fail()) {
      cin.clear();
      // Limpiar el estado de error
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      // Descartar la entrada incorrecta, pero no acepta flotantes...
    }
    if (opcion > 0) {
      valido = false;
    } else {
      cout << "Opción inválida, intente de nuevo: " << endl;
    }
  }
  return opcion;
}