#include <Arduino.h>
#include <SoftwareSerial.h>

/* Connect HC-05 TX to Arduino RX and HC-05 RX to Arduino TX */
SoftwareSerial Bluetooth(3, 2); /* RX, TX */

const int pin34 = 4;
bool newline_printed = false;

void setup() 
{  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("Arduino is ready");
 
  Bluetooth.begin(9600);  
  Serial.println("Bluetooth is ready");
  /* Change HC-05 name
  Bluetooth.begin(38400);  
  Bluetooth.println("AT");
  while(Bluetooth.available())
  {
    char ch;
    ch = Bluetooth.read();
    Serial.print(ch);
  }
  delay(1000);
  Bluetooth.println("AT+NAME=ARDUINO_BLE");
  delay(1000);  
  */

}


// the loop function runs over and over again forever
void blinkled() 
{
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(10);                       // wait for a second
}

void loop()
{
  if(Bluetooth.available())
  {  
    char c = Bluetooth.read();
    Serial.print(c);
    blinkled();
  }
 
/* Recieve data from console，and then send to bluetooth
  if(Serial.available())
  {
    char c = Serial.read();
    Serial.write(c);
    Bluetooth.write(c);  
  }
 */
}
