#define ML_Ctrl 4   // Define the direction control pin of B motor
#define ML_PWM 5    // Define the PWM control pin of B motor
#define MR_Ctrl 2   // Define direction control pin of A motor
#define MR_PWM 6    // Define the PWM control pin of a motor

void setup() {
  pinMode(ML_Ctrl, OUTPUT); //define direction control pin of B motor as output
  pinMode(ML_PWM, OUTPUT);  //define PWM control pin of B motor as output
  pinMode(MR_Ctrl, OUTPUT); //define direction control pin of A motor as output. 
  pinMode(MR_PWM, OUTPUT);  //define the PWM control pin of A motor as output
}
bool stop = false; 
void loop() {
  if (stop) return; //  comment return to stop and upload.
  digitalWrite(ML_Ctrl,HIGH); //set the direction control pin of B motor to HIGH
  analogWrite(ML_PWM,200);    //set the PWM control speed of B motor to 200
  digitalWrite(MR_Ctrl,HIGH); //set the direction control pin of A motor to HIGH
  analogWrite(MR_PWM,200);    //set the PWM control speed of A motor to 200

  // Move Forward
  delay(2000);//delay in 2s
  digitalWrite(ML_Ctrl,LOW); // Set the direction control pin of B
  analogWrite(ML_PWM, 200);  // Set the PWM control speed of B motor to 200
  digitalWrite(MR_Ctrl, LOW);// Set the direction control pin of A motor to low
  analogWrite(MR_PWM, 200);  // Set the PWM control speed of A motor to 200

  // Move Backwards
  delay(2000);// delay in 2s
  digitalWrite(ML_Ctrl, LOW);   // Set the direction control pin of B motor to LOW
  analogWrite(ML_PWM, 200);     // Set the PWM control speed of B motor to 200
  digitalWrite(MR_Ctrl,HIGH);   // Set the direction control pin of A motor to HIGH
  analogWrite(MR_PWM,200);      // Set the PWM control speed of A motor to 200

  // Left
  delay(2000);// delay in 2s
  digitalWrite(ML_Ctrl, HIGH);  // Set the direction control pin of B motor to HIGH
  analogWrite(ML_PWM, 200);     // Set the PWM control speed of B motor to 200
  digitalWrite(MR_Ctrl,LOW);    // Set the direction control pin of A motor to LOW
  analogWrite(MR_PWM,200);      // Set the PWM control speed of A motor to 200

  // Right
  delay(2000); //delay in 2s
  analogWrite(ML_PWM,0); //set the PWM control speed of B motor to 0
  analogWrite(MR_PWM,0); //set the PWM control speed of A motor

  //stop
  delay(2000); //delay in 2s
}


