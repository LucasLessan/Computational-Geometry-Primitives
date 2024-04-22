// ----- Encoding UTF-8

#ifndef POINT_HPP
#define POINT_HPP

class Point {
  // Implements a point structure in R^2

  public:
    // ----- Construtors
    Point(); // Same as Point(0.0, 0.0)
    Point(double x); // Same as Point(x, x)
    Point(double x, double y);

    // ----- Interface
    double get_x();
    double get_y();
    void set_x(double x);
    void set_y(double y);

  private:
    double _x;
    double _y;
};

#endif