/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://docs.arduino.cc/hardware/

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Blink/
*/

/*Set the 90-degree code,Copy the code and upload it to the development
board. The steering gear connected to port D9 will rotate to 90 ° */
#define servoPin 9 //servo Pin
int pos; //the angle variable of servo
int pulsewidth; // pulse width variable of servo

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(LED_BUILTIN, OUTPUT);

  // keep the servo motor at the correct angle
  //pinMode(servoPin, OUTPUT); //set servo pin to OUTPUT
  //procedure(0); //set the angle of servo to 0°

  // Test LED
  pinMode(9, OUTPUT); // Initialize digital pin 3 as an output
}

// the loop function runs over and over again forever
void loop() {
  /*
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
  */
  //procedure(90); // tell servo to go to position in variable 90 degrees

  // LED Test
  digitalWrite(9, HIGH); // Turns LED on (High is the voltage level)
  delay(100); // wait for a second
  digitalWrite(9, LOW); // Turns LED off (Low is the voltage level)
  delay(100); // wait for a second
}

// function to control servo
void procedure(int myangle) {
  pulsewidth = myangle * 11 + 500; //calculate the value of pulse width
  digitalWrite(servoPin,HIGH);
  delayMicroseconds(pulsewidth); //The duration of high level is pulse width
  digitalWrite(servoPin,LOW);
  delay((20 - pulsewidth / 1000)); // the cycle is 20ms, the low level last for the rest of time
}