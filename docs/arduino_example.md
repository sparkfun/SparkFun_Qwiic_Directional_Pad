Now that we have our library and board add-on installed, we can start experimenting with the breakout board. For the scope of this tutorial, we will highlight the example provided in the GitHub hardware repo to get started.



### Upload Arduino Example

From your downloads, open the example labeled as **Example1-ReadButtons.ino**. This example reads the button presses and writes to the non-addressable LED using the PCA9554 I/O I<sup>2</sup>C Expander.

For users using an Arduino microcontroller, select your board in the Tools menu (in our case the **SparkFun ESP32IoT RedBoard**) and the correct Port it enumerated on.

You can also copy or paste the code as shown below. Then click "Upload".

``` c++
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

#include <SparkFun_I2C_Expander_Arduino_Library.h> // Click here to get the library: http://librarymanager/All#SparkFun_I2C_Expander_Arduino_Library

SFE_PCA95XX io; // Defaults to the PCA9554 at I2C address 0x20

int buttonUp = 0;
int buttonDown = 1;
int buttonRight = 2;
int buttonLeft = 3;
int buttonCenter = 4;
int ledBlue = 5;
int ledGreen = 6;
int ledRed = 7;

void setup()
{
  Serial.begin(115200);
  delay(250);
  Serial.println("Qwiic Directional Pad Example");

  Wire.begin();

  // Initialize the PCA9554, default address = 0x20
  if (io.begin() == false) //Device Address, Number of GPIO
  {
    Serial.println("PCA9554 not detected. Please check wiring. Freezing...");
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
  /*io.revert(buttonCenter); //Set to not inverted
  io.revert(ledRed); //Set to not inverted
  io.revert(ledGreen); //Set to not inverted
  io.revert(ledBlue); //Set to not inverted*/

  redOff();
  greenOff();
  blueOff();

  Serial.println("Qwiic Directional Pad online!");
}

void loop()
{
  Serial.print("Button: ");

  if (io.digitalRead(buttonUp) == LOW)
  {
    Serial.print("Up");
    redOn();
    greenOff();
    blueOff();
  }
  else if (io.digitalRead(buttonDown) == LOW)
  {
    Serial.print("Down");
    redOff();
    greenOn();
    blueOff();
  }
  else if (io.digitalRead(buttonLeft) == LOW)
  {
    Serial.print("Left");
    redOn();
    greenOff();
    blueOn();
  }
  else if (io.digitalRead(buttonRight) == LOW)
  {
    Serial.print("Right");
    redOff();
    greenOn();
    blueOn();
  }
  else if (io.digitalRead(buttonCenter) == LOW)
  {
    Serial.print("Center");
    redOn();
    greenOn();
    blueOn();
  }
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
```

After uploading the code, open the [Serial Monitor](https://learn.sparkfun.com/tutorials/terminal-basics) or terminal emulator of your choice with the baud rate set to **115200**. Press on any of the buttons. You will notice a serial output indicating which button was pressed in the Arduino Serial Monitor. Looking to the board, you will notice the LED changing color with respect to the button press.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/"><img src="../assets/img/" width="600px" height="600px" alt="Arduino Serial Output"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>Arduino Serial Output</i></td>
    </tr>
  </table>
</div>
