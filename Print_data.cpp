// ----- Encoding UTF-8

#include <iostream>

#include "Point.hpp"
#include "Segment.hpp"
#include "Print_data.hpp"

void Print_data::print(Point p) {
  std::cout << "(" << p.get_x() << ", " << p.get_y() << ")\n";
}

void Print_data::print(Segment s) {  
  std::cout << "p1 = ";
  print(s.get_p1());
  
  std::cout << "p2 = ";
  print(s.get_p2());
}
