#pragma once

#include <iostream>
using namespace std;
#include <algorithm>
#include <windows.h>
#include <conio.h>
#include "Consola.h"
#include "keycode.h"

int mapData[10][10];

int copy_mapData[10][10];

int mapData_1[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,4,1,1,0,5,0,4,1},
	{1,0,0,0,1,0,2,1,0,1},
	{1,0,2,0,0,0,0,1,1,1},
	{1,0,0,0,0,0,1,1,0,1},
	{1,1,1,1,0,0,0,0,0,1},
	{1,0,0,1,0,2,0,2,0,1},
	{1,4,0,0,0,0,1,4,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};

int mapData_2[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,4,1,1,0,0,0,0,1},
	{1,5,0,1,1,0,1,1,4,1},
	{1,0,2,2,0,2,0,1,1,1},
	{1,0,0,0,0,0,1,1,0,1},
	{1,1,1,1,0,0,0,0,4,1},
	{1,4,0,1,0,2,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};

int mapData_3[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,5,0,0,4,1},
	{1,4,0,0,1,0,1,1,0,1},
	{1,0,2,2,0,0,0,1,1,1},
	{1,0,0,0,0,0,1,1,4,1},
	{1,1,1,1,0,0,0,0,0,1},
	{1,0,1,1,0,2,2,0,0,1},
	{1,4,0,0,0,0,1,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};

int mapData_4[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,4,1,1,0,0,0,4,1},
	{1,0,0,0,1,0,1,1,0,1},
	{1,0,2,2,0,0,0,1,1,1},
	{1,4,0,0,0,0,1,1,0,1},
	{1,1,1,1,0,0,0,0,0,1},
	{1,0,0,0,0,2,0,0,0,1},
	{1,0,2,0,5,0,1,1,4,1},
	{1,1,1,1,1,1,1,1,1,1}
};

int mapData_5[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,4,1,1,0,0,0,4,1},
	{1,1,0,0,1,0,1,1,0,1},
	{1,0,2,0,0,0,0,1,1,1},
	{1,5,0,0,0,0,1,1,0,1},
	{1,1,1,1,0,0,0,2,0,1},
	{1,1,0,1,0,2,0,2,0,1},
	{1,4,0,0,0,0,1,4,5,1},
	{1,1,1,1,1,1,1,1,1,1}
};

class Model
{
public:
	
};

