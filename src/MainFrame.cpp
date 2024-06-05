#include <wx/wx.h>
#include <string>
#include <MainFrame.hh>
using namespace std;

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title) {
// Crear un panel
wxPanel* panel = new wxPanel(this);

// Cambiar el color de fondo del panel a negro
panel->SetBackgroundColour(*wxBLACK);

// Crear un texto estático
//Botones para selección de tipo de jugadores
  wxStaticText* instruccionJugadores = new wxStaticText(panel, wxID_ANY, "Seleccione jugadores: ", wxPoint(15,0));
  // Cambiar el color del texto a blanco
  instruccionJugadores -> SetForegroundColour(*wxWHITE);
  wxArrayString opcionesJugadores;
  //opciones de cada boton
  opcionesJugadores.Add("Bot");
  opcionesJugadores.Add("BotConIA");
  opcionesJugadores.Add("Humano");

  //Botón jugador1
  wxChoice* jugador1 = new wxChoice(panel, wxID_ANY, wxPoint(100, 25), wxSize(100, -1), opcionesJugadores);
  //Texto
  wxStaticText* opcionJugador1 = new wxStaticText(panel, wxID_ANY, "Jugador1: ", wxPoint(15,30));
  opcionJugador1 -> SetForegroundColour(*wxWHITE);

  //Botón jugador2
  wxChoice* jugador2 = new wxChoice(panel, wxID_ANY,wxPoint(100, 60), wxSize(100, -1), opcionesJugadores);
  //Texto
  wxStaticText* opcionJugador2 = new wxStaticText(panel, wxID_ANY, "Jugador2: ", wxPoint(15,60));
  opcionJugador2 -> SetForegroundColour(*wxWHITE);

  //botón de opción de dimensión para tablero
  wxStaticText* instruccionTablero = new wxStaticText(panel, wxID_ANY, "Dimensiones del tablero:", wxPoint(15,120));
  instruccionTablero -> SetForegroundColour(*wxWHITE);
  //opciones del botón de 4 a 10
  wxArrayString opcionesDimension;
  for(int i = 4; i < 11; i++){
    opcionesDimension.Add(to_string(i));
  }
  //Texto columnas
  wxStaticText* columnas = new wxStaticText(panel, wxID_ANY, "Filas: ", wxPoint(15,150));
  columnas -> SetForegroundColour(*wxWHITE);
  //Botón columnas
  wxChoice* dimensionX = new wxChoice(panel, wxID_ANY, wxPoint(100, 140), wxSize(100, -1), opcionesDimension);
  
  //Texto Filas
  wxStaticText* filas = new wxStaticText(panel, wxID_ANY, "Columnas: ", wxPoint(15,180));
  filas -> SetForegroundColour(*wxWHITE);
  //Botón Filas
  wxChoice* dimensionY = new wxChoice(panel, wxID_ANY, wxPoint(100, 180), wxSize(100, -1), opcionesDimension);

  //Crear un botón de salir
  wxButton* button = new wxButton(panel, wxID_ANY, "Salir", wxPoint(15, 250), wxSize(100,35));
}