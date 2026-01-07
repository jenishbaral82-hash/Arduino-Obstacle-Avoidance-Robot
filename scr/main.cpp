#include <Arduino.h>
char data = '0';

int ln1 = 5;
int ln2 = 6;
int ln3 = 7;
int ln4 = 8;
int trig = 9; 
int echo = 10;
int buzP = 11;

void setup() {
  Serial.begin(9600);
  Serial.println("initializing...");

  pinMode(ln1, OUTPUT);
  pinMode(ln2, OUTPUT);
  pinMode(ln3, OUTPUT);
  pinMode(ln4, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzP, OUTPUT);
  digitalWrite(ln1, LOW);
  digitalWrite(ln2, LOW); 
  digitalWrite(ln3, LOW);
  digitalWrite(ln4, LOW);
  digitalWrite(trig, LOW);
  digitalWrite(buzP, LOW);
}

void buz() {
   digitalWrite(buzP, HIGH);
  delay(200);
  digitalWrite(buzP,LOW);
  delay(200);
  digitalWrite(buzP, HIGH);
  delay(200);
  digitalWrite(buzP,LOW);
}

void front() {
  digitalWrite(ln1,HIGH);
  digitalWrite(ln2,LOW);
  digitalWrite(ln3,HIGH);
  digitalWrite(ln4,LOW);
}

void left () {
  digitalWrite(ln1,HIGH);
  digitalWrite(ln2,LOW);
  digitalWrite(ln3,LOW);
  digitalWrite(ln4,HIGH);
}

void right() {
  digitalWrite(ln1,LOW);
  digitalWrite(ln2,HIGH);
  digitalWrite(ln3,HIGH);
  digitalWrite(ln4,LOW);
}

void back() {
  digitalWrite(ln1,LOW);
  digitalWrite(ln2,HIGH);
  digitalWrite(ln3,LOW);
  digitalWrite(ln4,HIGH);
  buz();
}

void stop() {
  digitalWrite(ln1, LOW);
  digitalWrite(ln2, LOW); 
  digitalWrite(ln3, LOW);
  digitalWrite(ln4, LOW);
  digitalWrite(buzP,HIGH);
  delay(500);
  digitalWrite(buzP,LOW);
}

void ultrasonic() {
  long duration, distance;
  digitalWrite(trig, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 29.1; 
  if (distance <= 5) {
    stop();
  }
}

void loop() {
  Serial.println("waiting for data....");

  if (Serial.available() > 0) {
    data = Serial.read();
    Serial.print("Received: ");
    Serial.println(data);

    if (data == 'F') {
      front();
      Serial.println("Moving Forward");
      ultrasonic();
    }
    else if (data == 'L') {
      left();
      Serial.println("Turning Left");
      ultrasonic();
    }
    else if (data == 'R') {
      right();
      Serial.println("Turning Right");
      ultrasonic();
    }
    else if (data == 'B') {
      back();
      Serial.println("Moving Backward");
    }
    else {
      stop();
      Serial.println("Stopping");
    }
  }
}
