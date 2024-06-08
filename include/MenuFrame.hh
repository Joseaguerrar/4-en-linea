#ifndef MENUFRAME_HH
#define MENUFRAME_HH
#include <wx/wx.h>

#include <TableroFrame.hh>
class MenuFrame : public wxFrame {
 public:
  MenuFrame(const wxString& title);

 private:
  void OnAnyButtonClicked(wxCommandEvent& evt);
  void OnButton1Clicked(wxCommandEvent& evt);
  void OnButton2Clicked(wxCommandEvent& evt);
  int wxStringToInt(wxString numeroAConvertir);
  TableroFrame* tablero;
  wxChoice* jugador1;
  wxChoice* jugador2;
  wxChoice* dimensionFilas;
  wxChoice* dimensionColumnas;
};

#endif