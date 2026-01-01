// Pin definitions
const int A_pin = 2;
const int B_pin = 3;
const int C_pin = 4;
const int Y_pin = 13;

void setup() {
  pinMode(A_pin, INPUT);
  pinMode(B_pin, INPUT);
  pinMode(C_pin, INPUT);
  pinMode(Y_pin, OUTPUT);
}

void loop() {
  // Read inputs
  int A = digitalRead(A_pin);
  int B = digitalRead(B_pin);
  int C = digitalRead(C_pin);

  // Logic implementation
  int n1 = !(A || B);      // NOR
  int n2 = C || n1;        // OR
  int n3 = A && B;         // AND
  int n4 = n2 || n3;       // OR
  int n5 = !C;             // NOT
  int Y  = !(n5 && n4);    // NAND

  // Output
  digitalWrite(Y_pin, Y);

  delay(10); // small delay for stability
}
