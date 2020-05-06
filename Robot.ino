#include <Servo.h>
#include <L298N.h>
Servo myservo;
int ledStatus = 0;
int ignoresec = 0;
int ServoDeg = 90;
void ledoffon(){
  if(ledStatus == 0){
    digitalWrite(13, HIGH);
    ledStatus = 1;
  }else{
    digitalWrite(13, LOW);
    ledStatus = 0;
  }
}
void servo_r(){
  ServoDeg = ServoDeg - 10;
  myservo.write(ServoDeg);
}
void servo_l(){
  ServoDeg = ServoDeg + 10;
  myservo.write(ServoDeg);
}
void servo_c(){
  ServoDeg = 90;
  myservo.write(ServoDeg);
}

L298N driver(5, 8, 7, 9, 11, 6, true, 255);
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(4, INPUT);
  digitalWrite(10, HIGH);
  digitalWrite(13, LOW);
  myservo.attach(3);
  myservo.write(ServoDeg);
}

void loop(){
    if(Serial.available()){
    char getstr = Serial.read();
    switch(getstr){
      case 'f': driver.forward(); break;
      case 'b': driver.backward();   break;
      case 'l': driver.left();   break;
      case 'r': driver.right();  break;
      case 's': driver.stop(); break;
      case 'h': ledoffon(); break;
      case 't': servo_l(); break;
      case 'm': servo_c(); break;
      case 'a': servo_r(); break;
      default:  break;
    }
  }
}
