# 2학년 1학기 과제
---

## 목차
1. 자료구조

    1.1. [2차원 배열](#2차원-배열)
    
    1.2. [재귀호출1](#재귀호출1)
    
    1.3. [재귀호출2](#재귀호출2)
    
    1.4. [ppm 이미지 표현](#ppm-이미지-표현)
    
    1.5. [원형 큐](#원형-큐)
    
    1.6. [서점 재고 관리](#서점-재고-관리)

    1.7. [infix to posfix](#infix-to-posfix)
    
2. 객체지향언어
    
    2.1. [ATM기계](#ATM기계)
    
    2.2. [다형성 활용](#다형성-활용)
    
    2.3. [영화 티켓박스](#영화-티켓박스)
    
---
   
# 1. 자료구조

## 2차원 배열

두 행렬의 곱을 계산하는 프로그램을 작성하시오.

### 개념
    2차원 배열, 동적 할당, 파일 처리

### 조건
    1. 파일로 두 행렬을 입력
    2. fopen 사용
    3. 두 행렬의 곱에 대한 결과 화면 출력

---
    
## 재귀호출1

입력된 정수의 각 자리 수를 더하는 프로그램을 순환방식으로 작성하시오.

### 예시
    결과 : 236 -> 11
    
---
    
## 재귀호출2

두 정수의 LCM을 구하는 프로그램을 순환방식으로 작성하시오.

### 예시
    결과 : 5 2 -> 10
    
---

## ppm 이미지 표현

지표면의 고도를 나타내는 데이터를 입력 받아 이미지로 표현하는 프로그램을 작성하시오.

입력 받은 데이터를 RGB 값으로 계산한 이후 새로운 이미지 파일을 생성하여 이를 출력하는 프로그램으로 플로우는 다음과 같다.

1. 데이터를 2D 배열로 읽습니다.
2. 각각 가장 어두운 색과 가장 밝은 색에 해당하는 최소 및 최대 표고를 찾습니다.
3. 지도에 있는 각 셀에 대해 회색 음영을 계산합니다.
4. 출력 파일을 지정된 형식(PPM)으로 생성합니다.
5. 온라인 무료 도구를 사용하여 PPM 파일을 JPG 파일로 변환하여 결과를 시각적으로 확인합니다.

1. Step 1 – Read the data into a 2D array 
입력데이터는 텍스트 파일로 지표면의 고도를 나타낸다. 입력데이터에는 3가지 정보가 제공되는데, 
A. Number of rows in the map (height of the image to be produced) 
B. Number of columns in the map (width of the image to be produced) 
C. Name of the file containing the data.

데이터를 입력 받기 전 입력이 정상적인지 아닌지 확인이 필요한데, 만약 입력에 오류가 존재한다면, 다음과 같은 출력을 하면서 프로그램에서 exit 하여야 한다. 
 Error : Problem reading in rows and columns 
 Error : Unable to open file <filename>

데이터 파일은 스페이스로 구별되는 정수들이며 하나의 데이터 집합이다. 480-row by 844-col 데이터는 405,120 (480*844) 정수들을 포함하며, 정수 각각은 한 특정지역(cell)의 평균고도를 나타낸다. 데이터 파일은 row0 에 대해 844 정수들, row 1 에 대한 844 정수들 등 row-major 순서로 만들어졌다.

입력을 받아 프로세스를 하기 전에 파일에 올바른 개수의 정수 데이터가 있는지 확인이 필요하며 만약 오류가 있다면 즉시 필요한 오류를 출력하고 프로그램에서 exit 하여야한다. 
 Error : Read a non-integer value 
 Error : Problem reading the file 
 Error : End of file reached prior to getting all the required data 
 Error : Too many data points

데이터 파일은 line break가 없으며 데이터를 2D array에 넣기 위해서는 파일에서 제공하는 row 외 column 값을 사용하여야 한다. 또한, 오류 없이 데이터가 입력되었는지 확인하기 위하여 제공되는 데이터 파일은 사이즈가 크기 때문에 작은 사이즈의 입력 파일을 만들어 충분한 테스트를 거쳐야 한다. 

2. Step 2 – Find the min and max values 
주어진 입력을 흑백 이미지로 출력하기 위하여 입력된 데이터에서 최소값(min)과 최대값(max)를 찾고 주어진 공식에 대입하면 된다. 이를 위해 먼저, 최소값과 최대값을 찾기 위한 함수 findMaxMin를 작성하여야 한다. 샘플 데이터를 만들어 이 함수가 올바르게 작동되는지 충분히 검토한 후 step 3로 이동하여야 한다. 

3. Step 3 – Compute the color for each part of the map and store 
입력 데이터를 흑백이미지로 출력하기 위하여 입력 데이터 각각에 대한 RGB 값을 계산하여야
한다. 이때 흑백출력임으로 각 데이터에 대하여, 다음 공식을 적용하고 실수로 계산하여 가장
근사한 정수로 변환시키면 된다.

shade of grey = {(elevation – minimumElevation)/(maximumElevation – minimumElevation)}*255

또한, 계산된 정수값을 R, G, B 값으로 동일하게 적용하면 된다. 이때 새로운 2D array를 만들어 계산된 RGB 값을 저장하여야 한다.

위와 같이 고도값(elevation value)에서 흑백 이미지 값으로 변환시키는 프로세스는 loadGreyscale 함수를 만들어 수행해야 한다. 

4. Step 4 – Produce the output file in the PPM format 
RGP 칼라 모델로 이미지를 출력하기 위해서 PPM(portable pixel map의 약자) format으로 output 파일을 만들어야 하며 이를 위해 outputImage 함수를 만들어 PPM 데이터를 output file로 wirte하시오. PPM 포멧으로 output file을 만드는 방법은 output file에 RGB 값을 쓰기 전에 세 가지 정보를 write 하면 되고 output file의 이름을 inputfile name.ppm로 만들면 된다. 즉, 만약 input file 명이 indata.dat라면, input.dat.ppm으로 이름을 만들어야 하며 다음 ppm 파일을 만드는 포멧은 다음과 같다.
 첫번째 줄 : 문자열 “P3” 
 두번째 줄 : width (number of column) 과 height (number of rows) 
 세번째 줄 : max color value (255) 
 나머지 줄 : RGB 값 예

---
   
## 원형 큐
    
1차원 배열을 이용한 원형큐를 구현하시오.

---
    
## 함수
    1. Create : 새로운 empty 큐 생성한다.
    2. Empty : 큐가 empty 인지 확인한다.
    3. Full : 큐가 full 인지 확인한다.
    4. Enqueuer : 새로운 데이터를 queue rear에 삽입한다.
    5. Dequeuer : front에 위치한 데이터 삭제하고 리턴하여 출력한다.
    6. QueueDisplay : 큐에 저장된 모든 데이터 출력한다. 만약 empty일 경우 메시지 출력한다.
    
---
    
## 서점 재고 관리

프로그램은 다음과 같은 기능을 사용자에게 제공하여야 함.

### 조건
    1. 전체 프로그램에 대해 재고를 저장하기 위한 theInventory는
       하나만 메인함수에 선언하여야 한다.
    2. theInventory는 구조체 일차원배열로 구조체는 작가의 이름과
        이 작가의 서적정보를 담는 연결리스트의 주소를 저장할 변수를 포함하여야 한다.
    3. 작가의 이름은 저장하기 전 last name과 first name의
       첫번째 알파벳만 대문자이고 나머진 소문자로 나타내어야 한다.
    4. 서적 정보를 저장할 연결리스트는 서적명, 재고량, 서적당 가격과
        다음 노드를 가르킬 포인터 변수를 포함하는 자기 참조 구조체를 선언해야 한다.

### 기능
    1. 입력된 순서대로 출력한다.
    2. 저자의 이름 순으로 정렬한다.
    3. 특정 작가의 서적을 정렬한다.
    4. 새로운 서적 정보를 입력한다.
    5. 특정 서적의 가격을 변경한다.
    6. 특정 서적의 재고량을 변경한다.
    7. 전체 서적의 재고량을 출력한다.
    8. 전체 서적의 가격을 출력한다.
    9. 종료한다.

### 함수
```
· greeting()
프로그램을 사용하여 고맙다는 표현을 출력하는 함수

· readDatabase (inventory)
사용자에게 입력파일명을 요구하는 함수

· printMenu()
사용자 메뉴를 출력하는 함수

· displayInventory(inventory) 
저자의 정렬 순으로 그리고 저자별로는 책 제목 순으로 재고를 출력하는 함수

· displayAuthorsWork(inventory)
사용자에게 저자명을 요구하고 그 저자의 책 정보를 제목으로 정렬하는 함수

· addBook(inventory)
사용자에게 책 정보를 요구하고 만약 저자가 존재하고 새 책일 경우 정보를 저장하는 함수
만약 저자가 존재하지 않다면, theInvetory에 저자명이 추가되어 그 저자에 대한 정보로 저장하는 함수
* 재고량은 정수, 가격은 양의 실수로 입력

· changePrice(inventory)
사용자에게 가격정보를 변경하기 위해 필요한 저자의 이름과 책 제목을 요구하는 함수
* 양의 실수로 입력

· changeQty(inventory)
사용자에게 재고량을 변경하기 위해 필요한 저자의 이름과 책 제목을 요구하는 함수
* 양의 정수로 입력

· totalQty(inventory)
이 함수는 재고에 있는 모든 책의 개수를 합산하는 함수

· calculateTotalAmount(inventory)
재고에 있는 모든 책의 가격을 합산하는 함수
```

---
    
## infix to posfix
    
중위표기법으로 입력된 수식을 후위표기법으로 변환시켜 수식계산을 하는 프로그램을 작성하시오.

### 조건
    1. 오픈 괄호 ( 다음에 반드시 ( 나 피연산자, 즉 숫자, +, - 가 온다.
    2. 피연산자 다음에 ) 나 연산기호 +, -, *, /, ^ 가 온다.
    3. ( 와 ) 개수는 일치하여야 한다
    4. (, ), 숫자, +, -, *, /, ^ 외 다른 기호는 에러로 처리한다.
    5. 피연산는 정수 및 실수이며 실수의 경우 소수점이 포함된다.
    6. 후위표기법을 이용하여 계산할 때 피연산자는 atof()를 이용하여 문자열을 실수로 변환시킨다.
    
### 알고리즘
    1. 수식 문자열을 입력
    2. Parsing을 통해 수식문법 확인
    3. 중위표기법을 후위표기법으로 스택을 사용하여 변환
    4. 후위표기법 계산
    
---
---
    
# 2. 객체지향언어

## ATM기계
   
아래 기능을 포함하는 ATM기계 프로그램을 작성하시오.
    
### 기능
    1. 계좌 개설 기능
    2. 계좌 조회 기능
    3. 계좌 해지 기능
    4. 업무 종료 기능
    5. 계좌 입금 기능
    6. 계좌 출금 기능
    7. 계좌 이체 기능
    8. 고객 관리 기능 1
       - ATM 잔고, 고객 잔고 총액, 평균, 최고 값 출력
    9. 고객 관리 기능 2
        - 계좌 목록 출력( 잔액 내림차순 정렬 ) - 알고리즘 구현
    
---
    
## 다형성 활용
    
전투용품 샵에서 구매한 전투용 무기를 사용하는 프로그램을 작성하시오.
    
### 조건
    1. Tank, Fighter, Missile 무기는 Weapon 클래스를 상속받는다.
    2. BattleShop은 Shop 클래스를 상속받는다.

---

## 영화 티켓박스

아래 기능을 포함하는 영화 티켓박스 프로그램을 작성하시오.
    
### 기능
    1. 영화 정보 보기
    2. 좌석 예약 현황 보기
    3. 좌석 예약 기능
    4. 좌석 예약 취소
        - 결제 완료 시 예약 취소 불가능
    5. 티켓 결제 기능 
    6. 관리 통계 기능
    
---
