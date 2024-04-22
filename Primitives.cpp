// ----- Encoding UTF-8

// Wherever there's a comment with "This is to improve readability", this means
// that we create variables to reduce clutter.
//
// As a simple example, instead of doing:
// auto a = b.get_c() + d.get_e();
// 
// we do:
// auto c = b.get_c();
// auto e = d.get_e();
// auto a = c + e;

#include "Point.hpp"
#include "Segment.hpp"
#include "Primitives.hpp"

int Primitives::clockwise(Segment s1, Segment s2) {

  double d = cross_product(s1, s2);

  if (d > 0.0)
    return 1;
  
  if (d < 0.0)
    return -1;
  
  return 0; // if (d == 0)
}

int Primitives::turn_direction(Segment s1, Segment s2) {

  // Only works if s1._p2 = s2._p1

  // Note that this is the same as s1 + s2, if treated as vectors,
  // in other words, if you translate s1 to the origin, and s2
  // accordingly, so that s1._p2 = s2._p1 holds.
  Segment s3(s2.get_p2());

  return cross_product(s1, s3);
}

bool Primitives::intersect(Segment s1, Segment s2) {

  // This is to improve readability
  Point p1 = s1.get_p1();
  Point p2 = s1.get_p2();
  Point p3 = s2.get_p1();
  Point p4 = s2.get_p2();
  
  // This is so we can test if the left (and right) endpoints
  // of s1 are on opposite sides in relation to s2.
  double d1 = cross_product(Segment(p3, p1), s2);
  double d2 = cross_product(Segment(p3, p2), s2);

  // This is so we can test if the left (and right) endpoints
  // of s2 are on opposite sides in relation to s1.
  double d3 = cross_product(Segment(p1, p3), s1);
  double d4 = cross_product(Segment(p1, p4), s1);

  // Thistests if each endpoint of s1 and s2 are on opposite sides
  // in relation to the other line segment.
  if (inverse_signs(d1, d2) && inverse_signs(d3, d4))
    return true;

  // Checks if any endpoint of s1 lies on s2, given that p1 or p2
  // are colinear with s2 because d1 or d2 is zero.
  if (d1 == 0 && intersect(p1, s2)) return true;
  if (d2 == 0 && intersect(p2, s2)) return true;

  // Checks if any endpoint of s2 lies on s1, given that p3 or p4
  // are colinear with s1 because d3 or d4 is zero.
  if (d3 == 0 && intersect(p3, s1)) return true;
  if (d4 == 0 && intersect(p4, s1)) return true;

  return false;
}

// Sets the smallest and largest of a and b to min and max, respectively
void min_max(double a, double b, double& min, double& max) {

  if (a >= b) {
    max = a;
    min = b;
  }

  else {
    max = b;
    min = a;
  }
}

bool Primitives::intersect(Point p, Segment s) {

  // This is to improve readability
  double p_x = p.get_x();
  double p_y = p.get_y();

  // This is to improve readability
  Point p1 = s.get_p1();
  Point p2 = s.get_p2();

  // This is to improve readability
  double p1_x = p1.get_x();
  double p1_y = p1.get_y();
  double p2_x = p1.get_x();
  double p2_y = p1.get_y();

  // These will save the smallest and largest values of each x and y from s
  double min_x, max_x;
  double min_y, max_y;

  // Read this as defining the intervals [min_x, max_x] and [min_y, max_y]
  min_max(p1_x, p2_x, min_x, max_x);
  min_max(p1_y, p2_y, min_y, max_y);

  // Checks if p_x and p_y are in the intervals [min_x, max_x] and [min_y, max_y], respectively
  bool a = (p_x <= max_x) && (p_x >= min_x);
  bool b = (p_y <= max_y) && (p_x >= min_y);

  return a && b;
}

Point Primitives::to_origin(Segment s) {

  // This is to improve readability
  Point p1 = s.get_p1();
  Point p2 = s.get_p2();

  // This is to improve readability
  double x = p2.get_x() - p1.get_x();
  double y = p2.get_y() - p1.get_y();

  Point p3(x, y); // p3 represents s as a vector which s._p1 being the origin

  return p3;
}

bool Primitives::inverse_signs(double x, double y) { return (x > 0.0 && y < 0.0) || (x < 0.0 && y > 0.0); }

double Primitives::cross_product(Segment s1, Segment s2) {

  Point v1 = to_origin(s1);
  Point v2 = to_origin(s2);

  double d = v1.get_x() * v2.get_y() - v2.get_x() * v1.get_y(); // read as x1 * y2 - x2 * y1

  return d;
}