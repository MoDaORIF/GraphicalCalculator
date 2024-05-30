#ifndef DRAW_H
#define DRAW_H

#include <string>
#include <wx/wx.h>
#include <muParser.h>

class Draw {

public:
  Draw(wxDC &dc); // Constructor accepting wxDC reference
  void DrawHorizontalLine(std::string &user_input);
  void OnButtonClick(wxCommandEvent &event);

private:
  wxDC &m_dc; // Reference to wxDC
  std::vector<wxPoint> calculateParabolaPoints();
  std::vector<wxPoint> evaluateExpression(std::wstring &expr);
};
#endif // DRAW_H
