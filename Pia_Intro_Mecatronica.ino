#include <Servo.h>
Servo myservo;
int i = 0;
int pos = 0;
#define pinservo  2
#define sencajon1 3
#define sencajon2 4
#define sencajon3 5
#define sencajon4 6
#define sencajon5 7
#define sencajon6 8
#define sencajon7 9
#define sencajon8 10
#define sencajon9 11
#define ledrcajon1  22
#define ledvcajon1  23
#define ledrcajon2  24
#define ledvcajon2  25
#define ledrcajon3  26
#define ledvcajon3  27
#define ledrcajon4  28
#define ledvcajon4  29
#define ledrcajon5  30
#define ledvcajon5  31
#define ledrcajon6  32
#define ledvcajon6  33
#define ledrcajon7  34
#define ledvcajon7  35
#define ledrcajon8  36
#define ledvcajon8  37
#define ledrcajon9  38
#define ledvcajon9  39
void setup() {
  // put your setup code here, to run once:
  pinMode(sencajon1, INPUT);
  pinMode(sencajon2, INPUT);
  pinMode(sencajon3, INPUT);
  pinMode(sencajon4, INPUT);
  pinMode(sencajon5, INPUT);
  pinMode(sencajon6, INPUT);
  pinMode(sencajon7, INPUT);
  pinMode(sencajon8, INPUT);
  pinMode(sencajon9, INPUT);
  pinMode(ledrcajon1, OUTPUT);
  pinMode(ledvcajon1, OUTPUT);
  pinMode(ledrcajon2, OUTPUT);
  pinMode(ledvcajon2, OUTPUT);
  pinMode(ledrcajon3, OUTPUT);
  pinMode(ledvcajon3, OUTPUT);
  pinMode(ledrcajon4, OUTPUT);
  pinMode(ledvcajon4, OUTPUT);
  pinMode(ledrcajon5, OUTPUT);
  pinMode(ledvcajon5, OUTPUT);
  pinMode(ledrcajon6, OUTPUT);
  pinMode(ledvcajon6, OUTPUT);
  pinMode(ledrcajon7, OUTPUT);
  pinMode(ledvcajon7, OUTPUT);
  pinMode(ledrcajon8, OUTPUT);
  pinMode(ledvcajon8, OUTPUT);
  pinMode(ledrcajon9, OUTPUT);
  pinMode(ledvcajon9, OUTPUT);

  //  myservo.attach(2);
  //  for(i=1;i<10;i++){
  //   pinMode("sencajon" + i,INPUT);
  //  }
  //  for(i=1;i<10;i++){
  //    pinMode("ledrcajon" + i,OUTPUT);
  //    pinMode("ledvcajon" + i,OUTPUT);
  //  }

}

void loop() {
  // put your main code here, to run repeatedly:
    for(i=1;i<10;i++){
      if(digitalRead('sencajon' + i) == HIGH){
        digitalWrite('ledrcajon' + i, HIGH);
        digitalWrite('ledvcajon' + i, LOW);
      }else{
        digitalWrite('ledrcajon' + i, LOW);
        digitalWrite('ledvcajon' + i, HIGH);
      }
      delay(100);
    }
//  if (digitalRead(sencajon1) == LOW) {
//    digitalWrite(ledrcajon1, HIGH);
//    digitalWrite(ledvcajon1, LOW);
//  } else {
//    digitalWrite(ledrcajon1, LOW);
//    digitalWrite(ledvcajon1, HIGH);
//  }
//  if (digitalRead(sencajon2) == LOW) {
//    digitalWrite(ledrcajon2, HIGH);
//    digitalWrite(ledvcajon2, LOW);
//  } else {
//    digitalWrite(ledrcajon2, LOW);
//    digitalWrite(ledvcajon2, HIGH);
//  }
//  if (digitalRead(sencajon3) == LOW) {
//    digitalWrite(ledrcajon3, HIGH);
//    digitalWrite(ledvcajon3, LOW);
//  } else {
//    digitalWrite(ledrcajon3, LOW);
//    digitalWrite(ledvcajon3, HIGH);
//  }
//  if (digitalRead(sencajon4) == LOW) {
//    digitalWrite(ledrcajon4, HIGH);
//    digitalWrite(ledvcajon4, LOW);
//  } else {
//    digitalWrite(ledrcajon4, LOW);
//    digitalWrite(ledvcajon4, HIGH);
//  }
//  if (digitalRead(sencajon5) == LOW) {
//    digitalWrite(ledrcajon5, HIGH);
//    digitalWrite(ledvcajon5, LOW);
//  } else {
//    digitalWrite(ledrcajon5, LOW);
//    digitalWrite(ledvcajon5, HIGH);
//  }
//  if (digitalRead(sencajon6) == LOW) {
//    digitalWrite(ledrcajon6, HIGH);
//    digitalWrite(ledvcajon6, LOW);
//  } else {
//    digitalWrite(ledrcajon6, LOW);
//    digitalWrite(ledvcajon6, HIGH);
//  }
//  if (digitalRead(sencajon7) == LOW) {
//    digitalWrite(ledrcajon7, HIGH);
//    digitalWrite(ledvcajon7, LOW);
//  } else {
//    digitalWrite(ledrcajon7, LOW);
//    digitalWrite(ledvcajon7, HIGH);
//  }
//  if (digitalRead(sencajon8) == LOW) {
//
//    digitalWrite(ledrcajon8, HIGH);
//    digitalWrite(ledvcajon8, LOW);
//  } else {
//    digitalWrite(ledrcajon8, LOW);
//    digitalWrite(ledvcajon8, HIGH);
//  }
//  if (digitalRead(sencajon9) == LOW) {
//    digitalWrite(ledrcajon9, HIGH);
//    digitalWrite(ledvcajon9, LOW);
//  } else {
//    digitalWrite(ledrcajon9, LOW);
//    digitalWrite(ledvcajon9, HIGH);
//  }
}
