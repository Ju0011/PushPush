#pragma once
#include <iostream>
#include "View.h"
#include <windows.h>
#include "View_Start.h"
#include <algorithm>    //�迭 ����
#include "Sound.h"
#include "Controller.h"

using namespace std;

int main()
{
    _setcursortype(_NOCURSOR);
    clrscr();
    system("mode con: cols=98 lines=30");   // ȭ�� ũ�� ����
    Sound* sound = 0;
    Controller* controller = 0;

    sound->Play();
    //sound->mp3Play();
    controller->controller();

    return 0;
}