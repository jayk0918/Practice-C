#include<stdio.h>

struct GameInfo {
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // 연관업체 게임
};


int main_struct(void){
	// 게임 출시
	// 이름 : 폭8
	// 발매년도 : 1972년
	// 가격 : 4$
	// 제작사 : 백병원 

	char* name = "폭8";
	int year = 1972;
	int price = 4;
	char* company = "백병원";


	// 또 다른 게임
	// 이름 : 청춘폭8
	// 발매년도 : 1972년
	// 가격 : 400$
	// 제작사 : 조병옥

	char* name2 = "청춘폭8";
	int year2 = 1972;
	int price2 = 400;
	char* company2 = "조병옥";

	// 구조체 사용
	struct GameInfo gameInfo1;
	gameInfo1.name = "폭8";
	gameInfo1.year = 1972;
	gameInfo1.price = 4;
	gameInfo1.company = "백병원";

	// 구조체 출력
	printf(" 게임 출시정보\n");
	printf(" 게임명 : %s\n", gameInfo1.name);
	printf(" 발매년도 : %d\n", gameInfo1.year);
	printf(" 가격 : %d\n", gameInfo1.price);
	printf(" 제작사 : %s\n", gameInfo1.company);
	printf("\n\n");

	// 구조체를 배열처럼 초기화
	struct GameInfo gameInfo2 = { "청춘폭8", 1972, 400, "조병옥" };
	printf(" 다른 게임 출시정보\n");
	printf(" 게임명 : %s\n", gameInfo2.name);
	printf(" 발매년도 : %d\n", gameInfo2.year);
	printf(" 가격 : %d\n", gameInfo2.price);
	printf(" 제작사 : %s\n", gameInfo2.company);
	printf("\n\n");

	// 구조체 배열
	struct GameInfo gameArray[2] = {
		{"폭8", 1972, 4, "백병원"},
		{"청춘폭8", 1972, 400, "조병옥"}
	};

	// 구조체 포인터
	struct GameInfo* gamePtr;
	gamePtr = &gameInfo1;
	printf(" 미션맨 게임 출시정보\n");
	/*
	printf(" 게임명 : %s\n", (*gamePtr).name);
	printf(" 발매년도 : %d\n", (*gamePtr).year);
	printf(" 가격 : %d\n", (*gamePtr).price);
	printf(" 제작사 : %s\n", (*gamePtr).company);
	*/
	printf(" 게임명 : %s\n", gamePtr->name);
	printf(" 발매년도 : %d\n", gamePtr->year);
	printf(" 가격 : %d\n", gamePtr->price);
	printf(" 제작사 : %s\n", gamePtr->company);
	printf("\n\n");

	// 연관 업체 게임 소개
	gameInfo1.friendGame = &gameInfo2;
	printf(" 연관업체 게임 출시정보\n");
	printf(" 게임명 : %s\n", gameInfo1.friendGame->name);
	printf(" 발매년도 : %d\n", gameInfo1.friendGame->year);
	printf(" 가격 : %d\n", gameInfo1.friendGame->price);
	printf(" 제작사 : %s\n", gameInfo1.friendGame->company);

	// typedef
	// 자료형 이름 지정
	int i = 1;
	typedef int 정수;
	typedef float 실수;
	정수 정수변수 = 3;
	실수 실수변수 = 3.14f;
	printf("\n");
	printf("%d", 정수변수);
	printf("\n");
	printf("%2f", 실수변수);

	typedef struct GameInfo 게임정보;
	게임정보 game1;
	game1.name = "조선의 게임";
	game1.year = 1392;
	printf("\n");
	printf("%s", game1.name);


	typedef struct GameInfomation {
		char* name;
		int year;
		int price;
		char* company;

		struct GameInfomation* friendGame; // 연관업체 게임
	} GAME_INFO;

	GAME_INFO game2;
	game2.name = "왜놈의 게임";
	game2.year = 1231;

	struct GameInfomation game3;
	game3.name = "양키의 게임";



	return 0;
}