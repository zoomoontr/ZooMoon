#include <Stepper.h>

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
