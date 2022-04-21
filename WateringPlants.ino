#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include <LiquidCrystal.h>

int Contrast=75;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)
#define water_ms 3000

Adafruit_BMP280 bmp;

//PINS SETUP
const int trigPin = 9;
const int echoPin = 13;
int relay = 8; 
int sensor = A0;
int sensor2 = A1;
int sensorValue2;
int sensorValue;
int RedLed = 7;
int BlueLed = 10;
long duration;
float water;

void setup() {

  Serial.begin(9600);
    while ( !Serial ) delay(100);   
  Serial.println(F("BMP280 test"));
  unsigned status;

  status = bmp.begin();
  if (!status) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
                      "try a different address!"));
    Serial.print("SensorID was: 0x"); Serial.println(bmp.sensorID(),16);
    Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
    Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
    Serial.print("        ID of 0x60 represents a BME 280.\n");
    Serial.print("        ID of 0x61 represents a BME 680.\n");
    while (1) delay(10);
  }
  
   bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     
                  Adafruit_BMP280::SAMPLING_X2,     
                  Adafruit_BMP280::SAMPLING_X16,    
                  Adafruit_BMP280::FILTER_X16,      
                  Adafruit_BMP280::STANDBY_MS_500); 


  analogWrite(6,Contrast);
  lcd.begin(16, 2);

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(BlueLed,OUTPUT);
  pinMode(relay,OUTPUT);
  pinMode(RedLed,OUTPUT);
  pinMode(sensor , INPUT);
  pinMode(sensor2,INPUT);
  lcd.print("***HELLO***");
  delay(1000);
}

void loop() {
  
  lcd.setCursor(0, 0);
  sensorValue = analogRead(sensor); //READING MOISTURE SENSOR VALUES
  sensorValue2 = analogRead(sensor2);
  delay(500);
  Serial.println(sensorValue); 
  Serial.print(sensorValue2);
  
  
  if(sensorValue <500){ //IF THE VALUE IS UNDER 500 THEN WE NEED TO STOP WATERING 
  digitalWrite(RedLed,LOW);
  digitalWrite(relay,LOW);

  }
  //WE DON'T TAKE VALUES ABOVE 1020 BECAUSE THEY ARE NOT VALID
  else if(sensorValue >820 && sensorValue<1020 && sensorValue2 >820 && sensorValue2 <1020){ //IF THE VALUE OF SENSOR ONE  IS OVER 820 AND THE VALUE OF SENSOR 2 OVER 820 THEN WE NEED TO START WATERING
    digitalWrite(RedLed,HIGH);
    digitalWrite(relay,HIGH);
    delay(2000);
    digitalWrite(relay,LOW);
  }
  else{ //IN OTHER CASE AGAIN STOP WATERING
      digitalWrite(RedLed,LOW);
      digitalWrite(relay,LOW);
  }
  
//CALLING THE FUNCTIONS
  print_Temperature();

  Water_tank_value();

  print_LCD(sensorValue,sensorValue2);

 
}

//-------------------FUNCTIONS-------------------

float Water_tank_value(){ //IN THIS FUNCTION WE MESURE HOW MUCH WATER DO WE HAVE IN OUR TANK
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);
  
  water = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(water);  
  
  
  if(water<4.5){ //IF THE WATER IS UNDER 4.5cm THEN WE BLUE LED IS ON AS A NOTIFICATION
    digitalWrite(BlueLed, HIGH);
    lcd.clear();
    //delay(2000);
    lcd.setCursor(0,0);
    lcd.print("Not enough Water"); //PRINTING THAT WE DON'T HAVE ENOUGH WATER
    delay(1000);
  }
  else{
    digitalWrite(BlueLed,LOW); //ELSE TURN OFF THE BLUE LED
  }
  return water;
  
}


void print_LCD(float value,float value2){ //THIS FUNCTION PRINTING THE MESSAGES IN THE LCD
  //SHOWS TEMPERATURE
  lcd.print(String("Temp: ") + bmp.readTemperature());
  delay(500);
  lcd.clear();
  //delay(500);
  lcd.setCursor(0,0);
  //DISPLAY THE VALUES OF THE TWO SENSORS
  lcd.print(String("G1: ") +  value);
  lcd.setCursor(0,6);
  lcd.print(String("G2: ") +  value2);
  
  //delay(4000);
  //lcd.clear();
  //delay(500);
  
}

void print_Temperature(){ //THIS FUNCTION JUST PRINT IN SERIAL MONITOR THE VALUES
    Serial.print(F("Temperature = "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");

    Serial.print(F("Pressure = "));
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");

    Serial.print(F("Approx altitude = "));
    Serial.print(bmp.readAltitude(1013.25)); /* Adjusted to local forecast! */
    Serial.println(" m");
    //delay(100);

}
