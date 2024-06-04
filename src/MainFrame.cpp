#include <MainFrame.hh>
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& tittle):wxFrame(nullptr, wxID_ANY, tittle){
    wxPanel* panel = new wxPanel(this);
    wxArrayString opciones;
    opciones.Add("Bot");
    opciones.Add("BotConIA");
    opciones.Add("Humano");
    wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150,375), wxSize(100,-1), opciones);
    wxArrayString opcionesA;
    opcionesA.Add("Bot");
    opcionesA.Add("BotConIA");
    opcionesA.Add("Humano");
    wxChoice* choice1 = new wxChoice(panel, wxID_ANY, wxPoint(200,100), wxSize(100,-1), opcionesA);
}