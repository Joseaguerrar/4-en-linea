#include <iostream>
#include <tablero.hh>
#include <jugadorIAFacil.hh>
#include <jugadorIAInteligente.hh>
#include <jugadorHumano.hh>
using namespace std;

/*int seleccionColumna();
string pedirNombre(int);

int main(){
    /*esta parte solo la comenté para que se ejecutara de momento la prueba de humanos,
     si se quiere ver solo se le quita el comentario y se le cambia el nombre de variable columna*/
    
    /*Tablero prueba(7,7);
    jugadorIAInteligente jugador1 = jugadorIAInteligente("jugador1", Ficha::Azul, 5);
    jugadorIAInteligente jugador2 = jugadorIAInteligente("jugador2", Ficha::Rojo, 1);
    int columna;
    while(!prueba.comprobarGanador(jugador1.getColorFicha()) && !prueba.comprobarGanador(jugador2.getColorFicha())){
        prueba.soltarFicha(jugador1.seleccionarColumna(prueba), jugador1.getColorFicha());
        prueba.mostrarTablero();
        cout << "-------------" << endl;
        prueba.soltarFicha(jugador2.seleccionarColumna(prueba), jugador2.getColorFicha());
        prueba.mostrarTablero();
        cout << "-------------" << endl;
    }
    prueba.mostrarTablero();*/



    //Ciclo Juego con 2 humanos
    //TODO: me parece que no es necesario los ciclos while para comprobar si es válida la columna ya que solo se aborta
    /*Tablero tablero2(8,8);
    int columna;
    string nombre1,nombre2;
    nombre1=pedirNombre(1);
    nombre2=pedirNombre(2);
    jugadorHumano jugador1=jugadorHumano(nombre1, Ficha::Azul);
    jugadorHumano jugador2=jugadorHumano(nombre2,Ficha::Rojo);
    bool juegoactivo=true;
    tablero2.mostrarTablero();
    while (juegoactivo){
        while (!tablero2.comprobarEmpate())
        {
            cout<<"Turno de: "<<jugador1.getNombre()<<endl; 
            columna=seleccionColumna()-1;
            while (!tablero2.puedeTirar(columna))
            {
                cout<<"Columna no válida, intente de nuevo..."<<endl;
                columna=seleccionColumna();
            }
            tablero2.soltarFicha(columna,jugador1.getColorFicha());
            if (tablero2.comprobarGanador(jugador1.getColorFicha()))
            {
                tablero2.mostrarTablero();
                cout<<"Se terminó el juego, ganó: "<<jugador1.getNombre()<<endl;
                juegoactivo=false;
                break;
            }
            tablero2.mostrarTablero();
            cout<<"Turno de: "<<jugador2.getNombre()<<endl; 
            columna=seleccionColumna()-1;
            while (!tablero2.puedeTirar(columna))
            {
                cout<<"Columna no válida, intente de nuevo..."<<endl;
                columna=seleccionColumna();
            }
            tablero2.soltarFicha(columna,jugador2.getColorFicha());
            tablero2.mostrarTablero();
            if (tablero2.comprobarGanador(jugador2.getColorFicha()))
            {
                tablero2.mostrarTablero();
                cout<<"Se terminó el juego, ganó: "<<jugador2.getNombre()<<endl;
                juegoactivo=false;
                break;
            }
        }
    }
    return 0;
}
/*int seleccionColumna(){
    int seleccion;
    cout<<"Seleccione una columna: "<<endl;
    cin>>seleccion;
    return seleccion;
}
/*string pedirNombre(int n){
    string nombre;
    cout<<"Digite el nombre para Jugador"<< n<<": " <<endl;
    cin>>nombre;
    return nombre;
}*/