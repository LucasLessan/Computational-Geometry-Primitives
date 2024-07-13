// ----- Encoding UTF-8

#ifndef PRINT_DATA_HPP
#define PRINT_DATA_HPP

#include "Point.hpp"
#include "Segment.hpp"

// Implements output functions for Points and Segments so as to adhere to the
// Single Responsibility principle.
class Print_data {
  public:
    // ----- Interface
    static void print(Point p);
    static void print(Segment s);
};

#endif
