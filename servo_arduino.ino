[23:36, 27/10/2019] Kağan: #include <SoftwareSerial.h>
#include <Servo.h>
#include <Wire.h>
#include <MPU6050.h>


int TxD = 10;
int RxD = 12;
int servoposition;
int servopos;
int new1;

Servo sa1;
Servo sa2; 
Servo sa3; 
Servo sa4; 
Servo sb1; 
Servo sb2; 
Servo sb3; 
Servo sb4;      
    

int servo_pin11 = 11;
int servo_pin9 = 9;
int servo_pin3 = 3;
int servo_pin4 = 4;
int servo_pin5 = 5;
int servo_pin6 = 6;
int servo_pin7 = 7;
int servo_pin8 = 8;

MPU6050 sensor ;

int16_t ax, ay, az ;

int16_t gx, gy, gz ;


SoftwareSerial bluetooth(TxD, RxD);
void setup() {
  int pos=0;
sa4.attach(5);
sa3.attach(4);
sa2.attach(3);
sa1.attach(2);

  Serial.begin(9600);       // start serial communication at 9600bps
  bluetooth.begin(9600);

sa1.attach ( servo_pin11 );
sa2.attach ( servo_pin9 );
s…
[23:36, 27/10/2019] Kağan: #include <Stepper.h>

#define STEPS 32
Stepper motor(STEPS, 2, 3, 4, 5);
Stepper motoro(STEPS, 9, 10, 11, 12);


int trigPin = 7; /* Sensorun trig pini Arduinonun 7 numaralı ayağına bağlandı */
int echoPin = 6; /* Sensorun echo pini Arduinonun 6 numaralı ayağına bağlandı */

unsigned long sure; // Echo bacağının kac mikro saniyede aktif olduğunu saklayacak olan değişken
double toplamYol;
int aradakiMesafe;
bool first = true;
bool second = false;


void setup() {
  pinMode(trigPin, OUTPUT); // Sensörün Trigger bacağına gerilim uygulayabilmemiz için OUTPUT yapıyoruz.
  pinMode(echoPin, INPUT); // Sensörün Echo bacağındaki gerilimi okuyabilmemiz için INPUT yapıyoruz.
  motor.setSpeed(100);
  motoro.setSpeed(100);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Dalga üretildikten sonra geri yansıyıp Echo bacağının HIGH duruma geçireceği süreyi pulseIn fonksiyonu ile
  // kaydediyoruz.
  sure = pulseIn(echoPin, HIGH);

  // Aşağıda yapılan süre-mesafe dönüşüm işlemleri yazımızda açıklanmıştır.
  toplamYol = (double)sure * 0.034;
  aradakiMesafe = toplamYol / 2;

  Serial.println(aradakiMesafe);

  if (first == true & aradakiMesafe <= 20 )
  {

    motor.step(1000);
    delay(1000);
    motoro.step(1000);
    delay(1000);

    first = false;
    second = true;


  }

  if ( second == true & aradakiMesafe > 20  )
  {

    motoro.step(-1000);
    delay(500);
    motor.step(-1000);
    delay(500);
    second = false;
    first = true;
    delay(100);

  }

}
