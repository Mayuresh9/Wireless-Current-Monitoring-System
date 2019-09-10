#include <stdio.h>
#include <math.h>
#define zero_error 0.153
int sensorPin = A0;   // select the input pin for current probe
int digitalValue = 0;  // variable to store the value coming from the sensor
float analogVoltage = 0.00;    // variable to store the analog value
int t,i,k;
char nature;

char a[50];
//int digitalValue;
void setup() {

  Serial.begin(38400);
   Serial.println("AT+RESET\r\n");
    Serial.begin(9600);
  analogReference(INTERNAL);                        // analog reference to 1.1V
 //pinMode(A0,INPUT);
  
}


void loop() {
  //Serial.println("select AC or DC");
 if(nature != '$' && nature != '#' ){
   //Serial.println("select");
  while(Serial.available()<=0)
    Serial.println("select AC or DC");
  nature = Serial.read();
  }

  switch(nature){
    case '$':
      while(1){
        for(i=0;i<200;i++){
          k=analogRead(sensorPin); 
          if(digitalValue<k)
            digitalValue = k;             // read the value from the analog channel
          delay(0.1);
          }
  
        analogVoltage = ((digitalValue * 1.1)/1023.00);     // converting equivalent digital value to analog
        digitalValue = 0;
        Serial.println(analogVoltage);
        analogVoltage=(analogVoltage/sqrt(2));
        analogVoltage= (analogVoltage*10)-0.2;
        t=analogVoltage;                                  // storing the integer value
        k=(analogVoltage-t)*1000;                         // storing the float value
        sprintf(a,"%d.%0.3d A",t,k);  // combining the iinteger and float part in an array
        Serial.println(analogVoltage); 
        Serial.println(a);                                 // sending anaglog values vai bluetooth
        delay(1000);
        if(Serial.read()=='#'){
          nature = '$';
          break;
        }
        }
        
     case '#':
      while(1){
        digitalValue = analogRead(sensorPin);             // read the value from the analog channel
  
        analogVoltage = (digitalValue * 1.1)/1023.00;     // converting equivalent digital value to analog 
        analogVoltage=analogVoltage*10;
        t=analogVoltage;                                  // storing the integer value
        k=(analogVoltage-t)*1000;                         // storing the float value
  
        sprintf(a,"%d.%0.3d A",t,k);                        // combining the iinteger and float part in an array
        Serial.println(a);                                 // sending anaglog values vai bluetooth
        delay(1000);
        if(Serial.read()=='$'){
          nature = '$';
          break;
          }
        
      }
  }
    

  
}
