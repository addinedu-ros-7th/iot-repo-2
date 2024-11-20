![Screenshot from 2024-11-20 09-38-47](https://github.com/user-attachments/assets/2ba343ba-9110-4084-9c7b-d432856a9d08)

---
# 1. Project Overview 
- 갑작스러운 상황 변화 <br>
- 운전자의 졸음 운전 <br>
- 센서를 통한 장애물 탐지 <br>
- 센서를 통한 차선 인식 <br>
- 딥러닝을 이용한 운전자 모니터링 <br>
- 운전 보조 기능 개발 <br>
- 안전 운전을 통한 사고율 감소 <br>

---
# 2. Team Name & Responsibility
## **Assistant Driving AngelS (ADAS) <br> IoT를 활용한 차량 보조 시스템 개발**

**팀원 및 담당 업무**
|이름|담당 업무|
|:---:|---|
|**이상범(팀장)**|데이터 수집, 졸음 감지 코드 작성, GUI 화면 구성, 통신 연결, Github 관리|
|**김완섭(팀원)**|도로 설계 및 구성, 도로 구현, 적외선 연결, Github 관리, PPT 자료 준비|
|**이영훈(팀원)**|모터 드라이버 연결, 모터 연결, 모터 동작 코드 작성|
|**윤희태(팀원)**|LED센서, 부저, 초음파, 적외선 연결, 통신 연결|
---
# 3. Stacks
<div align=center>

  <img src="https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=Ubuntu&logoColor=white"/>
  <img src="https://img.shields.io/badge/python-3776AB?style=for-the-badge&logo=python&logoColor=white"> 
  <img src="https://img.shields.io/badge/c++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white">
  <img src="https://img.shields.io/badge/Visual Studio Code-007ACC?style=for-the-badge&logo=Visual Studio Code&logoColor=white"/>
  <br>

  <img src="https://img.shields.io/badge/github-181717?style=for-the-badge&logo=github&logoColor=white">
  <img src="https://img.shields.io/badge/jira-0052CC?style=for-the-badge&logo=jira&logoColor=white">
  <img src="https://img.shields.io/badge/confluence-0052CC?style=for-the-badge&logo=confluence&logoColor=white">
  <img src="https://img.shields.io/badge/slack-FFD700?style=for-the-badge&logo=slack&logoColor=white">
  <img src="https://img.shields.io/badge/arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white">
  <br>

</div>

---
# 4. Plan 
## **4-1. Feature List**
||분류|Function(기능)|Description(구체화)|우선순위|
|:---:|:---:|:---:|---|:---:|
|1|인식 기능|차선 인식|* 적외선 센서를 이용한 차량 양쪽의 차선 인식|1|
| |       |       |* 인공지능 딥 러닝 모델을 활용해 차선 인식 정밀도 향상|3|
| |       |장애물 인식|* 초음파 센서를 이용한 차량 전,후방의 장애물 인식|1|
| |       |졸음 인식|* 인공지능 딥 러닝 모델을 활용해 운전자의 상태 모니터링|2|
|2|주행 기능|전진|* 양 쪽 모터를 정방향으로 회전시켜 차량 전진|1|
| |       |후진|* 양 쪽 모터를 역방향으로 회전시켜 차량 후진|2|
| |       |정지|* 양 쪽 모터 회전 수를 '0'으로 지정해 차량 정지|1|
| |       |감속|* 운전자의 졸음이 감지되면 우선 감속하여 주행|2|
| |       |조향|* 우회전 시 오른쪽 모터의 회전 수를 줄이거나 왼쪽 모터의 <br> 회전 수를 늘려 차량을 우회전|1|
| |       |   |* 좌회전 시 왼쪽 모터의 회전 수를 줄이거나 오른쪽 모터의 <br> 회전 수를 늘려 차량을 좌회전|1|
| |       |   |* 장애물이 인식되면 차량이 장애물을 회피하여 주행|3|
|3|알림 기능|후방 경고|* 차량 후방에 장애물이 인식되면 운전자에게 부저나 <br> LED를 통해 경고|2|
| |       |졸음 경고|* 운전자의 졸음이 감지되면 운전자에게 부저를 통해 경고|2|

## **4-2. Software Configuration**
![image](https://github.com/user-attachments/assets/efd6ef97-082f-46c6-a171-f4b5327aa9bb)

## **4-3. Hardware Cofiguration**
![하드웨어 구성도](https://github.com/user-attachments/assets/90a6210c-9264-49de-bc56-8c441f315d18)

## **4-4. GUI Interface**
- 전원 버튼 : 시스템 전원 ON/OFF <br>
- 방향 조향 키 : 앞 / 뒤 / 정지 <br>
- INNER CAM : 사용자 얼굴 인터페이스 <br>
- Direction : 진행방향 표시 <br>
- Distance : 앞/뒤 사물간 거리 표시 <br>
- Lane : 차선 인식 여부 표시 <br>
- Drowsy : 졸음 여부 표시 <br>
![GUI 인터페이스](https://github.com/user-attachments/assets/210d9ade-bd1b-4855-a5de-5987709cd7ca)

## **4-5. Road Design**
- 도로 주행 간 차선 인식, 장애물 인식 등 다양한 상황을 고려하여 도로 설계를 진행
![Screenshot from 2024-11-19 14-56-14](https://github.com/user-attachments/assets/d4f7fc76-0e54-4110-9648-f726f19836a7)

---
# 5. Review
## 5-1. 결과 및 기대효과
- 장애물 탐지 및 차선 탐지
- 센서 정보를 이용하여 차량 컨트롤 및 경고등 및 알림 확인
- 운전자 보조 기능 개발
  
## 5-2. 문제점 및 개선방안
- **곡선 도로 주행 시, 차선 이탈** <br>
  - 적외선 센서 감도 조절 <br>
  - 바퀴 테이핑을 통한 바퀴 마찰력 증가 <br>
  - 차선 인식 시, 약간의 후진을 통해 차선 이탈률 감소 <br>
  - 바퀴 회전력과 회전 시간을 추가하여 더욱 많이 회전하도록 함 <br>

- **무선 통신 시, 메모리 병목현상 발생** <br>
  - 여러 개의 통신 신호를 한줄로 입력하여 송수신 <br>
  - settimeout 함수를 통해 데이터가 버퍼상에 머물러 있는 시간을 줄임 <br>
  - 전력이 부족할 경우 무선 통신이 잘되지 않아 보조 배터리 활용하여 test 진행 <br>
  - 원활한 통신을 위해 개인용 핫스팟 사용
