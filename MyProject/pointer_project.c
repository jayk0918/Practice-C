#include<stdio.h>
#include<time.h>

// ����Ⱑ 6���� �ִ�.
// �̵��� ���׿� ����ִµ� �縷��
// �縷�� ������ ���� ������ ������
// ���� �� �����ϱ� ���� ���׿� ���� �༭ �������

int level;
int arrayFish[6];
int* cursor;
void initData();
void printFishes();
void decreseWater(long elapsedTime);
int checkFishAlive();


int main(void) {
	
	long startTime = 0; // ���� ���� �ð�
	long totalElapsedTime = 0; // �� ��� �ð�
	long preElapsedTime = 0; // ���� ��� �ð� (�ֱٿ� ���� �� �ð� ����)

	int num; // �� �� ���׿� ���� �� ������, ����� �Է�
	initData();

	cursor = arrayFish;

	startTime = clock(); // ���� �ð��� milliseceond (1/1000�� ��ȯ)
	while (1) {
		printFishes();
		//getchar(); // �ӽ÷� ����� �Է� ���
		printf("\n�� �� ���׿� ���� �ٰ��̿�?\n");
		scanf_s("%d", &num);

		// �Է°� üũ
		if (num < 1 || num > 6) {
			printf("\n�ȹٷ� �Է��϶����̴� �ȹٷ�!\n");
			continue;
		}

		// �� ��� �ð�
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("\n�� ��� �ð� : %ld �� \n", totalElapsedTime);
		
		// ���� �� �� �ð�(���������� �� �� �ð�) ���ķ� �帥 �ð�
		preElapsedTime = totalElapsedTime - preElapsedTime;
		printf("\n�ֱ� ��� �ð� : %ld ��\n", preElapsedTime);

		// ������ �� ����(����)
		decreseWater(preElapsedTime);

		// ����ڰ� �Է��� ���׿� ���� �ش�
		// 1. ������ ���� 0�̸� = ���� ���� �ʴ´� ������ �̹� ��ܰ��� �ǳԴ�.
		if (cursor[num - 1] <= 0) {
			printf("\n%d �� ������ �̹� ��ܰ��� �ǳԴ�. �� �༭ ���ϴ�\n", num);
		}

		// 2. ������ ���� 0�� �ƴ� ��� = ���� �ش� & 100�� ���� �ʴ��� üũ
		else if (cursor[num-1]+1 <=100) {
			// ���� �ش�.
			printf("\n%d \n�� ���� ��������", num);
			cursor[num - 1] += 1; // cursor[num-1] = cursor[num -1] + 1
		}

		// �������� �� ������ Ȯ�� (�������� 20�ʸ��� �� ���� ����)

		if (totalElapsedTime / 20 > level - 1) {
			// ������
			level++; 
			printf("\n\n������ - ���� �� ������ �ɰ��̴϶� level %d -> level %d\n\n", level - 1, level);

			// ���������� 5�� ����
			if (level == 5) {
				printf("\n\n ȣ�� ������� �Դٴ°ǰ� ���� ���ư����� �ϰ�\n\n");
				exit(0);
			}
		}

		// ��� ����Ⱑ �������� �������� ��
		if (checkFishAlive() == 0) {
			// ����
			printf("\n\n�ʴ� ��� �������� �������� ���´� �ʵ� ������ �������Ŷ� �� ����� ��\n\n");
			exit(0);
		}
		else {
			// ���� ����Ⱑ �ִ�
			printf("\n���� ����ִ� ����Ⱑ �ִ�, �ּ��� ���� ����� �װ�\n");
		}
		preElapsedTime = totalElapsedTime;

	}

	return 0;
}

void initData() {
	level = 1;
	for (int i = 0; i < 6; i++) {
		arrayFish[i] = 100; // ������ �� ����
	}
}

void printFishes() {
	printf("%3d�� %3d�� %3d�� %3d�� %3d�� %3d��\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++) {
		printf("%4d", arrayFish[i]);
	}
	printf("\n\n");
}

void decreseWater(long elapsedTime) {
	for (int i = 0; i < 6; i++) {
		arrayFish[i] -= (level * 3 * (int)elapsedTime); // 3 : ���̵� ������ ���� ��(����)
		if (arrayFish[i]<0) {
			arrayFish[i] = 0;
		}
	}
}

int checkFishAlive() {
	for (int i = 0; i < 6; i++) {
		if (arrayFish[i] > 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

