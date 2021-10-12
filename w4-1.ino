#include <Servo.h>
Servo myservo;
const int servoPin=14;
int pos=0;

void setup() {
  pinMode(13,INPUT);
 myservo.attach(servoPin);//
 Serial.begin(115200);

}

// the loop function runs over and over again forever
void loop() {
  int input=analogRead(13);
   int pos = map(input, 0, 4095, 0, 180); 
 myservo.write(pos);
 Serial.println(pos);
  Serial.println(input);

 delay(50);// wait for a second

}
