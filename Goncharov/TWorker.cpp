#include "TWorker.h"
#include <iostream>
#include <string>

using namespace std;

int n;//global size var
TWorker::TWorker()
{
	fio = "Ivanov I I";
	department = "IT";
	position = "CEO";
	year = 2016;
	salary = 200000.0;
	cout << "����� �������� ����������� �� ���������";
}

TWorker::TWorker(std::string _fio, std::string _dep, std::string _pos, int _year, double _salary):fio(_fio), department(_dep), position(_pos), year(_year), salary(_salary)
{
}

TWorker::TWorker(TWorker & cpy)
{
	fio = cpy.fio;
	department = cpy.department;
	position = cpy.position;
	year = cpy.year;
	salary = cpy.salary;
}



void TWorker::Set()
{
	cout << "������� ������� � �������� ������ ���������:\n";
	cin.ignore();
	getline(cin, fio, '\n');
	cout << "������� �������� ������:\n";
	getline(cin, department, '\n');
	cout << "������� ���������:\n";
	getline(cin, position, '\n');
	cout << "������� ��� ����������� �� ������:\n";
	cin >> year;
	cout << "������� ��������:\n";
	cin >> salary;
}

bool TWorker::ExperienceOver(int exp, string dep)
{
	if(department == dep)
		if (2018 - year > exp)
			return true;
	return false;
}

void TWorker::ShowData()
{
	cout << fio << "\t" << department << "\t" << position << "\t" << year << "\t" << salary << endl;
}

bool TWorker::SalaryInRange(double beg, double end)
{
	if (salary >= beg && salary <= end)
		return true;
	return false;
}

bool TWorker::IsPosition(std::string pos)
{
	if (position == pos)
		return true;
	return false;
}

TWorker::~TWorker()
{
}

void demo()
{
	cout << "���������������� ���������\n\n\n";
	cout << "������� ���������� ����������: ";
	cin >> n;
	TWorker *list = new TWorker[n];
	for (int i = 0; i < n; i++)
		list[i].Set();
		int ch(1);
	while (ch)
	{
		cout << "1. ������ ���������� ���������� ������, ���� ������� ��������� ��������\n2.������ ����������, �������� ������� ��������� � �������� ���������\n3.������ ����������, ���������� �������� ���������\n\n\n";
		cin >> ch;
		switch (ch)
		{
		case 1:
			EXPOVER(list);
			system("pause");
			break;
		case 2:
			InRange(list);
			system("pause");
			break;
		case 3:
			POS(list);
			system("pause");
			break;
		}
	}
}

void InRange(TWorker *list)
{
	cout << "������� �������� ��������\n";
	double beg, end;
	cin >> beg >> end;
	for (int i = 0; i < n; i++)
	{
		if (list[i].SalaryInRange(beg, end))
			list[i].ShowData();
	}
}

void EXPOVER(TWorker *list)
{
	cout << "������� �������� ������\n";
	string dep;
	cin.ignore();
	getline(cin, dep, '\n');
	cout << "������� ���� ������\n";
	int exp;
	cin >> exp;
	for (int i = 0; i < n; i++)
		if (list[i].ExperienceOver(exp, dep))
			list[i].ShowData();
}

void POS(TWorker * list)
{
	cout << "������� ���������\n";
	string pos;
	cin >> pos;
	for (int i = 0; i < n; i++)
		if (list[i].IsPosition(pos))
			list[i].ShowData();
}
