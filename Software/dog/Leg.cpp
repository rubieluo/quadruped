#include "Leg.h"
#include <math.h>

#define DELAY 500

double to_degrees(double radians) {
  return radians * (180.0 / M_PI);
}

Leg::Leg(int shoulder_roll, int shoulder_pitch, int elbow_pitch) {
  this->shoulder_roll.attach(shoulder_roll);
  this->shoulder_pitch.attach(shoulder_pitch);
  this->elbow_pitch.attach(elbow_pitch);

  this->shoulder_roll.write(90);
  this->shoulder_pitch.write(90);
  this->elbow_pitch.write(90);
  delay(DELAY);
}

void Leg::set_inverted(bool inverted) {
  this->inverted = inverted;
}

void Leg::set_offsets(int shoulder_roll, int shoulder_pitch, int elbow_pitch) {
  this->shoulder_roll_offset = shoulder_roll;
  this->shoulder_pitch_offset = shoulder_pitch;
  this->elbow_pitch_offset = elbow_pitch;
}

void Leg::set_position(Point setpoint) {
  double hypot = sqrt(pow(setpoint.get_x(),2) + pow(setpoint.get_y(), 2));
  double phi = acos((pow(hypot, 2) - pow(UPPER_LEG, 2) - pow(LOWER_LEG, 2)) / (-2 * UPPER_LEG * LOWER_LEG));
  double theta = asin((LOWER_LEG * sin(phi)) / hypot) - atan2(setpoint.get_x(), setpoint.get_y());
  double gamma = atan2(setpoint.get_z(), setpoint.get_y());

  if (!inverted) {
    elbow_pitch.write(int(round(to_degrees(M_PI - phi))) + elbow_pitch_offset);
    shoulder_pitch.write(int(round(to_degrees((M_PI / 2) - theta))) + shoulder_pitch_offset);
    shoulder_roll.write(int(round(to_degrees((M_PI / 2) - gamma) + shoulder_roll_offset)));
  } else {
    elbow_pitch.write(int(round(to_degrees(phi))) + elbow_pitch_offset);
    shoulder_pitch.write(int(round(to_degrees((M_PI / 2) + theta))) + shoulder_pitch_offset);
    shoulder_roll.write(int(round(to_degrees((M_PI / 2) + gamma) + shoulder_roll_offset)));
  }
  
}
