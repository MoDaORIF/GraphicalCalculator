#ifndef FRAME_H
#define FRAME_H

#include <string>
#include <wx/wx.h>

class MainFrame : public wxFrame {

public:
  MainFrame(){};
  MainFrame(const wxString &title);
  void OnButtonClick(wxCommandEvent &event);
  // wxSize GetSizeOfScreen();

  int screen_width;
  int screen_height;

private:
  void OnQuit(wxCommandEvent &event);
  void OnPaint(wxPaintEvent &event);
  void PaintCurve();

  wxButton *button;
  wxTextCtrl *m_textCtrl;
  // Set to false by default. Tells the program to pain or not
  bool paintOnFrame = false;
  std::string user_input;

  wxDECLARE_EVENT_TABLE();
};

enum { ID_QUIT = 1 };

#endif // FRAME_H
