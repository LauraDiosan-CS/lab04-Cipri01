#include "Service.h"

//Descr: add an expense in Repo
//In: a day, an amount, a type
//Out: -
void Service::addExpense(int day, int amount, char* type) {
	Expense newExpense(day, amount, type);
	this->repo.addExpense(newExpense);
}

//Descr: get all expense for Repo
//In: -
//Out: all expense
Expense* Service::getAll() {
	return this->repo.getAll();
}

//Descr: update an expense
//In: a position, new day, new amount, new type
//Out: -
void Service::updateExpense(int pos, int new_day, int new_amount, char* new_type) {
	repo.updateExpense(this->repo.getAll()[pos], new_day, new_amount, new_type);
}

//Descr: delete an expense by day
//In: a day
//Out: -
void Service::deleteExpenseByDay(int day) {
	int length = this->repo.getSize();
	for (int i = 0; i < length; i++) {
		if (this->getAll()[i].getDay() == day) {
			this->repo.deleteExpense(this->getAll()[i]);
		}
	}
}

//Descr: get size of Repo
//In: -
//Out: size of Repo
int Service::getSizeRepo() {
	return this->repo.getSize();
}

//Descr: get budget from Repo
//In: - 
//Out: the budget
int Service::getBudget() {
	return this->repo.getBudget();
}