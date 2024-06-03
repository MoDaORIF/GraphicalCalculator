// FIX: x and y coordinate are swapped. Fix this
#include "math.h"
#include "frame.h"
#include <cctype>   // for std::isdigit
#include <cmath>    // for std::pow
#include <iostream> // for std::cin, std::cout
#include <ostream>
#include <set>           // for std::set
#include <sstream>       // for std::istringstream
#include <stack>         // for std::stack
#include <stdexcept>     // for std::runtime_error
#include <string>        // for std::string
#include <unordered_map> // for std::unordered_map
#include <vector>        // for std::vector
#include <wx/wx.h>       // for wxWidgets

// Function to apply an operator to two operands
using std::istringstream;
using std::set;
using std::unordered_map;
using std::vector;

double Math::applyOperator(double a, double b, char op) {

  int scale = 100;

  // Convert wxSize to int variables

  //std::cout << "height: " << screen_height << "width: " << screen_width
   //         << std::endl;

  switch (op) {

    // (a op b * (-1)) in each case because {0;0} is a the top left of the
    // window divided by scale to scale down and make the lines more visible
    // TODO: Scale has to be passed by reference. Scale is a GUI slider
    // FIX: Translate carthesian coordinates into screen coordinates
    // Exemple: -25;25 => 75;75

    // The basic algorithm to translate from cartesian coordinates to screen
    // coordinates are
    // screenX = cartX + screen_width / 2
    // screenY = screen_height / 2 - cartY

  case '+':
    return (a + b);
  case '-':
    return (a - b);
  case '*':
    return (a * b);
  case '/':
    return (a / b);
  case '^':
    return (std::pow(a, b)) * -1 / 100;
  default:
    throw std::runtime_error("Invalid operator");
  }
}

// Function to determine the precedence of an operator
int Math::precedence(char op) {
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
  if (op == '^')
    return 3;
  return 0;
}

// Function to perform the Shunting Yard algorithm and evaluate the expression
double
Math::evaluateExpression(const std::string &expr,
                         const unordered_map<char, double> &variable_values) {
  std::stack<double> values;
  std::stack<char> ops;
  istringstream input(expr);
  char token;

  while (input >> token) {
    if (std::isdigit(token)) {
      input.putback(token);
      double value;
      input >> value;
      values.push(value);
    } else if (token == '(') {
      ops.push(token);
    } else if (token == ')') {
      while (!ops.empty() && ops.top() != '(') {
        double b = values.top();
        values.pop();
        double a = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(applyOperator(a, b, op));
      }
      if (!ops.empty())
        ops.pop();
    } else if (std::isalpha(token)) {
      if (variable_values.find(token) != variable_values.end()) {
        values.push(variable_values.at(token));
      } else {
        throw std::runtime_error("Variable not defined");
      }
    } else if (std::string("+-*/^").find(token) != std::string::npos) {
      while (!ops.empty() && precedence(ops.top()) >= precedence(token)) {
        double b = values.top();
        values.pop();
        double a = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(applyOperator(a, b, op));
      }
      ops.push(token);
    }
  }

  while (!ops.empty()) {
    double b = values.top();
    values.pop();
    double a = values.top();
    values.pop();
    char op = ops.top();
    ops.pop();
    values.push(applyOperator(a, b, op));
  }

  return values.top();
}

// Function to detect all variables in the expression
set<char> Math::detectVariables(const std::string &expr) {
  set<char> variables;
  for (char c : expr) {
    if (std::isalpha(c)) {
      variables.insert(c);
    }
  }
  if (variables.empty()) {
    throw std::runtime_error("No variables found in the expression");
  }
  return variables;
}

int Math::main(const std::string &expr, const int screen_width,
               const int screen_height, const int xMin, const int xMax,
               int scale, int xOffset, int yOffset, vector<wxPoint> *pwxPoint) {

  MainFrame *test = new MainFrame;
  wxSize var_test = test->GetSizeOfScreen();
  int t1 = var_test.GetWidth();
  int t2 = var_test.GetHeight();

  // Display the size using std::cout
  std::cout << "Screen size: " << t1 << " x " << t2
            << std::endl;

  // Ask the user for a mathematical expression
  std::cout << "User input: " << expr;

  vector<wxPoint> points;

  try {
    // Detect all variables in the expression
    set<char> variables = detectVariables(expr);

    // Evaluate the expression 100 times with all variables incrementing each
    // time
    for (int i = xMin; i < xMax; ++i) {
      unordered_map<char, double> variable_values;
      for (char var : variables) {
        variable_values[var] = static_cast<double>(i);
      }
      double result = evaluateExpression(expr, variable_values);
      points.push_back(wxPoint(i, static_cast<int>(result)));
    }

    // Output the results for debugging
    std::cout << "Results: ";
    for (const auto &point : points) {
      std::cout << "Carthesien  : " << "(" << point.x << ", " << point.y * -1
                << ") " << std::endl;
      std::cout << "ui          : " << "(" << point.x << ", " << point.y << ") "
                << std::endl;
      std::cout << std::endl;
    }
    std::cout << std::endl;

    // update pwxPoints with the calculated points
    *pwxPoint = points;

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
}
