#include <JuegoFrame.hh>
#include <wx/wx.h>

using namespace std;

JuegoFrame :: JuegoFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title){
    wxPanel* panel = new wxPanel(this);
}