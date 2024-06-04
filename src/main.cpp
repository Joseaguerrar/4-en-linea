#include <wx/wx.h>
#include <App.hh>
#include <MainFrame.hh>
#include <wx/display.h>


wxIMPLEMENT_APP(App);

bool App::OnInit() {
    wxDisplay pantalla(0); 
    wxRect geometriaPantalla = pantalla.GetGeometry();
    int anchoX = geometriaPantalla.GetWidth();
    int altoY = geometriaPantalla.GetHeight();
    MainFrame* mainFrame = new MainFrame("Botones para jugadores");
    mainFrame->SetSize(anchoX, altoY);
    mainFrame->Show();
    return true;
}