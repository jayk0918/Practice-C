#include <stdio.h>

int main_loop(void) {
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

	// ���� �ݺ���
	/*
	for (int i = 2; i < 10;  i++) {
		printf("\n%d �� ���\n", i);
		for (int j = 1; j < 10;  j++) {
			printf("%d X %d = %d\n", i,  j,  i * j);
		}
	}
	*/

	/* �����
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
	*/

	// ���� ��
	/*
	for (int i = 1; i <= 5; i++) {
		for (int j = i; j <= 4;  j++) {
			printf(" ");
		}
		for (int k = 1; k <= i; k++) {
			printf("*");
		}
		printf("\n");
	}
	*/

	// �Ƕ�̵� �ױ�

	int floor;
	printf("�� ������ �������̳�?");
	scanf_s("%d", &floor);
	
	for (int i = 0; i < floor; i++) {

		for (int j = i; j <= floor-1; j++) {
			printf(" ");
		}

		for (int k = 0; k < (i * 2) + 1; k++) {
			printf("*");
		}
		printf("\n");
		
	}

	return 0;
}