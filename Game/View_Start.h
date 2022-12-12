#pragma once
#include <iostream>
#include <windows.h>
#include "Consola.h"
#include "keycode.h"
#include "View.h"
using namespace std;

class View_Start
{
	
public:
	int logo()
	{
		View* view = 0;
		view->textcolor(BLUE, WHITE);
		int i;

		textbackground(BLUE);

		for (i = 2; i < 15; i++)
		{
			gotoxy(4, i);
			printf("                                                                                           ");
		}

		
		//1 줄
		textbackground(GRAY);
		view->putstr(6,3, "            ");
		view->putstr(51, 3, "            ");
		Sleep(100);

		//2 줄

		view->putstr(6, 4, "  ");
		view->putstr(16, 4, "  ");

		view->putstr(40, 4, "  ");

		view->putstr(51, 4, "  ");

		view->putstr(61, 4, "  ");

		view->putstr(85, 4, "  ");

		Sleep(100);

		//3 줄

		view->putstr(6, 5, "  ");
		view->putstr(16, 5, "  ");

		view->putstr(40, 5, "  ");

		view->putstr(51, 5, "  ");

		view->putstr(61, 5, "  ");

		view->putstr(85, 5, "  ");

		Sleep(100);

		//4 줄

		view->putstr(6, 6, "  ");
		view->putstr(16, 6, "  ");

		view->putstr(40, 6, "  ");

		view->putstr(51, 6, "  ");

		view->putstr(61, 6, "  ");

		view->putstr(85, 6, "  ");

		Sleep(100);

		//5 줄

		view->putstr(6, 7, "            ");
		view->putstr(51, 7, "            ");

		view->putstr(40, 7, "  ");

		view->putstr(85, 7, "  ");

		Sleep(100);

		//6 줄

		view->putstr(6, 8, "  ");

		view->putstr(40, 8, "  ");

		view->putstr(51, 8, "  ");

		view->putstr(85, 8, "  ");

		Sleep(100);

		//7 줄

		view->putstr(6, 9, "  ");

		view->putstr(18, 9, "  ");

		view->putstr(26, 9, "  ");

		view->putstr(30, 9, "        ");

		view->putstr(40, 9, "        ");

		view->putstr(51, 9, "  ");

		view->putstr(63, 9, "  ");

		view->putstr(71, 9, "  ");

		view->putstr(75, 9, "        ");

		view->putstr(85, 9, "        ");

		Sleep(100);

		//8 줄

		view->putstr(6, 10, "  ");

		view->putstr(18, 10, "  ");

		view->putstr(26, 10, "  ");

		view->putstr(30, 10, "  ");

		view->putstr(40, 10, "  ");

		view->putstr(46, 10, "  ");

		view->putstr(51, 10, "  ");

		view->putstr(63, 10, "  ");

		view->putstr(71, 10, "  ");

		view->putstr(75, 10, "  ");

		view->putstr(85, 10, "  ");

		view->putstr(91, 10, "  ");

		Sleep(100);

		//9 줄

		view->putstr(6, 11, "  ");

		view->putstr(18, 11, "  ");

		view->putstr(26, 11, "  ");

		view->putstr(30, 11, "        ");
		
		view->putstr(40, 11, "  ");

		view->putstr(46, 11, "  ");

		view->putstr(51, 11, "  ");

		view->putstr(63, 11, "  ");

		view->putstr(71, 11, "  ");

		view->putstr(75, 11, "        ");

		view->putstr(85, 11, "  ");

		view->putstr(91, 11, "  ");
		
		Sleep(100);

		//10 줄

		view->putstr(6, 12, "  ");

		view->putstr(18, 12, "  ");

		view->putstr(26, 12, "  ");

		view->putstr(36, 12, "  ");

		view->putstr(40, 12, "  ");
		
		view->putstr(46, 12, "  ");

		view->putstr(51, 12, "  ");

		view->putstr(63, 12, "  ");

		view->putstr(71, 12, "  ");

		view->putstr(81, 12, "  ");

		view->putstr(85, 12, "  ");

		view->putstr(91, 12, "  ");

		Sleep(100);

		//11 줄
		view->putstr(6, 13, "  ");

		view->putstr(18, 13, "          ");

		view->putstr(30, 13, "        ");

		view->putstr(40, 13, "  ");

		view->putstr(46, 13, "  ");

		view->putstr(51, 13, "  ");

		view->putstr(63, 13, "          ");

		view->putstr(75, 13, "        ");

		view->putstr(81, 13, "  ");

		view->putstr(85, 13, "  ");

		view->putstr(91, 13, "  ");

		Sleep(100);

		gotoxy(38, 20);
		view->textcolor(BLUE, WHITE);
		cout << "  Please press ENTER!  " << endl;
		
		while (getchar() != '\n');
		system("cls");
		return 0;
	}

	int selectStage() {
		system("cls");
		int selectStage;

		View* view = 0;

		do {
			view->textcolor(BLUE, WHITE);
			view->putstr(32, 5, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
			view->putstr(32, 7, "┃  *************************  ┃");
			view->putstr(32, 9, "┃        SELECT STAGE!        ┃");
			view->putstr(32, 11, "┃           (1~5) :           ┃");
			view->putstr(32, 13, "┃  *************************  ┃");
			view->putstr(32, 15, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
			gotoxy(52, 11);
			cin >> selectStage;
		} while (selectStage < 0 && selectStage > 6);
	
		if (selectStage != NULL) {
			system("cls");
		}
	
		return selectStage;
	}

	int exit() {
		system("cls");
		while (getchar() != '\n');
		View* view = 0;
		view->textcolor(BLUE, WHITE);
		view->putstr(32, 5, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
		view->putstr(32, 7, "┃  *************************  ┃");
		view->putstr(32, 9, "┃          GAME EXIT!         ┃");
		view->putstr(32, 11, "┃      Please press ENTER!    ┃");
		view->putstr(32, 13, "┃  *************************  ┃");
		view->putstr(32, 15, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

		while (getchar() != '\n');
		system("cls");
		return 0;
	}

};

