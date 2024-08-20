#include "Quadruped.h"

Quadruped::Quadruped() {
  front_right = new Leg(FR_SHOULDER_ROLL_PIN, FR_SHOULDER_PITCH_PIN, FR_ELBOW_PITCH_PIN);
  front_left = new Leg(FL_SHOULDER_ROLL_PIN, FL_SHOULDER_PITCH_PIN, FL_ELBOW_PITCH_PIN);
  back_right = new Leg(BR_SHOULDER_ROLL_PIN, BR_SHOULDER_PITCH_PIN, BR_ELBOW_PITCH_PIN);
  back_left = new Leg(BL_SHOULDER_ROLL_PIN, BL_SHOULDER_PITCH_PIN, BL_ELBOW_PITCH_PIN);

  front_left->set_inverted(true);
  back_left->set_inverted(true);

  front_right->set_offsets(0, -3, 0);
  front_left->set_offsets(0, -9, 0);
  back_right->set_offsets(0, 0, 18);
  back_left->set_offsets(6, -15, 0);


  gait = new Gait(FORWARD);
}

void Quadruped::walk() {
  for(int i = 0; i < 4; i++) {
    front_right->set_position(gait->gait_1[i]);
    front_left->set_position(gait->gait_2[i]);
    back_right->set_position(gait->gait_2[i]);
    back_left->set_position(gait->gait_1[i]);
    delay(250);
  }
}