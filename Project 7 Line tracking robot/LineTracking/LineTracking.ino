 #define ML_Ctrl 4 //definedirectioncontrolpinofBmotor
 #define ML_PWM 5  //definePWMcontrolpinofBmotor
 #define MR_Ctrl 2 //definedirectioncontrolpinofAmotor
 #define MR_PWM 6  //definePWMcontrolpinofAmotor

const int sensor_l=11;    //definethepinofleftlinetrackingsensor
const int sensor_c=7;     //definethepinofmiddlelinetrackingsensor
const int sensor_r=8;     //definethepinofrightlinetrackingsensor
int l_val,c_val,r_val;    //definethesevariables

void setup() {
  Serial.begin(9600);       // start serial monitor and set baud rate to 9600

  pinMode(ML_Ctrl,OUTPUT);  // set direction control pin of B motor
  pinMode(ML_PWM,OUTPUT);   // set PWM control pin of B motor to OUTPUT
  pinMode(MR_Ctrl,OUTPUT);  // set direction control pin of A motor to OUTPUT
  pinMode(MR_PWM,OUTPUT);   // set PWM control pin of A motor to OUTPUT

  pinMode(sensor_l,INPUT);  // set the pins of left line tracking sensor to INPUT
  pinMode(sensor_c,INPUT);  // set the pins of center line tracking sensor to INPUT
  pinMode(sensor_r,INPUT);  // set the pins of right line tracking sensor to INPUT
}

void loop() {
  tracking(); //run main program
}

void tracking(){
  l_val = digitalRead(sensor_l);  // Read value of left line tracking sensor
  c_val = digitalRead(sensor_c);  // Read value of center line tracking sensor
  r_val = digitalRead(sensor_r);  // Read value of right line tracking sensor

  if(c_val==1){   // If the state of middle one is 1, which means detecting black line
    front();      // Car goes forward
  }
  else{
    if((l_val==1) && (r_val==0)){   // If only left line tracking sensor detects black trace
      left();                       // Car turns left
    }
    else if((l_val==0) && (r_val==1)){  // If only right line tracking sensor detects black trace
      right();                          // Car turns right
    }
    else{     // If left and right line tracking detect black trace or they don't read
      stop(); // car stops
    }
  }
}

// Defines the status of going forward
void front(){
  Serial.println("Going forward");
  digitalWrite(ML_Ctrl, HIGH);    // Set direction control pin of B motor to HIGH
  analogWrite(ML_PWM, 70);        // Set PWM control speed of B motor to 70
  digitalWrite(MR_Ctrl, HIGH);    // Set direction control pin of A motor to HIGH
  analogWrite(MR_PWM, 70);        // Set PWM control speed of A motor to 70
}

// Define the state of going back
void back(){
  Serial.println("Going back");
  digitalWrite(ML_Ctrl, LOW);    // Set direction control pin of B motor to LOW
  analogWrite(ML_PWM, 200);      // Set PWM control speed of B motor to 200
  digitalWrite(MR_Ctrl, HIGH);   // Set direction control pin of A motor to HIGH
  analogWrite(MR_PWM, 200);      // Set PWM control speed of A motor to 70
}

// Define the state of car turning left
void left(){
  Serial.println("Turn left");
  digitalWrite(ML_Ctrl,LOW);    // set direction control pin of B motor to LOW
  analogWrite(ML_PWM,200);      // set PWM control speed of B motor to 200
  digitalWrite(MR_Ctrl,HIGH);   // set direction control pin of A motor to HIGH level
  analogWrite(MR_PWM,200);      // set PWM control speed of A motor to 200
}

// Define the state of car turning right
void right(){
  Serial.println("Turn right");
  digitalWrite(ML_Ctrl,HIGH); //set direction control pin of B motor to HIGH level
  analogWrite(ML_PWM,200);    //set PWM control speed of Bmotor to200
  digitalWrite(MR_Ctrl,LOW);  //set direction control pin of A motor to LOW
  analogWrite(MR_PWM,200);    //set PWM control speed of A motor to 200
}

//define the state of stop
void stop(){
  Serial.println("Stop");
  analogWrite(ML_PWM,0);//set PWM control speed of B motorto 0
  analogWrite(MR_PWM,0);//set PWM control speed of A motorto 0
}

 