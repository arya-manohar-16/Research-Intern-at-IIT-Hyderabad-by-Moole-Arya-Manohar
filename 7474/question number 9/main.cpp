#include <Arduino.h>
int Q1 = 0;
int Q2 = 1;
int Q3 = 1;

unsigned long cycle = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Cycle\tQ1 Q2 Q3");
  logState();
}

void loop() {
  int nextQ1 = Q1 ^ (!Q3);
  int nextQ2 = Q1;
  int nextQ3 = Q3 ^ Q2;

  Q1 = nextQ1;
  Q2 = nextQ2;
  Q3 = nextQ3;

  cycle++;
  logState();

  delay(500);
}

void logState() {
  Serial.print(cycle);
  Serial.print("\t");
  Serial.print(Q1);
  Serial.print("  ");
  Serial.print(Q2);
  Serial.print("  ");
  Serial.println(Q3);
}
