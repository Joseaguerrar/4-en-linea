#ifndef TABLERO_HH
#define TABLERO_HH
#include <iostream>
#include<string>
#include <vector>
using namespace std;
class Tablero {
    public:
        // Constructores
        Tablero(int filas, int columnas);
        // Metodos
        bool puedeTirar(int columna);
        bool soltarFicha(int columna, char ficha);
        char mostrarTablero();
        int getColumnas();
        int getFilas();
        vector<vector<char>> getCopiaTablero();
        vector<vector<char>> getTablero();
    private:
        vector<vector<char>> tablero;
        int filas;
        int columnas;
    };
#endif