<img src="https://capsule-render.vercel.app/api?type=waving&color=1e2699&height=150&section=header&text=Ball_and_Beam Project&fontSize=50&fontColor=ffffff" />

<a href="https://youtu.be/9qptE6XTPzs"><img src="https://img.shields.io/badge/YouTube-FF0000?style=for-the-badge&logo=youtube&logoColor=white&link=https://youtu.be/9qptE6XTPzs"></a>



# **목차**
-[개요](#개요)
  
-[게임설명](#게임설명)

## **개요**
- ✏️**프로젝트 주제**✏️ : 공을 움직이고 제어하는 시스템의 설계 및 조정
- 📆**프로젝트 지속기간**📆 : 2022.11~2022.12
- 💻**개발환경 및 개발언어**💻 :
  
  ![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)

  ![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
  
  
## **게임설명**

-[메인게임](#메인게임)

-[미니게임1](#미니게임1)

-[미니게임2](#미니게임2)

-[미니게임3](#미니게임3)




### **메인게임** : 몬스터를 피해 생존자를 구해라
- 인간 측 플레이어 승리 및 패배 조건 : 생존자 3명 중 2명을 구해 마을을 탈출하게 되면 승, 마을을 탈출하기 전에 체력이 다 소진되면 패배하게 됩니다
- 몬스터 측 플레이어 승리 및 패배 조건 : 인간 측 플레이어가 생존자를 2명 이상 구하지 못하게 하거나 체력이 모두 소진되게 하면 승리합니다. 인간 츩 플레이어가 생존자를 구하여 마을을 탈출하면 패배하게 됩니다.
- 이 게임을 진행하면서 생존자를 납치한 몬스터가 있는 칸에 도달하게 되면 미니게임을 시작하여 미니게임을 이기게 되면 생존자를 1명 구할 수 있게 됩니다.
- 인간 측 플레이어는 칸을 움직일 때마다 일정 체력을 소진하게 됩니다.
- 몬스터 측 플레이어가 인간 측 플레이어와 접촉할 경우 인간 측 플레이어는 큰 체력을 소진하게 되며 둘의 자리가 바뀌게 됩니다.
- 인간 측 플레이어는 체력 회복 칸에 가면 일정량의 체력을 회복할 수 있습니다.
- 몬스터는 게임을 시작한 직후 금지벽 3개를 설치할 수 있습니다.
- 인간 측 플레이어가 모든 미니게임 칸을 한번씩 가게되면 게임이 종료되며 누가 승리하였는지 판별하게 됩니다.
- 단, 인간 츨 플레이어가 모든 미니게임에 도달하지 못하였어도 인간 플레이어의 체력이 모두 소진되면 게임이 바로 종료되며 인간 플레이어는 패배하게 됩니다.
- 말은 양측 플레이어가 번갈아가며 주사위를 굴려 주사위에 나온 수만큼 동,서,남,북을 지정하여 움직이게 됩니다.
  
![image](https://github.com/SeoooooNyeong/Game_Project_Java/assets/113419106/3d005da5-5ff0-43c3-918d-8eabddcf1dda)

🟣 - 일반칸

⭕ - 인간 플레이어 말

❤ - 체력 추가칸

💲 - 미니게임 시작칸

👹 - 몬스터 플레이어 말

🚫 - 갈수 없는 벽


### **미니게임1** 

<img src = "https://github.com/SeoooooNyeong/Game_Project_Java/assets/113419106/5504719d-1aab-41d8-8d0a-68637194cfc5" width="650px">

### **미니게임2**

<img src = "https://github.com/SeoooooNyeong/Game_Project_Java/assets/113419106/c05ad5cf-1e7a-4143-8ed1-64cb92eb5c18" width="650px">

### **미니게임3**

<img src = "https://github.com/SeoooooNyeong/Game_Project_Java/assets/113419106/11b9bb2a-0152-4b45-9d6c-1d2375eb3d56" width="650px">
