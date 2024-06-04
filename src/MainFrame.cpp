#include <wx/wx.h>
#include <string>
#include <MainFrame.hh>
using namespace std;

MainFrame::MainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title) {
  wxPanel* panel = new wxPanel(this);
  wxStaticText* instruccionTablero = new wxStaticText(panel, wxID_ANY, "Dimensiones del tablero:", wxPoint(0,120));
  wxStaticText* instruccionJugadores = new wxStaticText(panel, wxID_ANY, "Seleccione jugadores: ", wxPoint(0,0));
  wxArrayString opcionesJugadores;
  opcionesJugadores.Add("Bot");
  opcionesJugadores.Add("BotConIA");
  opcionesJugadores.Add("Humano");
  wxChoice* jugador1 = new wxChoice(panel, wxID_ANY, wxPoint(0, 25), wxSize(100, -1), opcionesJugadores);
  wxChoice* jugador2 = new wxChoice(panel, wxID_ANY, wxPoint(0, 60), wxSize(100, -1), opcionesJugadores);
  wxArrayString opcionesDimension;

  for(int i = 4; i < 11; i++){
    opcionesDimension.Add(to_string(i));
  }

  wxStaticText* columnas = new wxStaticText(panel, wxID_ANY, "Filas: ", wxPoint(0,150));
  wxStaticText* filas = new wxStaticText(panel, wxID_ANY, "Columnas: ", wxPoint(0,180));
  wxChoice* dimensionX = new wxChoice(panel, wxID_ANY, wxPoint(100, 140), wxSize(100, -1), opcionesDimension);
  wxChoice* dimensionY = new wxChoice(panel, wxID_ANY, wxPoint(100, 180), wxSize(100, -1), opcionesDimension);

  // Crear un botón de salir
  wxButton* button = new wxButton(panel, wxID_ANY, "Salir", wxPoint(0, 250), wxSize(100,35));

}