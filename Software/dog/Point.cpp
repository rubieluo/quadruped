#include "Point.h"

using namespace std;

Point::Point(double x, double y, double z) : x(x), y(y), z(z)
{}

double Point::get_x() const {
	return x;
}

double Point::get_y() const {
	return y;
}

double Point::get_z() const {
  return z;
}
