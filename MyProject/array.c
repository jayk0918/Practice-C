#include<stdio.h>

int main_array(void) {

	// 배열
	/*
	int subway1 = 30;
	int subway2 = 40;
	int subway3 = 50;

	printf("지하철 1에 %d명\n", subway1);
	printf("지하철 2에 %d명\n", subway2);
	printf("지하철 3에 %d명\n", subway3);
	*/

	int subway_array[3];
	subway_array[0] = 30;
	subway_array[1] = 40;
	subway_array[2] = 50;

	// 배열 길이
	/*
	int arrayLength = sizeof(subway_array) / sizeof(subway_array[0]);

	for (int i = 0; i < arrayLength; i++) {
		printf("지하철 %d 에 %d 명\n", i + 1, subway_array[i]);
	}
	*/

	// 값 설정방법
	/*
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}
	*/

	/*
	float arr_f[5] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f };
	for (int i = 0; i < 5; i++) {
		printf("%.2f\n", arr_f[i]);
	}
	*/

	// 문자 vs 문자열
	/*
	char c = 'A';
	printf("%c", c);
	*/

	// 문자열 끝에는 '끝'을 의미하는 NULL문자 '\0'이 포함되어야 함
	// char str[7] = "coding"; // + \0
	// printf("%s", str);

	/*
	char string[] = "slavery";
	printf("%s\n", string);
	printf("%d\n", sizeof(string));

	for (int i = 0; i < sizeof(string); i++) {
		printf("%c\n", string[i]);
	}

	// 한글 2byte
	char kor[] = "누구인가?";
	printf("%s\n", kor);
	printf("%d\n", sizeof(kor));

	*/

	/*
	char c_array[7] = { 'c', 'o', 'd', 'i', 'n', 'g', '\0' };
	printf("%s\n", c_array);
	*/

	char c_array[10] = { 'c', 'o', 'd', 'i', 'n', 'g' };
	//printf("%s\n", c_array);
	/*
	for (int i = 0; i < sizeof(c_array); i++) {
		printf("%c\n", c_array[i]);
	}
	*/

	// ASCII 코드(아스키 코드)값 출력
	/*
	for (int i = 0; i < sizeof(c_array); i++) {
		printf("%d\n", c_array[i]);
	}
	*/

	// 문자열 입력받기
	/*
	char name[256];
	printf("이름 : ");
	scanf_s("%s", name, sizeof(name));
	printf("%s\n", name);
	*/

	// ASCII 코드(아스키 코드) : ANSI(미국표준협회)에서 제시한 표준 코드 체계
	// 7bit, 총 128개 코드 (0~127)
	// a : 97 (문자 a의 아스키코드 정수값)
	// A : 65
	// 0 : 48

	/*
	printf("a : %d\n", 'a');
	printf("A : %d\n", 'A');
	printf("0 : %d\n", '0');
	*/

	// 참고 2 : 0~127 사이의 아스키코드 정수값에 해당하는 문자 확인
	for (int i = 0; i < 128; i++) {
		printf("아스키코드 정수 %d : %c\n", i, i);
	}

	return 0;
}