// ----- Encoding UTF-8

#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include "Point.hpp"

class Segment {
  // Implements a line segment structure in R^2

  public:
    // ----- Construtors
    Segment(Point p2); // Same as Segment(Point(0.0, 0.0), p2)
    Segment(Point p1, Point p2);

    // ----- Interface
    Point get_p1();
    Point get_p2();
    void set_p1(Point p1);
    void set_p2(Point p2);

  private:
    Point _p1;
    Point _p2;
};

#endif