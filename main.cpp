#include <iostream>
#include <assert.h>

#include "Point.hpp"
#include "Segment.hpp"
#include "Primitives.hpp"
#include "Print_Data.hpp"

// Tests the Primitives class
int main(int argc, char* argv[]) {

  Point p1(0.0, 1.0);
  Point p2(1.0, 0.0);
  Point p3(1.0); // (x, y) = (1, 1)
  Point p4(1.0, 2.0);
  Point p5(2.0, 0.0);
  Point p6(2.0, 1.0);
  Point p7(2.0, 2.0);
  Point p8(-1.0, -1.0);

  Segment s1(p3); // ((0, 0), (1, 1))
  Segment s2(p2); // ((0, 0), (1, 0))
  Segment s3(p1, p2); // ((0, 1), (1, 0))
  Segment s4(p5, p6); // ((2, 0), (2, 1))
  Segment s5(p3, p4); // ((2, 0), (2, 1))
  Segment s6(p3, p2); // ((1, 1), (1, 0))
  Segment s7(p3, p7); // ((1, 1), (2, 2))
  Segment s8(p8); // ((-1, -1), (0, 0))

  // Tests clockwise()
  assert(Primitives::clockwise(s1, s2) == -1);
  assert(Primitives::clockwise(s2, s1) == 1); // "Reflexiveness"

  assert(Primitives::clockwise(s1, s8) == 0);
  assert(Primitives::clockwise(s8, s1) == 0); // Reflexiveness

  // Tests turn_direction()
  assert(Primitives::turn_direction(s1, s5) == 1);
  assert(Primitives::turn_direction(s1, s6) == -1);
  assert(Primitives::turn_direction(s1, s7) == 0);

  // Tests intersect()
  assert(Primitives::intersect(s1, s3) == true);
  assert(Primitives::intersect(s3, s1) == true); // intersect() should be reflexive
  
  assert(Primitives::intersect(s1, s2) == true); // Edge case, one point intersection
  assert(Primitives::intersect(s2, s1) == true); // Reflexiveness

  assert(Primitives::intersect(s1, s4) == false);
  assert(Primitives::intersect(s4, s1) == false); // Reflexiveness
}