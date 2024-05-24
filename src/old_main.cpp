#include <wx/wx.h>
#include "frame.h"

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

class test : public wxFrame {
public:
    test(const wxString& title);

private:
    void OnQuit(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

enum {
    ID_Quit = 1
};

wxBEGIN_EVENT_TABLE(test, wxFrame)
    EVT_MENU(ID_Quit, test::OnQuit)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    test* frame = new test("Hello wxWidgets");
    frame->Show(true);
    return true;
}

test::test(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 150)) {
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Quit, "E&xit\tAlt-X", "Quit this program");

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets from WSL !");
}

void test::OnQuit(wxCommandEvent& WXUNUSED(event)) {
    Close(true);
}

