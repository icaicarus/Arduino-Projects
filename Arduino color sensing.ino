// Define pins
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6
#define redLED 7
#define greenLED 8
#define blueLED 9

// Initialize variables
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
int redColor = 0;
int greenColor = 0;
int blueColor = 0;

void setup() {
  // Setting the sensor pins
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Setting the LED pins
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  
  // Setting frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  // Begins serial communication
  Serial.begin(9600);
} 

void loop() {
  // Read the RGB values sensed
  int displayR = redFreq();
  int displayG = greenFreq();
  int displayB = blueFreq();

  // Display values on the LED
  LEDcolor(displayR, displayG, displayB);
  delay(200);
}  

void LEDcolor(int r, int g, int b) {
  analogWrite(redLED, r);
  analogWrite(greenLED, g);
  analogWrite(blueLED, b);
} 

void redFreq() {
  // Sensor setting configuration: Red photodiodes ON
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  redFrequency = pulseIn(sensorOut, LOW);
  
  // Map sensor values to RGB
  redColor = map(redFrequency, 12, 297, 255,0);
  
  // Confirm output on serial monitor
  Serial.print("R = ");
  Serial.print(redColor);
  delay(100);
  
  return redColor;
}

void greenFreq() {
  // Sensor setting configuration: Green photodiodes ON
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  greenFrequency = pulseIn(sensorOut, LOW);
  
  // Map sensor values to RGB
  greenColor = map(greenFrequency, 22, 317, 255, 0);
  
  // Confirm output on serial monitor 
  Serial.print(" G = ");
  Serial.print(greenColor);
  delay(100);
  
  return greenColor;
}

void blueFreq() {
  // Sensor setting configuration: Blue photodiodes ON
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  blueFrequency = pulseIn(sensorOut, LOW);

  // Map sensor values to RGB
  blueColor = map(blueFrequency, 32, 328, 255, 0);
  
  // Confirm output on serial monitor 
  Serial.print("B = ");
  Serial.print(blueColor);
  delay(100);
  
  return blueColor;
}