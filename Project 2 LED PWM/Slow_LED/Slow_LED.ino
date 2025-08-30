int ledPin = 9;     // Define the LED pin at D9
int value;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);  // initialize ledpin as an output
}

void loop() {
  // put your main code here, to run repeatedly:
  for(value = 0; value<255; value=value+1){
    analogWrite(ledPin, value); // LED gradually lights up
    delay(30); // delay 5MS
  }

  for(value = 255; value>0; value=value-1){
    analogWrite(ledPin, value); // LED gradually goes out
    delay(30); // delay 5MS
  }
}
