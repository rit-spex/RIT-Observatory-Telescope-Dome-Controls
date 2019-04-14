int forwardPositive = 16;
int forwardNegative = 17;
int backwardPositive = 18;
int backwardNegative = 19;

//CHANGE THIS BASED ON YOUR PREFERENCE.
//0 = NONE, 1 = FORWARD, -1 = BACKWARD
int motorStatus = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(forwardPositive, OUTPUT);
  pinMode(forwardNegative, OUTPUT);
  pinMode(backwardPositive, OUTPUT);
  pinMode(backwardNegative, OUTPUT);
}

/*
 * !!!!!!!!!!!!!!!!!!!!!!!!
 * ENSURE THAT WHEN RUNNING THE MOTOR FORWARDS (digitalWrite LOW)
 * THE BACKWARDS SETTINGS ARE (digitalWrite HIGH) AND VICE VERSA
 * i.e. dont contradict yourself!
 * !!!!!!!!!!!!!!!!!!!!!!!!!
 */
void loop() {
  // put your main code here, to run repeatedly:
  if(motorStatus == 0) {
    //disable forward motor
    digitalWrite(forwardPositive, HIGH);
    digitalWrite(forwardNegative, HIGH);
    //disable backward motor
    digitalWrite(backwardPositive, HIGH);
    digitalWrite(backwardNegative, HIGH);
  }

  if(motorStatus == 1) {
    //disable backward motor
    digitalWrite(backwardPositive, HIGH);
    digitalWrite(backwardNegative, HIGH);
    //enable forward motor
    digitalWrite(forwardPositive, LOW);
    digitalWrite(forwardNegative, LOW);
  }

  if(motorStatus == -1) {
    //disable forward motor
    digitalWrite(forwardPositive, HIGH);
    digitalWrite(forwardNegative, HIGH);
    //enable backward motor
    digitalWrite(backwardPositive, LOW);
    digitalWrite(backwardNegative, LOW);
  }
}
