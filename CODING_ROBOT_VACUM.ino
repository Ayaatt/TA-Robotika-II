#define rightMotor_Dir 4  // arah putar (Motor 1 / kanan)
#define rightMotor_Vel 5  // kontrol kecepatan (Motor 1 / Kiri)
#define leftMotor_Vel 6
#define leftMotor_Dir 7
#define fullspeed 255
#define nospeed 0
#define lowspeed1 50
#define lowspeed2 75
#define lowspeed3 100
#define lowspeed4 150
#define lowspeed5 175
#define highspeed1 225
#define highspeed2 176
#define highspeed3 200
#define highspeed4 215
#define highspeed5 250
int tengah ;
int kiri;
int kanan;

#include<NewPing.h>
#define TRIGGER_PIN 19
#define ECHO_PIN 18
#define MAX_DISTANCE 500
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


#define TRIGGER_PIN1 17
#define ECHO_PIN1 16
NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE);


#define TRIGGER_PIN2 15
#define ECHO_PIN2 14
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);
void maju()
{
  digitalWrite(rightMotor_Dir,HIGH);  //Motor diberi HIGH untuk bergerak CW
  analogWrite(rightMotor_Vel,60);  //Motor diberi HIGH agar EN=full speed
  digitalWrite(leftMotor_Dir,HIGH);  //Motor diberi HIGH untuk bergerak CW
  analogWrite(leftMotor_Vel,60);  //Motor diberi HIGH agar EN=full speed
  }
void mundur()
{
   digitalWrite(rightMotor_Dir,LOW);  //Motor diberi HIGH untuk bergerak CW
   analogWrite(rightMotor_Vel,50);  //Motor diberi HIGH agar EN=full speed
   digitalWrite(leftMotor_Dir,LOW);  //Motor diberi HIGH untuk bergerak CW
   analogWrite(leftMotor_Vel,50);  //Motor diberi HIGH agar EN=full speed
   }

   void berhenti()
{
   digitalWrite(rightMotor_Dir,LOW);  //Motor diberi HIGH untuk bergerak CW
   analogWrite(rightMotor_Vel,nospeed);  //Motor diberi HIGH agar EN=full speed
   digitalWrite(leftMotor_Dir,LOW);  //Motor diberi HIGH untuk bergerak CW
   analogWrite(leftMotor_Vel,nospeed);  //Motor diberi HIGH agar EN=full speed
   }

void belokkanan()
{
   digitalWrite(rightMotor_Dir,HIGH);  //Motor diberi HIGH untuk bergerak CW
   analogWrite(rightMotor_Vel,50);  //Motor diberi HIGH agar EN=full speed
   digitalWrite(leftMotor_Dir,LOW);  //Motor diberi HIGH untuk bergerak CW
   analogWrite(leftMotor_Vel,90);  //Motor diberi HIGH agar EN=full speed
  delay(200); 
  }
void belokkiri()
{
   digitalWrite(rightMotor_Dir,HIGH);  //Motor diberi HIGH untuk bergerak CW
   analogWrite(rightMotor_Vel,90);  //Motor diberi HIGH agar EN=full speed
   digitalWrite(leftMotor_Dir,LOW);  //Motor diberi HIGH untuk bergerak CW
   analogWrite(leftMotor_Vel,50);  //Motor diberi HIGH agar EN=full speed
   delay(200);
}
void setup()
{
  pinMode (4,OUTPUT);  //Setting pin 4 sebagai output
  pinMode (5,OUTPUT);  //Setting pin 5 sebagai output
  pinMode (6,OUTPUT);  //Setting pin 6 sebagai output
  pinMode (7,OUTPUT);  //Setting pin 7 sebagai output
  Serial.begin(115200);
}
void loop()
  {
  delay(100);
    tengah = sonar.ping_cm();
    kanan = sonar1.ping_cm();
    kiri = sonar2.ping_cm();
    if (tengah ==0 ) {
    tengah = MAX_DISTANCE; }
    if (kanan == 0 ){
    kanan = MAX_DISTANCE;}
    if (kiri == 0 ){
    kiri = MAX_DISTANCE;}
      Serial.print(" hasil pengukuran ");
      Serial.print(tengah);
      Serial.println(" cm");
      Serial.print(kanan);
      Serial.println(" cm");
      Serial.print(kiri);
      Serial.println(" cm");
      if(kiri<=10 && tengah<=10 && kanan <=10)
      {
        mundur();
      }
      else if((tengah <=10) && (kiri <=10))
      {
        belokkanan();
      }
      else if ((tengah <=10) && (kanan <=10))
      {
        belokkiri();
      }
            else if(kiri <=10)
      {
      belokkanan();
      }
      else if(kanan <=10)
      {
        belokkiri();
      }
      else if (tengah <=10)
      {
      belokkanan();
      }
      else       {
        maju();
      }

}
