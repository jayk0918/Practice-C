#include <stdio.h>

// ����
void print_apple(int num);
int apple(int total, int ate);

int plus(int num1, int num2);
int minus(int num1, int num2);
int multiply(int num1, int num2);
int divide(int num1, int num2);
void result(int result);

int main_function(void) {

	// function

	//int num = 2;
	//printNum(num);

	//int left = apple(5, 2);
	//print_apple(left);

	// ���� �Լ�
	result(plus(5, 2));
	result(minus(5, 2));
	result(multiply(5, 2));
	result(divide(10, 2));

	return 0;
}

// ����
void print_apple(int left) {
	printf("���� ��� ������ %d\n", left);
}

int apple(int total, int ate) {
	return total - ate;
}

int plus(int num1, int num2) {
	return num1 + num2;
}

int minus(int num1, int num2) {
	if (num1 > num2) {
		return num1 - num2;
	}
	else {
		return num2 - num1;
	}
}

int multiply(int num1, int num2) {
	return num1 * num2;
}

int divide(int num1, int num2) {
	if (num1 > num2) {
		return num1 / num2;
	}
	else {
		return num2 / num1;
	}
}

void result(int result) {
	printf("����� : %d\n", result);
}

