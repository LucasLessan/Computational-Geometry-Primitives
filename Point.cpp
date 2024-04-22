// ----- Encoding UTF-8

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(double x) : _x(x), _y(x) {}

Point::Point(double x, double y) : _x(x), _y(y) {}

double Point::get_x() { return _x; }

double Point::get_y() { return _y; }

void Point::set_x(double x) { _x = x; }

void Point::set_y(double y) { _y = y; }