#ifndef MATH_H
#define MATH_H

#include <string>
#include <wx/wx.h>
#include <vector>

class Math {

public:
  Math();
  std::vector<wxPoint> evaluateExpressionWithX(const std::string &expr, int xMin, int xMax, int scale, int xOffset, int yOffset);

private:
  double applyOperator(double a, double b, char op);
  int precedence(char op);
  double evaluateExpression(const std::string &expr);
};

#endif // !MATH_H
