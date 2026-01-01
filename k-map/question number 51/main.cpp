#include <Arduino.h>
const int X_pin = 2;
const int Y_pin = 3;
const int Z_pin = 4;
const int F_pin = 13;

void setup() {
  pinMode(X_pin, INPUT);
  pinMode(Y_pin, INPUT);
  pinMode(Z_pin, INPUT);
  pinMode(F_pin, OUTPUT);
}

void loop() {
  int X = digitalRead(X_pin);
  int Y = digitalRead(Y_pin);
  int Z = digitalRead(Z_pin);

  int M = (!X) && Y;
  int F = M ^ Z;

  digitalWrite(F_pin, F);
}
