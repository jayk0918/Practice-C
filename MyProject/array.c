#include<stdio.h>

int main_array(void) {

	// �迭
	/*
	int subway1 = 30;
	int subway2 = 40;
	int subway3 = 50;

	printf("����ö 1�� %d��\n", subway1);
	printf("����ö 2�� %d��\n", subway2);
	printf("����ö 3�� %d��\n", subway3);
	*/

	int subway_array[3];
	subway_array[0] = 30;
	subway_array[1] = 40;
	subway_array[2] = 50;

	// �迭 ����
	/*
	int arrayLength = sizeof(subway_array) / sizeof(subway_array[0]);

	for (int i = 0; i < arrayLength; i++) {
		printf("����ö %d �� %d ��\n", i + 1, subway_array[i]);
	}
	*/

	// �� �������
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

	// ���� vs ���ڿ�
	/*
	char c = 'A';
	printf("%c", c);
	*/

	// ���ڿ� ������ '��'�� �ǹ��ϴ� NULL���� '\0'�� ���ԵǾ�� ��
	// char str[7] = "coding"; // + \0
	// printf("%s", str);

	/*
	char string[] = "slavery";
	printf("%s\n", string);
	printf("%d\n", sizeof(string));

	for (int i = 0; i < sizeof(string); i++) {
		printf("%c\n", string[i]);
	}

	// �ѱ� 2byte
	char kor[] = "�����ΰ�?";
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

	// ASCII �ڵ�(�ƽ�Ű �ڵ�)�� ���
	/*
	for (int i = 0; i < sizeof(c_array); i++) {
		printf("%d\n", c_array[i]);
	}
	*/

	// ���ڿ� �Է¹ޱ�
	/*
	char name[256];
	printf("�̸� : ");
	scanf_s("%s", name, sizeof(name));
	printf("%s\n", name);
	*/

	// ASCII �ڵ�(�ƽ�Ű �ڵ�) : ANSI(�̱�ǥ����ȸ)���� ������ ǥ�� �ڵ� ü��
	// 7bit, �� 128�� �ڵ� (0~127)
	// a : 97 (���� a�� �ƽ�Ű�ڵ� ������)
	// A : 65
	// 0 : 48

	/*
	printf("a : %d\n", 'a');
	printf("A : %d\n", 'A');
	printf("0 : %d\n", '0');
	*/

	// ���� 2 : 0~127 ������ �ƽ�Ű�ڵ� �������� �ش��ϴ� ���� Ȯ��
	for (int i = 0; i < 128; i++) {
		printf("�ƽ�Ű�ڵ� ���� %d : %c\n", i, i);
	}

	return 0;
}