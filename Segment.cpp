// ----- Encoding UTF-8

#include "Point.hpp"
#include "Segment.hpp"

Segment::Segment(Point p2) : _p2(p2) {}

Segment::Segment(Point p1, Point p2) : _p1(p1), _p2(p2) {}

Point Segment::get_p1() { return _p1; }

Point Segment::get_p2() { return _p2; }

void Segment::set_p1(Point p1) { _p1 = p1; }

void Segment::set_p2(Point p2) { _p2 = p2; }