#include <Arduino.h>
int Q2 = 1;
int Q1 = 1;
int Q0 = 1;

unsigned long cycle = 0;

void setup() {
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  Serial.println("Cycle\tQ2 Q1 Q0");
  logState();
}

void loop() {
  int nextQ2 = Q2 ^ Q0;
  int nextQ1 = Q2;
  int nextQ0 = Q1;

  Q2 = nextQ2;
  Q1 = nextQ1;
  Q0 = nextQ0;

  cycle++;

  digitalWrite(2, Q2);
  digitalWrite(3, Q1);
  digitalWrite(4, Q0);

  logState();

  if (Q2 == 1 && Q1 == 0 && Q0 == 0) {
    Serial.println("Target state 100 reached");
    while (1);
  }

  delay(500);
}

void logState() {
  Serial.print(cycle);
  Serial.print("\t");
  Serial.print(Q2);
  Serial.print("  ");
  Serial.print(Q1);
  Serial.print("  ");
  Serial.println(Q0);
}
