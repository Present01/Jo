#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2,3);  // tx = 2, rx = 3 번 핀 사용

int lon = 250;  // 1/4 박자

void setup(){
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop(){
  int a = analogRead(A0);
  BTSerial.println(a);
  delay(500);
  int btval = BTSerial.read();  // 블루투스 모듈 값 입력
 // Serial.println(btval);  // btval 값 출력 
  
  if(btval == 0){
    tone(4, 262, lon);  // 도
  }else if(btval == 1){
    tone(4, 294, lon);  // 레
  }else if(btval == 2){
    tone(4, 330, lon);  // 미
  }else if(btval == 3){
    tone(4, 349, lon);  // 파
  }else if(btval == 4){
    tone(4, 392, lon);  // 솔
  }else if(btval == 5){
    tone(4, 440, lon);  // 라
  }else if(btval == 6){
    tone(4, 494, lon);  // 시
  }else if(btval == 7){
    tone(4, 523, lon);  // 도
  }else if(btval == 8){
    tone(4, 588, lon);  // 레
  }else if(btval == 9){
    tone(4, 660, lon);  // 미
  }
}
