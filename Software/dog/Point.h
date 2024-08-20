#ifndef POINT_H_
#define POINT_H_

class Point {
  public:
    Point(const double x = 0, const double y = 95, const double z = 0);
    double get_x() const;
    double get_y() const;
    double get_z() const;

  private:
    double x;
    double y;
    double z;
};

#endif