#include<stdio.h>
#include<time.h>

// 물고기가 6마리 있다.
// 이들은 어항에 살고있는데 사막임
// 사막이 더워서 물이 빠르게 증발함
// 물이 다 증발하기 전에 어항에 물을 줘서 살려야함

int level;
int arrayFish[6];
int* cursor;
void initData();
void printFishes();
void decreseWater(long elapsedTime);
int checkFishAlive();


int main(void) {
	
	long startTime = 0; // 게임 시작 시간
	long totalElapsedTime = 0; // 총 경과 시간
	long preElapsedTime = 0; // 직전 경과 시간 (최근에 물을 준 시간 간격)

	int num; // 몇 번 어항에 물을 줄 것인지, 사용자 입력
	initData();

	cursor = arrayFish;

	startTime = clock(); // 현재 시간을 milliseceond (1/1000초 반환)
	while (1) {
		printFishes();
		//getchar(); // 임시로 사용자 입력 대기
		printf("\n몇 번 어항에 물을 줄것이오?\n");
		scanf_s("%d", &num);

		// 입력값 체크
		if (num < 1 || num > 6) {
			printf("\n똑바로 입력하란말이다 똑바로!\n");
			continue;
		}

		// 총 경과 시간
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("\n총 경과 시간 : %ld 초 \n", totalElapsedTime);
		
		// 직전 물 준 시간(마지막으로 물 준 시간) 이후로 흐른 시간
		preElapsedTime = totalElapsedTime - preElapsedTime;
		printf("\n최근 경과 시간 : %ld 초\n", preElapsedTime);

		// 어항의 물 감소(증발)
		decreseWater(preElapsedTime);

		// 사용자가 입력한 어항에 물을 준다
		// 1. 어항의 물이 0이면 = 물을 주지 않는다 물고기는 이미 요단강을 건넜다.
		if (cursor[num - 1] <= 0) {
			printf("\n%d 번 물고기는 이미 요단강을 건넜다. 물 줘서 뭐하니\n", num);
		}

		// 2. 어항의 물이 0이 아닌 경우 = 물을 준다 & 100을 넘지 않는지 체크
		else if (cursor[num-1]+1 <=100) {
			// 물을 준다.
			printf("\n%d \n자 물을 받으세요", num);
			cursor[num - 1] += 1; // cursor[num-1] = cursor[num -1] + 1
		}

		// 레벨업을 할 것인지 확인 (레벨업은 20초마다 한 번씩 수행)

		if (totalElapsedTime / 20 > level - 1) {
			// 레벨업
			level++; 
			printf("\n\n레벨업 - 점점 더 지옥이 될것이니라 level %d -> level %d\n\n", level - 1, level);

			// 최종레벨은 5로 설정
			if (level == 5) {
				printf("\n\n 호오 여기까지 왔다는건가 이제 돌아가도록 하게\n\n");
				exit(0);
			}
		}

		// 모든 물고기가 지옥으로 가버렸을 때
		if (checkFishAlive() == 0) {
			// 전멸
			printf("\n\n너는 모든 물고기들을 지옥으로 보냈다 너도 지옥에 떨어지거라 이 사악한 것\n\n");
			exit(0);
		}
		else {
			// 생존 물고기가 있다
			printf("\n아직 살아있는 물고기가 있다, 최선을 다해 살려라 닝겐\n");
		}
		preElapsedTime = totalElapsedTime;

	}

	return 0;
}

void initData() {
	level = 1;
	for (int i = 0; i < 6; i++) {
		arrayFish[i] = 100; // 어항의 물 높이
	}
}

void printFishes() {
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++) {
		printf("%4d", arrayFish[i]);
	}
	printf("\n\n");
}

void decreseWater(long elapsedTime) {
	for (int i = 0; i < 6; i++) {
		arrayFish[i] -= (level * 3 * (int)elapsedTime); // 3 : 난이도 조절을 위한 값(임의)
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

