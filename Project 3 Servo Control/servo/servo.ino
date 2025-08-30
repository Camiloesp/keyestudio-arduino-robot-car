#define servoPin 10   //servo Pin
int pos;    // The angle variable of servo
int pulseWidth; // Pulse width variable of servo
bool initialized = false;
int targetDegree = 90;

void setup() {
  // put your setup code here, to run once:
  pinMode(servoPin, OUTPUT);  // Sets the pin of servo as an output
  procedure(0);               // Sets the angle of servo to 0 degrees
  initialized = true;
}

void loop() {
  // put your main code here, to run repeatedly:
  return;
  if (!initialized) return;
  for(pos=0; pos<=targetDegree; pos+=1){ // From 0 to 180 degrees
    // in steps of 1 degree
    procedure(pos); // Tells servo to go to position in variable 'pos'
    delay(15);      // Controls the rotation speed of servo
  }

  for(pos=targetDegree; pos>=0; pos-=1){ // From 180 to 0 degrees
    // in steps of 1 degree
    procedure(pos); // Tells servo to go to position in variable 'pos'
    delay(15);      // Controls the rotation speed of servo
  }
}

void procedure(int angle){
  pulseWidth = angle * 11 + 500; // Calculate the value of pulse width
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pulseWidth);  // The duration of high level is pulse width
  digitalWrite(servoPin, LOW);
  delay((20-pulseWidth/1000));    // The cycle is 20ms, the low level last for the rest of time
}
