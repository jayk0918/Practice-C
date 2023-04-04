#include<stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

// ����
int random_num();
char random_calculate();
void question(int num1, int num2, char calculate);
int doCalculate(int num1, int num2, char calculate);


int main_fuction_project(void) {

	// ���� 5��, �� ������ ���� ����� ���� ��� ���� (����)
	// ������ ���, Ʋ���� ����

	srand(time(NULL)); // ���� �ʱ�ȭ
	int count = 0;
	bool passFail = true;

	printf("�������� 999\n");

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
			printf("�������̶��? ������ �ſ� �Ķ�.\n");
			passFail = false;
			break;
		}
		else {
			printf("�����Ϸα���, ������ �ſ� �Ķ�.\n");
			passFail = false;
			break;
		}
	}

	if (passFail == true) {
		printf("�� ���߾�����\n");
	}

	return 0;
}

// ����
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
