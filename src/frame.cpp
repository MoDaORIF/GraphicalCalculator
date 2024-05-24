#include "frame.h"
#include "draw.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(ID_QUIT, MainFrame::OnQuit)
    EVT_PAINT(MainFrame::OnPaint)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 150)) {
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_QUIT, "E&xit\tAlt-X", "Quit this program");

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
}

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event)) {
    Close(true);
}

void MainFrame::OnPaint(wxPaintEvent& event) {
    wxPaintDC dc(this);
    drawHorizontalLine(dc);
}
