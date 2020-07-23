#include <LiquidCrystal.h>  //Libreria de pantalla LCD
#include<Servo.h> //Libreria para controlar Servo motores

const int rs = 40, en = 41, d4 = 42, d5 = 43, d6 = 44, d7 = 47; //Asignacion de pines de pantalla LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //Declaracion de la pantalla LCD

unsigned long previousMillis = 0;
const long interval = 4000;
bool ledState = LOW;

Servo servoEn;    //Declaracion de el servo de entrada
Servo servoSal;   //Declaracion de el servo de salida
int aa = 0;
int caj[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; //Array para monitorear los cajones
int caju = 0; //Cajones usados

#define totales 9 //Total de cajones en el estacionamiento

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
  if (aa > 0 && digitalRead(botonSal) == LOW) {
    aa--;
    Serial.println(aa);
    servoSal.write(110);
    delay(3000);
    servoSal.write(20);
  }
  if(aa <= 0 && digitalRead(botonSal) == LOW){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ESTACIONAMIENTO");
    lcd.setCursor(0, 1);
    lcd.print("VACIO");
    
    delay(1000);
    }
  if (digitalRead(sencajon1) == HIGH) {
    caj[0] = 1;
    Serial.println("cajon 9 ocupado");
    digitalWrite(ledvcajon1, LOW);
    digitalWrite(ledrcajon1, HIGH);

  } else {
    digitalWrite(ledvcajon1, HIGH);
    caj[0] = 0;
    digitalWrite(ledrcajon1, LOW);
  }
  if (digitalRead(sencajon2) == HIGH) {
    Serial.println("cajon 2 ocupado");
    caj[1] = 1;
    digitalWrite(ledvcajon2, LOW);
    digitalWrite(ledrcajon2, HIGH);
  } else {
    digitalWrite(ledvcajon2, HIGH);
    caj[1] = 0;
    digitalWrite(ledrcajon2, LOW);
  }
  if (digitalRead(sencajon3) == HIGH) {
    caj[2] = 1;
    Serial.println("cajon 3 ocupado");
    digitalWrite(ledvcajon3, LOW);
    digitalWrite(ledrcajon3, HIGH);
  } else {
    caj[2] = 0;
    digitalWrite(ledvcajon3, HIGH);
    digitalWrite(ledrcajon3, LOW);
  }
  if (digitalRead(sencajon4) == HIGH) {
    caj[3] = 1;
    Serial.println("cajon 4 ocupado");
    digitalWrite(ledvcajon4, LOW);
    digitalWrite(ledrcajon4, HIGH);
  } else {
    caj[3] = 0;
    digitalWrite(ledvcajon4, HIGH);
    digitalWrite(ledrcajon4, LOW);
  }
  if (digitalRead(sencajon5) == HIGH) {
    caj[4] = 1;
    Serial.println("cajon 5 ocupado");
    digitalWrite(ledvcajon5, LOW);
    digitalWrite(ledrcajon5, HIGH);
  } else {
    caj[4] = 0;
    digitalWrite(ledvcajon5, HIGH);
    digitalWrite(ledrcajon5, LOW);
  }
  if (digitalRead(sencajon6) == HIGH) {
    caj[5] = 1;
    Serial.println("cajon 6 ocupado");
    digitalWrite(ledvcajon6, LOW);
    digitalWrite(ledrcajon6, HIGH);
  } else {
    caj[5] = 0;
    digitalWrite(ledvcajon6, HIGH);
    digitalWrite(ledrcajon6, LOW);
  }
  if (digitalRead(sencajon7) == HIGH) {
    caj[6] = 1;
    Serial.println("cajon 7 ocupado");
    digitalWrite(ledvcajon7, LOW);
    digitalWrite(ledrcajon7, HIGH);
  } else {
    caj[6] = 0;
    digitalWrite(ledvcajon7, HIGH);
    digitalWrite(ledrcajon7, LOW);
  }
  if (digitalRead(sencajon8) == HIGH) {
    caj[7] = 1;
    Serial.println("cajon 8 ocupado");
    digitalWrite(ledvcajon8, LOW);
    digitalWrite(ledrcajon8, HIGH);
  } else {
    caj[7] = 0;
    digitalWrite(ledvcajon8, HIGH);
    digitalWrite(ledrcajon8, LOW);
  }
  if (digitalRead(sencajon9) == HIGH) {
    caj[8] = 1;
    Serial.println("cajon 9 ocupado");
    digitalWrite(ledvcajon9, LOW);
    digitalWrite(ledrcajon9, HIGH);
  } else {
    caj[8] = 0;
    digitalWrite(ledvcajon9, HIGH);
    digitalWrite(ledrcajon9, LOW);
  }
  caju = caj[0] + caj[1] + caj[2] + caj[3] + caj[4] + caj[5] + caj[6] + caj[7] + caj[8];
  lcd.setCursor(0, 0);
  lcd.print("Autos dentro:   ");
  lcd.print(aa);
  lcd.setCursor(0, 1);
  lcd.print("Cajones Usados: ");
  lcd.print(caju);
}
