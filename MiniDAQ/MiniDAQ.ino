
#define CUSTOM                                //setting ethercat bus IO to custom mode (configurable channels)
#include "TestEasyCAT_Custom.h"               //including customised channel h file (made with EasyConfigurator)
#include "EasyCAT.h"               
#include <Wire.h>
#include <Adafruit_ADS1X15.h>                 //ADC h file
#include <Adafruit_BNO055.h>                  //Accelerometer h file
#include <SPI.h>
#define RATE_ADS1115_860SPS (0x00E0)          //highest sample rate

EasyCAT EASYCAT;                              //instantiate EasyCAT board
Adafruit_ADS1115 ads11151;                    //ADC 1
Adafruit_ADS1115 ads11152;                    //ADC 2
Adafruit_BNO055 bno = Adafruit_BNO055(55);    //Accelerometer


void setup()
{
  Serial.begin(115200);        
  ads11151.begin(0x48);                       //ADC with ADDR pin tied to ground (address = 0X48)
  ads11151.setDataRate(RATE_ADS1115_860SPS);  
  ads11152.begin(0x49);                       //ADC with ADDR pin tied to V+
  ads11152.setDataRate(RATE_ADS1115_860SPS);

  if (EASYCAT.Init() == true)                 //Initialise EasyCAT board
  {
    Serial.print ("initialized");
  }
  else
  {
    Serial.print ("initialization failed");

  }  

  if (!bno.begin())                           //Initialise Accelerometer
  {
    Serial.print("no accelerometer detected");
    while(1);
  }

bno.setExtCrystalUse(true);
}

 
void loop(){
  EASYCAT.MainTask();                         //Calling EasyCAT maintask, must be called cyclically
  Application();                              //Calling main data aquisition function
}


void Application ()                                        
{
int16_t adc1;                                 //ADC reading integer declarations
int16_t adc2;
int16_t adc3;
int16_t adc4;
int16_t adc5;
int16_t adc6;
int16_t adc7;
int16_t adc8;

adc1 = ads11151.readADC_SingleEnded(0);       //Reading all analogue channels
adc2 = ads11151.readADC_SingleEnded(1);
adc3 = ads11151.readADC_SingleEnded(2);
adc4 = ads11151.readADC_SingleEnded(3);

adc5 = ads11152.readADC_SingleEnded(0);
adc6 = ads11152.readADC_SingleEnded(1);
adc7 = ads11152.readADC_SingleEnded(2);
adc8 = ads11152.readADC_SingleEnded(3);

imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);    //Reading Accelerometer

float voltage1 = (adc2*5.000)/27200.00;        //Converting adc IO readings (integer from 0-1023) to voltage, this may be customised for sensors used
float voltage2 = (adc3*5.000)/27200.00;
float voltage3 = (adc4*5.000)/27200.00;
float voltage4 = (adc5*5.000)/27200.00;
float voltage5 = (adc6*5.000)/27200.00;
float voltage6 = (adc7*5.000)/27200.00;
float voltage7 = (adc8*5.000)/27200.00;
float voltage8 = (adc1*5.000)/27200.00;
float X = euler.x();                            //Assigning each component of euler vector to a float
float Y = euler.y();
float Z = euler.z();

EASYCAT.BufferIn.Cust.Analogue1 = voltage1;     //sending all readings to the EtherCAT buffer
EASYCAT.BufferIn.Cust.Analogue2 = voltage2;
EASYCAT.BufferIn.Cust.Analogue3 = voltage3;
EASYCAT.BufferIn.Cust.Analogue4 = voltage4;
EASYCAT.BufferIn.Cust.Analogue5 = voltage5;
EASYCAT.BufferIn.Cust.Analogue6 = voltage6;
EASYCAT.BufferIn.Cust.Analogue7 = voltage7;
EASYCAT.BufferIn.Cust.Analogue8 = voltage8;
EASYCAT.BufferIn.Cust.EulerX = X;
EASYCAT.BufferIn.Cust.EulerY = Y;
EASYCAT.BufferIn.Cust.EulerZ = Z;
}





