#pragma once

#include <iostream>
#include <algorithm>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "Consola.h"
#include "keycode.h"
#include "Model.h"
using namespace std;

class View
{
public:
	int getkey() {
		int ch = _getch();
		return (ch == 0xe0) ? (0xe000 | _getch()) : ch;
	}

	// start화면 그리기 위한 함수
	void putstr(int x, int y, const char* str) {
		gotoxy(x, y);
		cout << str;
	}

	// 캐릭터 넣기 위한 함수
	void drawCharacter(int col, int row) {
		gotoxy((MAP_X1 + col + 1) * 2, MAP_Y1 + row + 1);
		textcolor(BLUE, WHITE);
		puts("★");
	}

	void delCharacter(int col, int row) {
		gotoxy((MAP_X1 + col + 1) * 2 + 1, MAP_Y1 + row + 1);
		puts(" ");
		gotoxy((MAP_X1 + col + 1) * 2, MAP_Y1 + row + 1);
		puts(" ");
	}

	void drawCell(int col, int row, int mapData[10][10]) {

		const char* cellSymbol[] = { " ", "▩", "●", "●", "○", "♥" };
		int cell = mapData[row][col];

		switch (cell) {
		case    0:    textcolor(WHITE, WHITE);      break;  // 빈공간
		case    1:    textcolor(GREEN, WHITE);       break;  // 벽
		case    2:    textcolor(RED, WHITE);       break;  // 움직일 공
		case 3:textcolor(BLUE, WHITE); break;	//채워진 공
		case    4:   textcolor(BLACK, WHITE);      break;  // 골대
		case 5: textcolor(PURPLE, WHITE);        break;		// 아이템
		}
		
		gotoxy((MAP_X1 + col + 1) * 2, MAP_Y1 + row + 1);
		puts(cellSymbol[cell]);
	}

	void drawMap(int mapData[10][10]) {
		
		for (int row = 0; row < MAP_HEIGHT; ++row) {
			for (int col = 0; col < MAP_WIDTH; ++col)
				drawCell(col, row, mapData);
		}
	}

	void define_Map(int map_number) {
		system("cls");
		switch (map_number){
		case 0:
		case 6:
			break;
		case 1:
			copy(&mapData_1[0][0], &mapData_1[0][0] + 100, &mapData[0][0]);
			copy(&mapData_1[0][0], &mapData_1[0][0] + 100, &copy_mapData[0][0]);
			break;
		case 2:
			copy(&mapData_2[0][0], &mapData_2[0][0] + 100, &mapData[0][0]);
			copy(&mapData_2[0][0], &mapData_2[0][0] + 100, &copy_mapData[0][0]);
			break;
		case 3:
			copy(&mapData_3[0][0], &mapData_3[0][0] + 100, &mapData[0][0]);
			copy(&mapData_3[0][0], &mapData_3[0][0] + 100, &copy_mapData[0][0]);
			break;
		case 4:
			copy(&mapData_4[0][0], &mapData_4[0][0] + 100, &mapData[0][0]);
			copy(&mapData_4[0][0], &mapData_4[0][0] + 100, &copy_mapData[0][0]);
			break;
		case 5:
			copy(&mapData_5[0][0], &mapData_5[0][0] + 100, &mapData[0][0]);
			copy(&mapData_5[0][0], &mapData_5[0][0] + 100, &copy_mapData[0][0]);
			break;
		}
		Inform();
		drawMap(copy_mapData);
		map_inform(map_number);
		drawCharacter(2, 4);
		
	}

	void textcolor(int foreground, int background)
	{
		int color = foreground + background * 16;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}

	void map_inform(int map_number)
	{
		textcolor(GREEN,WHITE);
		gotoxy(30, 3);
		cout << "[ STAGE " << map_number << " ]";
	}

	int Inform() {
		textcolor(GREEN, WHITE);
		putstr(60, 5, "┏━━━━━━━━━━━━━━━━━━━━━━━━┓");
		putstr(60, 6, "┃          Help          ┃");
		putstr(60, 8, "┃    ↑↓← → : Move    ┃");
		putstr(60, 10, "┃     N : Next Stage     ┃");
		putstr(60, 12, "┃     P : Pre  Stage     ┃");
		putstr(60, 14, "┃     Space: Restart     ┃");
		putstr(60, 16, "┃      Esc: Game Exit    ┃");
		putstr(60, 18, "┃  ♥ : PUSH COUNT RESET ┃");
		putstr(60, 20, "┗━━━━━━━━━━━━━━━━━━━━━━━━┛");

		return 0;
	}

	int success() {
		for (int row = 0; row < MAP_HEIGHT; ++row) {
			for (int col = 0; col < MAP_WIDTH; ++col)
				if (mapData[row][col] == 2 || mapData[row][col] == 4) return 0;
		}
		return 1;
	}

	int show_success(int map_number)
	{
		system("cls");

		while (getchar() != '\n');
		textcolor(YELLOW, WHITE);
		putstr(32, 5, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
		putstr(32, 7, "┃  *************************  ┃");
		gotoxy(32, 9); cout << "┃     [ STAGE " << map_number << " ] CLEAR!      ┃";
		putstr(32, 11, "┃      GO TO NEXT STAGE :     ┃");
		putstr(32, 13, "┃         PRESS ENTER!        ┃");
		putstr(32, 15, "┃  *************************  ┃");
		putstr(32, 17, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

		while (getchar() != '\n');

		map_number++;

		define_Map(map_number);
		return 0;
	}

	void drawCount(int pushCount) {
		textcolor(BLACK, WHITE);
		gotoxy(40, 8);
		cout << "PUSH COUNT : " << pushCount << endl;
	}
};
