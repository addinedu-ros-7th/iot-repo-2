#include <WiFi.h>

const int LED_drowsy = 13;
bool led_status = LOW;

const int BUZZER_drowsy = 21;

const int BUZZER_back = 14;
bool buzzer_status = LOW;

// 후방 초음파 센서 
const int TRIG_back = 18;  // 초음파 보내는 핀
const int ECHO_back = 19;  // 초음파 받는 핀

// 후방 접근 led
const int LED_back = 4;

// 전방 초음파 센서
const int TRIG_front = 22;
const int ECHO_front = 23;

unsigned long previousMillis_led = 0;
unsigned long previousMillis_buzzer = 0;

// 적외선 센서
const int tcrt_R = 32;  // 오른쪽 적외선 센서
const int tcrt_L = 33;  // 왼쪽 적외선 센서


const char* ssid = "addinedu_class_1(2.4G)";
const char* password = "addinedu1";
WiFiServer server(8080);  // 서버 포트 8080

void setup() 
{
  Serial.begin(9600);
  pinMode(LED_back, OUTPUT);
  pinMode(LED_drowsy, OUTPUT); 

  // 전방 초음파 핀 모드 설정
  pinMode(TRIG_front, OUTPUT);
  pinMode(ECHO_front, INPUT);

  // 후방 초음파 핀 모드 설정
  pinMode(TRIG_back, OUTPUT);
  pinMode(ECHO_back, INPUT);
  
  // 적외선 센서 핀 모드 설정
  pinMode(tcrt_R, INPUT);
  pinMode(tcrt_L, INPUT);
  
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(100);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP()); 

  server.begin();  // 서버 시작
}


// 후진시 led, 부저 제어 함수
void ultra_back_led_buzzer(int distance)
{
  // 정상
  
  if (distance > 20)
  {
    
    digitalWrite(LED_back, LOW);
    noTone(BUZZER_back);  // 부저 안울림
    // tone(BUZZER_drowsy, 262);
  }

  // 경고  
  // 이때, 모터 속도가 줄어들면서 서행 해야 함.
  else if (distance > 10)  
  {
    unsigned long currentMillis_led = millis();

    if (currentMillis_led - previousMillis_led >= 200)
    {
      previousMillis_led = currentMillis_led;

      // led 스위치
      led_status = !led_status;
      digitalWrite(LED_back, led_status);

      // 부저 스위치
      buzzer_status = !buzzer_status;

      if (buzzer_status)
      {
        tone(BUZZER_back, 262); // 부저 on
      }
      else
      {
        noTone(BUZZER_back);     // 소리 멈춤
      }
    }
  }

  else
  {
    unsigned long currentMillis_buzzer = millis();

    if (currentMillis_buzzer - previousMillis_buzzer >= 3)
    {
      previousMillis_buzzer = currentMillis_buzzer;

      // 부저 스위치
      buzzer_status = !buzzer_status;

      if (buzzer_status)
      {
        tone(BUZZER_back, 262); // 부저 on
      }
      else
      {
        noTone(BUZZER_back);     // 소리 멈춤
      }
    }

    digitalWrite(LED_back, HIGH);
    // noTone(BUZZER_drowsy);  // 부저 안울림
    //tone(BUZZER_drowsy, 262);
  }

}


// 전방 초음파 발생 함수
int front_ultra() 
{
  long duration_front, distance_front;

  digitalWrite(TRIG_front, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_front, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_front, LOW);
  duration_front = pulseIn(ECHO_front, HIGH);  // 초음파 받는 시간, echo 핀에 초음파 신호가 들어오는 시간을 pulseIn 을 통해 측정

  distance_front = duration_front * 17 / 1000;  // cm 로 환산

  return distance_front;
}


// 후방 초음파 발생 함수
int back_ultra()
{
  long duration_back, distance_back;

  digitalWrite(TRIG_back, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_back, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_back, LOW);
  duration_back = pulseIn(ECHO_back, HIGH);  // 초음파 받는 시간, echo 핀에 초음파 신호가 들어오는 시간을 pulseIn 을 통해 측정

  distance_back = duration_back * 17 / 1000;  // cm 로 환산

  return distance_back;
}

// 장애물 인식이 우선시 되야 함.
// 우노 보드로 문자열 보내는 함수
void send_trct_signal(int R, int L)
{
  // 직진
  if ((R == 1) && (L == 1))
  {
    Serial.println("전진");
  }
  
  // 오른쪽 적외선 센서 인식되면 좌회전
  else if ((R == 0) && (L == 1))
  {
    Serial.println("좌");
  }

  // 왼쪽 적외선 센서 인식되면 우회전
  else if ((R == 1) && (L == 0))
  {
    Serial.println("우");
  }
}


bool go = false;
bool stop = false;
bool back = false;
bool drowsy = false;

void loop() 
{
  //long duration_front, distance_front, duration_back, distance_back;

  WiFiClient client = server.available();

  while (client.connected())
  {
    client.setTimeout(10);

    // 데이터를 파이썬으로부터 받을 때 --------------------------------------------------------------------------------------
    String data = client.readString();
    Serial.println(data);

    if (data[0]=='1')
    {
      go = true;
    }
    else if (data[0]=='0')
    {
      go = false;
    }

    // 멈췄을 때
    if (data[1]=='1')
    {
      stop = true;
    }
    else if (data[1]=='0')
    {
      stop = false;
    }

    // 뒤로 갈 때
    if (data[2]=='1')
    {
      back = true;
    }
    else if (data[2]=='0')
    {
      back = false;
    }

    if (data[3]=='1')
    {
      drowsy = true;
    }
    else if (data[3]=='0')
    {
      drowsy = false;
    }


    // 졸음운전할 때
    if (drowsy)
    {
      tone(BUZZER_drowsy, 262);
      digitalWrite(LED_drowsy, HIGH);
    }
    else
    {
      noTone(BUZZER_drowsy);
      digitalWrite(LED_drowsy, LOW);
      // 앞으로 갈 때
      if (go)
      {
        // 후진 LED, 부저 무조건 끄기
        digitalWrite(LED_back, LOW);
        noTone(BUZZER_drowsy);
        // client 로 값 보내기

        // 전방 초음파 센서 측정 값
        int distance_front = front_ultra();
        int lane_R = digitalRead(tcrt_R);
        int lane_L = digitalRead(tcrt_L);

        String data_ultra_lane = String(distance_front) + " " + "L" + String(lane_L) + " " + "R" + String(lane_R);

        client.println(data_ultra_lane);

        // 전진 누르면 자율주행 시작
        // 센서 값을 읽어서 전진, 좌, 우 값을 실시간으로 보냄.
        send_trct_signal(lane_R, lane_L);
        
        if (distance_front < 10)
        {
       	   Serial.println("정지")
        }
        
      }

      // 멈췄을 때
      else if (stop)
      {
        client.println(front_ultra());

        // 우노 보드로 신호 보내줌
        Serial.println("정지");

        // 모터 멈추기 코드
      }

      // 뒤로 갈 때
      else if (back)
      {
        // led 점등 및 부저 울리기
        int distance_back = back_ultra();
        ultra_back_led_buzzer(distance_back);
        // client 로 값 보내기
        client.println(distance_back);

        // 우노 보드로 신호 보내줌
        Serial.println("후진");

        // 특정 거리 이상 가까워지면 정지
        if (distance_back < 10)
        {
          Serial.println("정지");

        }
      }
    }
  }
}



