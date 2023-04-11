#include<stdio.h>
#include<time.h>

// 5마리 고양이
// 아무 키나 눌러서 랜덤으로 가챠
// 5마리 모두 뽑으면 끝
// 중복 가능
void initCharacters();
void printChar(int selected);
int checkCollection();

typedef struct {
	char* name; // 이름
	int age; // 나이
	char* character; // 성격
	int level; // 키우기 난이도 (1~5, 5가 어려움)
} WISH;

// 현재까지 보유한 캐릭
int collection[5] = { 0, 0, 0, 0, 0 };

// 전체 가챠 리스트
WISH wishes[5];

int main(void) {

	srand(time(NULL));
		
	initCharacters();

	while (1) {
		printf("기원 시작\n");
		getchar();

		int selected = rand()% 5; // 0~4 숫자 반환
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
	wishes[0].name = "치치";
	wishes[0].age = 100;
	wishes[0].character = "픽뚫";
	wishes[0].level = 4;

	wishes[1].name = "라이덴 에이";
	wishes[1].age = 2000;
	wishes[1].character = "히키코모리";
	wishes[1].level = 5;

	wishes[2].name = "카미사토 아야카";
	wishes[2].age = 20;
	wishes[2].character = "대포복어";
	wishes[2].level = 5;

	wishes[3].name = "나히다";
	wishes[3].age = 500;
	wishes[3].character = "배추";
	wishes[3].level = 5;

	wishes[4].name = "다이루크";
	wishes[4].age = 35;
	wishes[4].character = "감동";
	wishes[4].level = 4;
}

void printChar(int selected) {
	printf("\n\n 나온 캐릭터는? \n\n");
	printf(" 이름 : %s\n", wishes[selected].name);
	printf(" 나이 : %d\n", wishes[selected].age);
	printf(" 요약 : %s\n", wishes[selected].character);
	//printf(" 레벨 : %d\n", wishes[selected].level);

	for (int i = 0; i < wishes[selected].level; i++) {
		printf("%s", "★");
	}
	printf("\n\n");

}

int checkCollection() {
	// 현재 보유한 캐릭터 목록 출력
	// 다 모았는지 여부도 확인
	int collectAll = 1;

	printf("\n보유한 캐릭 목록\n");
	for (int i = 0; i < 5; i++) {
		if (collection[i] == 0) {
			printf("%10s", "(빈 박스)");
			collectAll = 0;
		}
		else {
			printf("%20s", wishes[i].name);
		}
	}
	printf("\n============================\n");

	if (collectAll){
		printf("\n축하합니다 흑우님 당신은 모든 캐릭을 다 모았습니다\n");
	}

	return collectAll;
}