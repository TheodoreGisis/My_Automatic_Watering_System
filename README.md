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

12.
