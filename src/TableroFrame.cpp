#include <wx/wx.h>
#include <TableroFrame.hh>

using namespace std;

wxBEGIN_EVENT_TABLE(TableroFrame, wxFrame)
    EVT_PAINT(TableroFrame::OnPaint)
wxEND_EVENT_TABLE()

TableroFrame::TableroFrame(const wxString& title, int filas, int columnas)
    : wxFrame(nullptr, wxID_ANY, title), tablero(filas, columnas) {
    wxPanel* panel = new wxPanel(this);
    panel->Bind(wxEVT_LEFT_DOWN, &TableroFrame::OnMouseEvent, this);
    //para agregar el botón para salir
    wxMenu *menuFile = new wxMenu;
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
 
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
 
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
 
    SetMenuBar(menuBar);
    Bind(wxEVT_MENU, &TableroFrame::OnExit, this, wxID_EXIT);
 
}

void TableroFrame::OnPaint(wxPaintEvent& event) {
    wxPaintDC dc(this);
    DibujarTablero(dc);
}

//Metodo que captura el evento del click del mouse
void TableroFrame::OnMouseEvent(wxMouseEvent& event) {
    //Se toma la posicion del mouse en ese momento, mas especificamente la del eje x
    wxPoint position = event.GetPosition();
    int x = position.x;
    //Se toma el tamano de la ventana
    wxSize pantalla = GetClientSize();
    int largoPantalla = pantalla.GetWidth();
    int columnas = tablero.getColumnas();
    //Se toma el tamano de cada celda
    int celdaLargo = largoPantalla / columnas;
    //Para saber que columna se selecciono, se divide la posicion x del mouse entre el largo de la celda
    int columnaSeleccionada = x / celdaLargo;

    Ficha ficha = Ficha::Azul;
    //Si se puede tirar, se suelta la ficha
    if (tablero.puedeTirar(columnaSeleccionada)) {
        tablero.soltarFicha(columnaSeleccionada, ficha);
        Refresh();
    }
}

//Metodo que dibuja el tablero
void TableroFrame::DibujarTablero(wxDC& dc) {
    //Se toma el tamano de la ventana, tanto su largo, como su ancho
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

void TableroFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}