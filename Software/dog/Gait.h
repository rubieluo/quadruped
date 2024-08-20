#ifndef GAIT_H_
#define GAIT_H_

#include "Point.h"

const Point FORWARD_1[4]= {Point(0, 110, 0), Point(0, 90, 0), Point(10, 90, 0), Point(10, 110, 0)};
const Point FORWARD_2[4]= {Point(10, 90, 0), Point(10, 110, 0), Point(0, 110, 0), Point(0, 90, 0)};

const Point BACKWARD_1[4]= {Point(0, 95, 0), Point(0, 75, 0), Point(-20, 75, 0), Point(-20, 95, 0)};
const Point BACKWARD_2[4]= {Point(-20, 75, 0), Point(-20, 95, 0), Point(0, 95, 0), Point(0, 75, 0)};

const Point RIGHT_1[4]= {Point(0, 95, 0), Point(0, 75, 0), Point(0, 75, 20), Point(0, 95, 20)};
const Point RIGHT_2[4]= {Point(0, 75, -20), Point(0, 95, -20), Point(0, 95, 0), Point(0, 75, 0)};

const Point LEFT_1[4]= {Point(0, 95, 0), Point(0, 75, 0), Point(20, 75, 0), Point(20, 95, 0)};
const Point LEFT_2[4]= {Point(20, 75, 0), Point(20, 95, 0), Point(0, 95, 0), Point(0, 75, 0)};

class Gait {
  public:
    Gait(int motion);
    Point gait_1[4];
    Point gait_2[4];
    void set_gait(int motion);
};

enum motion {
  FORWARD,
  BACKWARD, 
  LEFT,
  RIGHT
};
  
#endif