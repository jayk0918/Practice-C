#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>

// 10마리의 서로 다른 동물 (각 카드 2장씩)
// 사용자로부터 2개의 입력값을 받고 -> 같은 동물일 경우 카드 뒤집기 / 틀리면 원상복귀
// 모든 동물 쌍을 찾으면 게임 종료
// 총 실패 횟수 알려주기

int arrayAnimal[4][5];
int checkAnimal[4][5]; // 뒤집혔는지 여부 확인
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

// 디버깅 필요
int main_multi_dimentional_project(void) {
	srand(time(NULL));

	initAnimalArray();
	initAnimalName();

	shuffleAnimal();

	int failCount = 0;

	while (1) {
		int select1 = 0;
		int select2 = 0;

		printAnimals(); // 동물 위치 출력
		printQuestions(); // 문제 출력
		printf("뒤집을 카드 2개를 골라라\n");
		scanf_s("%8d, %8d", &select1, &select2);

		if (select1 == select2) {
			printf("똑바로 하란말이다 똑바로!\n");
			continue;
		}

		// 좌표에 해당하는 카드를 뒤집어보고 같은지 확인
		int firstSelect_x = convert_position_x(select1);
		int firstSelect_y = convert_position_y(select1);

		int secondSelect_x = convert_position_x(select2);
		int secondSelect_y = convert_position_y(select2);

		int firstCheck = checkAnimal[firstSelect_x][firstSelect_y];
		int secondCheck = checkAnimal[secondSelect_x][secondSelect_y];
		bool equalAnimal;
		// 동물이 같은지 비교
		if (arrayAnimal[firstSelect_x][firstSelect_y] == arrayAnimal[secondSelect_x][secondSelect_y]) {
			equalAnimal = true;
		}
		else {
			equalAnimal = false;
		}

		// 같은 동물인 경우
		if (firstCheck == 0 && secondCheck== 0 && equalAnimal == true) {
			printf("\n\n정답이다 : %s 를 발견함\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x] [secondSelect_y] = 1;
		}
		// 다른 동물인 경우
		else {
			printf("\n\n틀렸다 이놈 / 틀렸거나 이미 뒤집은 카드다 멍청한 놈\n\n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");
			failCount++;
		}

		if (foundAllAnimals() == 1) {
			printf("\n\n모든 동물을 다 찾았다\n\n");
			printf("\n\n지금까지 총 %d번 틀렸다. 반성하도록\n\n", failCount);
			break;
		}

	}

	return 0;
}

void initAnimalArray() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			arrayAnimal[i][j] = -1; // 빈 값
		}
	}
}

void initAnimalName() {
	strAnimal[0] = "원숭이";
	strAnimal[1] = "하마";
	strAnimal[2] = "강아지";
	strAnimal[3] = "고양이";
	strAnimal[4] = "돼지";

	strAnimal[5] = "코끼리";
	strAnimal[6] = "기린";
	strAnimal[7] = "낙타";
	strAnimal[8] = "타조";
	strAnimal[9] = "호랑이";
}

void shuffleAnimal() {
	// 동물 4*5 카드, 10마리의 동물
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
		int randomPosition = rand() % 20; // 0~19사이의 숫자 반환
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

void printAnimals() { // 동물 위치 출력
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("\n");
}

void printQuestions() { // 문제 출력 (카드 지도)
	printf("\n\n (문제)\n\n");
	int seq = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			// 정답을 맞췄을 경우 '동물 이름'
			if (checkAnimal[i][j] != 0) {
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}
			// 틀렸을 경우 뒷면 표시 (위치 숫자 보여줄 예정)
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