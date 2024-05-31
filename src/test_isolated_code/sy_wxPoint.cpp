#include <cctype>          // for std::isdigit
#include <cmath>           // for std::pow
#include <iostream>        // for std::cin, std::cout
#include <sstream>         // for std::istringstream
#include <stack>           // for std::stack
#include <stdexcept>       // for std::runtime_error
#include <string>          // for std::string
#include <unordered_map>   // for std::unordered_map
#include <vector>          // for std::vector
#include <set>             // for std::set
#include <wx/wx.h>         // for wxWidgets

// Function to apply an operator to two operands
using std::istringstream;
using std::unordered_map;
using std::vector;
using std::set;

double applyOperator(double a, double b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return std::pow(a, b);
        default:
            throw std::runtime_error("Invalid operator");
    }
}

// Function to determine the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Function to perform the Shunting Yard algorithm and evaluate the expression
double evaluateExpression(const std::string &expr, const unordered_map<char, double> &variable_values) {
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
set<char> detectVariables(const std::string &expr) {
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

int main() {
    // Ask the user for a mathematical expression
    std::string math;
    std::cout << "Expression math: ";
    std::cin >> math;

    vector<wxPoint> points;

    try {
        // Detect all variables in the expression
        set<char> variables = detectVariables(math);

        // Evaluate the expression 100 times with all variables incrementing each time
        for (int i = 0; i < 100; ++i) {
            unordered_map<char, double> variable_values;
            for (char var : variables) {
                variable_values[var] = static_cast<double>(i);
            }
            double result = evaluateExpression(math, variable_values);
            points.push_back(wxPoint(i, static_cast<int>(result)));
        }

        // Plot the points (this is just a placeholder, actual drawing should be done in a wxWidgets context)
        // Assuming 'dc' is a valid wxDC object provided by wxWidgets framework
        // wxDC dc; // This line is just a placeholder
        // dc.DrawLines(points.size(), &points[0]);

        // Output the results for debugging
        std::cout << "Results: ";
        for (const auto &point : points) {
            std::cout << "(" << point.x << ", " << point.y << ") ";
        }
        std::cout << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

