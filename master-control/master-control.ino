#define led1 8
// constants won't change. They're used here to
// set pin numbers:

const int buttonPin = 2; // the number of the pushbutton pin Digital 2
const int buttonbPin = 3; // the number of the pushbutton pin Digital 3
const int buttoncPin = 4; // the number of the pushbutton pin Digital 4
const int buttondPin = 5; // the number of the pushbutton pin Digital 5
const int buttonePin = 6; // the number of the pushbutton pin Digital 6
const int buttonfPin = 7; // the number of the pushbutton pin Digital 7

const int ledPin = 13; // the number of the LED pin

// Variables will change:
int ledState = HIGH; // the current state of the output pin
int state = 20;

int buttonState; // the current reading from the input pin
int buttonbState; // the current reading from the input pin
int buttoncState; // the current reading from the input pin
int buttondState; // the current reading from the input pin
int buttoneState; // the current reading from the input pin
int buttonfState; // the current reading from the input pin

int lastButtonState = LOW; // the previous reading from the input pin
int lastButtonbState = LOW; // the previous reading from the input pin
int lastButtoncState = LOW; // the previous reading from the input pin
int lastButtondState = LOW; // the previous reading from the input pin
int lastButtoneState = LOW; // the previous reading from the input pin
int lastButtonfState = LOW; // the previous reading from the input pin

// the following variables are unsigned long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0; // the last time the output pin was toggled
unsigned long debounceDelay = 50; // the debounce time; increase if the output flickers
unsigned long lastDebouncebTime = 0; // the last time the output pin was toggled
unsigned long debouncebDelay = 50; // the debounce time; increase if the output flickers
unsigned long lastDebouncecTime = 0; // the last time the output pin was toggled
unsigned long debouncecDelay = 50; // the debounce time; increase if the output flickers
unsigned long lastDebouncedTime = 0; // the last time the output pin was toggled
unsigned long debouncedDelay = 50; // the debounce time; increase if the output flickers
unsigned long lastDebounceeTime = 0; // the last time the output pin was toggled
unsigned long debounceeDelay = 50; // the debounce time; increase if the output flickers
unsigned long lastDebouncefTime = 0; // the last time the output pin was toggled
unsigned long debouncefDelay = 50; // the debounce time; increase if the output flickers
void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(buttonbPin, INPUT);
  pinMode(buttoncPin, INPUT);
  pinMode(buttondPin, INPUT);
  pinMode(buttonePin, INPUT);
  pinMode(buttonfPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);
  //digitalWrite(led1, LOW);
  Serial.begin(38400); // Default communication rate of the Bluetooth module
}

void loop() {
  if(Serial.available() >0 ){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
  }
  
  delay(10);
  
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);
  int readingb = digitalRead(buttonbPin);
  int readingc = digitalRead(buttoncPin);
  int readingd = digitalRead(buttondPin);
  int readinge = digitalRead(buttonePin);
  int readingf = digitalRead(buttonfPin);
  
  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited
  // long enough since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  ///////////////////////////////////////////////////////////
  //**Push Button 1
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
    
    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        Serial.write('1'); // Sends '1' to the master to turn on LED
        ledState = !ledState;
      }
    }
  }

//////////////////////////////////////////////////////////
//**Push Button 2
  if (readingb != lastButtonbState) {
    // reset the debouncing timer
    lastDebouncebTime = millis();
  }
  
  if ((millis() - lastDebouncebTime) > debouncebDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
    // if the button state has changed:
    if (readingb != buttonbState) {
      buttonbState = readingb;
      // only toggle the LED if the new button state is HIGH
      if (buttonbState == HIGH) {
        Serial.write('2'); // Sends '1' to the master to turn on LED
        ledState = !ledState;
      }
    }
  }
  
//////////////////////////////////////////////////////
//**Push Button 3
  if (readingc != lastButtoncState) {
    // reset the debouncing timer
    lastDebouncecTime = millis();
  }
  if ((millis() - lastDebouncecTime) > debouncecDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (readingc != buttoncState) {
      buttoncState = readingc;
      // only toggle the LED if the new button state is HIGH
      if (buttoncState == HIGH) {
        Serial.write('3'); // Sends '1' to the master to turn on LED
        ledState = !ledState;
      }
    }
  }
  
///////////////////////////////////
//**Push Button 4
// If the switch changed, due to noise or pressing:
  if (readingd != lastButtondState) {
    // reset the debouncing timer
    lastDebouncedTime = millis();
  }
  if ((millis() - lastDebouncedTime) > debouncedDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
    // if the button state has changed:
    if (readingd != buttondState) {
      buttondState = readingd;

      // only toggle the LED if the new button state is HIGH
      if (buttondState == HIGH) {
        Serial.write('4'); // Sends '1' to the master to turn on LED
        ledState = !ledState;
      }
    }
  }
  
//////////////////////////////////////////////////////////
//**Push Button 5
  if (readinge != lastButtoneState) {
    // reset the debouncing timer
    lastDebounceeTime = millis();
  }
  
  if ((millis() - lastDebounceeTime) > debounceeDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
    // if the button state has changed:
    if (readinge != buttoneState) {
      buttoneState = readinge;
      // only toggle the LED if the new button state is HIGH
      if (buttoneState == HIGH) {
        Serial.write('5'); // Sends '1' to the master to turn on LED
        ledState = !ledState;
      }
    }
  }

//////////////////////////////////////////////////////
//**Push Button 6
  if (readingf != lastButtonfState) {
    // reset the debouncing timer
    lastDebouncefTime = millis();
  }
  
  if ((millis() - lastDebouncefTime) > debouncefDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
    // if the button state has changed:
    if (readingf != buttonfState) {
      buttonfState = readingf;
      // only toggle the LED if the new button state is HIGH
      if (buttonfState == HIGH) {
        Serial.write('6'); // Sends '1' to the master to turn on LED
        ledState = !ledState;
      }
    }
  }
  
///////////////////////////////////
// set the LED:
  digitalWrite(ledPin, ledState);

  // save the reading. Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
  lastButtonbState = readingb;
  lastButtoncState = readingc;
  lastButtondState = readingd;
  lastButtoneState = readinge;
  lastButtonfState = readingf;
}
