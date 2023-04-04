#include<stdio.h>
#include<time.h>

int main_array_project(void) {

	srand(time(NULL));
	int input; // 사용자 입력값
	int treatment = rand() % 4; // 발모제 선택

	int showBottle = 0; // 이번 게임에 보여줄 병 개수
	int previousShowBottle = 0; // 앞 게임에 보여준 병 개수
	
	for (int i = 1; i < 4; i++) {
		int bottle[4] = { 0, 0, 0, 0 };
		do {
			showBottle = rand() % 2 + 2; // 보여줄 병 개수
		} while (showBottle == previousShowBottle);
		previousShowBottle = showBottle;

		int isIncluded = 0; // 보여줄 병 중에 발모제가 포함되었는지 여부
		printf("\n%d번째 시도\n", i);
		
		// 보여줄 병 종류 선택
		for (int j = 0; j < showBottle; j++) {
			int randBottle = rand() % 4;

			// 아직 선택되지 않은 병이라면 선택 처리
			if (bottle[randBottle] == 0) {
				bottle[randBottle] = 1;
				if (randBottle == treatment) {
					isIncluded = 1;
				}
			}
			// 이미 선택된 병이면 다시 선택
			else {
				j--;
			}
		}
		// 사용자에게 문제 표시
		for (int k = 0; k < 4; k++) {
			if (bottle[k] == 1) {
				printf("%d", k + 1);
			}
		}
		printf("\n\n물약을 머리에 바릅니다.\n\n");

		if (isIncluded == 1) {
			printf("\n자라났다 머리머리\n");
		}
		else {
			printf("\n머머리 ㅠㅠ\n");
		}

		printf("\n계속하려면 아무 키나 누르거라\n");

	}

	printf("\n\n발모제를 맞추어 보시오\n\n");
	scanf_s("%d", &input);

	if (input == treatment + 1) {
		printf("맞추었구나\n");
	}
	else {
		printf("틀렸다 정답은 %d이었느니라 너는 한 사람을 머머리로 만들었다\n", treatment + 1);
	}

	return 0;
}