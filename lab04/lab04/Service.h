#ifndef SERVICE_H
#define SERVICE_H
#include "Repo.h"

class Service {
private:
	Repo repo;
public:
	void addExpense(int day, int amount, char* type); //CREATE
	Expense* getAll(); //READ
	void updateExpense(int pos, int new_day, int new_amount, char* new_type); //UPDATE
	void deleteExpenseByDay(int day); //DELETE
	int getSizeRepo();
	int  getBudget();
};
#endif // !SERVICE_H
