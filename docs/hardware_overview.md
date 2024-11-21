In this section, we will highlight the hardware and pins that are broken out on the SparkFun Qwiic Directional Pad. For more information, check out our [Resources and Going Further](../resources/) on the components used on the breakout board.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/PRT-26851_Qwiic_Directional_Pad_Top.jpg"><img src="../assets/img/PRT-26851_Qwiic_Directional_Pad_Top.jpg" width="600px" height="600px" alt="Top View"></a></td>
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/PRT-26851_Qwiic_Directional_Pad_Bottom.jpg"><img src="../assets/img/PRT-26851_Qwiic_Directional_Pad_Bottom.jpg" width="600px" height="600px" alt="Bottom View"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>Top View</i></td>
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>Bottom View</i></td>
    </tr>
  </table>
</div>



### Power

To power the board, you will need **3.3V**. You can connect a Qwiic cable to Qwiic connector on either side of the board or you can solder directly to the PTHs. Below are the power pins that are broken out on the edge of the board.

* **3V3** &mdash; This pin is the voltage input for the board. The recommended input voltage for this pin is 3.3V.
* **GND** &mdash; Of course, is the common, ground voltage (0V reference) for the system.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
      <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/PRT-26851_Qwiic_Directional_Pad_Top_Power_Ground.jpg"><img src="../assets/img/PRT-26851_Qwiic_Directional_Pad_Top_Power_Ground.jpg" width="600px" height="600px" alt="Power and Ground Highlighted - Top View"></a></td>
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/PRT-26851_Qwiic_Directional_Pad_Top_Power_Ground.jpg"><img src="../assets/img/PRT-26851_Qwiic_Directional_Pad_Bottom_Power_Ground.jpg" width="600px" height="600px" alt="Power, Ground, and Qwiic Connector Highlighted - Bottom View"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
      <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>Power and Ground Highlighted - Top View</i></td>
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>Power, Ground, and Qwiic Connector Highlighted - Bottom View</i></td>
    </tr>
  </table>
</div>



### 5-Way Directional Pad

A low profile 5-way directional pad is populated on the top side of the board. These buttons are small! We recommend using your fingernail when pressing down on a button. Each pad includes a momentary push button that is read by the PCA9554 8-bit I<sup>2</sup>C I/O expander that is populated on the bottom of the board.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
      <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/PRT-26851_Qwiic_Directional_Pad_Top_5-Way_Directional_Pad_Buttons_Switches.jpg"><img src="../assets/img/PRT-26851_Qwiic_Directional_Pad_Top_5-Way_Directional_Pad_Buttons_Switches.jpg" width="600px" height="600px" alt="5-Way Directional Pad Highlighted - Top View"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
      <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>5-Way Directional Pad Highlighted - Top View</i></td>
    </tr>
  </table>
</div>

!!! note
    You can only press one button at a time! For example, if the UP button is pressed down, it will only register the UP button being pressed down. Once the UP button is released, the board will be able to read another button press.



### PCA9554 8-bit I<sup>2</sup>C I/O Expander

The TI PCA9554 that is populated on the bottom side of the board is an 8-bit I<sup>2</sup>C I/O expander that enables users to read and write to the following GPIO pins through I<sup>2</sup>C. It is used to read the 5-way directional pad or write to the non-addressable RGB LED. The I<sup>2</sup>C address of the PCA9554 is set to **0x20** by default. By adjusting the jumpers on the back of the board, the alternative address can be any value between _0x21_ to _0x27_.

* **GPIO0** &mdash; GPIO0 is connected to the 5-way directional pad's UP button. A 10k&ohm; pull-up resistor is connected.
* **GPIO1** &mdash; GPIO1 is connected to the 5-way directional pad's DOWN button. A 10k&ohm; pull-up resistor is connected.
* **GPIO2** &mdash; GPIO3 is connected to the 5-way directional pad's RIGHT button. A 10k&ohm; pull-up resistor is connected.
* **GPIO3** &mdash; GPIO4 is connected to the 5-way directional pad's LEFT button. A 10k&ohm; pull-up resistor is connected.
* **GPIO4** &mdash; GPIO4 is connected to the 5-way directional pad's CENTER button. A 10k&ohm; pull-up resistor is connected.
* **GPIO5** &mdash; GPIO5 is connected to the blue LED. The LED can be disconnected if users decide to use a different input to the GPIO5's PTH.
* **GPIO6** &mdash; GPIO6 is connected to the green LED. The LED can be disconnected if users decide to use a different input to the GPIO6's PTH.
* **GPIO7** &mdash; GPIO7 is connected to the red LED. The LED can be disconnected if users decide to use a different input to the GPIO7's PTH.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
      <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/PRT-26851_Qwiic_Directional_Pad_Top_PCA9554_IO_I2C_Expander_PTH.jpg"><img src="../assets/img/PRT-26851_Qwiic_Directional_Pad_Top_PCA9554_IO_I2C_Expander_PTH.jpg" width="600px" height="600px" alt="PCA9554 Highlighted - Top View"></a></td>
      <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/PRT-26851_Qwiic_Directional_Pad_Bottom_PCA9554_IO_I2C_Expander.jpg"><img src="../assets/img/PRT-26851_Qwiic_Directional_Pad_Bottom_PCA9554_IO_I2C_Expander.jpg" width="600px" height="600px" alt="PCA9554 Highlighted - Bottom View"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;" colspan=2"><i>PCA9554 and Some GPIO Pins Highlighted<br />Top and Bottom View</i></td>
    </tr>
  </table>
</div>



### Qwiic and I<sup>2</sup>C

The board includes two horizontal Qwiic connectors to connect to other Qwiic-enabled I<sup>2</sup>C devices. However, the board still breaks out 0.1"-spaced pins for users who prefer a soldered connection.

* **SCL** &mdash; I<sup>2</sup>C clock on the PCA9554.
* **SDA** &mdash; I<sup>2</sup>C data on the PCA9554.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/PRT-26851_Qwiic_Directional_Pad_Top_I2C_PTH.jpg"><img src="../assets/img/PRT-26851_Qwiic_Directional_Pad_Top_I2C_PTH.jpg" width="600px" height="600px" alt="Qwiic Connector, I2C, and PCA9554 Highlighted"></a></td>
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/PRT-26851_Qwiic_Directional_Pad_Bottom_Qwiic_I2C_PTH.jpg"><img src="../assets/img/PRT-26851_Qwiic_Directional_Pad_Bottom_Qwiic_I2C_PTH.jpg" width="600px" height="600px" alt="Qwiic Connector, I2C, and PCA9554 Highlighted"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>Qwiic Connector, I<sup>2</sup>C, and PCA9554 Highlighted</i></td>
    </tr>
  </table>
</div>

As explained in the previous section, the I<sup>2</sup>C address of the PCA9554 is set to **0x20** by default. By adjusting the jumpers on the back of the board, the alternative address can be any value between _0x21_ to _0x27_.



### Interrupt

The interrupt pin labeled as INT is for users that want to notify a microcontroller that there is a button being pressed down on the 5-way directional pad. This pin is active low.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
      <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/PRT-26851_Qwiic_Directional_Pad_Top_Interrupt.jpg"><img src="../assets/img/PRT-26851_Qwiic_Directional_Pad_Top_Interrupt.jpg" width="600px" height="600px" alt="Interrupt Highlighted - Top View"></a></td>
      <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/PRT-26851_Qwiic_Directional_Pad_Bottom_Interrupt.jpg"><img src="../assets/img/PRT-26851_Qwiic_Directional_Pad_Bottom_Interrupt.jpg" width="600px" height="600px" alt="Interrupt Highlighted  - Bottom View"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;" colspan="2"><i>Interrupt Highlighted - Top and Bottom View</i></td>
    </tr>
  </table>
</div>



### LEDs

The board includes two LEDs on the top and bottom of the board. Both can be disabled with the jumpers on the back of the board.

* **STAT** &mdash; The status LED is a non-addressable RGB LED that is used to indicate which button is being pressed on the 5-way directional pad. While this is populated on the bottom of the board, it will light up through the hole toward the top side of the board.
* **PWR** &mdash; On the bottom side of the board, the power LED indicates when power is available on 3.3V.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
      <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/PRT-26851_Qwiic_Directional_Pad_Top_LEDs.jpg"><img src="../assets/img/PRT-26851_Qwiic_Directional_Pad_Top_LEDs.jpg" width="600px" height="600px" alt="LEDs Highlighted"></a></td>
      <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/PRT-26851_Qwiic_Directional_Pad_Bottom_LEDs.jpg"><img src="../assets/img/PRT-26851_Qwiic_Directional_Pad_Bottom_LEDs.jpg" width="600px" height="600px" alt="LEDs Highlighted"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;" colspan="2"><i>LEDs Highlighted Top and Bottom View</i></td>
    </tr>
  </table>
</div>



### Jumpers

!!!note
    If this is your first time working with jumpers, check out the [How to Work with Jumper Pads and PCB Traces](https://learn.sparkfun.com/tutorials/how-to-work-with-jumper-pads-and-pcb-traces/all) tutorial for more information.

The back of the board includes jumpers to configure the board.

* **I<sup>2</sup>C** &mdash; By default, this three-pad jumper is closed. The three way jumper labeled I<sup>2</sup>C connects 3.3V to two 2.2k&ohm; pull-up resistors and to the I<sup>2</sup>C data and clock lines. If multiple devices are connected to the bus with the pull-up resistors enabled, the parallel equivalent resistance will create too strong of a pull-up for the bus to operate correctly. As a general rule of thumb, [disable all but one pair of pull-up resistors](https://learn.sparkfun.com/tutorials/i2c/all#i2c-at-the-hardware-level) if multiple devices are connected to the bus.
* **LED OUT** &mdash; By default, this jumper connects the LED to the output's 3.3V pin. Cutting this trace disables the LED.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/PRT-26851_Qwiic_Directional_Pad_Bottom_Jumpers.jpg"><img src="../assets/img/PRT-26851_Qwiic_Directional_Pad_Bottom_Jumpers.jpg" width="600px" height="600px" alt="Jumpers Highlighted - Bottom View"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>Jumpers Highlighted<br />Bottom View</i></td>
    </tr>
  </table>
</div>



### 3D Model

A 3D model of the board and components was exported to a STEP file using KiCad.

<!-- Import the component -->
<script type="module" src="https://ajax.googleapis.com/ajax/libs/model-viewer/3.5.0/model-viewer.min.js"></script>

<div style="text-align: center;">
    <model-viewer src="../assets/3d_model/SparkFun_Qwiic_Directional_Pad_3D_Model.glb" camera-controls poster="../assets/3d_model/SparkFun_Qwiic_Directional_Pad_3D_Image.png" environment-image="legacy" shadow-intensity="1.58" exposure="0.64" shadow-softness="0.24" tone-mapping="neutral" camera-orbit="-46.67deg 57.14deg 153.3m" field-of-view="30deg" style="width: 750px; height: 500px;">
    </model-viewer>
</div>
<br />
<div style="text-align: center">
    <a href="../assets/3d_model/SparkFun_Qwiic_Directional_Pad_3D_Model.step" target="stp_file" class="md-button">Click Here for the STEP File</a>
</div>



### Board Dimensions

The board is 1.0" x 1.0" (25.4mm x 25.4mm). There are 2x mounting holes. You can use 4-40 standoffs to mount the board to a panel or enclosure.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/SparkFun_Qwiic_Directional_Pad-User_Board_Dimensions.png"><img src="../assets/img/SparkFun_Qwiic_Directional_Pad-User_Board_Dimensions.png" width="600px" height="600px" alt="Board Dimensions"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>Board Dimensions</i></td>
    </tr>
  </table>
</div>
