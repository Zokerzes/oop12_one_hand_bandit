#pragma once
#include <iostream>

#include <string.h>
#include <time.h>
using namespace std;
class Baraban
{
	int* Wait;
	int MaxQueueLength;
	int QueueLength;

public:
	Baraban();
	Baraban(int m);
	~Baraban();
	void Add(int c);
	int Extract();
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int GetCount();
	void Show();
};

