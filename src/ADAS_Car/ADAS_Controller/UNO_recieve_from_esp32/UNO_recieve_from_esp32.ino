// ESP 에서 보낸 신호를 아두이노 우노에서 받는 코드
// ESP 의 TXD 를 아두이노 우노의 RX 에 연결
// 값을 받기만 하므로 우노의 TX 는 연결하지 않아도 됨.
const int motor_R = 6;  // 오른쪽 모터
const int motor_R_forward = 7;  // 오른쪽 정방향
const int motor_R_reverse = 8;  // 오른쪽 역박향

const int motor_L = 3;
const int motor_L_forward = 4;  // 왼쪽 정방향
const int motor_L_reverse = 5;  // 왼쪽 역박향


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motor_R, OUTPUT);
  pinMode(motor_R_forward, OUTPUT);
  pinMode(motor_R_reverse, OUTPUT);

  pinMode(motor_L, OUTPUT);
  pinMode(motor_L_forward, OUTPUT);
  pinMode(motor_L_reverse, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 양 쪽 적외선 센서 값을 가져오기
  if (Serial.available())
  {
    String data = Serial.readStringUntil('\n');
    data.trim();  // 앞 뒤 공백 및 개행문자 제거

    if (data == "전진")
    {
      //Serial.println("전진");

      analogWrite(motor_R, 110);
      digitalWrite(motor_R_forward, HIGH);
      digitalWrite(motor_R_reverse, LOW);

      analogWrite(motor_L, 110);
      digitalWrite(motor_L_forward, HIGH);
      digitalWrite(motor_L_reverse, LOW);
    }

    else if (data == "후진")
    {
      //Serial.println("후진");

      analogWrite(motor_R, 110);
      digitalWrite(motor_R_forward, LOW);
      digitalWrite(motor_R_reverse, HIGH);

      analogWrite(motor_L, 110);
      digitalWrite(motor_L_forward, LOW);
      digitalWrite(motor_L_reverse, HIGH);
    }

    else if (data == "정지")
    {
      //Serial.println("정지");

      analogWrite(motor_R, 0);

      analogWrite(motor_L, 0);

    }

    // 좌회전
    else if (data == "좌")
    {
      //Serial.println("조향");
      analogWrite(motor_R, 150);
      digitalWrite(motor_R_forward, LOW);
      digitalWrite(motor_R_reverse, HIGH);

      //analogWrite(motor_L, 0);

      analogWrite(motor_L, 150);
      digitalWrite(motor_L_forward, LOW);
      digitalWrite(motor_L_reverse, HIGH);
      delay(100);

      analogWrite(motor_R, 150);
      digitalWrite(motor_R_forward, HIGH);
      digitalWrite(motor_R_reverse, LOW);

      //analogWrite(motor_L, 0);

      analogWrite(motor_L, 150);
      digitalWrite(motor_L_forward, LOW);
      digitalWrite(motor_L_reverse, HIGH);
      delay(300);

    }

    // 우회전
    else if (data == "우")
    {
      //Serial.println("조향");
      analogWrite(motor_L, 100);
      digitalWrite(motor_L_forward, LOW);
      digitalWrite(motor_L_reverse, HIGH);

      //analogWrite(motor_R, 0);

      analogWrite(motor_R, 100);
      digitalWrite(motor_R_forward, LOW);
      digitalWrite(motor_R_reverse, HIGH);
      delay(100);

      analogWrite(motor_L, 100);
      digitalWrite(motor_L_forward, HIGH);
      digitalWrite(motor_L_reverse, LOW);

      //analogWrite(motor_R, 0);

      analogWrite(motor_R, 100);
      digitalWrite(motor_R_forward, LOW);
      digitalWrite(motor_R_reverse, HIGH);
      delay(300);
    }
  }
}
