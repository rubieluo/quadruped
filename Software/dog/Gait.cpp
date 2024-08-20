#include "Gait.h"

Gait::Gait(int motion) {
  set_gait(motion);
}

void Gait::set_gait(int motion) {
  switch (motion) {
    case FORWARD:
      for (int i = 0; i < 4; i++) {
        gait_1[i] = FORWARD_1[i];
        gait_2[i] = FORWARD_2[i];
      }
      break;
    case BACKWARD:
      for (int i = 0; i < 4; i++) {
        gait_1[i] = BACKWARD_1[i];
        gait_2[i] = BACKWARD_2[i];
      }
      break;
    case RIGHT:
      for (int i = 0; i < 4; i++) {
        gait_1[i] = RIGHT_1[i];
        gait_2[i] = RIGHT_2[i];
      }
      break;
    case LEFT:
      for (int i = 0; i < 4; i++) {
        gait_1[i] = LEFT_1[i];
        gait_2[i] = LEFT_2[i];
      }
      break;
  }
}