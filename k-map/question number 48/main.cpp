#include <Arduino.h>
const int A_pin = 2;
const int B_pin = 3;
const int C_pin = 4;
const int D_pin = 5;
const int F_pin = 13;

void setup() {
  pinMode(A_pin, INPUT);
  pinMode(B_pin, INPUT);
  pinMode(C_pin, INPUT);
  pinMode(D_pin, INPUT);
  pinMode(F_pin, OUTPUT);
}

void loop() {
  int A = digitalRead(A_pin);
  int B = digitalRead(B_pin);
  int C = digitalRead(C_pin);
  int D = digitalRead(D_pin);

  int F;

  if (A == 0 && B == 0)
    F = C;
  else if (A == 0 && B == 1)
    F = D;
  else if (A == 1 && B == 0)
    F = !D;
  else
    F = (!C && !D);

  digitalWrite(F_pin, F);
}
