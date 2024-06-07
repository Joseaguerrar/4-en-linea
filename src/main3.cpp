#include <iostream>
#include <string>
#include <tablero.hh>
#include <jugadorIAFacil.hh>
#include <jugadorIAInteligente.hh>
#include <jugadorHumano.hh>
using namespace std;

// Prototipos de las funciones
void jugar();
//crear los diferentes juegos
void crearHyH();
void crearHyB();
void crearHyIA();
void crearByB();
void crearByIA();
void crearIAyIA();
//Ciclos
void CiclohumanoContraHumano(jugadorHumano,jugadorHumano,Tablero);//falta
void CiclohumanoContraBot(jugadorHumano,jugadorIAFacil,Tablero);//falta
void CiclohumanoContraIA(jugadorHumano,jugadorIAInteligente,Tablero);//falta
void CiclobotContraBot(jugadorIAFacil,jugadorIAFacil,Tablero);//falta
void CiclobotContraIA(jugadorIAFacil,jugadorIAInteligente,Tablero);//falta
void CicloIAContraIA(jugadorIAInteligente,jugadorIAInteligente,Tablero);//falta
//Datos
string pedirNombre(int);
int pedirColumnas();
int pedirFilas();
int seleccionColumna();
int pedirProfundidadIA();
Tablero crearTablero();
jugadorHumano crearJugadorH(int);
jugadorIAFacil crearJugadorB(int);
jugadorIAInteligente crearJugadorIA(int);//falta
int main() {
    int opcion = 0;
    bool juegoactivo=true;

    while (juegoactivo) {
        cout << "Seleccione una opción: "<<endl;
        cout << "1. Jugar" << endl;
        cout << "2. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                jugar();
                break;
            case 2:
                cout << "Tenga buen día..." << endl;
                return 0; // Salir del programa
            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
        }
    }

    return 0;
}

// Definición de la función que simula el juego
void jugar() {
    int opcionJuego;
    bool juegoactivo=true;
    while (juegoactivo) {
        cout << "\t Seleccione una opción:" << endl;
        cout << "1. Humano contra Humano" << endl;
        cout << "2. Humano contra Bot" << endl;
        cout << "3. Humano contra IA " << endl;
        cout << "4. Bot contra Bot" << endl;
        cout << "5. Bot contra IA " << endl;
        cout << "6. IA contra IA " << endl;
        cout << "7. Volver al menú principal" << endl;
        cin >> opcionJuego;

        switch (opcionJuego) {
            case 1:
                crearHyH();
                break;
            case 2:
                //crearHyB();
                break;
            case 3:
                //crearHyIA();
                break;
            case 4:
                //crearByB();
                break;
            case 5:
                //crearByIA();
                break;
            case 6:
                //crearIAyIA();
                break;
            case 7:
                return;// Volver al menú principal
            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                break;
        }
    }
}
void crearHyH(){
    jugadorHumano jugador1= crearJugadorH(1);
    jugadorHumano jugador2=crearJugadorH(2);
    Tablero tablero= crearTablero();
    CiclohumanoContraHumano(jugador1,jugador2,tablero);
}
/*void crearHyB(){
    jugadorHumano jugador1= crearJugadorH(1);
    jugadorIAFacil jugador2=crearJugadorB(2);
    Tablero tablero= crearTablero();
    CiclohumanoContraBot(jugador1,jugador2,tablero);

}
/*
void crearHyIA(){
    jugadorHumano jugador1= crearJugadorH(1);
    jugadorIAInteligente jugador2=crearJugadorIA(2);
    Tablero tablero= crearTablero();
    CiclohumanoContraIA(jugador1,jugador2,tablero);
}
void crearByB(){
    jugadorIAFacil jugador1=crearJugadorB(1);
    jugadorIAFacil jugador2=crearJugadorB(2);
    Tablero tablero= crearTablero();
    CiclobotContraBot(jugador1,jugador2,tablero);
}
void crearByIA(){

}
void crearIAyIA(){

}
*/ //Ciclos//
void CiclohumanoContraHumano(jugadorHumano jugador1,jugadorHumano jugador2,Tablero tablero){
    int columna;
    bool juegoactivo=true;
    tablero.mostrarTablero();
        while (!tablero.comprobarEmpate())
        {
            cout<<"Turno de: "<<jugador1.getNombre()<<endl; 
            columna=seleccionColumna()-1;
            while (!tablero.puedeTirar(columna))
            {
                cout<<"Columna no válida, intente de nuevo..."<<endl;
                columna=seleccionColumna();
            }
            tablero.soltarFicha(columna,jugador1.getColorFicha());
            if (tablero.comprobarGanador(jugador1.getColorFicha()))
            {
                tablero.mostrarTablero();
                cout<<"Se terminó el juego, ganó: "<<jugador1.getNombre()<<endl;
                juegoactivo=false;
                break;
            }
            tablero.mostrarTablero();
            cout<<"Turno de: "<<jugador2.getNombre()<<endl; 
            columna=seleccionColumna()-1;
            while (!tablero.puedeTirar(columna))
            {
                cout<<"Columna no válida, intente de nuevo..."<<endl;
                columna=seleccionColumna();
            }
            tablero.soltarFicha(columna,jugador2.getColorFicha());
            tablero.mostrarTablero();
            if (tablero.comprobarGanador(jugador2.getColorFicha()))
            {
                tablero.mostrarTablero();
                cout<<"Se terminó el juego, ganó: "<<jugador2.getNombre()<<endl;
                juegoactivo=false;
                break;
            }
        }
    if (tablero.comprobarEmpate())
    {
        cout<<"Se terminó el juego, es un empate! "<<endl;
    }
    
        
      
}
//Funciones para los datos//
Tablero crearTablero(){
    int columnas=pedirColumnas();
    int filas=pedirFilas();
    Tablero tablero= Tablero(filas,columnas);
    return tablero;
}
jugadorHumano crearJugadorH(int n){
    Ficha ficha;
    string nombre=pedirNombre(n);
    if (n==1)
    {
        ficha= Ficha::Azul;
    }else if (n==2){
        ficha=Ficha::Rojo;
    }
    jugadorHumano jugador= jugadorHumano(nombre,ficha);
    return jugador;
}
jugadorIAFacil crearJugadorB(int n){
    Ficha ficha;
    string nombre=pedirNombre(n);
    if (n=1)
    {
        ficha= Ficha::Azul;
    }else{
        ficha=Ficha::Rojo;
    }
    jugadorIAFacil jugador= jugadorIAFacil(nombre,ficha);
    return jugador;
}
jugadorIAInteligente crearJugadorIA(int n){
    Ficha ficha;
    string nombre=pedirNombre(n);
    int deep= pedirProfundidadIA();
    if (n=1)
    {
        ficha= Ficha::Azul;
    }else{
        ficha=Ficha::Rojo;
    }
    jugadorIAInteligente jugador= jugadorIAInteligente(nombre,ficha,deep);
    return jugador;
}
string pedirNombre(int n){
    string nombre;
    cout<<"Digite el nombre para Jugador"<< n<<": " <<endl;
    cin>>nombre;
    return nombre;
}
int pedirColumnas(){
    int columnas;
    cout<<"Digite la cantidad de columnas: "<<endl;
    cin>>columnas;
    return columnas;
}
int pedirFilas(){
    int filas;
    cout<<"Digite la cantidad de filas: "<<endl;
    cin>>filas;
    return filas;
}
int pedirProfundidadIA(){
    int deep;
    cout<<"Digite la dificultad de la IA(Mayor=más difícil): "<<endl;
    cin>>deep;
    return deep;
}
int seleccionColumna(){
    int seleccion;
    cout<<"Seleccione una columna: "<<endl;
    cin>>seleccion;
    return seleccion;
}