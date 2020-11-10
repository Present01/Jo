#블루투스와 아두이노의 양방향 제어하기

깃허브 링크(조현재): https://github.com/Present01/Jo 

유튜브 링크(조은경): https://youtu.be/nr_zcJOILfc

**소감문은 맨 아래에 있습니다.**

ANU assignment

**주제 : 휴대폰으로 밝기를 확인하며 연주를 해보자**

**서론 :**
**저희 2팀은 스마트폰-> 블루투스-> 아두이노 부분에 대해서는 작은 피아노를 구현해 내었고 아두이노 -> 블루투스 -> 스마트폰에 대해서는 빛의 밝기를 수치와 가시적인 색으로 표현하도록 구현하였습니다.**

**아두이노 회로**

![10](https://user-images.githubusercontent.com/36477051/98627509-c4741180-2357-11eb-9e38-2e7a3d546535.PNG) 

![1](https://user-images.githubusercontent.com/36477051/98627524-cb9b1f80-2357-11eb-80c9-98984ffa65e1.PNG)

위의 그림은 전체적으로 보았을 때의 아두이노 회로입니다.
위의 그림 부분은 블루투스를 연결하기 위한 부분으로서 VCC-5V GND-GND TXD-2 RXD-3 으로 연결되어있습니다. 특이점이 있다면 5V 연결(붉은 선)이 있습니다. 5V는 조도 센서에서도 저렇게 브레드보드(빵판)의 버스띠(전원공급)에 따로 연결하였습니다. 그리고 5V에 직접적으로 연결되는 회로도 버스띠에 따로 연결하게 되어 병렬연결이 가능해집니다.

![2](https://user-images.githubusercontent.com/36477051/98627527-cc33b600-2357-11eb-900f-c066e432d509.PNG)

조도 센서는 위에 말했듯이 5V를 병렬로 연결하기 위해 버스띠에 연결합니다. 다른 회로 연결 부분은 중복되는 경우가 없기에 바로 연결하여 중간에는 A0(회색선)를 조도 센서 회로의 또 다른 끝은 GND(하늘색 선)을 연결했습니다.

![3](https://user-images.githubusercontent.com/36477051/98627528-cccc4c80-2357-11eb-96e6-7b310537c80d.PNG)

피에조 스피커는 병렬로 연결할 필요가 없기에 바로 연결하는데 주의할 점은 (+)극과 (-)극을 구분해서 연결하는 것으로 (+)극에는 4번 핀에 (-)극에는 GND를 연결했습니다.

**아두이노**

![4](https://user-images.githubusercontent.com/36477051/98627529-cccc4c80-2357-11eb-8b79-4f300c775379.PNG)

위의 두 사진은 연결되어있는 사진입니다. 

![5](https://user-images.githubusercontent.com/36477051/98627543-d0f86a00-2357-11eb-8d31-1787fd225000.PNG)



소프트웨어 시리얼(SoftwareSerial)은 블루투스(tx=3, rx=2)를 이용하기 위한 것이고 변수 lon의 값은 250으로 설정했습니다. 또한 소프트웨어 시리얼과 시리얼을 사용할 수 있도록 설정했습니다.
a 변수는 A0를 읽어오는 변수로 조도값을 읽어옵니다. 그 밑의 BTSerial.println(a); 덕에 읽어온 조도값이 블루투스를 통해 블루투스에 연결된 곳으로 가게 되었습니다. 이 활동은 0.5초마다 반복하게 됩니다. 변수 btval는 블루투스로 온 값을 저장합니다.

![6](https://user-images.githubusercontent.com/36477051/98627544-d2299700-2357-11eb-8441-f8a391b0f32c.PNG)

그 후 위의 사진처럼 블루투스에서 온 값인 btval을 조건으로 하여 tone함수를 이용해 작은 피아노 연주가 가능해집니다. 또한 한 음의 지속시간은 변수 lon으로 250 (1/4 박자)입니다.

![7](https://user-images.githubusercontent.com/36477051/98627545-d2299700-2357-11eb-8911-fecc4f4a9f25.PNG)

**앱인벤터**

![8](https://user-images.githubusercontent.com/36477051/98627546-d2c22d80-2357-11eb-8369-c73b17beccbd.PNG)

Clock 센서를 활용하여 0.5초 간격으로 데이터를 받았고, if-then 블록을 중첩하여 앱을 만들었습니다. 
첫 번째 if 조건은 블루투스클라이언트 데이터가 0보다 크다고 두어 데이터가 오면 이라는 조건을 표현했고 then으로 텍스트 레이블(밝기)에 블루투스(아두이노)로 받은 조도 값을 출력해줍니다. 다음 if-then 중첩을 활용하여 입력받은 조도값을 기준으로 색 레이블을 다음과 같이 표현했습니다.

400 이상 연한 노란색
400~300 노란색
300 미만 갈색
200 미만 검은색

![9](https://user-images.githubusercontent.com/36477051/98627547-d35ac400-2357-11eb-9c90-ce371e96bb73.PNG)

ErrorOccurred 블록을 사용하여 오류발생시 오류를 처리하고 ListPicker를 통해 블루투스가 연결되기 전과 후를 구별하여 전에는 주변 블루투스를 모두 수집하여 ListPicker elements(요소)값에 주소를 저장하고 After에는 선택된 블루투스를 연결하고 연결됨이라는 문구를 라벨1에 출력하도록 했습니다.

앱 디자인을 고려하여 “표 형식 배치”를 사용하여 버튼 10개를 앱 화면에 만들어 각 음계를 표현하도록 했고 각 음계에 해당하는 번호를 아두이노로 btval 값으로 전송해주어 아두이노에서 tone 함수의 조건으로 구별되는 값을 제공해주는 역할을 하도록 했습니다.

----

**소감문**

20201109 장지현

앱인벤터로 피에조 스피커를 작은 피아노처럼 쓰니 신기하기도 했고 재밌었고 아두이노회로를 보며 여러부품이 있을때의 구성등을 이해하게되었습니다 병렬로 연결하는 것에 대해서 굉장히 흥미로웠습니다. 또한 빵판에 대해 구성이나 구조에 더욱 알게되어 좋았습니다

20201111 조현재

피에조스피커와 블루투스 모듈을 이용해서 스마트폰의 버튼을 누르면 피아노처럼 한옥타브의 소리를 낼 수 있도록 만들어보았습니다. 처음 아이디어 구상 단계에서는 과연 잘 될까 의문이 들었지만 열심히 한 덕분에 아주 만족스러운 결과가 나올 수 있었습니다. 깃허브에 파일을 올리는것 또한 이번기회에 처음 해보았는데 CMD를 통해서 올려야 해서 좀 까다로웠습니다. 깃허브를 사용한것이 되게 좋은 경험이였던것 같습니다. 

20201110 조은경

조원들과 의견을 나누고 함께 창작활동을 한다는 것은 참 재미있는것 같습니다. 의견을 모아서 더 나은 창작물이 나왔고 자잘한 실수를 발견할 수 있었습니다. 이번작업을 하며 앱인벤터에서 신호를 받는 딜레이 설정이 잘못되어 오류가나면서 시간설정의 중요성을 깨달았습니다.

