#ifndef REPO_H
#define REPO_H
#include "Cheltuieli.h"
using namespace std;

class Repo {
private:
	Cheltuiala cgeltuieli[20];
	int noExpense;
public:
	Repo();
	~Repo();
	void addExpense(Cheltuiala& c);
	int getSize();
	Cheltuiala* getAll();
	Cheltuiala getItemFromPos(int pos);
};
#endif // !REPO_H

