//Pinos da Ponte H
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

char carac;

void desligaMotores () {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}
  
void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
  
void loop() {
 // Armazena o carectere lido na Serial
 if (Serial.available() > 0) {
   carac = Serial.read();
   Serial.print("Caractere: ");
   Serial.println(carac);
   Serial.println();
 }
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
