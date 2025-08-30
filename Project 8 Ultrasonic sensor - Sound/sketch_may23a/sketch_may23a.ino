
int trigPin = 12; // Trigger
int echoPin = 13; // Echo
long duration,cm, inches;

void setup() {
  // Serial port begin
  Serial.begin(9600);

  // Define input and outputs
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  return;
  // Sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse.
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  // Read the signal from the sensor: a HIGH pulse whose duration is the time (in microseconds)
  // from the sending of the ping to the reception of its echo off of an object.
  duration=pulseIn(echoPin,HIGH);
  // Serial.print("Duration: ");
  // Serial.println(duration);

  // Convert the time into a distance
  cm=(duration/2)/29.1;     //Divideby29.1ormultiplyby0.0343
  inches=(duration/2)/74;   //Divideby74ormultiplyby0.0135

  // Serial.print(inches);
  // Serial.print("in, ");
  // Serial.print(cm);
  // Serial.print("cm");
  // Serial.println();
  delay(50);
  if(cm>=2&&cm<=10)
    digitalWrite(9,HIGH);
  else
    digitalWrite(9,LOW);
}
