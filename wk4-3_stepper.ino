#include <Stepper.h> //引入步進馬達函示庫

const int stepsPerRevolution = 2048;  //此馬達轉一圈為2048步
const int RPM = 5; //馬達旋轉速度
const int Button1_Pin = 12, Button2_Pin = 14;
//宣告Stepper物件，的步數和引腳
//引角依序對應驅動版的1N1、1N3、1N2、1N4
Stepper myStepper(stepsPerRevolution, 13, 14, 12, 27);  

void setup() {  
   pinMode(Button1_Pin, INPUT);
   pinMode(Button2_Pin, INPUT);
  Serial.begin(115200);
  myStepper.setSpeed(RPM);  //設定馬達轉速
}

void loop() {
  //正轉一圈
  if(digitalRead(Button1_Pin) == HIGH && btn1_Pressed == false){
    btn1_Pressed = true;
  myStepper.step(stepsPerRevolution);
  delay(500);
  }
  else if(digitalRead(Button1_Pin) == LOW && btn1_Pressed == true){
    btn1_Pressed = false;
  delay(500);
  }
  
  //Player 2
  if(digitalRead(Button2_Pin) == HIGH && btn2_Pressed == false){
   myStepper.step(-stepsPerRevolution);
  delay(500);
  }
  else if(digitalRead(Button2_Pin) == LOW && btn2_Pressed == true){
    btn2_Pressed = false;
  }
 
  //倒轉一圈
  myStepper.step(-stepsPerRevolution);
  delay(500);
}
