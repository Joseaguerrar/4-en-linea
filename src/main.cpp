#include <wx/wx.h>
#include <App.hh>
#include <MenuFrame.hh>
#include <wx/display.h>
#include <TableroFrame.hh>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    wxDisplay pantalla(0); 
    wxRect geometriaPantalla = pantalla.GetGeometry();
    int anchoX = geometriaPantalla.GetWidth();
    int altoY = geometriaPantalla.GetHeight();
    MenuFrame* menuFrame = new MenuFrame("Botones para jugadores");
    menuFrame->SetSize(anchoX, altoY);
    menuFrame->Show();
    return true;
}