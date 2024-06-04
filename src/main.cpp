#include <wx/wx.h>
#include <App.hh>
#include <MainFrame.hh>

wxIMPLEMENT_APP(App);

bool App::OnInit(){
  MainFrame* mainFrame = new MainFrame("botones para jugadores");
  mainFrame -> Show();
  return true;
}

