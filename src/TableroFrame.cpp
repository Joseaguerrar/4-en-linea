#include <wx/wx.h>

#include <TableroFrame.hh>

using namespace std;

wxBEGIN_EVENT_TABLE(TableroFrame, wxFrame) EVT_PAINT(TableroFrame::OnPaint)
    wxEND_EVENT_TABLE()

        TableroFrame ::TableroFrame(const wxString& title, int filas, int columnas)
    : wxFrame(nullptr, wxID_ANY, title), tablero(filas, columnas) {
  wxPanel* panel = new wxPanel(this);
}

void TableroFrame::OnPaint(wxPaintEvent& event) {
  wxPaintDC dc(this);
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
      dc.SetBrush(*wxWHITE_BRUSH);
      dc.DrawRectangle(x, y, celdaLargo, celdaAlto);
      dc.SetPen(*wxBLACK_PEN);
      dc.DrawRectangle(x, y, celdaLargo, celdaAlto);
    }
  }
}
