#include<stdio.h>
#include<time.h>

int main_array_project(void) {

	srand(time(NULL));
	int input; // ����� �Է°�
	int treatment = rand() % 4; // �߸��� ����

	int showBottle = 0; // �̹� ���ӿ� ������ �� ����
	int previousShowBottle = 0; // �� ���ӿ� ������ �� ����
	
	for (int i = 1; i < 4; i++) {
		int bottle[4] = { 0, 0, 0, 0 };
		do {
			showBottle = rand() % 2 + 2; // ������ �� ����
		} while (showBottle == previousShowBottle);
		previousShowBottle = showBottle;

		int isIncluded = 0; // ������ �� �߿� �߸����� ���ԵǾ����� ����
		printf("\n%d��° �õ�\n", i);
		
		// ������ �� ���� ����
		for (int j = 0; j < showBottle; j++) {
			int randBottle = rand() % 4;

			// ���� ���õ��� ���� ���̶�� ���� ó��
			if (bottle[randBottle] == 0) {
				bottle[randBottle] = 1;
				if (randBottle == treatment) {
					isIncluded = 1;
				}
			}
			// �̹� ���õ� ���̸� �ٽ� ����
			else {
				j--;
			}
		}
		// ����ڿ��� ���� ǥ��
		for (int k = 0; k < 4; k++) {
			if (bottle[k] == 1) {
				printf("%d", k + 1);
			}
		}
		printf("\n\n������ �Ӹ��� �ٸ��ϴ�.\n\n");

		if (isIncluded == 1) {
			printf("\n�ڶ󳵴� �Ӹ��Ӹ�\n");
		}
		else {
			printf("\n�ӸӸ� �Ф�\n");
		}

		printf("\n����Ϸ��� �ƹ� Ű�� �����Ŷ�\n");

	}

	printf("\n\n�߸����� ���߾� ���ÿ�\n\n");
	scanf_s("%d", &input);

	if (input == treatment + 1) {
		printf("���߾�����\n");
	}
	else {
		printf("Ʋ�ȴ� ������ %d�̾����϶� �ʴ� �� ����� �ӸӸ��� �������\n", treatment + 1);
	}

	return 0;
}