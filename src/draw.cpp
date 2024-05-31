#include "draw.h"
#include "math.h"
#include <cstdio>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

Draw::Draw(wxDC &dc) : m_dc(dc) {}

void Draw::DrawHorizontalLine(std::string &user_input) {
  int xMin = -100;
  int xMax = 100 + 1;
  int scale = 10; // Scale the parabola for better visibility
  int xOffset = 1000;
  int yOffset = 500;

  std::cout << "DrawHorizontalLine: " << user_input << std::endl;

  Math *math = new Math;

  try {
    // Evaluate expression and generate points
    std::vector<wxPoint> wxPoints;

    math->main(user_input, xMin, xMax, scale, xOffset, yOffset, &wxPoints);

    // Draw lines connecting the points
    // m_dc.DrawLines(wxPoints.size(), wxPoints.data());
    m_dc.DrawLines(wxPoints.size(), &wxPoints[0], xOffset, yOffset);

  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}
