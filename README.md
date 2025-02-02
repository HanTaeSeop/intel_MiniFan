# **intel_MiniFan**
## **프로젝트 개요**
- 프로젝트 기간: 2024.08.06 ~ 2024.08.09
- 주요 기능:
    - 풍량 조절: PWM을 활용해 Low, Middle, High, Auto 모드 구현.
    - 타이머 설정: 10초, 5분, 7분 단위로 자동 종료.
    - LCD 상태 표시: I2C LCD로 실시간 상태 정보 제공.
    - Serial 통신: 원격으로 풍량 및 타이머 제어 가능.
    - 부저 알림: 사용자 이벤트 발생 시 청각 피드백 제공.
## 🛠️ **주요 기술 스택**
| 기술                 | 설명                                             |
|----------------------|--------------------------------------------------|
| **Atmega128A**       | 하드웨어 제어 및 MCU 기반 시스템 개발             |
| **Microchip Studio** | Atmega128A 펌웨어 작성 및 빌드                    |
| **C언어**            | 코드 작성 및 FSM 설계                            |
| **I2C 통신**         | LCD와 FND를 연결해 실시간 상태 표시               |
| **UART 통신**        | Serial 데이터를 통해 원격 제어 구현               |
| **ComPortMaster**        | 시리얼 포트를 통한 데이터 통신을 관리하고 모니터링 하는 소프트웨어      |

## 📂 **디렉토리 구조**

```plaintext
📁 src
├── 📂 AP
│   ├── 📂 Listener         # 이벤트 리스너 구현
│   ├── 📂 Presenter        # UI 상태 갱신 처리
│   ├── 📂 Service          # 비즈니스 로직 처리
│   ├── 📂 Model            # 상태 저장   
│   ├── apMain.c            # 메인 실행 파일
│   └── apMain.h            # 메인 헤더 파일
├── 📂 Driver
│   ├── 📂 Button           # 버튼 입력 처리
│   ├── 📂 Buzzer           # 부저 제어
│   ├── 📂 MORTOR           # 선풍기 모터 제어
│   ├── 📂 FND              # FND 출력 관리
│   └── 📂 LCD              # LCD 출력 제어
├── 📂 Periph
│   ├── GPIO                # GPIO 핀 제어
│   ├── TIM                 # 타이머 인터럽트 처리
│   └── UART0               # UART0 통신 처리

```

##  **프로젝트 주요 기능**

### 1️⃣ **풍량 조절**
- **MANUAL / Auto 모드**:
  - PWM 신호를 사용해 5V DC 모터의 속도 제어.
  - Auto 모드에서는 딜레이를 활용해 0.2초마다 랜덤 풍량 전환.
- **Serial 통신 명령어 (UART0)**:
  - "OFF", "WEAK", "NORMAL", "STRONG" 명령어로 원격 제어 가능.


### 2️⃣ **타이머 설정**
- **타이머 간격**: 10초, 5분, 7분.
- **버튼 입력**:
  - 3번 버튼 클릭 횟수에 따라 타이머 설정.
- **타이머 종료 시 동작**:
  - 설정된 시간이 끝나면 모터가 자동으로 정지.
  - 남은 시간을 FND에 표시.


### 3️⃣ **부저 피드백**
- **PWM 신호를 이용한 부저 동작**:
  - 버튼 클릭 또는 Serial 명령 시 이벤트를 청각적으로 알림.
- **안정적 작동 구현**:
  - 부저 출력 후 일정 딜레이를 적용해 신호 충돌 방지.


### 4️⃣ **LCD 상태 표시**
- **풍량 및 타이머 상태 표시**:
  - I2C 통신 방식으로 LCD에 실시간 정보 표시.
  - 현재 풍량 모드 (Low, Middle, High, Auto) 및 타이머 남은 시간 제공.


### 5️⃣ **Serial 통신 제어**
- **UART 기반**:
  - 원격으로 Atmega128A에 명령 전송 가능.
- **명령어**:
  - `WEAK`, `NORMAL`, `STRONG`, `OFF`와 같은 텍스트 명령어로 모터 및 타이머 제어.
 
###  **SKILL**
1. **타이머 인터럽트**:
   - OVF (OverFlow Interrupt)
     - FND 화면 최신화에 사용 (약 1.008ms)
   - COMP (Compare Match Interrupt)
     - 타이머 시간감소에 사용 (약 1ms) 
2. **UART 통신 처리**:
   - 수신된 명령어를 내부 버퍼에 저장 후 FSM에서 처리.
3. **LCD 업데이트**:
   - I2C 통신으로 풍량 상태와 타이머 정보를 표시.
##  **구현 상세**

###  **FSM 설계**
![alt text](img/MINIFAN_FSM.jpg)

### **S/W STACK**
![alt text](img/SW_stack.jpg)

##  **시연 영상**

### [MANUAL MODE](https://drive.google.com/file/d/1X37EoyOC53tnysK8pTU-ZTfENI0gIBNC/view?usp=drive_link)
![alt text](img/MANUAL.gif)

### [AUTO MODE](https://drive.google.com/file/d/1KGiZ1KC3k27PbFsKsn3VEPB5IdnZiL4e/view?usp=drive_link)
![alt text](img/AUTO.gif)

### [TIMER SETTING](https://drive.google.com/file/d/1XGbKD3ZzHhRqEvff3SPEgFYRt7JN2JAB/view?usp=drive_link)
![alt text](img/REARTIMER.gif)

### [TIMER START](https://drive.google.com/file/d/1ntSNZFDx7lAW5LWSc59XSABkcIeA_7BH/view?usp=drive_link)
![alt text](img/START.gif)

### [NETWORKING](https://drive.google.com/file/d/1nLT0Tv8iwy4gRQx3rUmE-kOZenSzUh3k/view?usp=drive_link)
![alt text](img/UART.gif)


