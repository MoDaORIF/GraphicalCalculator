#ifndef DRAW_H
#define DRAW_H

#include "frame.h"
#include <muParser.h>
#include <set> // for std::set
#include <string>
#include <unordered_map> // for std::unordered_map
#include <wx/wx.h>

class Draw : public MainFrame {

public:
  Draw(wxDC &dc); // Constructor accepting wxDC reference
  std::vector<wxPoint> plotLines(std::string &user_input);
  void OnButtonClick(wxCommandEvent &event);

private:
  wxDC &m_dc; // Reference to wxDC
  //
  double applyOperator(double a, double b, char op);
  int precedence(char op);

  double
  evaluateExpression(const std::string &expr,
                     const std::unordered_map<char, double> &variable_values);

  std::set<char> detectVariables(const std::string &expr);

  int calculateLinePoints(const std::string &expr, const int xMin,
                          const int xMax, int scale,
                          std::vector<wxPoint> *pwxPoint);
};
#endif // DRAW_H
