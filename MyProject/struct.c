#include<stdio.h>

struct GameInfo {
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // ������ü ����
};


int main_struct(void){
	// ���� ���
	// �̸� : ��8
	// �߸ų⵵ : 1972��
	// ���� : 4$
	// ���ۻ� : �麴�� 

	char* name = "��8";
	int year = 1972;
	int price = 4;
	char* company = "�麴��";


	// �� �ٸ� ����
	// �̸� : û����8
	// �߸ų⵵ : 1972��
	// ���� : 400$
	// ���ۻ� : ������

	char* name2 = "û����8";
	int year2 = 1972;
	int price2 = 400;
	char* company2 = "������";

	// ����ü ���
	struct GameInfo gameInfo1;
	gameInfo1.name = "��8";
	gameInfo1.year = 1972;
	gameInfo1.price = 4;
	gameInfo1.company = "�麴��";

	// ����ü ���
	printf(" ���� �������\n");
	printf(" ���Ӹ� : %s\n", gameInfo1.name);
	printf(" �߸ų⵵ : %d\n", gameInfo1.year);
	printf(" ���� : %d\n", gameInfo1.price);
	printf(" ���ۻ� : %s\n", gameInfo1.company);
	printf("\n\n");

	// ����ü�� �迭ó�� �ʱ�ȭ
	struct GameInfo gameInfo2 = { "û����8", 1972, 400, "������" };
	printf(" �ٸ� ���� �������\n");
	printf(" ���Ӹ� : %s\n", gameInfo2.name);
	printf(" �߸ų⵵ : %d\n", gameInfo2.year);
	printf(" ���� : %d\n", gameInfo2.price);
	printf(" ���ۻ� : %s\n", gameInfo2.company);
	printf("\n\n");

	// ����ü �迭
	struct GameInfo gameArray[2] = {
		{"��8", 1972, 4, "�麴��"},
		{"û����8", 1972, 400, "������"}
	};

	// ����ü ������
	struct GameInfo* gamePtr;
	gamePtr = &gameInfo1;
	printf(" �̼Ǹ� ���� �������\n");
	/*
	printf(" ���Ӹ� : %s\n", (*gamePtr).name);
	printf(" �߸ų⵵ : %d\n", (*gamePtr).year);
	printf(" ���� : %d\n", (*gamePtr).price);
	printf(" ���ۻ� : %s\n", (*gamePtr).company);
	*/
	printf(" ���Ӹ� : %s\n", gamePtr->name);
	printf(" �߸ų⵵ : %d\n", gamePtr->year);
	printf(" ���� : %d\n", gamePtr->price);
	printf(" ���ۻ� : %s\n", gamePtr->company);
	printf("\n\n");

	// ���� ��ü ���� �Ұ�
	gameInfo1.friendGame = &gameInfo2;
	printf(" ������ü ���� �������\n");
	printf(" ���Ӹ� : %s\n", gameInfo1.friendGame->name);
	printf(" �߸ų⵵ : %d\n", gameInfo1.friendGame->year);
	printf(" ���� : %d\n", gameInfo1.friendGame->price);
	printf(" ���ۻ� : %s\n", gameInfo1.friendGame->company);

	// typedef
	// �ڷ��� �̸� ����
	int i = 1;
	typedef int ����;
	typedef float �Ǽ�;
	���� �������� = 3;
	�Ǽ� �Ǽ����� = 3.14f;
	printf("\n");
	printf("%d", ��������);
	printf("\n");
	printf("%2f", �Ǽ�����);

	typedef struct GameInfo ��������;
	�������� game1;
	game1.name = "������ ����";
	game1.year = 1392;
	printf("\n");
	printf("%s", game1.name);


	typedef struct GameInfomation {
		char* name;
		int year;
		int price;
		char* company;

		struct GameInfomation* friendGame; // ������ü ����
	} GAME_INFO;

	GAME_INFO game2;
	game2.name = "�ֳ��� ����";
	game2.year = 1231;

	struct GameInfomation game3;
	game3.name = "��Ű�� ����";



	return 0;
}