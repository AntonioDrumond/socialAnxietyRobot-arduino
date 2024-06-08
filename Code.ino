#include <SoftwareSerial.h>
#include <Servo.h>

Servo serv;
#define motor 9
#define echo 7
#define trig 8
#define buzzer 6

void setup(){
  serv.attach(motor);
  serv.write(0);
  pinMode(buzzer, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  
  Serial.begin(9600);
}

long measure(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  return duration;
}

void breakpoint0(){
  noTone(buzzer);
}
void breakpoint1(){
  tone(buzzer, 800);
}
void breakpoint2(){
  tone(buzzer, 1000);
}
void breakpoint3(){
  tone(buzzer, 1200);
}
void breakpoint4(){
  tone(buzzer, 1400);
}
void breakpoint5(){
  tone(buzzer, 1600);
}
void breakpoint6(){
  tone(buzzer, 1800);
}
void breakpoint7(){
  tone(buzzer, 2000);
}
void breakpoint8(){
  noTone(buzzer);
  kill();
}

void kill(){
  serv.write(180);
  noTone(buzzer);
  while(1==1){
    Serial.println("kill");
  }
}

void loop(){
  long distance = measure();
  if(distance<=1375) breakpoint8();
  if(distance<=2750) breakpoint7();
  if(distance<=4125) breakpoint6();
  if(distance<=5500) breakpoint5();
  if(distance<=6875) breakpoint4();
  if(distance<=8250) breakpoint3();
  if(distance<=9625) breakpoint2();
  if(distance<=11000) breakpoint1();
  if(distance>11000) breakpoint0();
  Serial.println(distance);
}