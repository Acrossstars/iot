#include <Arduino.h>
#include <Mouse.h>
#include <Keyboard.h>

void setup()
{
  Mouse.begin();
  Keyboard.begin();
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

int time = 0;
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
    Serial.print("Analog: ");
    Serial.print(sensorValue);
    Serial.print(", Voltage: ");
    Serial.println(voltage);

    time += 6000;
    
    Serial.print("Time: ");
    Serial.println(time);

    Mouse.move(4, 0, 0);
    delay(100);
    Mouse.move(-8, 0, 0);
    delay(100);
    Mouse.move(4, 0, 0);

        // предел в милисекундах
    if(time > 25000 && voltage > 4)
    {
      long randNumber = random(1, 10);
      // Keyboard.press(KEY_LEFT_ALT); // Command key in Mac, use KEY_LEFT_CTRL for Pc
      Keyboard.press(KEY_LEFT_CTRL); // Command key in Mac, use KEY_LEFT_CTRL for Pc
      delay(100);
      for (long i = 0; i < randNumber; i++)
      {
        Keyboard.press(KEY_TAB);
        delay(100);
      }
      time = 0;
      delay(100);
      Keyboard.releaseAll(); // This is important after every Keyboard.press it will continue to be pressed
    }

    delay(5000);
    // delay(3500);

  }
}