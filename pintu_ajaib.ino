#include <Servo.h>

Servo myServo;  // Membuat objek servo
const int triggerPin = 7;  // Pin trigger untuk sensor ultrasonik
const int echoPin = 6;     // Pin echo untuk sensor ultrasonik
long duration;
int distance;
int merah = 13;
int buzzer = 2;

void setup() {
  myServo.attach(9);  // Hubungkan servo ke pin digital 9
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.write(0);  // Servo dalam keadaan pintu tertutup
  Serial.begin(9600);  // Memulai serial untuk debugging
  pinMode(buzzer,OUTPUT);
}

void loop() {
  // Mengatur trigger untuk mengirim pulsa
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2000);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(2000);
  digitalWrite(triggerPin, LOW);

  // Mengukur durasi pulsa echo
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  // Menghitung jarak

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Membuka pintu jika jarak kurang dari 20 cm
  if (distance < 10) {
    myServo.write(90);  // Membuka pintu
    delay(5000);
    digitalWrite(merah, HIGH);
    digitalWrite(buzzer, HIGH);
  }

  else if(distance >10){
    myServo.write(0);  // Menutup pintu
    digitalWrite(merah, LOW);
    digitalWrite(buzzer, LOW);
  }
  delay(500);  // Delay untuk menghindari pembacaan yang berulang}
}