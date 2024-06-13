#include <wx/wx.h>
#include <TableroFrame.hh>
#include <MenuFrame.hh>
#include <string>
using namespace std;

MenuFrame::MenuFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title) {
  // Crear un panel
  wxPanel* panel = new wxPanel(this);

  // Cambiar el color de fondo del panel a negro
  panel->SetBackgroundColour(*wxBLACK);

  // Crear un texto estático
  // Botones para selección de tipo de jugadores
  wxStaticText* instruccionJugadores = new wxStaticText(
      panel, wxID_ANY, "Seleccione jugadores: ", wxPoint(15, 0));
  // Cambiar el color del texto a blanco
  instruccionJugadores->SetForegroundColour(*wxWHITE);
  wxArrayString opcionesJugadores;
  // opciones de cada boton
  opcionesJugadores.Add("Bot");
  opcionesJugadores.Add("BotConIA");
  opcionesJugadores.Add("Humano");

  // Botón jugador1
  jugador1 = new wxChoice(panel, wxID_ANY, wxPoint(100, 25), wxSize(100, -1),
                          opcionesJugadores);
  // Texto
  wxStaticText* opcionJugador1 =
      new wxStaticText(panel, wxID_ANY, "Jugador1: ", wxPoint(15, 30));
  opcionJugador1->SetForegroundColour(*wxWHITE);

  // Botón jugador2
  jugador2 = new wxChoice(panel, wxID_ANY, wxPoint(100, 60), wxSize(100, -1),
                          opcionesJugadores);
  // Texto
  wxStaticText* opcionJugador2 =
      new wxStaticText(panel, wxID_ANY, "Jugador2: ", wxPoint(15, 60));
  opcionJugador2->SetForegroundColour(*wxWHITE);

  // botón de opción de dimensión para tablero
  wxStaticText* instruccionTablero = new wxStaticText(
      panel, wxID_ANY, "Dimensiones del tablero:", wxPoint(15, 120));
  instruccionTablero->SetForegroundColour(*wxWHITE);
  // opciones del botón de 4 a 10
  wxArrayString opcionesDimension;
  for (int i = 4; i < 11; i++) {
    opcionesDimension.Add(to_string(i));
  }
  // Texto columnas
  wxStaticText* columnas =
      new wxStaticText(panel, wxID_ANY, "Columnas: ", wxPoint(15, 150));
  columnas->SetForegroundColour(*wxWHITE);
  // Botón columnas
  dimensionColumnas = new wxChoice(panel, wxID_ANY, wxPoint(100, 140),
                                   wxSize(100, -1), opcionesDimension);

  // Texto Filas
  wxStaticText* filas =
      new wxStaticText(panel, wxID_ANY, "Filas: ", wxPoint(15, 180));
  filas->SetForegroundColour(*wxWHITE);
  // Botón Filas
  dimensionFilas = new wxChoice(panel, wxID_ANY, wxPoint(100, 180),
                                wxSize(100, -1), opcionesDimension);

  // Crear un botón de salir
  wxButton* buttonSalir =
      new wxButton(panel, wxID_ANY, "Salir", wxPoint(15, 250), wxSize(100, 35));

  buttonSalir->Bind(wxEVT_BUTTON, &MenuFrame::OnButton1Clicked, this);
  // Crear botón para continuar
  wxButton* buttonContinuar = new wxButton(panel, wxID_ANY, "Continuar",
                                           wxPoint(150, 250), wxSize(100, 35));
  buttonContinuar->Bind(wxEVT_BUTTON, &MenuFrame::OnButton2Clicked, this);
}

// No pasa nada si no se presionan botones
void MenuFrame::OnAnyButtonClicked(wxCommandEvent& evt) {
  wxLogMessage("Nothing");
}

// evento de botón de salir
void MenuFrame::OnButton1Clicked(wxCommandEvent& evt) { 
  this->Close(true); 
  }

//Cuando se presiona el boton continuar se recolecta la siguiente información y se dibuja el tablero
void MenuFrame::OnButton2Clicked(wxCommandEvent& evt) {
  wxString jugador1Seleccionado = jugador1->GetStringSelection();
  cout << jugador1Seleccionado << endl;
  wxString jugador2Seleccionado = jugador2->GetStringSelection();
  cout << jugador2Seleccionado << endl;
  wxString columnaSeleccionada = dimensionColumnas->GetStringSelection();
  cout << columnaSeleccionada << endl;
  wxString filaSeleccionada = dimensionFilas->GetStringSelection();
  cout << filaSeleccionada << endl;
  // Crear una nueva instancia de TableroFrame
  int fila = wxStringToInt(filaSeleccionada);
  int columna = wxStringToInt(columnaSeleccionada);
  tablero = new TableroFrame("Tablero", fila, columna);
  
  // Mostrar la ventana del tablero
  tablero->Show(true);
}

int MenuFrame::wxStringToInt(wxString numeroAConvertir){
  int numero = 0;
  numero = wxAtoi(numeroAConvertir);
  return numero;
}