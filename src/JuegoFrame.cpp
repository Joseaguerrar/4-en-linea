#include <wx/wx.h>

#include <JuegoFrame.hh>

using namespace std;

JuegoFrame ::JuegoFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title) {
  wxPanel* panel = new wxPanel(this);
}