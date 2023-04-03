#include <stdio.h>

int main(void) {
	/*
	for (int i = 0; i <= 10; i++) {
		printf("Hello World\n");
	}
	*/
	/*
	int limit = 0;
		
	while (limit != 10) {
		printf("counting numbers : %d\n", limit++);
	}
	*/
	/*
	do {
		printf("counting numbers : %d\n", limit);
		limit++;
	} while (limit != 10);
	*/

	// 이중 반복문
	/*
	for (int i = 2; i < 10;  i++) {
		printf("\n%d 단 계산\n", i);
		for (int j = 1; j < 10;  j++) {
			printf("%d X %d = %d\n", i,  j,  i * j);
		}
	}
	*/

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}