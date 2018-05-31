#include <Servo.h>
Servo myservo;
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
#define ledvcajon9  29
void setup() {
  // put your setup code here, to run once:
  myservo.attach(2);
  for(i=1;i<10;i++){
   pinMode("sencajon"i,INPUT);
  }
  for(i=1;i<10;i++){
    pinMode("ledrcajon"i,OUTPUT);
    pinMode("ledvcajon"i,OUTPUT);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
