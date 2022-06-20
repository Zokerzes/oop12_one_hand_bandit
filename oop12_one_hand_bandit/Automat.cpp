
#include "Automat.h"

Automat::Automat()
{
	r1 = -1;
	r2 = -1;
	r3 = -1;
	this->count = 5;
	for (int i = 0; i < count; i++)
	{
		b1.Add(49 + i);
		b2.Add(49 + i);
		b3.Add(49 + i);
	}

}

Automat::Automat(int count)
{
	r1 = -1;
	r2 = -1;
	r3 = -1;
	this->count = count;
	for (int i = 0; i < count; i++)
	{
		b1.Add(49 + i);
		b2.Add(49 + i);
		b3.Add(49 + i);
	}
}

void Automat::kick()
{
	srand(time(0));
	int r =1+ rand() % count;
	for (int i = 0; i < r; i++) r1=b1.Extract();
	r =1+ rand() % count;
	for (int i = 0; i < r; i++) r2=b1.Extract();
	r =1+ rand() % count;
	for (int i = 0; i < r; i++) r3=b1.Extract();
}

void Automat::print()
{
	cout << (char)r1 << " " << (char)r2 << " " << (char)r3<<endl;
}

void Automat::game()
{
	int gamePoint = 0;
	system("cls");
	cout << "*********** ONE HAND BANDIT ***********" << endl << endl;
	char mChoise = ' ';
	do
	{
		system("cls");
		cout << "*********** ONE HAND BANDIT ***********" << endl << endl;
		cout << "(1) CONTINUE GAME" << endl << "(0) EXIT" << endl << endl;
		mChoise = _getch();
		kick();
		print();
		Sleep(50);
		if (r1 == r2 && r2 == r3) 
		{ gamePoint += 10; cout << "<< Point +10 >>"; }
		else if (r1 == r2 || r2 == r3 || r1 == r3) 
		{gamePoint++; cout << "<< Point +1 >>";}
		cout << "Game point " << gamePoint << endl;
		_getch();
	} while (mChoise != '0');
}

void Automat::menu()
{
	char mChoise, exit;
	do
	{
		do
		{
			system("cls");
			cout << "*********** ONE HAND BANDIT ***********" << endl << endl;
			cout << "(1) START GAME" << endl << "(0) EXIT" << endl << endl;
			mChoise = _getch();
		} while (mChoise != '1' && mChoise != '0');

		switch (mChoise)
		{
		case '1':
			game();
			break;

		case '0':

			break;
		}
		cout << endl << "Do you want go to menu or exit? (1 - yes, 0 - no)" << endl;
		fflush(stdin);
		exit = _getch();
	} while (exit != '0');
}
