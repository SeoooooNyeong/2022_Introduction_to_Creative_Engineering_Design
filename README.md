
<img src="https://capsule-render.vercel.app/api?type=waving&color=ab51ef&height=150&section=header&text=Ball_and_Beam Project&fontSize=50&fontColor=ffffff"/>

<a href="https://youtu.be/9qptE6XTPzs"><img src="https://studio.youtube.com/video/EEtzcdL9Sp0/edit?style=for-the-badge&logo=youtube&logoColor=white&link=https://youtu.be/9qptE6XTPzs"></a>



# **목차**
- [개요](#개요)
  
- [BangBangControl](#BangBangControl)

- [PidControl](#PidControl)

## **개요**
- ✏️**프로젝트 주제**✏️ : 공을 움직이고 제어하는 시스템의 설계 및 조정
- 📆**프로젝트 지속기간**📆 : 2022.11~2022.12
- 💻**개발환경 및 개발언어**💻 :
  
  ![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)

  ![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
  
  
## **BangBangControl**
- Band-bang Control : 시스템의 출력을 두 가지 상태 중 하나로만 전환시키는 방식.
- 주어진 입력 조건에 따라 출력을 두 가지 상태 중 하나로만 바꾸는 간단한 제어 방식.
- 공과 빔(수평으로 놓인 막대) 사이에 공을 움직이는 제어 시스템
- 빔의 기울기를 조절하여 공의 위치를 제어
- 공의 위치를 측정하고 원하는 위치로 공을 이동시키기 위해 빔의 기울기를 조정
- 빔의 기울기를 두 가지 값 중 하나로만 전환시켜서 공의 위치 조절


## **PidControl**
- PID : P(비례), I(적분), D(미분)
- P : 비례 제어는 현재 오차에 비례하는 제어 출력을 생성. 만약 공이 원하는 위치에서 멀리 떨어져 있다면, 비례 제어는 빔을 강하게 기울여 오차를 빨리 줄이도록 하며, 오차가 줄어들면 빔의 기울기도 줄어듦
- I : 적분 제어는 과거의 오차를 누적하여 제어 출력을 조절. 오차를 제로로 수렴시키기 위해 사용. 과거에 오차가 적절히 줄어들지 않았을 때, 적분 제어는 오차를 보상하기 위해 누적 오차를 사용
- D : 미분 제어는 오차의 변화율을 감지하고 제어 출력을 안정화. 오차의 급격한 변화를 예방하고 시스템을 안정화시키는 데 사용. 빠르게 움직이는 공의 위치를 안정화하는 데 미분 제어 사용
- PID 제어는 비례, 적분 및 미분 요소의 가중합으로 제어 출력을 계산
- PID 제어로 공의 위치를 정확하게 원하는 위치로 이동시킴, 빔의 기울기를 조절하여 제어 출력 생성
- 오차를 최소화하고 시스템을 안정화시키기 위해 비례, 적분 및 미분 요소를 조합하여 제어 출력 계
