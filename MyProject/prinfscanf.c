#include <stdio.h>

//int main(void) {

	// 정수형 변수

	/* 
	int age = 12;
	printf("%d\n" , age);
	age = 13;
	printf("%d\n", age);
	*/

	// 실수형 변수
	/*
	float f = 46.5f;
	printf("%.1f\n", f);
	double d = 4.428;
	printf("%.2lf\n", d);
	*/

	// 상수
	/*
	const int year = 2000;
	printf("태어난 년도 : %d\n", year);
	*/

	// printf
	// 연산
	/*
	int add = 3 + 7;
	printf("3 + 7 = %d\n", add);
	printf("%d * %d = %d\n", 30, 79, 30 * 79);
	*/

	// scanf
	/*
	int input;
	printf("값을 입력하세요 : ");
	scanf_s("%d", &input);
	printf("입력값 : %d\n", input);
	*/

	/*
	int one, two, three;
	printf("3개의 정수를 입력하세요 : ");
	scanf_s("%d %d %d", &one, &two, &three);
	printf("첫번째 값 : %d\n", one);
	printf("첫번째 값 : %d\n", two);
	printf("첫번째 값 : %d\n", three);
	*/

	// 문자(한 글자), 문자열(한 글자 이상의 여러 글자)
	/*
	char c = 'A';
	printf("%c\n", c);
	*/

	/*
	char str[256];
	scanf_s("%s", str, sizeof(str));
	printf("%s\n", str);
	*/

	// 프로젝트
	// 경찰관이 범죄자의 정보를 입수
	// 이름, 나이, 몸무게, 키 죄목

	/*
	char name[256];
	printf("이름 : ");
	scanf_s("%s", name, sizeof(name));

	int age;
	printf("나이 : ");
	scanf_s("%d", &age);

	float weight;
	printf("몸무게 : ");
	scanf_s("%f", &weight);

	double height;
	printf("키 : ");
	scanf_s("%lf", &height);

	char guilt[256];
	printf("죄목 : ");
	scanf_s("%s", guilt, sizeof(guilt));

	// 조서 내용 출력
	printf("\n\n -- 정보 -- \n\n");
	printf(" 이름     :  %s\n", name);
	printf(" 나이     :  %d\n", age);
	printf(" 몸무게  :  %.2f\n", weight);
	printf(" 키        :  %.2lf\n", height);
	printf(" 범죄     :  %s\n", guilt);


	return 0;
}*/