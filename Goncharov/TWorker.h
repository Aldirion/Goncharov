#pragma once
#include <string>
void demo();

class TWorker
{
	std::string fio;
	std::string department;
	std::string position;
	int year;
	double salary;
public:
	TWorker();
	TWorker(std::string, std::string, std::string, int, double);
	TWorker(TWorker &cpy);
	//methods
	void Set();
	bool ExperienceOver(int, std::string dep);
	void ShowData();
	bool SalaryInRange(double beg, double end);
	bool IsPosition(std::string pos);
	~TWorker();
};

void InRange(TWorker *list);
void EXPOVER(TWorker *list);
void POS(TWorker *list);