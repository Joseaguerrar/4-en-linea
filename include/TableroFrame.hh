#ifndef TABLEROFRAME_HH
#define TABLEROFRAME_HH
#include <wx/wx.h>

#include <tablero.hh>

class TableroFrame: public wxFrame{
    public:
        TableroFrame(const wxString& title, int filas, int columnas);
    private:
        void OnPaint(wxPaintEvent& event);
        void DibujarTablero(wxDC& dc);
        void OnMouseEvent(wxMouseEvent& event);
        void OnExit(wxCommandEvent& event);
        wxDECLARE_EVENT_TABLE();
        Tablero tablero;
};

#endif