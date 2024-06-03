#include "frame.h"
#include "draw.h"
#include <iostream>
#include <string>
#include <wx/wx.h>

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame) EVT_MENU(ID_QUIT, MainFrame::OnQuit)
    EVT_BUTTON(wxID_ANY, MainFrame::OnButtonClick) EVT_PAINT(MainFrame::OnPaint)
        wxEND_EVENT_TABLE()

    // Public
    MainFrame::MainFrame(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(2000, 1000)),
      paintOnFrame(false) {

  // Menu bar on top of the program
  wxMenu *menuFile = new wxMenu;
  menuFile->Append(ID_QUIT, "E&xit\tAlt-X", "Quit this program");

  wxMenuBar *menuBar = new wxMenuBar;
  menuBar->Append(menuFile, "&File");

  SetMenuBar(menuBar);

  CreateStatusBar();
  SetStatusText("Welcome to wxWidgets!");

  // Create the panel
  wxPanel *panel = new wxPanel(this, wxID_ANY);

  // Dialog box
  wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

  // Button
  wxButton *button = new wxButton(panel, wxID_ANY, "Enter Text");
  vbox->Add(button, 0, wxALL | wxCENTER, 10);
  // Bind button event
  button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClick, this);

  m_textCtrl =
      new wxTextCtrl(panel, wxID_ANY, "", wxPoint(-1, -1), wxSize(300, 30));
  vbox->Add(m_textCtrl, 0, wxALL | wxCENTER, 10);

  panel->SetSizer(vbox);
}

void MainFrame::PaintCurve() {

  paintOnFrame = true;
  // Refresh the windows to call MainFrame::OnPaint
  Refresh();
}

// Public
void MainFrame::OnButtonClick(wxCommandEvent &event) {
  // Get the value of the text box
  user_input = m_textCtrl->GetValue().ToStdString();

  std::cout << "OnButtonClick :" << user_input << std::endl;

  PaintCurve();
}

wxSize MainFrame::GetSizeOfScreen() {
  wxSize window_size = GetSize();
  return window_size;
}
// Private
void MainFrame::OnQuit(wxCommandEvent &WXUNUSED(event)) { Close(true); }

// Private
void MainFrame::OnPaint(wxPaintEvent &event) {
  if (paintOnFrame) {
    static std::string last_user_input;
    if (user_input != last_user_input) {
      last_user_input = user_input;

      wxSize window_size = GetSize();
      int screen_width = window_size.GetWidth();
      int screen_height = window_size.GetHeight();

      wxPaintDC dc(this);
      Draw draw(dc);

      draw.DrawHorizontalLine(user_input, screen_width, screen_height);
      // TODO: receivre wxPoints and then DrawLines here
    }
  }
}
