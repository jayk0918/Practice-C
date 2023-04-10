#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>

// 10������ ���� �ٸ� ���� (�� ī�� 2�徿)
// ����ڷκ��� 2���� �Է°��� �ް� -> ���� ������ ��� ī�� ������ / Ʋ���� ���󺹱�
// ��� ���� ���� ã���� ���� ����
// �� ���� Ƚ�� �˷��ֱ�

int arrayAnimal[4][5];
int checkAnimal[4][5]; // ���������� ���� Ȯ��
void initAnimalArray();
char* strAnimal[10];
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int convert_position_x(int x);
int convert_position_y(int y);
void printAnimals();
void printQuestions();
int foundAllAnimals();

// ����� �ʿ�
int main_multi_dimentional_project(void) {
	srand(time(NULL));

	initAnimalArray();
	initAnimalName();

	shuffleAnimal();

	int failCount = 0;

	while (1) {
		int select1 = 0;
		int select2 = 0;

		printAnimals(); // ���� ��ġ ���
		printQuestions(); // ���� ���
		printf("������ ī�� 2���� ����\n");
		scanf_s("%8d, %8d", &select1, &select2);

		if (select1 == select2) {
			printf("�ȹٷ� �϶����̴� �ȹٷ�!\n");
			continue;
		}

		// ��ǥ�� �ش��ϴ� ī�带 ������� ������ Ȯ��
		int firstSelect_x = convert_position_x(select1);
		int firstSelect_y = convert_position_y(select1);

		int secondSelect_x = convert_position_x(select2);
		int secondSelect_y = convert_position_y(select2);

		int firstCheck = checkAnimal[firstSelect_x][firstSelect_y];
		int secondCheck = checkAnimal[secondSelect_x][secondSelect_y];
		bool equalAnimal;
		// ������ ������ ��
		if (arrayAnimal[firstSelect_x][firstSelect_y] == arrayAnimal[secondSelect_x][secondSelect_y]) {
			equalAnimal = true;
		}
		else {
			equalAnimal = false;
		}

		// ���� ������ ���
		if (firstCheck == 0 && secondCheck== 0 && equalAnimal == true) {
			printf("\n\n�����̴� : %s �� �߰���\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x] [secondSelect_y] = 1;
		}
		// �ٸ� ������ ���
		else {
			printf("\n\nƲ�ȴ� �̳� / Ʋ�Ȱų� �̹� ������ ī��� ��û�� ��\n\n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");
			failCount++;
		}

		if (foundAllAnimals() == 1) {
			printf("\n\n��� ������ �� ã�Ҵ�\n\n");
			printf("\n\n���ݱ��� �� %d�� Ʋ�ȴ�. �ݼ��ϵ���\n\n", failCount);
			break;
		}

	}

	return 0;
}

void initAnimalArray() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			arrayAnimal[i][j] = -1; // �� ��
		}
	}
}

void initAnimalName() {
	strAnimal[0] = "������";
	strAnimal[1] = "�ϸ�";
	strAnimal[2] = "������";
	strAnimal[3] = "�����";
	strAnimal[4] = "����";

	strAnimal[5] = "�ڳ���";
	strAnimal[6] = "�⸰";
	strAnimal[7] = "��Ÿ";
	strAnimal[8] = "Ÿ��";
	strAnimal[9] = "ȣ����";
}

void shuffleAnimal() {
	// ���� 4*5 ī��, 10������ ����
	// [][][][][]
	// [][][][][]
	// [][][][][]
	// [][][][][]

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 2; j++) {
			int position = getEmptyPosition();
			int x = convert_position_x(position);
			int y = convert_position_y(position);

			arrayAnimal[x][y] = i;

		}
	}
}

int getEmptyPosition() {
	while (1) {
		int randomPosition = rand() % 20; // 0~19������ ���� ��ȯ
		int x = convert_position_x(randomPosition);
		int y = convert_position_y(randomPosition);

		if (arrayAnimal[x][y] == -1) {
			return randomPosition;
		}

	}
	return 0;
}

int convert_position_x(int x) {
	return x / 5;
}

int convert_position_y(int y) {
	return y % 5;
}

void printAnimals() { // ���� ��ġ ���
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("\n");
}

void printQuestions() { // ���� ��� (ī�� ����)
	printf("\n\n (����)\n\n");
	int seq = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			// ������ ������ ��� '���� �̸�'
			if (checkAnimal[i][j] != 0) {
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}
			// Ʋ���� ��� �޸� ǥ�� (��ġ ���� ������ ����)
			else {
				printf("%8d", seq);
			}
			seq++;
		}
		printf("\n");
	}
}

int foundAllAnimals() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			if (checkAnimal[i][j] == 0) {
				return 0;
			}
		}
	}
	return 1;
}