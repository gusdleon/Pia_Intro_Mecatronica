#include <LiquidCrystal.h>
const int rs = 40, en = 41, d4 = 42, d5 = 43, d6 = 44, d7 = 47;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

unsigned long previousMillis = 0;
const long interval = 4000;
bool ledState = LOW;

#include<Servo.h>
Servo servoEn;
Servo servoSal;
int aa = 0;
#define totales 9
int caj[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int caju = 0;

#define pinservoEn  2   //Señal PWM para Servo de ENTRADA
#define pinservoSal 46  //Señal PWM para Servo de SALIDA
#define botonEn   3     //Boton de ENTRADA
#define botonSal  4     //Boton de SALIDA

#define sencajon1 5     //Inicio de declaracion de constantes para sensores de cajon
#define sencajon2 6
#define sencajon3 7
#define sencajon4 8
#define sencajon5 9
#define sencajon6 10
#define sencajon7 11
#define sencajon8 12
#define sencajon9 13     //Fin de declaracion de constantes para sensores de cajon

#define ledrcajon1  22   //Inicio de declaracion de constantes para LEDS de cajon
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
#define ledvcajon9  39  //Fin de declaracion de constantes para LEDS de cajon
void setup() {
  pinMode(45, OUTPUT);
  analogWrite(45, 50);
  Serial.begin(250000);
  lcd.begin(20, 2);
  lcd.print("hello, world!");

  pinMode(botonEn, INPUT_PULLUP);
  pinMode(botonSal, INPUT_PULLUP);

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

  if (digitalRead(sencajon1) == HIGH) {
    aa++;
  }
  if (digitalRead(sencajon2) == HIGH) {
    aa++;
  }
  if (digitalRead(sencajon3) == HIGH) {
    aa++;
  }
  if (digitalRead(sencajon4) == HIGH) {
    aa++;
  }
  if (digitalRead(sencajon5) == HIGH) {
    aa++;
  }
  if (digitalRead(sencajon6) == HIGH) {
    aa++;
  }
  if (digitalRead(sencajon7) == HIGH) {
    aa++;
  }
  if (digitalRead(sencajon8) == HIGH) {
    aa++;
  }
  if (digitalRead(sencajon9) == HIGH) {
    aa++;
  }
  Serial.println(aa);
  caju = aa;
  servoEn.attach(pinservoEn);
  servoSal.attach(pinservoSal);
  servoEn.write(90);
  servoSal.write(20);
}

void loop() {
  if ((digitalRead(botonEn) == LOW) && (caj[0] == 0 || caj[1] == 0 || caj[2] == 0 || caj[3] == 0 || caj[4] == 0 || caj[5] == 0 || caj[6] == 0 || caj[7] == 0 || caj[8] == 0) && aa < 9) {
    aa++;
    Serial.println(aa);
    servoEn.write(180);
    delay(3000);
    servoEn.write(90);
  }
  if (digitalRead(botonSal) == LOW) {
    aa--;
    Serial.println(aa);
    servoSal.write(110);
    delay(3000);
    servoSal.write(20);

  }
  if (digitalRead(sencajon9) == HIGH) {
    caj[0] = 1;
    Serial.println("cajon 1 ocupado");
    digitalWrite(22, LOW);
    digitalWrite(23, HIGH);

  } else {
    digitalWrite(22, HIGH);
    caj[0] = 0;
    digitalWrite(23, LOW);
  }
  if (digitalRead(sencajon8) == HIGH) {
    Serial.println("cajon 2 ocupado");
    caj[1] = 1;
    digitalWrite(24, LOW);
    digitalWrite(25, HIGH);
  } else {
    digitalWrite(24, HIGH);
    caj[1] = 0;
    digitalWrite(25, LOW);
  }
  if (digitalRead(sencajon7) == HIGH) {
    caj[2] = 1;
    Serial.println("cajon 3 ocupado");
    digitalWrite(26, LOW);
    digitalWrite(27, HIGH);
  } else {
    caj[2] = 0;
    digitalWrite(26, HIGH);
    digitalWrite(27, LOW);
  }
  if (digitalRead(sencajon6) == HIGH) {
    caj[3] = 1;
    Serial.println("cajon 4 ocupado");
    digitalWrite(28, LOW);
    digitalWrite(29, HIGH);
  } else {
    caj[3] = 0;
    digitalWrite(28, HIGH);
    digitalWrite(29, LOW);
  }
  if (digitalRead(sencajon5) == HIGH) {
    caj[4] = 1;
    Serial.println("cajon 5 ocupado");
    digitalWrite(30, LOW);
    digitalWrite(31, HIGH);
  } else {
    caj[04] = 0;
    digitalWrite(30, HIGH);
    digitalWrite(31, LOW);
  }
  if (digitalRead(sencajon4) == HIGH) {
    caj[5] = 1;
    Serial.println("cajon 6 ocupado");
    digitalWrite(32, LOW);
    digitalWrite(33, HIGH);
  } else {
    caj[5] = 0;
    digitalWrite(32, HIGH);
    digitalWrite(33, LOW);
  }
  if (digitalRead(sencajon3) == HIGH) {
    caj[6] = 1;
    Serial.println("cajon 7 ocupado");
    digitalWrite(34, LOW);
    digitalWrite(35, HIGH);
  } else {
    caj[6] = 0;
    digitalWrite(34, HIGH);
    digitalWrite(35, LOW);
  }
  if (digitalRead(sencajon2) == HIGH) {
    caj[7] = 1;
    Serial.println("cajon 8 ocupado");
    digitalWrite(36, LOW);
    digitalWrite(37, HIGH);
  } else {
    caj[7] = 0;
    digitalWrite(36, HIGH);
    digitalWrite(37, LOW);
  }
  if (digitalRead(sencajon1) == HIGH) {
    caj[8] = 1;
    Serial.println("cajon 9 ocupado");
    digitalWrite(38, LOW);
    digitalWrite(39, HIGH);
  } else {
    caj[8] = 0;
    digitalWrite(38, HIGH);
    digitalWrite(39, LOW);
  }
  caju = caj[0] + caj[1] + caj[2] + caj[3] + caj[4] + caj[5] + caj[6] + caj[7] + caj[8];
  lcd.setCursor(0, 0);
  lcd.print("Autos dentro:   ");
  lcd.print(aa);
  lcd.setCursor(0, 1);
  lcd.print("Cajones Usados: ");
  lcd.print(caju);
}
