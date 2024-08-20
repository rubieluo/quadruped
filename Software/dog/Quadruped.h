#ifndef QUADRUPED_H_
#define QUADRUPED_H_

#include <Arduino.h>
#include <Servo.h>
#include "Gait.h"
#include "Leg.h"

class Quadruped {
  public:
    Quadruped();
    Gait* gait;
    void walk();

  private:
    Leg* front_right;
    Leg* front_left;
    Leg* back_right;
    Leg* back_left;
};

#endif