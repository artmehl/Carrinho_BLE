// Código feito por: Arthur Mehl - GitHub: https://github.com/artmehl
// Pode copiar, termina esse projeto ai e seja feliz :)). Se quiser, pode dar um salve também.

#include <SoftwareSerial.h>

//Pinos HC-05
#define RX 2
#define TX 3

//Pinos da Ponte H
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

#define LED 9

// Cria uma nova Serial via Software (utilizado pelo HC-05)
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
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(LED, OUTPUT);
}
  
void loop() {
 // Armazena o carectere lido na Serial
 if (ble.available() > 0) {
  carac = ble.read();
  Serial.print("- ");
  Serial.println(carac);

  // Escolhe qual função executar a partir do caractere
  switch (carac) {
    case 'F':
      digitalWrite(LED, HIGH);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(500);
      desligaMotores();
      digitalWrite(LED, LOW);
      break;

    case 'E':
      digitalWrite(LED, HIGH);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(500);
      desligaMotores();
      digitalWrite(LED, LOW);
      break;

    case 'D':
      digitalWrite(LED, HIGH);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
      delay(500);
      desligaMotores();
      digitalWrite(LED, LOW);
      break;

    case 'T':
      digitalWrite(LED, HIGH);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(500);
      desligaMotores();
      digitalWrite(LED, LOW);
      break;

    default:
      break;   
  }
 }
}
