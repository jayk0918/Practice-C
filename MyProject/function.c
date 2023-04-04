#include <stdio.h>

// 선언
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

	// 계산기 함수
	result(plus(5, 2));
	result(minus(5, 2));
	result(multiply(5, 2));
	result(divide(10, 2));

	return 0;
}

// 정의
void print_apple(int left) {
	printf("남은 사과 개수는 %d\n", left);
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
	printf("결과는 : %d\n", result);
}

