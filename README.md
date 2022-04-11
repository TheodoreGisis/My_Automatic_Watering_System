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
