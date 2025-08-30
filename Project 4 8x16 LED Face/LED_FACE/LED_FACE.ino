
//unsigned char smile[] = {0x00, 0x00, 0x38, 0x40, 0x40, 0x38, 0x02, 0x02, 0x02, 0x02, 0x38, 0x40, 0x40, 0x38, 0x00, 0x00};
//unsigned char smile[] = {0x00, 0x00, 0x1c, 0x02, 0x02, 0x02, 0x5c, 0x40, 0x40, 0x5c, 0x02, 0x02, 0x02, 0x1c, 0x00, 0x00};
unsigned char smile[] = {0x00, 0x00, 0x38, 0x40, 0x40, 0x38, 0x02, 0x02, 0x02, 0x02, 0x38, 0x40, 0x40, 0x38, 0x00, 0x00};
unsigned char angry[] = {0x00, 0x40, 0x58, 0x40, 0x23, 0x24, 0x0c, 0x08, 0x08, 0x08, 0x2c, 0x27, 0x60, 0x40, 0x58, 0x40};
#define SCL_Pin A5 // Set clock pin to A5
#define SDA_Pin A4 // Set data pin to A4

void setup() {
  // put your setup code here, to run once:
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
  // Clear Matrix Display
  // matrix_display(clear);
}

void loop(){
  matrix_display(smile); //display smile pattern
  //delay(1000);
  //matrix_display(angry);
}
//this function is used for dot matrix display
void matrix_display(unsigned char matrix_value[])
{
IIC_start(); //the function to call the data transmission
IIC_send(0xc0); //Select address

for(int i = 0;i < 16;i++) //Pattern data has 16 bytes
{
IIC_send(matrix_value[i]); //data to convey patterns
}
IIC_end(); //end the transmission of patterns data
IIC_start();
IIC_send(0x8A); //display control, set pulse width to 4/16
IIC_end();
}

// the condition that data transmission starts
void IIC_start()
{
digitalWrite(SCL_Pin,HIGH);
delayMicroseconds(3);
digitalWrite(SDA_Pin,HIGH);
delayMicroseconds(3);
digitalWrite(SDA_Pin,LOW);
delayMicroseconds(3);
}

// Transmit Data
void IIC_send(unsigned char send_data)
{
for(char i = 0;i < 8;i++) //Every character has 8 bits
{
digitalWrite(SCL_Pin,LOW); //pull down the SCL_Pin to change the signal of SDA
delayMicroseconds(3);
if(send_data & 0x01) //1 or 0 of byte is used to set high and low level of SDA_Pin
{
digitalWrite(SDA_Pin,HIGH);
}
else
{
digitalWrite(SDA_Pin,LOW);
}
delayMicroseconds(3);
digitalWrite(SCL_Pin,HIGH); //Pull up SCL_Pin to stop data transmission
delayMicroseconds(3);
send_data = send_data >> 1; //Detect bit by bit, so move the data right by one bit
}
}

// The sign that data transmission ends.
void IIC_end()
{
digitalWrite(SCL_Pin,LOW);
delayMicroseconds(3);
digitalWrite(SDA_Pin,LOW);
delayMicroseconds(3);
digitalWrite(SCL_Pin,HIGH);
delayMicroseconds(3);
digitalWrite(SDA_Pin,HIGH);
delayMicroseconds(3);
}

