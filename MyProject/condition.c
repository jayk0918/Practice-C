#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

int main_condition(void) {
	/*
	int age = 59;
	if (age >= 20 && age < 60) {
		printf("�Ϲ���\n");
	}
	else if (age >= 60) {
		printf("����\n");
	}	
	else {
		printf("�л�\n");
	}
	*/

	/*
	bool judge = true;
	int age;
	while (judge) {
		printf("���̴� ? : ");
		scanf_s("%d", &age);

		if (age == 999) {
			printf("����\n");
			judge = false;
		}
		else {
			if (age >= 8 && age <= 13) {
				printf("�ʵ�\n");
			}
			else if (age >= 14 && age <= 16) {
				printf("�ߵ�\n");
			}
			else if (age >= 17 && age <= 19) {
				printf("���\n");
			}
			else if (age < 8) {
				printf("�ֱ�\n");
			}
			else {
				printf("������\n");
			}
		}
	}
	*/

	// break , continue
	/*
	for (int i = 1; i <= 30; i++) {
		if (i >= 6) {
			printf("��, �������� ������ ���ư�����");
			break;
		}
		printf("%d �� �л��� ��ǥ�غ� �϶����̾�\n", i);
	}
	*/


	// 1������ 30������ �� 7���� �Ἦ, 7�� ���� 6������ 10������ ��ǥ
	/*
	for (int i = 1; i <= 30; i++) {
		if (i >= 6 && i <= 10) {
			if (i == 7) {
				printf("7���� ����? ���� �Ἦ�� ��? ������ ����� �ְڴ�\n");
				continue;
			}
			printf("%d�� �л��� ��ǥ �غ� �ϼ���\n", i);
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
		printf("���� ���̷δ�\n");
	}
	else {
		printf("�����ΰ�? ���� ���Ҹ��� �Ͽ���?\n");
	}
	*/

	// random
	/*
	srand(time(NULL)); // ���� �ʱ�ȭ
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			int num = (rand() % 45)+1;
			printf("%d ", num);
		}
		printf("\n");
	}
	*/

	// ���� ���� �� - switch case
	/*
	srand(time(NULL)); // ���� �ʱ�ȭ
	int num = (rand() % 3);
	
	switch (num) {
		case 1:
			printf("����\n");
			break;
		case 2:
			printf("����\n");
			break;
		case 3:
			printf("��\n");
			break;
		default:
			printf("��?��\n");
			break;
	}
	*/

	// up & down
	srand(time(NULL)); // ���� �ʱ�ȭ
	int answer = rand() % 100 + 1;
	int num = 0;
	int chance = 5;
	bool result = false;

	while (chance) {
		printf("���� ��ȸ %d ��\n", chance--);
		printf("���ڸ� ���纸�ÿ�(1~100) : ");
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
		printf("����\n");
	}
	else {
		printf("���� ��ȸ ����\n");
		printf("������ : %d", answer);
	}







	return 0;
}