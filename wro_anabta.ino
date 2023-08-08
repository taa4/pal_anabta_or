const int pwm = 2 ; //initializing pin 2 as pwm
const int in_1 = 50 ;
const int in_2 = 52;
#include <Servo.h>

// constants won't change
const int TRIG_PIN  = 6;  // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN  = 7;  // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int SERVO_PIN = 5; // Arduino pin connected to Servo Motor's pin
const int DISTANCE_THRESHOLD = 80; // centimeters
const int TRIG_PIN1  = 4;  // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN1  = 3;  // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int TRIG_PIN2  = 8;  // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN2  = 9;  // Arduino pin connected to
int time =0;

Servo servo; // create servo object to control a servo

// variables will change:
float duration_us, distance_cm,duration_us1, distance_cm1,duration_us2, distance_cm2;
void setup() {
   pinMode(pwm,OUTPUT) ; //we have to set PWM pin as output
   pinMode(in_1,OUTPUT) ; //Logic pins are also set as output
   pinMode(in_2,OUTPUT) ;
   Serial.begin (9600);       // initialize serial port
  pinMode(TRIG_PIN, OUTPUT); // set arduino pin to output mode
  pinMode(ECHO_PIN, INPUT);  // set arduino pin to input mode
  pinMode(TRIG_PIN1, OUTPUT); // set arduino pin to output mode
  pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIG_PIN2, OUTPUT); // set arduino pin to output mode
  pinMode(ECHO_PIN2, INPUT);
  servo.attach(SERVO_PIN);   // attaches the servo on pin 9 to the servo object
  servo.write(90);
   }
void loop() {
time =0 ;
while (time <=176){
   //For Clock wise motion , in_1 = High , in_2 = Low
    analogWrite(pwm,170) ;
   digitalWrite(in_1,HIGH) ;
   digitalWrite(in_2,LOW) ;
   
   digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(50);
  digitalWrite(TRIG_PIN, LOW);
duration_us = pulseIn(ECHO_PIN, HIGH);
  distance_cm = 0.017 * duration_us;

  digitalWrite(TRIG_PIN1, HIGH); 
  delayMicroseconds(50);
 digitalWrite(TRIG_PIN1, LOW);
duration_us1 = pulseIn(ECHO_PIN1, HIGH);
  distance_cm1 = 0.017 * duration_us1;
  
  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(50);
  digitalWrite(TRIG_PIN2, LOW);
duration_us2 = pulseIn(ECHO_PIN2, HIGH);
  distance_cm2 = 0.017 * duration_us2;

  if(distance_cm < DISTANCE_THRESHOLD){
    servo.write(120); // rotate servo motor to 90 degree
    delay(100);
    }
    else{
    servo.write(90);  // rotate servo motor to 0 degree
    delay(75);
  }
  
    if(distance_cm1 < 50){
    servo.write(120); // rotate servo motor to 90 degree
    delay(50);
    }
  else{
    servo.write(90);  // rotate servo motor to 0 degree
    delay(75);
  }
  Serial.println(distance_cm1);
  /*if(distance_cm2 < 40){
    servo.write(50); // rotate servo motor to 90 degree
    delay(200);
    }
  else{
    servo.write(90);  // rotate servo motor to 0 degree
    delay(100);
  }*/
  time++;}
  analogWrite(pwm,130) ;
   digitalWrite(in_1,LOW) ;
   digitalWrite(in_2,LOW) ;
   delay (100000);
   
   }