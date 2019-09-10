#include <stdio.h>
#include <math.h>
#define zero_error 0.038
int sensorPin = A0;   // select the input pin for current probe
int digitalValue = 0;  // variable to store the value coming from the sensor
float analogVoltage = 0.00;    // variable to store the analog value
int t,i,k;

char a[50];
//int digitalValue;
void setup() {

  Serial.begin(9600);
  analogReference(INTERNAL);                        // analog reference to 1.1V
 pinMode(A0,INPUT);
  
}


void loop() {
  for(i=0;i<200;i++){
    k=analogRead(sensorPin); 
    if(digitalValue<k)
  digitalValue = k;             // read the value from the analog channel
  delay(0.1);
  }
  
  analogVoltage = (digitalValue * 1.1)/1023.00;     // converting equivalent digital value to analog
   digitalValue = 0;
  analogVoltage=(analogVoltage/sqrt(2))-zero_error;
  t=analogVoltage;                                  // storing the integer value
  k=(analogVoltage-t)*1000;                         // storing the float value
  
  sprintf(a,"%d.%0.3d",t,k);                        // combining the iinteger and float part in an array
 Serial.println(a);                                 // sending anaglog values vai bluetooth
  delay(1000);
}
