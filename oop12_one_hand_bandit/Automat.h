#pragma once
#include <iostream>
#include "windows.h"
#include <string.h>
#include <time.h>
#include "Baraban.h"
#include <conio.h>
using namespace std;

class Automat
{
	Baraban b1;
	Baraban b2;
	Baraban b3;
	int r1;
	int r2;
	int r3;
 	int count{ int() };
public:

	Automat();
	Automat(int count);

	void kick();
	void print();
	void game();
	void menu();
};

