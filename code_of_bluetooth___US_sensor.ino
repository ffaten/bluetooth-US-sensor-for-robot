#include <SoftwareSerial.h>
#include <Servo.h>
Servo myServo ;
SoftwareSerial myserial (0,1); 
int cm = 0;
int distanceThreshold = 0;
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup(){
  myserial.begin(9600);
  Serial.begin(9600);
  myServo.attach(3);
}
void loop()
{
  distanceThreshold = 50;
  cm = 0.01723 * readUltrasonicDistance(9, 10);
  if (Serial.available() && cm <= distanceThreshold ){
 
  delay(3000);
    myserial.print("Hello!");
 myServo.write(90);
   
  }
   delay(100);
}
