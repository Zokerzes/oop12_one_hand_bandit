#include "Baraban.h"

Baraban::Baraban()
{
	//получаем размер
	MaxQueueLength = 20;
	//создаем очередь
	Wait = new int[MaxQueueLength];
	//Изначально очередь пуста
	QueueLength = 0;
}

Baraban::Baraban(int m)
{
	//получаем размер
	MaxQueueLength = m;
	//создаем очередь
	Wait = new int[MaxQueueLength];
	//Изначально очередь пуста
	QueueLength = 0;
}

Baraban::~Baraban()
{
	delete[]Wait;
}

void Baraban::Add(int c)
{
	if (!IsFull())	Wait[QueueLength++] = c;
}

int Baraban::Extract()
{
	//Если в очереди есть элементы, то возвращаем тот,
 //который вошел первым и сдвигаем очередь 
	if (!IsEmpty()) {
		//запомнить первый
		int temp = Wait[0];
		//сдвинуть все элементы
		for (int i = 1; i < QueueLength; i++)
			Wait[i - 1] = Wait[i];
		//забрасываем первый "вытолкнутый элемент
		//в конец"
		Wait[QueueLength - 1] = temp;
		return temp;
	}
	else return 0;
}

void Baraban::Clear()
{
	QueueLength = 0;
}

bool Baraban::IsEmpty()
{
	return QueueLength == 0;
}

bool Baraban::IsFull()
{
	return QueueLength == MaxQueueLength;
}

int Baraban::GetCount()
{
	return QueueLength;
}

void Baraban::Show()
{
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " ";
	}
}
