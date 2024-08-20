#include "Quadruped.h"

Quadruped* quadruped;

void setup() {
  Serial.begin(9600);
  quadruped = new Quadruped();
}

void loop() {
  quadruped->walk();
}
