#include "frame.h"
#include <wx/wx.h>

class GraphCalc : public wxApp {
public:
  virtual bool OnInit();
};

wxIMPLEMENT_APP(GraphCalc);

bool GraphCalc::OnInit() {

  MainFrame* frame = new MainFrame("Graphical calculator");
  frame->Show(true);
  return true;
}
