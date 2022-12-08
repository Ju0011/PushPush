#pragma once
#include <iostream>
#include "View.h"
#include <windows.h>
#include "View_Start.h"
#include <algorithm>    //배열 복사

using namespace std;

int main()
{
   
    system("mode con: cols=98 lines=30");   // 화면 크기 조정
    View* view = 0;
    View_Start* start = 0;

    start->logo();
    start->selectStage();

    _setcursortype(_NOCURSOR);

    textbackground(BLACK);
    clrscr();

    bool exit = false;
    
    int map_number = start->selectStage();
    view->define_Map(map_number);

    view->Inform(50);

    int start_x = 2, start_y = 4;
    int oldx, oldy;
    view->drawCharacter(start_x, start_y);

    while (exit != true) {
        bool move = true;
        int dx = 0, dy = 0;

        int key = view->getkey();
		int new_x = oldx = start_x;
		int new_y = oldy = start_y;

        switch (key) {
        case M_LEFTKEY: dx = -1; break;
        case M_UPKEY: dy = -1; break;
        case M_DOWNKEY:  dy = 1; break;
        case M_RIGHTKEY:  dx = 1; break;

        case SPACE:
            view->delCharacter(oldx, oldy);
            view->drawMap(copy_mapData);
            start_x = 2; start_y = 4;
            view->drawCharacter(2, 4);
            break;

        case N:
        case n:
            if (map_number > 0 && map_number < 5) {
                start_x = 2; start_y = 4;

                map_number++; view->define_Map(map_number);
            }
           
            break;
        case P:
        case p:
            if (map_number > 0 && map_number <= 6) {
                start_x = 2; start_y = 4;

                map_number--; view->define_Map(map_number);
            }
            break;
        case ESC:
            start->exit();
            exit = true;
        }

        new_x = start_x + dx;
        new_y = start_y + dy;


        
        switch (mapData[new_y][new_x]) {
        case 0: //길
            
            break;
        case 1: //벽
        case 4: //골인지점
            move = false;
            break;

        case 2: //공
            if (mapData[new_y + dy][new_x + dx] == 0) { //길
                mapData[new_y][new_x] = 0;  //길
                mapData[new_y + dy][new_x + dx] = 2;    //공
                view->drawCell(new_x + dx, new_y + dy, mapData);
            }
            else if(mapData[new_y + dy][new_x + dx] == 4) { //골대
                mapData[new_y][new_x] = 0;  //길
                mapData[new_y + dy][new_x + dx] = 3;    //채워진 공
                view->drawCell(new_x + dx, new_y + dy, mapData);
            }
            else if (mapData[new_y + dy][new_x + dx] == 1) {    //벽
                move = false;
            }
            break;

        case 3: // 완성된 골
            if (mapData[new_y + dy][new_x + dx] == 0) { //길
                mapData[new_y][new_x] = 4;  //골대
                mapData[new_y + dy][new_x + dx] = 2;    // 공
                view->drawCell(new_x + dx, new_y + dy, mapData);
            }
            else if (mapData[new_y + dy][new_x + dx] == 4) {    // 골대
                mapData[new_y][new_x] = 4;  //골대
                mapData[new_y + dy][new_x + dx] = 3;    // 채워진 공
                view->drawCell(new_x + dx, new_y + dy, mapData);
            }
            else if (mapData[new_y + dy][new_x + dx] == 1) {    //벽
                move = false;
            }
        }
        
        if (move) {
            start_x = new_x;
            start_y = new_y;
            view->drawCell(new_x, new_y, mapData);
            view->delCharacter(oldx, oldy);
            view->drawCharacter(new_x, new_y);
        }

        if (view->success()) {
            start_x = 2;
            start_y = 4;
            view->show_success(map_number);
        }

    }
}