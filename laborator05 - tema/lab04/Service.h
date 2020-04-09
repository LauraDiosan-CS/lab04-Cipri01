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
	void deleteExpensesBetweenTwoDays(int day_start, int day_end);
	void deleteExpenseByType(char* type_del);
	void getExpenseByType(char* type, Expense expenses[], int& contor_exp);
	void getExpenseByTypeAndConditionBigger(char* type, int value, Expense expenses[], int& contor_exp);
	void getExpenseByTypeAndConditionEqual(char* type, int value, Expense expenses[], int& contor_exp);
	int getSumOfAmountsOfExpensesByType(char* type_s);
	int getDayWithMaximumValueForAmount();
	void sortDaysByAmount(int expenses[], int& contor_exp);
	void sortAmountsByType(char* type, int amounts[], int& contor_amounts);
	void filterByType(char* type);
	void filterByTypeAndConditionSmaller(char* type_for_filter, int value);
	void filterByTypeAndConditionEqual(char* type_for_filter, int value);
};
#endif // !SERVICE_H
