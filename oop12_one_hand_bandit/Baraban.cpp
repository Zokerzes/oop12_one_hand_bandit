#include "Baraban.h"

Baraban::Baraban()
{
	//�������� ������
	MaxQueueLength = 20;
	//������� �������
	Wait = new int[MaxQueueLength];
	//���������� ������� �����
	QueueLength = 0;
}

Baraban::Baraban(int m)
{
	//�������� ������
	MaxQueueLength = m;
	//������� �������
	Wait = new int[MaxQueueLength];
	//���������� ������� �����
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
	//���� � ������� ���� ��������, �� ���������� ���,
 //������� ����� ������ � �������� ������� 
	if (!IsEmpty()) {
		//��������� ������
		int temp = Wait[0];
		//�������� ��� ��������
		for (int i = 1; i < QueueLength; i++)
			Wait[i - 1] = Wait[i];
		//����������� ������ "����������� �������
		//� �����"
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
