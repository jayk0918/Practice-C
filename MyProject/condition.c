#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

int main_condition(void) {
	/*
	int age = 59;
	if (age >= 20 && age < 60) {
		printf("일반인\n");
	}
	else if (age >= 60) {
		printf("노인\n");
	}	
	else {
		printf("학생\n");
	}
	*/

	/*
	bool judge = true;
	int age;
	while (judge) {
		printf("나이는 ? : ");
		scanf_s("%d", &age);

		if (age == 999) {
			printf("종료\n");
			judge = false;
		}
		else {
			if (age >= 8 && age <= 13) {
				printf("초딩\n");
			}
			else if (age >= 14 && age <= 16) {
				printf("중딩\n");
			}
			else if (age >= 17 && age <= 19) {
				printf("고딩\n");
			}
			else if (age < 8) {
				printf("애기\n");
			}
			else {
				printf("늙은이\n");
			}
		}
	}
	*/

	// break , continue
	/*
	for (int i = 1; i <= 30; i++) {
		if (i >= 6) {
			printf("아, 나머지는 집으로 돌아가세요");
			break;
		}
		printf("%d 번 학생은 발표준비를 하란말이야\n", i);
	}
	*/


	// 1번부터 30번까지 중 7번은 결석, 7번 빼고 6번부터 10번까지 발표
	/*
	for (int i = 1; i <= 30; i++) {
		if (i >= 6 && i <= 10) {
			if (i == 7) {
				printf("7번이 없어? 감히 결석을 해? 병신을 만들어 주겠다\n");
				continue;
			}
			printf("%d번 학생놈 발표 준비 하세요\n", i);
		}
	}
	*/

	// && ||
	/*
	int a = 10;
	int b = 10;
	int c = 12;
	int d = 13;

	if (a == b && c ==d) {
		printf("옳은 말이로다\n");
	}
	else {
		printf("누구인가? 누가 개소리를 하였어?\n");
	}
	*/

	// random
	/*
	srand(time(NULL)); // 난수 초기화
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			int num = (rand() % 45)+1;
			printf("%d ", num);
		}
		printf("\n");
	}
	*/

	// 가위 바위 보 - switch case
	/*
	srand(time(NULL)); // 난수 초기화
	int num = (rand() % 3);
	
	switch (num) {
		case 1:
			printf("가위\n");
			break;
		case 2:
			printf("바위\n");
			break;
		case 3:
			printf("보\n");
			break;
		default:
			printf("몰?루\n");
			break;
	}
	*/

	// up & down
	srand(time(NULL)); // 난수 초기화
	int answer = rand() % 100 + 1;
	int num = 0;
	int chance = 5;
	bool result = false;

	while (chance) {
		printf("남은 기회 %d 번\n", chance--);
		printf("숫자를 맞춰보시오(1~100) : ");
		scanf_s("%d", &num);

		if (answer > num) {
			printf("UP\n");
		}
		else if (answer == num) {
			result = true;
			break;
		}
		else {
			printf("DOWN\n");
		}
	}

	if (result == true) {
		printf("정답\n");
	}
	else {
		printf("남은 기회 소진\n");
		printf("정답은 : %d", answer);
	}







	return 0;
}