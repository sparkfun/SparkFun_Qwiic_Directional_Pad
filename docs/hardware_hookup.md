In this section, we will go over how to connect to the Qwiic Directional Pad.



### Connecting Via Qwiic

Insert a Qwiic cable between your Arduino microcontroller and the Qwiic Directional Pad. In this case, we used the SparkFun IoT RedBoard - ESP32 Development Board for the Arduino microcontroller. When ready, connect a USB cable to the Arduino to program, power, and view serial messages.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/PRT-26851-Qwiic_Directional_Pad_ESP32_PCA9554_IO_Expander.jpg"><img src="../assets/img/PRT-26851-Qwiic_Directional_Pad_ESP32_PCA9554_IO_Expander.jpg" width="600px" height="600px" alt="IoT RedBoard - ESP32 and Qwiic Directional Pad Connectedvia Qwiic"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>IoT RedBoard - ESP32 and Qwiic Directional Pad Connected via Qwiic</i></td>
    </tr>
  </table>
</div>



### Connecting via PTH

For temporary connections to the PTHs, you could use IC hooks to test out the pins. However, you'll need to solder headers or wires of your choice to the board for a secure connection. You can choose between a combination of [header pins and jumper wires](https://learn.sparkfun.com/tutorials/how-to-solder-through-hole-soldering/all), or [stripping wire and soldering the wire](https://learn.sparkfun.com/tutorials/working-with-wire/all) directly to the board.

<div class="grid cards col-2" markdown>

-   <a href="https://learn.sparkfun.com/tutorials/how-to-solder-through-hole-soldering/all">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/learn_tutorials/5/Soldering_Action-01.jpg"style="width:264px; height:148px; object-fit:contain;" alt="How to Solder: Through Hole Soldering">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/how-to-solder-through-hole-soldering/all">
      <b>How to Solder: Through Hole Soldering</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->

-   <a href="https://learn.sparkfun.com/tutorials/working-with-wire/all">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/0/5/0/0/f/5138de3cce395fbb1b000002.JPG" style="width:264px; height:148px; object-fit:contain;" alt="Working with Wire">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/working-with-wire/all">
      <b>Working with Wire</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
</div>



### Interrupt

For users that want to notify the microcontroller that there is a button press, you could connect the INT pin to one of the Arduino's interrupts. In this case, we connected the Directional Pad's INT pin to IoT RedBoard's pin 4.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/PRT-26851-Qwiic_Directional_Pad_ESP32_PCA9554_IO_Expander_Interrupt.jpg"><img src="../assets/img/PRT-26851-Qwiic_Directional_Pad_ESP32_PCA9554_IO_Expander_Interrupt.jpg" width="600px" height="600px" alt="IoT RedBoard - ESP32 and Qwiic Directional Pad Connected via Qwiic and Interrupt Pin"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>IoT RedBoard - ESP32 and Qwiic Directional Pad Connected via Qwiic and Interrupt Pin</i></td>
    </tr>
  </table>
</div>

!!! note
    Example 3 from the SparkFun I2C Expander Arduino Library uses the IoT RedBoard - ESP32's pin `14` for the interrupt. The example in this tutorial is slightly different and uses pin `4` for the interrupt.
