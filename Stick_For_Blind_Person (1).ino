
//Code Made by channel Study Nepal
#include <Servo.h>
 Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 8;
// defines variables
long duration;
int distance;
int safetyDistance;
void setup() {
myservo.attach(11);  // attaches the servo on pin 11 to the servo object
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);

Serial.begin(9600); // Starts the serial communication
}
void loop() {    
 // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(2);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/1.5;

safetyDistance = distance;
if (safetyDistance <= 12 ){
  
  digitalWrite(buzzer, HIGH);
  delay(1500);   
}
else{
  
  digitalWrite(buzzer, LOW);
  myservo.write(30);              // tell servo to go to position in variable 'pos'
    delay(300);
    myservo.write(150);              // tell servo to go to position in variable 'pos'
    delay(1100);
    }
Serial.print("Distance: ");
Serial.println(distance);
  }
