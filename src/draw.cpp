#include "draw.h"
#include "math.h"
#include <cstdio>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

// FIX: Draw child of frame.cp ?
Draw::Draw(wxDC &dc) : m_dc(dc) {}

void Draw::DrawHorizontalLine(std::string &user_input, int screen_width,
                              int screen_height) {
  int xMin = 0;
  int xMax = 100 + 1;
  int scale = 10; // Scale the parabola for better visibility
  int xOffset = 1000;
  int yOffset = 500;

  std::cout << "DrawHorizontalLine: " << user_input << std::endl;

  Math m_math = *new Math;

  try {
    // Evaluate expression and generate points
    std::vector<wxPoint> wxPoints;

    m_math.main(user_input, screen_width, screen_height, xMin, xMax, scale,
               xOffset, yOffset, &wxPoints);

    // Draw lines connecting the points
    // m_dc.DrawLines(wxPoints.size(), wxPoints.data());
    m_dc.DrawLines(wxPoints.size(), &wxPoints[0], xOffset, yOffset);

  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}
