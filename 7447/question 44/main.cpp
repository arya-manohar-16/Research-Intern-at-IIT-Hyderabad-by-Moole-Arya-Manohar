#include <Arduino.h>
const int X_pin = 2;
const int Y_pin = 3;
const int Z_pin = 13;

void setup() {
  pinMode(X_pin, INPUT);
  pinMode(Y_pin, INPUT);
  pinMode(Z_pin, OUTPUT);
}

void loop() {
  int X = digitalRead(X_pin);
  int Y = digitalRead(Y_pin);

  // Gate-level implementation
  int Z1 = (!X && Y);
  int Z2 = (X && !Y);
  int Z  = Z1 || Z2;

  // Equivalent XOR
  // int Z = X ^ Y;

  digitalWrite(Z_pin, Z);
}
