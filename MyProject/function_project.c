#include<stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

// 선언
int random_num();
char random_calculate();
void question(int num1, int num2, char calculate);
int doCalculate(int num1, int num2, char calculate);


int main_fuction_project(void) {

	// 문이 5개, 각 문마다 점점 어려운 수식 퀴즈가 출제 (랜덤)
	// 맞히면 통과, 틀리면 실패

	srand(time(NULL)); // 난수 초기화
	int count = 0;
	bool passFail = true;

	printf("빤쓰런은 999\n");

	for (int i = 0; i < 5; ++i) {
		int num1 = random_num();
		int num2 = random_num();
		char calculate = random_calculate();

		int input = 0;
		int result = doCalculate(num1, num2, calculate);

		if (num1 > num2) {
			question(num1, num2, calculate);
		}
		else {
			question(num2, num1, calculate);
		}
		
		scanf_s("%d", &input);

		if (input == result) {
			printf("PASS\n");
		}
		else if (input == 999) {
			printf("빤쓰런이라니? 저놈을 매우 쳐라.\n");
			passFail = false;
			break;
		}
		else {
			printf("마구니로구나, 저놈을 매우 쳐라.\n");
			passFail = false;
			break;
		}
	}

	if (passFail == true) {
		printf("다 맞추었도다\n");
	}

	return 0;
}

// 정의
int random_num() {
	int random_num = rand() % 10 + 1;
	return random_num;
}

char random_calculate() {
	int random_num = rand() % 3;
	switch (random_num) {
		case 0:
			return '+';
			break;
		case 1:
			return '-';
			break;
		case 2:
			return '*';
			break;
		case 3:
			return "/";
			break;
		default:
			return "?";
	}
}

void question(int num1, int num2, char calculate) {
	printf("%d %c %d = ?\n", num1, calculate, num2);
}

int doCalculate(int num1, int num2, char calculate) {

	int result = 0;

	switch (calculate) {
	case '+':
		result = num1 + num2;
		break;
	case '-':
		if (num1 > num2) {
			result = num1 - num2;
		}
		else {
			result = num2 - num1;
		}
		break;
	case '*':
		result = num1 * num2;
		break;
	case '/':
		if (num1 > num2) {
			result = num1 / num2;
		}
		else {
			result = num2 / num1;
		}
		break;
	default:
		printf("unknown error\n");
		break;
	}

	return result;
}
