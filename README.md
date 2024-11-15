# iot-repo-2
---
# 1. Project Overview 
- 운전자 부주의 또는 갑작스런 상황 변화로 인한 사고를 예방하고자 함 <br>
- 아두이노 센서를 이용하여 ‘장애물 탐지 및 차선 탐지' 진행 <br>
- 센서 정보를 이용하여 ‘차량 모터 컨트롤’ 및 ‘경고등 점등’ 수행 <br>
- 운전보조 및 경고 시스템을 통해 운전자 보조 기능 개발
---
# 2. Team Name & Responsibility
## **Assistant Driving AngelS (ADAS) <br> IoT를 활용한 차량 보조 시스템 개발**

**팀원 및 담당 업무**
|이름|담당 업무|
|:---:|---|
|**이상범(팀장)**|PyQt UI 구성 및 코드 구현, DB 관리, Github 관리|
|**김완섭(팀원)**|도로 설계 및 구성, 조립, Github 관리|
|**이영훈(팀원)**|아두이노 코드 구현|
|**윤희태(팀원)**|아두이노 코드 구현|
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
  <br>
  
  <img src="https://img.shields.io/badge/arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white">
  <img src="https://img.shields.io/badge/mysql-4479A1?style=for-the-badge&logo=mysql&logoColor=white"> 
  <br>

</div>

---
# 4. Plan 
## **4-1. Feature List**
||분류|Function(기능)|Description(구체화)|우선순위|
|:---:|:---:|:---:|---|:---:|
|1|인식 기능|차선 인식|* 적외선 센서를 이용한 차량 양쪽의 차선 인식|1|
| |       |       |* 인공지능 딥 러닝 모델을 활용해 차선 인식 정밀도 향상|3|
| |       |도로 인식|* 인공지능 딥 러닝 모델을 활용해 교차로 인식|3|
| |       |장애물 인식|* 초음파 센서를 이용한 차량 전,후방의 장애물 인식|1|
| |       |졸음 인식|* 인공지능 딥 러닝 모델을 활용해 운전자의 상태 모니터링|2|
|2|주행 기능|전진|* 양 쪽 모터를 정방향으로 회전시켜 차량 전진|1|
| |       |후진|* 양 쪽 모터를 역방향으로 회전시켜 차량 후진|2|
| |       |정지|* 양 쪽 모터 회전 수를 '0'으로 지정해 차량 정지|1|
| |       |감속|* 운전자의 졸음이 감지되면 우선 감속하여 주행|2|
| |       |조향|* 우회전 시 오른쪽 모니터의 회전 수를 줄이거나 왼쪽 모터의 <br> 회전 수를 늘려 차량을 우회전|1|
| |       |   |* 좌회전 시 왼쪽 모니터의 회전 수를 줄이거나 오른쪽 모터의 <br> 회전 수를 늘려 차량을 좌회전|1|
| |       |   |* 장애물이 인식되면 차량이 장애물을 회피하여 주행|3|
|3|알림 기능|후방 경고|* 차량 후방에 장애물이 인식되면 운전자에게 부저나 <br> LED를 통해 경고|2|
| |       |졸음 경고|* 운전자의 졸음이 감지되면 운전자에게 부저를 통해 경고|2|

## **4-2. Software Configuration**
![image](https://github.com/user-attachments/assets/efd6ef97-082f-46c6-a171-f4b5327aa9bb)

## **4-3. Hardware Cofiguration**
![image](https://github.com/user-attachments/assets/cf4ee31b-9634-4cfa-b58b-7e0264ffbbea)

## **4-4. GUI Interface**
- 전원 버튼 : 시스템 전원 ON/OFF <br>
- 방향 조향 키 : 앞 / 뒤 / 정지 <br>
- CAM1 : 사용자 얼굴 인터페이스 <br>
- CAM2 : 도로 주행 상황 인터페이스 <br>
- Direction : 진행방향 표시 <br>
- Distance : 앞/뒤 사물간 거리 표시 <br>
- Object : CAM2에서 인식된 사물 정보 표시 <br>
- Lane : 차선 인식 여부 표시 <br>
- Drowsy : 졸음 여부 표시 <br>
![Screenshot from 2024-11-13 15-58-57](https://github.com/user-attachments/assets/0ce044d0-dad1-4b2b-8fae-c3c2957d07c2)

## **4-5. Road Design**
- 도로 주행 간 차선 인식, 장애물 인식 등 다양한 상황을 고려하여 도로 설계를 진행
![Screenshot from 2024-11-13 16-22-02](https://github.com/user-attachments/assets/3f5275ba-c6d3-4e85-b924-207060893967)
---
# 5. Review
## 5-1. 결과 및 기대효과

## 5-2. 문제점 및 개선방안

## 5-3. 소감
|이름|소감|
|:---:|---|
|**이상범(팀장)**||
|**김완섭(팀원)**|정말 다양한 소프트웨어와 하드웨어를 연동 시키는 과정에서 어려움을 겪었지만, <br> 색다른 경험을 하였습니다.|
|**이영훈(팀원)**||
|**윤희태(팀원)**||
