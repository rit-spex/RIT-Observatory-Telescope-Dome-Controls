int outPinOne = 7;
int outPinTwo = 8;
int goStatus = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(outPinOne, OUTPUT);
  pinMode(outPinTwo, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    analogWrite(outPinOne, 0);
    analogWrite(outPinTwo, 255); /*
}
