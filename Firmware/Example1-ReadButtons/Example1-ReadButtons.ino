/*
  Using the Qwiic Directional Pad
  By: Nathan Seidle
  SparkFun Electronics
  Date: October 8th, 2024

  License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

  Feel like supporting our work? Buy a board from SparkFun!
  https://www.sparkfun.com/products/14733

  This example demonstrates how to use pinMode and digitalRead/Write to read the directional pad and turn
  on/off the RGB LED channels.

  Hardware Connections:
  Plug the Qwiic board to your Arduino/ESP32 or other
  Press the buttons
  Watch each LED turn on one-at-a-time
*/

#include <SparkFun_PCA9536_Arduino_Library.h> //Click here:

PCA9536 io;

int buttonUp = 0;
int buttonDown = 1;
int buttonRight = 2;
int buttonLeft = 3;
int buttonCenter = 4;
int ledRed = 5;
int ledGreen = 6;
int ledBlue = 7;

void setup()
{
  Serial.begin(115200);
  delay(250);
  Serial.println("Qwiic Directional Pad Example");

  Wire.begin();

  // Initialize the PCA9557, default address = 0x18
  if (io.begin(0x18, 8) == false) //Device Address, Number of GPIO
  {
    Serial.println("PCA9557 not detected. Please check wiring. Freezing...");
    while (1)
      ;
  }

  io.pinMode(buttonUp, INPUT);
  io.pinMode(buttonDown, INPUT);
  io.pinMode(buttonLeft, INPUT);
  io.pinMode(buttonRight, INPUT);
  io.pinMode(buttonCenter, INPUT);
  io.pinMode(ledRed, OUTPUT);
  io.pinMode(ledGreen, OUTPUT);
  io.pinMode(ledBlue, OUTPUT);

  //By default, on the PA9557, IO 4567 are inverted
  io.revert(buttonCenter); //Set to not inverted
  io.revert(ledRed); //Set to not inverted
  io.revert(ledGreen); //Set to not inverted
  io.revert(ledBlue); //Set to not inverted

  redOff();
  greenOff();
  blueOff();

  Serial.println("Qwiic Directional Pad online!");
}

void loop()
{
  Serial.print("Buttons: ");

  if (io.digitalRead(buttonUp) == LOW)
  {
    Serial.print(" Up");
    redOn();
    greenOff();
    blueOff();
  }
  else if (io.digitalRead(buttonDown) == LOW)
    Serial.print(" Down");
  else if (io.digitalRead(buttonLeft) == LOW)
    Serial.print(" Left");
  else if (io.digitalRead(buttonRight) == LOW)
    Serial.print(" Right");
  else if (io.digitalRead(buttonCenter) == LOW)
    Serial.print(" Center");
  else
  {
    Serial.print(" None");
    redOff();
    greenOff();
    blueOff();
  }
  Serial.println();

  delay(100);
}

void redOn()
{
  io.digitalWrite(ledRed, LOW);
}
void redOff()
{
  io.digitalWrite(ledRed, HIGH);
}
void greenOn()
{
  io.digitalWrite(ledGreen, LOW);
}
void greenOff()
{
  io.digitalWrite(ledGreen, HIGH);
}
void blueOn()
{
  io.digitalWrite(ledBlue, LOW);
}
void blueOff()
{
  io.digitalWrite(ledBlue, HIGH);
}
