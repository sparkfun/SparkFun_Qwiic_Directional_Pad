/*
  Using the PCA9554 with Interrupts
  Modified by: Ho Yun "Bobby" Chan
  Orignally Written By: Nathan Seidle
  SparkFun Electronics
  Date: November 22nd, 2024

  License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

  Feel like supporting our work? Buy a board from SparkFun!
  https://www.sparkfun.com/products/17047 - Qwiic GPIO
  https://www.sparkfun.com/products/26784 - Qwiic Power Switch
  https://www.sparkfun.com/products/26851 - Qwiic Directional Pad

  This example demonstrates how to use interrupts to check for new pin changes on the Qwiic Directional Pad
  and turn on/off the RGB LED channels

  Hardware Connections:
  Plug the Qwiic Directional Pad into a Qwiic enabled board (SparkFun Thing Plus C, RedBoard, RedBoard IoT, etc)
  If you don't have a platform with a Qwiic connection use the SparkFun Qwiic Breadboard Jumper (https://www.sparkfun.com/products/17912)
  Connect a wire from a GPIO pin that is interrupt capable to the !INT pin on the Qwiic Directional Pad
  Open the serial monitor at 115200 baud to see the output.
*/

#include <SparkFun_I2C_Expander_Arduino_Library.h>  // Click here to get the library: http://librarymanager/All#SparkFun_I2C_Expander_Arduino_Library

//SFE_PCA95XX io(PCA95XX_PCA9534); // Create a PCA9534 - Has interrupt pin
//SFE_PCA95XX io(PCA95XX_PCA9536); // Create a PCA9536 - Has optional interrupt pin
//SFE_PCA95XX io(PCA95XX_PCA9537); // Create a PCA9537 - Has interrupt pin
SFE_PCA95XX io(PCA95XX_PCA9554);  // Create a PCA9554 - Has interrupt pin
//SFE_PCA95XX io(PCA95XX_PCA9556); // Create a PCA9556 - No interrupt pin / Not compatible with this code
//SFE_PCA95XX io(PCA95XX_PCA9557); // Create a PCA9557 - No interrupt pin / Not compatible with this code

int buttonUp = 0;
int buttonDown = 1;
int buttonRight = 2;
int buttonLeft = 3;
int buttonCenter = 4;
int ledBlue = 5;
int ledGreen = 6;
int ledRed = 7;

int gpioExpander_interrupt = 4;  //INT of PCA9554 is connected to ESP pin 4. Goes low when an input pin changes.

bool buttonPressed = false;

//Interrupt that is called when INT pin goes low
void IRAM_ATTR gpioExpanderISR() {
  buttonPressed = true;
}

void setup() {
  Serial.begin(115200);
  delay(250);
  Serial.println("Qwiic Directional Pad Example");

  Wire.begin();

  // Initialize the PCA95xx with its default I2C address
  if (io.begin() == false) {
    Serial.println("PCA9554 not detected. Please check wiring. Freezing...");
    while (1)
      ;
  }
  pinMode(gpioExpander_interrupt, INPUT_PULLUP);

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

  attachInterrupt(gpioExpander_interrupt, gpioExpanderISR, CHANGE);
}

void loop() {
  //Wait for interrupt to fire
  if (buttonPressed == true) {
    Serial.println("Interrupt! ");
    //Get all the pins in one read to save time
    uint8_t currentState = io.getInputRegister();
    // Pins are pulled high so when we see low, button is being pressed
    if ((currentState & (1 << buttonUp)) == 0) {
      Serial.println("Up");

      //RED
      redOn();
      greenOff();
      blueOff();
    } else if ((currentState & (1 << buttonDown)) == 0) {
      Serial.println("Down");

      //GREEN
      redOff();
      greenOn();
      blueOff();
    } else if ((currentState & (1 << buttonLeft)) == 0) {
      Serial.println("Left");

      //MAGENTA
      redOn();
      greenOff();
      blueOn();
    } else if ((currentState & (1 << buttonRight)) == 0) {
      Serial.println("Right");

      //CYAN
      redOff();
      greenOn();
      blueOn();
    } else if ((currentState & (1 << buttonCenter)) == 0) {
      Serial.println("Center");

      //WHITE
      redOn();
      greenOn();
      blueOn();
    } else {
      Serial.println(" None");

      //OFF
      redOff();
      greenOff();
      blueOff();
    }

    buttonPressed = false;
  }
}



void redOn() {
  io.digitalWrite(ledRed, LOW);
}
void redOff() {
  io.digitalWrite(ledRed, HIGH);
}
void greenOn() {
  io.digitalWrite(ledGreen, LOW);
}
void greenOff() {
  io.digitalWrite(ledGreen, HIGH);
}
void blueOn() {
  io.digitalWrite(ledBlue, LOW);
}
void blueOff() {
  io.digitalWrite(ledBlue, HIGH);
}
