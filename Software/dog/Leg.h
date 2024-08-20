#ifndef LEG_H_
#define LEG_H_

#include <Arduino.h>
#include <Servo.h>
#include "Constants.h"
#include "Point.h"

class Leg {
  public:
    Leg(int shoulder_roll, int shoulder_pitch, int elbow_pitch);
    void set_position(Point setpoint);
    void set_inverted(bool inverted = false);
    void set_offsets(int shoulder_roll = 0, int shoulder_pitch = 0, int elbow_pitch = 0);
    Servo shoulder_roll;
    Servo shoulder_pitch;
    Servo elbow_pitch;
  
  private:
    bool inverted = false;
    int shoulder_roll_offset = 0;
    int shoulder_pitch_offset = 0;
    int elbow_pitch_offset = 0;
};

#endif