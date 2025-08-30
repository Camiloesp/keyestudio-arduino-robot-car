int L_pin = 11; //pins of left line tracking sensor
int M_pin = 7; //pins of middle line tracking sensor
int R_pin = 8; //pins of right line tracking sensor
int val_L,val_R,val_M;// define these variables

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 bits per second
  pinMode(L_pin, INPUT);  // make the L_pin as an input
  pinMode(M_pin, INPUT);  // make the M_pin as an input
  pinMode(R_pin, INPUT);  // make the R_pin as an input
  pinMode(9, OUTPUT);

  
}

void loop() {
  val_L = digitalRead(L_pin); // Read the L_pin
  val_R = digitalRead(R_pin); // Read the R_pin
  val_M = digitalRead(M_pin); // Read the M_pin
  Serial.print("Left:");
  Serial.print(val_L);
  Serial.print("Middle:");
  Serial.print(val_M);
  Serial.print("Right:");
  Serial.println(val_R);
  //delay(500); // Delay in between reads for stability.

  // Left sensor
  if (val_L == HIGH)  // If left line tracking detects signals
  {
    digitalWrite(9, LOW); // LED is off
  }
  else // If left line tracking doesn't detects signals
  {
    digitalWrite(9, HIGH); // LED is on
    delay(2000);
  }

  // Right sensor
  if (val_R == HIGH)//if right line tracking sensor detects signals
  {
    digitalWrite(9, LOW);//LED is off
  }
  else
  {
    digitalWrite(9, HIGH);//LED lights up
    delay(2000);
  }

  // Middle sensor
  if (val_M == HIGH)//if middle line tracking sensor detects signals
  {
    digitalWrite(9, LOW);//LED is off
  }
  else//if middle line tracking sensor doesn’t detect signals
  {
    digitalWrite(9, HIGH);//LED lights up
    delay(2000);
  }
}
