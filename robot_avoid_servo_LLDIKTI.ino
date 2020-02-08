//KODING UNTUK PAMERAN LLDIKTI IV BANDUNG
//KODINGAN FIX 11 DESEMBER 2019 12:12 AM
#include <Servo.h>
#include <NewPing.h>
Servo myservo;
#define pinT 13
#define pinE 12
#define MAX_DISTANCE 200
NewPing sonar(pinT, pinE, MAX_DISTANCE);

// inialisasi pin untuk driver motor
const int motor1 = 6;
const int motor2 = 7;
const int motor3 = 8;
const int motor4 = 9;

// inialisasi pin untuk pengaturan kecepatan
// wajib menggunakan pin PWM
const int ena = 3;
const int enb = 5;

// inialisasi variabel penampung nilai kecepatan
int Speed;
boolean goesForward = false;
int distance = 100;
int speedSet = 0;
//program seting awal
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // inialisasi status I/O masing2 pin
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);

  myservo.write(90);
  myservo.attach(10);
}

//program utama, looping/ berulang
void loop() {
  fungsi();
}

int lookRight()
{
  myservo.write(0);
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(90);
  return distance;
}

int lookLeft()
{
  myservo.write(180);
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(90);
  return distance;
  delay(100);
}

int readPing() {
  delay(70);
  int cm = sonar.ping_cm();
  if (cm == 0)
  {
    cm = 250;
  }
  return cm;
}

void maju() {
  if (!goesForward)
  {
    goesForward = true;
    analogWrite(ena, 100); //roda kanan
    analogWrite(enb, 40); //roda kiri
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor4, HIGH);
    digitalWrite(motor3, LOW);
  }
}
void mundur() {
  goesForward = false;
  analogWrite(ena, 100);
  analogWrite(enb, 100);
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor4, LOW);
  digitalWrite(motor3, HIGH);
}
void kanan() {
  analogWrite(ena, 70); //kanan
  analogWrite(enb, 90); //kiri
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  delay(1000);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
}
void kiri() {
  analogWrite(ena, 90); //kanan
  analogWrite(enb, 70); //kiri
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
  delay(1000);
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
}
void diam() {
  analogWrite(ena, 100);
  analogWrite(enb, 100);
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, LOW);
}
