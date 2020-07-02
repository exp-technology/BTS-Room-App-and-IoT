#include <dht.h>
#include <Servo.h>
#define sensor_api A0
#define sensor_asap A1
#define sensor_suhu A2
#define servo 9
#define buzzer 7
#define pin_5v_tambahan 3
dht DHT;
Servo myservo;
int pos = 0 , kunci = 0;
int hsensorapi, hsensorasap,hsensorsuhu;
String data;



void setup() {
  // put your setup code here, to run once:
pinMode(pin_5v_tambahan, OUTPUT);
digitalWrite(pin_5v_tambahan, HIGH);
myservo.attach(servo); 
Serial.begin(9600);
pinMode(buzzer,OUTPUT);
for (pos = 0; pos >= 0; pos -= 5) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
delay(10000);
}

void loop() {
  // put your main code here, to run repeatedly:
DHT.read11(sensor_suhu);
hsensorapi = analogRead(sensor_api);
hsensorasap = analogRead(sensor_asap);
hsensorsuhu = (DHT.temperature);


if(kunci == 0){
if ( hsensorapi < 100 || hsensorasap > 300 || hsensorsuhu > 40){
//  satu didepan menandakan bahwa kirim notifikasi di raspberry
  data = "1-"+String(hsensorapi) + "-" + String(hsensorasap) + "-" + String(hsensorsuhu) ;
  Serial.println(data);
    for (pos = 0; pos <= 180; pos += 5) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
   digitalWrite(buzzer,HIGH);
   kunci = 1;
}
else{
 
data = "0-"+String(hsensorapi) + "-" + String(hsensorasap) + "-" + String(hsensorsuhu) ;   
Serial.println(data);
digitalWrite(buzzer,LOW);
}
}
else{
  data = "1-"+String(hsensorapi) + "-" + String(hsensorasap) + "-" + String(hsensorsuhu) ;
  Serial.println(data);
}

delay(20);

}





//footnote 
//sensor dht11 dengan menggunakan analog input
//sensor dht11 langsung menampilkan suhu panas derajat celcius
//dengan perintah
//#include <dht.h>
//dht DHT;
//DHT.read11(pinsensorasap);
//Serial.println(DHT.temperature);
//
//sensor mq2 menggunakan analogread biasa tanpa menggunakan library
//dengan parameter apabila lebih dari 300 (>300) pembacaan analogRead
//maka dapat disimpulkan terdapat asap
//sensor mq2 membutuhkan waktu delay di awal +- 20 detik untuk kalibrasi
//
//sensor flame menggunakan analogRead biasa tanpa menggunakan library
//dengan parameter apabila kurang dari 100 (<100) analogRead
//disimpulan terapat Api

//actuator servo menggunakan library
/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep

 #include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
} 
*/




//###############komunikasi
//void loop() {
//
//  a = Serial.read();
////  Serial.println(a);
//  if(a == 49){
//  ascii 49 adalah character 1 di python
//  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//  }
//  else{
//    
//  }
//  delay(20);
//}

