#include<App.hh>
#include<MainFrame.hh>
#include<wx/wx.h>


bool App::OnInit(){
    MainFrame* mainFrame= new MainFrame("Primera interfaz");
    mainFrame->SetClientSize(800,500);
    mainFrame-> Show();

    return true;
}