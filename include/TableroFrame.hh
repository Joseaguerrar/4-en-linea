#ifndef TABLEROFRAME_HH
#define TABLEROFRAME_HH
#include <wx/wx.h>
#include <tablero.hh>

class TableroFrame: public wxFrame{
    public:
        TableroFrame(const wxString& title);
    private:
        void OnPaint(wxPaintEvent& event);
        wxDECLARE_EVENT_TABLE();
        Tablero tablero;
};

#endif