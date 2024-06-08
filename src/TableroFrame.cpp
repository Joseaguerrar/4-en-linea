#include <wx/wx.h>
#include <TableroFrame.hh>

using namespace std;

wxBEGIN_EVENT_TABLE(TableroFrame, wxFrame) 
  EVT_PAINT(TableroFrame::OnPaint)
  EVT_LEFT_DOWN(TableroFrame::OnMouseClick)
  EVT_MOTION(TableroFrame::OnMouseEvent)
wxEND_EVENT_TABLE()
  
TableroFrame ::TableroFrame(const wxString& title, int filas, int columnas)
    : wxFrame(nullptr, wxID_ANY, title), tablero(filas, columnas) {
  wxPanel* panel = new wxPanel(this);
}

void TableroFrame::OnPaint(wxPaintEvent& event) {
  wxPaintDC dc(this);
  DibujarTablero(dc);
}

//Metodo de evento que toma la posicion de x del raton para asi saber donde tiene que dibujar 
//la ficha en soltar ficha
//TO DO: Arreglar Ficha ficha y probar si funciona bien
void TableroFrame::OnMouseClick(wxMouseEvent& event) {
    wxPoint position = event.GetPosition();
    int x = position.x;
    Ficha ficha;
    wxSize pantalla = GetClientSize();
    int largoPantalla = pantalla.GetWidth();
    int columnas = tablero.getColumnas();
    int celdaLargo = largoPantalla / columnas;
    int columnaSeleccionada = x / celdaLargo;
    if (tablero.puedeTirar(columnaSeleccionada)) {
        tablero.soltarFicha(columnaSeleccionada, ficha);
        ficha = ( ficha == Ficha::Rojo) ? Ficha::Azul : Ficha::Rojo;
        Refresh();
    }
}

//Metodo para saber la posicion del mouse
void TableroFrame::OnMouseEvent(wxMouseEvent& event){
  wxPoint mousePos = event.GetPosition();
  wxString mensaje = wxString::Format("(x=%d y=%d)",mousePos.x, mousePos.y);
  wxLogStatus(mensaje);
}

void TableroFrame::DibujarTablero(wxDC& dc){
  // Obtiene las dimensiones del monitor del usuario
  wxSize pantalla = GetClientSize();
  int largoPantalla = pantalla.GetWidth();
  int altoPantalla = pantalla.GetHeight();
  // Obtiene las filas y columnas del tablero
  int filas = tablero.getFilas();
  int columnas = tablero.getColumnas();
  // Obtiene las dimensiones de las celdas
  int celdaLargo = largoPantalla / columnas;
  int celdaAlto = altoPantalla / filas;
  // For que dibuja las celdas segun las dimensiones previamente hechas
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      int x = j * celdaLargo;
      int y = i * celdaAlto;
      dc.SetPen(*wxBLACK_PEN);
      dc.DrawRectangle(x, y, celdaLargo, celdaAlto);
      //Dependiendo del color de la ficha, se dibujara la ficha en la casilla dada
      if (tablero.getTablero()[i][j] == Ficha::Rojo) {
        dc.SetBrush(*wxRED_BRUSH);
        dc.DrawCircle(x + celdaLargo / 2, y + celdaAlto / 2, min(celdaLargo, celdaAlto) / 2 - 2);
      } else if (tablero.getTablero()[i][j] == Ficha::Azul) {
        dc.SetBrush(*wxBLUE_BRUSH);
        dc.DrawCircle(x + celdaLargo / 2, y + celdaAlto / 2, min(celdaLargo, celdaAlto) / 2 - 2);
      }
    }
  }
}