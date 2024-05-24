#ifndef FRAME_H
#define FRAME_H

#include <wx/string.h>
#include <wx/wx.h>

class MainFrame : public wxFrame {

public:
  MainFrame(const wxString& title);

private:
  void OnQuit(wxCommandEvent &event);
  void OnPaint(wxPaintEvent &event);

  wxDECLARE_EVENT_TABLE();
};

enum { ID_QUIT = 1 };

#endif // FRAME_H
