// ----- Encoding UTF-8

#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

#include "Point.hpp"
#include "Segment.hpp"

class Primitives {
  // Implements some computational geometry primitives

  public:
    // ----- Interface

    // Returns 1 if s1 is clockwise from s2 in relation to the origin,
    // -1 if s2 is clockwise from s1 and 0 if they're colinear.
    static int clockwise(Segment s1, Segment s2); 

    // Given consecutive line segments s1 and s2, returns 1 if s2 turns left from s1,
    // -1 if s2 turns right and 0 if s2 goes straight from s1.
    static int turn_direction(Segment s1, Segment s2); 

    static bool intersect(Segment s1, Segment s2); // Returns true if s1 and s2 intercept, even if only at some point p
    static bool intersect(Point p, Segment s); // Returns true if Point p intercepts s (which means p lies on s)

  private:
    static double cross_product(Segment s1, Segment s2); // Returns the cross product of s1 and s2
    
    // Given a line segment s, it translates s to the origin (treating s._p1 as the origin)
    // and returns the point that represents the new vector.
    static Point to_origin(Segment s);

    static bool inverse_signs(double x, double y); // Returns true if x and y have inverse signs
};

#endif