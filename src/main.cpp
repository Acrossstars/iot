#include <Arduino.h>
#include <Mouse.h>

void setup()
{
  Mouse.begin();

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop()
{
  delay(1000);

  while (true)
  {
    // read the input on analog pin 0:
    int sensorValue = analogRead(A0);
    // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
    float voltage = sensorValue * (5.0 / 1023.0);
    // print out the value you read:
    Serial.println(voltage);

    Mouse.move(4, 0, 0);
    delay(100);
    Mouse.move(-8, 0, 0);
    delay(100);
    Mouse.move(4, 0, 0);

    delay(5000);
  }
}