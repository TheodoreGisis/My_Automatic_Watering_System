# My_Automatic_Watering_System

## GENERAL
This is an automatic plant watering system.Arduino Uno board has used as the main "brain" of our system and soil moisture sensor has used to collect the necessary data from the ground.Arduino is responsible to check the data and control the usage of the water pump.The water pump has two states, open and closed.When the soil moisture detects that the ground is too dry, then the Arduino is responsible to enable the water pump(open state) and watering for 5 seconds.After that Arduino is also responsible to disaple the water pump until the ground is detected as dry again(close state).

## REQUIREMENTS

* Arduino Uno board
* 1 or 2 soil moisture sensors
* Oled character display module 16 x 2 
* Red and blue leds
* Ultrasonic sensor
* Breadboard
* 330Ω resistors
* Relay
* Water pump
* Pressure Sensor BMP280
* 12Volt and 5Volt adapter

## CONNECTION
1.Connect the relay's Vcc to 5Volt.

2.Connect the relay's ground to the negative rail of the breadboard.

3.Connect relay's IN pin to Pin 8 in Arduino

4.Connect red wire (+) of the pump to the C (Common terminal) pin of the relay.

5.Connect the black wire of the pump and connect to the adapter on minus pin (-).

6.Take a jumper wire and connect to the plus pin of the adapter and connect with NO (Normally open 120–240V terminal) pin on Relay.

7.Connect the ground and the Vcc pins of the Ultrasonic sensor in breadboard.

8.Connect the trig pin of the Ultrasonic sensor on pin 9 of Arduino and echo pin on 13.

9.Connect the Vcc and the ground of the soil moisture sensor on the breadboard.

10.Connect moisture's A0 pin on the A0 analog pin of the Arduino.

11.Connect the Vcc and the ground pins of BMP280 Barometric.

12.Connect BMP280's SCL pin on A5 pin of the Arduino(Remember that A5 analog pin is the SCL pin of arduino).

13.Connect BMP280's SDA pin on A4 pin of the Arduino (Remember that A4 analog pin is the SDA pin of arduino).

14.Connect one 330Ω resistor in series with one Red led and connect the edge on the 7 pin of Arduino.

15.Connect one 330Ω resistor in series with one Blue led and connect the edge on the 10 pin of Arduino.

16.For the LCD display Connect:

* D4 -> PIN 5 
* D5 -> PIN 4
* D6 -> PIN 3
* D7 -> PIN 2
* E -> PIN 11
* Rs ->PIN 12
* A-> 5Volts
* K-> Ground
* VDD->5Volts
* Vss->Ground
* V0->PIN 6
* RW ->Ground


## CIRCUIT

p align="center">
  <img width="430" height="470" src="https://github.com/TheodoreGisis/WallFollowingRobot/blob/main/Robot/ROBOT.jpg" >
</p>
