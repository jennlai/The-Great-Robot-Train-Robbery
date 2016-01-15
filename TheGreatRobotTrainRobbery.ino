/*
 * An independent Arduino robot capable of travel, detection 
 * of motion at a specific distance, and release of an action 
 * figure onto a moving train – all single-handedly.
 * 
 * Jennifer Lai
 */

#include <Servo.h> 
Servo myservo;

int val = 0;           // variable to store the distance value read
int analogPin = 3;        // Infrared Sensor (Right lead) connected to analog pin 3
int motorPin = 6;         // Motor connected to analog pin 6
int i = 0;          // servo position in degrees

 
void setup()
{
    pinMode(motorPin, OUTPUT);
    myservo.attach(9);        // servo attached to analog pin 9
    Serial.begin(9600);       // setup serial
}

void loop()
{
    // if (digitalRead(A0) == HIGH)
    // {
    while (i < 1)
    {
    delay(2000);        // wait 2 seconds
    digitalWrite(motorPin, 220);
    delay(5000);        // wait 5 seconds
    digitalWrite(motorPin, LOW);
    i++;
    }
  
    val = analogRead(A0);       // read distance
    Serial.println(val);      //150 // debug value

    if (val > 180)        // if distance is greater than 180
    { 
    myservo.write(180);       // servo spins 180 degrees
    }
    // }
}

