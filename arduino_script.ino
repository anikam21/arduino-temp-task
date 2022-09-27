#include <Servo.h>

Servo servo_9;
//The variable we will use to store the sensor input
int sensorInput = 0;
//The variable we will use to store temperature in degrees
int tempDeg = 0; 
//The variable we will use to store the max temperture 
int maxTemp = 0;

void setup() {
  	pinMode(A0, INPUT);
	//Start the Serial Port at 9600 baud (default)
	Serial.begin(9600);
	pinMode(LED_BUILTIN, OUTPUT);
    pinMode(3, OUTPUT);
  	pinMode(5, OUTPUT);
  	pinMode(6, OUTPUT);
  	servo_9.attach(9, 500, 2500);
}
void loop() {
   sensorInput = -40;
   maxTemp = 125;
   
  //read the analog sensor and store it
   tempDeg = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
    
  if(tempDeg<sensorInput){
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }
  
  if(tempDeg >= sensorInput && tempDeg <= sensorInput + 30){
    digitalWrite(LED_BUILTIN, HIGH);
  	analogWrite(3, 0);
  	analogWrite(6, 0);
  	analogWrite(5, 255);
  	delay(1000); // Wait for 1000 millisecond(s)
  	digitalWrite(LED_BUILTIN, LOW);
  	delay(1000); // Wait for 1000 millisecond(s)
	}
  
  if(tempDeg >= sensorInput + 30 && tempDeg <= sensorInput + 60){
    digitalWrite(LED_BUILTIN, HIGH);
  	analogWrite(3, 0);
  	analogWrite(6, 255);
  	analogWrite(5, 0);
  	delay(1000); // Wait for 1000 millisecond(s)
  	digitalWrite(LED_BUILTIN, LOW);
  	delay(1000); // Wait for 1000 millisecond(s)
	}
   
  if(tempDeg >= sensorInput + 60 && tempDeg <= sensorInput + 90){
    digitalWrite(LED_BUILTIN, HIGH);
  	analogWrite(3, 255);
  	analogWrite(6, 255);
  	analogWrite(5, 0);
  	delay(1000); // Wait for 1000 millisecond(s)
  	digitalWrite(LED_BUILTIN, LOW);
  	delay(1000); // Wait for 1000 millisecond(s)
	}
   
  if(tempDeg >= sensorInput + 90 && tempDeg <= sensorInput + 120){
    digitalWrite(LED_BUILTIN, HIGH);
  	analogWrite(3, 120);
  	analogWrite(6, 81);
  	analogWrite(5, 169);
  	delay(1000); // Wait for 1000 millisecond(s)
  	digitalWrite(LED_BUILTIN, LOW);
  	delay(1000); // Wait for 1000 millisecond(s)
	}
  
  if(tempDeg >= sensorInput + 120 && tempDeg <= sensorInput + 150){
    digitalWrite(LED_BUILTIN, HIGH);
  	analogWrite(3, 255);
  	analogWrite(6, 0);
  	analogWrite(5, 0);
  	delay(1000); // Wait for 1000 millisecond(s)
  	digitalWrite(LED_BUILTIN, LOW);
  	delay(1000); // Wait for 1000 millisecond(s)
	}
  
  if(tempDeg >= sensorInput + 150 && tempDeg <= sensorInput + 165){
    digitalWrite(LED_BUILTIN, HIGH);
  	analogWrite(3, 255);
  	analogWrite(6, 255);
  	analogWrite(5, 255);
  	delay(1000); // Wait for 1000 millisecond(s)
  	digitalWrite(LED_BUILTIN, LOW);
  	delay(1000); // Wait for 1000 millisecond(s)
	}
  
  if(tempDeg == sensorInput){
    servo_9.write(0);  // tell servo to go to a particular angle
  	delay(1000);
  }
  if (tempDeg == maxTemp) {
    servo_9.write(180);  // tell servo to go to a particular angle
  	delay(1000);
  } 
}
