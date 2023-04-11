#include<stdio.h>
#include<time.h>

// 5���� �����
// �ƹ� Ű�� ������ �������� ��í
// 5���� ��� ������ ��
// �ߺ� ����
void initCharacters();
void printChar(int selected);
int checkCollection();

typedef struct {
	char* name; // �̸�
	int age; // ����
	char* character; // ����
	int level; // Ű��� ���̵� (1~5, 5�� �����)
} WISH;

// ������� ������ ĳ��
int collection[5] = { 0, 0, 0, 0, 0 };

// ��ü ��í ����Ʈ
WISH wishes[5];

int main(void) {

	srand(time(NULL));
		
	initCharacters();

	while (1) {
		printf("��� ����\n");
		getchar();

		int selected = rand()% 5; // 0~4 ���� ��ȯ
		printChar(selected);
		collection[selected] = 1;

		int collectAll = checkCollection();
		if (collectAll == 1) {
			break;
		}

	}

	return 0;
}

void initCharacters() {
	wishes[0].name = "ġġ";
	wishes[0].age = 100;
	wishes[0].character = "�ȶ�";
	wishes[0].level = 4;

	wishes[1].name = "���̵� ����";
	wishes[1].age = 2000;
	wishes[1].character = "��Ű�ڸ�";
	wishes[1].level = 5;

	wishes[2].name = "ī�̻��� �ƾ�ī";
	wishes[2].age = 20;
	wishes[2].character = "��������";
	wishes[2].level = 5;

	wishes[3].name = "������";
	wishes[3].age = 500;
	wishes[3].character = "����";
	wishes[3].level = 5;

	wishes[4].name = "���̷�ũ";
	wishes[4].age = 35;
	wishes[4].character = "����";
	wishes[4].level = 4;
}

void printChar(int selected) {
	printf("\n\n ���� ĳ���ʹ�? \n\n");
	printf(" �̸� : %s\n", wishes[selected].name);
	printf(" ���� : %d\n", wishes[selected].age);
	printf(" ��� : %s\n", wishes[selected].character);
	//printf(" ���� : %d\n", wishes[selected].level);

	for (int i = 0; i < wishes[selected].level; i++) {
		printf("%s", "��");
	}
	printf("\n\n");

}

int checkCollection() {
	// ���� ������ ĳ���� ��� ���
	// �� ��Ҵ��� ���ε� Ȯ��
	int collectAll = 1;

	printf("\n������ ĳ�� ���\n");
	for (int i = 0; i < 5; i++) {
		if (collection[i] == 0) {
			printf("%10s", "(�� �ڽ�)");
			collectAll = 0;
		}
		else {
			printf("%20s", wishes[i].name);
		}
	}
	printf("\n============================\n");

	if (collectAll){
		printf("\n�����մϴ� ���� ����� ��� ĳ���� �� ��ҽ��ϴ�\n");
	}

	return collectAll;
}