#include <SoftwareSerial.h>

//Pinos HC-05
#define RX 0
#define TX 1

//Pinos da Ponte H
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

SoftwareSerial ble (RX, TX);
char carac;

void desligaMotores () {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}
  
void setup() {
  Serial.begin(9600);
  ble.begin(9600);
  delay(100);
  ble.println("SETUP");
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
  
void loop() {
 // Armazena o carectere lido na Serial
 if (ble.available() > 0) {
  carac = ble.read();

  // Escolhe qual função executar a partir do caractere
  switch (carac) {
    case 'F':
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(500);
      desligaMotores();
      break;

    case 'E':
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(500);
      desligaMotores();
      break;

    case 'D':
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
      delay(500);
      desligaMotores();
      break;

    case 'T':
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(500);
      desligaMotores();
      break;

    default:
      break;   
  }
 }
}
