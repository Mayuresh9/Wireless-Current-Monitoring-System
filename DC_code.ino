#include <stdio.h>
int sensorPin = A0;   // select the input pin for current probe
int digitalValue = 0;  // variable to store the value coming from the sensor
float analogVoltage = 0.00;    // variable to store the analog value
int t,k;
char a[50];
void setup() {

  Serial.begin(9600);
  analogReference(INTERNAL);                        // analog reference to 1.1V
 pinMode(A0,INPUT);
  
}


void loop() {
  digitalValue = analogRead(sensorPin);             // read the value from the analog channel
  
  analogVoltage = (digitalValue * 1.1)/1023.00;     // converting equivalent digital value to analog 
  
  t=analogVoltage;                                  // storing the integer value
  k=(analogVoltage-t)*1000;                         // storing the float value
  
  sprintf(a,"%d.%0.3d",t,k);                        // combining the iinteger and float part in an array
 Serial.println(a);                                 // sending anaglog values vai bluetooth
  delay(1000);
}
