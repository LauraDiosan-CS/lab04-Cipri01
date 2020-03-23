#ifndef REPO_H
#define REPO_H
#include <iostream>
#include "Expense.h"
using namespace std;

class Repo {
private:
	Expense costs[50];
	int noExpense;
	int budget;
public:
	Repo(); //constructor implicit
	Repo(Expense costs[], int noExpense, int budget); //constructor with param
	~Repo(); //destructor
	Repo& operator=(Repo& r); //operator =
	Expense* getAll(); //get all method
	Expense getItemFromPos(int pos); //get from pos method
	void addExpense(Expense& e); //add method
	void updateExpense(Expense& e, int day, int amount, char* type); //update method
	void deleteExpense(Expense e); //delete method
	int search(const Expense& e); //search method
	int getSize(); //get size method
	int getBudget(); //get budget method
	void setSize(int new_noExpense); //set size method
	void setBudget(int new_budget); //set budget method

};
#endif // !REPO_H
