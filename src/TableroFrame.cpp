#include <wx/wx.h>
#include "TableroFrame.hh" // Asegúrate de que la ruta del archivo de encabezado sea correcta

using namespace std;

wxBEGIN_EVENT_TABLE(TableroFrame, wxFrame)
    EVT_PAINT(TableroFrame::OnPaint)
    EVT_LEFT_DOWN(TableroFrame::OnMouseClick)
wxEND_EVENT_TABLE()

TableroFrame::TableroFrame(const wxString& title, int filas, int columnas)
    : wxFrame(nullptr, wxID_ANY, title), tablero(filas, columnas) {
    wxPanel* panel = new wxPanel(this);
    panel->Bind(wxEVT_LEFT_DOWN, &TableroFrame::OnMouseEvent, this);
}

void TableroFrame::OnPaint(wxPaintEvent& event) {
    wxPaintDC dc(this);
    DibujarTablero(dc);
}

void TableroFrame::OnMouseEvent(wxMouseEvent& event) {
    wxPoint position = event.GetPosition();
    int x = position.x;

    wxSize pantalla = GetClientSize();
    int largoPantalla = pantalla.GetWidth();
    int columnas = tablero.getColumnas();
    int celdaLargo = largoPantalla / columnas;
    int columnaSeleccionada = x / celdaLargo;

    Ficha ficha = Ficha::Azul; // Asegúrate de inicializar la ficha correctamente

    if (tablero.puedeTirar(columnaSeleccionada)) {
        tablero.soltarFicha(columnaSeleccionada, ficha);
        tablero.mostrarTablero();
        Refresh(); // Refresca la ventana para actualizar el dibujo
    }
}

void TableroFrame::OnMouseClick(wxMouseEvent& event) {
    wxPoint mousePos = event.GetPosition();
    wxString mensaje = wxString::Format("(x=%d y=%d)", mousePos.x, mousePos.y);
    wxLogStatus(mensaje);
}

void TableroFrame::DibujarTablero(wxDC& dc) {
    wxSize pantalla = GetClientSize();
    int largoPantalla = pantalla.GetWidth();
    int altoPantalla = pantalla.GetHeight();

    int filas = tablero.getFilas();
    int columnas = tablero.getColumnas();

    int celdaLargo = largoPantalla / columnas;
    int celdaAlto = altoPantalla / filas;

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            int x = j * celdaLargo;
            int y = i * celdaAlto;
            dc.SetPen(*wxBLACK_PEN);
            dc.DrawRectangle(x, y, celdaLargo, celdaAlto);

            if (tablero.getTablero()[i][j] == Ficha::Rojo) {
                dc.SetBrush(*wxRED_BRUSH);
                dc.DrawCircle(x + celdaLargo / 2, y + celdaAlto / 2, min(celdaLargo, celdaAlto) / 2 - 2);
            } else if (tablero.getTablero()[i][j] == Ficha::Azul) {
                dc.SetBrush(*wxBLUE_BRUSH);
                dc.DrawCircle(x + celdaLargo / 2, y + celdaAlto / 2, min(celdaLargo, celdaAlto) / 2 - 2);
            }
            dc.SetBrush(*wxWHITE_BRUSH);
        }
    }
}
