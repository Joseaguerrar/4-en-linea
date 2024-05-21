#include<string>
using namespace std;
class IJugador{
    protected:
        IJugador();
        IJugador(string Nombre, char ColorFicha): nombre(Nombre), colorFicha(ColorFicha){}
        virtual string getNombre(){return nombre;};
        virtual void setNombre(string Nombre);
        virtual char getColorFicha(){return colorFicha;}
        virtual void setColorFicha(string Nombre);
    private:
        string nombre;
        char colorFicha;
};