// Include Libraries
#include "Arduino.h"
#include "DS18B20.h"
#include <Stepper.h>

// Pin Definitions
#define DS18B20WP_PIN_DQ  2







const int SR = 50;
Stepper myStepper(SR, 8, 9, 10, 11);
DS18B20 ds18b20wp(DS18B20WP_PIN_DQ);


int p=0;


// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // set the speed 
    myStepper.setSpeed(100);
    
    Serial.begin(9600);
    
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    p = menu();
    
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
    




void loop() 
{
    float T = ds18b20wp.readTempC();
    Serial.print(F("Temp: ")); Serial.print(T); Serial.println(F(" [C]"));
   
    if(T<(p-4)
       {myStepper.step(265);
        Serial.println("Clockwise. More hot water coming in.");
         delay(1000);
       }  
     else if(T>(p-4) && T<(p+4))
        {myStepper.step(0);
         delay(1000);
        } 
     else if (T>(p+4))
        {myStepper.step(-265);
         Serial.println("Counterclockwise... Oops, overshot the tp. Going forward!");
         delay(1000);
        }   


}







int menu()
{

    Serial.println(F("\nWhat is your desired Temperature??"));
    
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
        {
      
        int k= Serial.read();
//        Serial.println("Cool. So it is "); Serial.println(k[:]); Serial.println("??");
        Serial.println(" \nNow Sit back and watch. We got it!  ;) \n");
//        time0= millis();
        return k;
        }
    
}
