#ifndef MATH_H
#define MATH_H

#include <set> // for std::set
#include <string>
#include <unordered_map> // for std::unordered_map
#include <vector>
#include <wx/wx.h>

class Math {

public:
  Math(){};
  int main(const std::string &expr, int screen_width, int screen_height,
           int xMin, int xMax, int scale, int xOffset, int yOffset,
           std::vector<wxPoint> *pwxPoint);

private:
  double applyOperator(double a, double b, char op);
  int precedence(char op);
  double
  evaluateExpression(const std::string &expr,
                     const std::unordered_map<char, double> &variable_values);
  std::set<char> detectVariables(const std::string &expr);
};

#endif // !MATH_H
