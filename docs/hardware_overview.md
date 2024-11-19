In this section, we will highlight the hardware and pins that are broken out on the SparkFun Qwiic Directional Pad. For more information, check out our [Resources and Going Further](../resources/) on the components used on the breakout board.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/"><img src="../assets/img/" width="600px" height="600px" alt="Top View"></a></td>
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/"><img src="../assets/img/" width="600px" height="600px" alt="Bottom View"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>Top View</i></td>
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>Bottom View</i></td>
    </tr>
  </table>
</div>



### Power

To power the board, you will need 3.3V. You can connect a Qwiic cable to Qwiic connector on either side of the board or you can solder directly to the PTHs. Below are the power pins that are broken out on the edge of the board.

* **3V3** &mdash; This pin is the voltage input for the board. The recommended input voltage for this pin is 3.3V.
* **GND** &mdash; Of course, is the common, ground voltage (0V reference) for the system.



<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/"><img src="../assets/img/" width="600px" height="600px" alt="Power, Ground, Qwiic Connector Highlighted"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>Power, Ground, and Qwiic Connector Highlighted</i></td>
    </tr>
  </table>
</div>



### Qwiic and I<sup>2</sup>C

The board includes two horizontal Qwiic connectors to connect Qwiic-enabled I<sup>2</sup>C devices. However, the board still breaks out 0.1"-spaced pins for users who prefer a soldered connection.

* **SCL** &mdash; I<sup>2</sup>C clock on the PCA9554.
* **SDA** &mdash; I<sup>2</sup>C data on the PCA9554.
* **3.3V** &mdash; This pin is the voltage input for the board. The recommended input voltage for this pin is 3.3V.
* **GND** &mdash; Of course, is the common, ground voltage (0V reference) for the system.


<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/"><img src="../assets/img/" width="600px" height="600px" alt="Qwiic Connector, I2C, and PCA9554 Highlighted"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>Qwiic Connector, I<sup>2</sup>C, and PCA9554 Highlighted</i></td>
    </tr>
  </table>
</div>


Connected on the I<sup>2</sup>C bus is the TI PCA9554 8-Bit I<sup>2</sup>C I/O Expander (the bigger 16-pin IC located at the center of the board). This IC is used to read the 5-way directional pad or write to the non-addressable RGB LED. Its I<sup>2</sup>C device's 7-bit address is **0x20** by default. By adjusting the jumpers on the back of the board, the alternative address can be any value between _0x21_ to _0x27_.



### Interrupt



### PCA9554 and GPIO Pins

The PCA9554 is a 8-bit GPIO IC that enables users to toggle the following GPIO pins through I<sup>2</sup>C. The I<sup>2</sup>C address of the PCA9554 is **0x20**.

* **GPIO0** &mdash; GPIO0 is connected to the 5-way directional pad's UP button. A 10k&ohm; pull-up resistor is connected.
* **GPIO1** &mdash; GPIO1 is connected to the 5-way directional pad's DOWN button. A 10k&ohm; pull-up resistor is connected.
* **GPIO2** &mdash; GPIO3 is connected to the 5-way directional pad's RIGHT button. A 10k&ohm; pull-up resistor is connected.
* **GPIO3** &mdash; GPIO4 is connected to the 5-way directional pad's LEFT button. A 10k&ohm; pull-up resistor is connected.
* **GPIO4** &mdash; GPIO4 is connected to the 5-way directional pad's CENTER button. A 10k&ohm; pull-up resistor is connected.
* **GPIO5** &mdash; GPIO5 is connected to the blue LED. The LED can be disconnected if users decide to use a different input to the GPIO5's PTH.
* **GPIO6** &mdash; GPIO6 is connected to the green LED. The LED can be disconnected if users decide to use a different input to the GPIO6's PTH.
* **GPIO7** &mdash; GPIO7 is connected to the red LED. The LED can be disconnected if users decide to use a different input to the GPIO7's PTH..

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/"><img src="../assets/img/" width="600px" height="600px" alt="PCA9554 and GPIO Pins Highlighted"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>PCA9554 and GPIO Pins Highlighted</i></td>
    </tr>
  </table>
</div>



### LEDs

The board includes a power LED to indicate when power is available on the 3.3V pins. There is also a non-addressable RGB LED to indicate what button is being pressed. Both can be disabled with the jumpers on the back of the board.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/"><img src="../assets/img" width="600px" height="600px" alt="LEDs Highlighted"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>LEDs Highlighted</i></td>
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
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/"><img src="../assets/img/" width="600px" height="600px" alt="Jumpers Highlighted"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>Jumpers Highlighted</i></td>
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
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><a href="../assets/img/"><img src="../assets/img/" width="600px" height="600px" alt="Board Dimensions"></a></td>
    </tr>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle; border: solid 1px #cccccc;"><i>Board Dimensions</i></td>
    </tr>
  </table>
</div>
