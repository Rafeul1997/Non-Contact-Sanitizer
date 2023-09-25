#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

int myVal,high,low;

int Red = 4;
int Yellow = 5;
int Blue = 6;
int Relay = 7;


void setup()

 {
    
    pinMode(Red,OUTPUT);
    pinMode(Yellow,OUTPUT);
    pinMode(Blue,OUTPUT);
    pinMode(Relay,OUTPUT);
    
    digitalWrite(Blue,HIGH);
    
    digitalWrite(Relay,HIGH);
    
  Serial.begin(9600);
    
    
    myVal=0;
    low =94;
    high=98;
    
    
    
  Serial.println("Adafruit MLX90614");  
  mlx.begin();  
}

void loop() {
    
    digitalWrite(Relay,HIGH);
    
    digitalWrite(Yellow,LOW);
    
    digitalWrite(Red,LOW);
    
    
//  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC()); 
 // Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
 // Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF()); 
  //Serial.print("*F\t");
    Serial.print("Object = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");
  Serial.println();
    myVal=mlx.readObjectTempF();
  delay(500);
    
    if ((myVal > low) && (myVal < high))
    
     {
        
Serial.print("Sanitizer");
        digitalWrite(Yellow,HIGH);
       digitalWrite(Relay,LOW);
       delay(1500);
       //     digitalWrite(Yellow,LOW);
       digitalWrite(Relay,HIGH);
        delay(2500);
        
}
else {
        
          Serial.print("DETECTED");  
            digitalWrite(Red,HIGH);
           // delay(1000);
           // digitalWrite(Red,LOW);
        

}
    
    delay(3000);
}