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
			if (i) {
				if (this->getAll()[i - 1].getDay() == day) {
					this->repo.deleteExpense(this->getAll()[i-1]);
				}
			}
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

//Descr: delete all expenses between two days
//In: day_start - start, day_end - end
//Out: -
void Service::deleteExpensesBetweenTwoDays(int day_start, int day_end) {
	int length = this->repo.getSize();
	for (int i = 0; i < length; i++) {
		if ((this->getAll()[i].getDay() >= day_start) && (this->getAll()[i].getDay() <= day_end)) {
			this->repo.deleteExpense(this->getAll()[i]);
			if (i) {
				if ((this->getAll()[i-1].getDay() >= day_start) && (this->getAll()[i-1].getDay() <= day_end)) {
					this->repo.deleteExpense(this->getAll()[i - 1]);
				}
			}
		}
	}
}

//Descr: delete all expenses of a certain type
//In: type_del - type for delete
//Out: -
void Service::deleteExpenseByType(char* type_del) {
	int length = this->repo.getSize();
	for (int i = 0; i < length; i++) {
		if (strcmp(this->getAll()[i].getType(), type_del) == 0) {
			this->repo.deleteExpense(this->getAll()[i]);
			if (i) {
				if (strcmp(this->getAll()[i - 1].getType(), type_del) == 0) {
					this->repo.deleteExpense(this->getAll()[i-1]);
				}
			}
			
		}
	}
}

//Descr: displaying all expenses for a particular type
//In: type_display - type for display, expenses_type[] - list of Expense object, contor_exp - contor for expenses
//Out: -
void Service::getExpenseByType(char* type, Expense expenses[], int& contor_exp) {
	contor_exp = 0;
	int length = this->repo.getSize();
	for (int i = 0; i < length; i++) {
		if (strcmp(this->getAll()[i].getType(), type) == 0) {
			expenses[contor_exp++] = this->getAll()[i];
		}
	}
}

//Descr: displaying all expenses for a particular type and condition ( > )
//In: type_display - type for display, value - value for condition, expenses_type[] - list of Expense object, contor_exp - contor for expenses
//Out: -
void Service::getExpenseByTypeAndConditionBigger(char* type, int value, Expense expenses[], int& contor_exp) {
	contor_exp = 0;
	int length = this->repo.getSize();
	for (int i = 0; i < length; i++) {
		if ((strcmp(this->getAll()[i].getType(), type) == 0) && (this->getAll()[i].getAmount() > value)) {
			expenses[contor_exp++] = this->getAll()[i];
		}
	}
}

//Descr: displaying all expenses for a particular type and condition ( = )
//In: type_display - type for display, value - value for condition, expenses_type[] - list of Expense object, contor_exp - contor for expenses
//Out: -
void Service::getExpenseByTypeAndConditionEqual(char* type, int value, Expense expenses[], int& contor_exp) {
	contor_exp = 0;
	int length = this->repo.getSize();
	for (int i = 0; i < length; i++) {
		if ((strcmp(this->getAll()[i].getType(), type) == 0) && (this->getAll()[i].getAmount() == value)) {
			expenses[contor_exp++] = this->getAll()[i];
		}
	}
}

//Descr: get the sum of amounts for all expenses of certain type
//In: type_s - type for sum
//Out: sum of amounts for all expense of certain type
int Service::getSumOfAmountsOfExpensesByType(char* type_s) {
	int length = this->repo.getSize();
	int sum = 0;
	for (int i = 0; i < length; i++) {
		if (strcmp(this->getAll()[i].getType(), type_s) == 0) {
			sum += this->getAll()[i].getAmount();
		}
	}
	return sum;
}

//Descr: get the day with maximum value for amount
//In: - 
// day with maximum value for amount
int Service::getDayWithMaximumValueForAmount() {
	int frequency_for_days[32] = {};
	int max_amount = -1;
	int max_day = -1;
	int length = this->repo.getSize();
	for (int i = 0; i < length; i++) {
		frequency_for_days[this->getAll()[i].getDay()] += this->getAll()[i].getAmount();
		if (frequency_for_days[this->getAll()[i].getDay()] > max_amount) {
			max_amount = frequency_for_days[this->getAll()[i].getDay()];
			max_day = this->getAll()->getDay();
		}
	}
	return max_day;
}

//Descr: sort the days decreasing according to the sum of the expenses
//In: expenses_amounts[] - array for amounts, contor_exp - contor for array
//Out: -
void Service::sortDaysByAmount(int expenses_amounts[], int& contor_exp) {
	int length = this->repo.getSize();
	int amounts[32] = {};
	contor_exp = 0;
	for (int i = 0; i < length; i++) {
		amounts[this->getAll()[i].getDay()] += this->getAll()[i].getAmount();
	}
	for (int i = 1; i < 32; i++) {
		if (amounts[i]) {
			expenses_amounts[contor_exp++] = amounts[i];
		}
	}
	for (int i = 0; i < contor_exp - 1; i++) {
		for (int j = i + 1; j < contor_exp; j++) {
			if (expenses_amounts[i] < expenses_amounts[j]) {
				int aux = expenses_amounts[i];
				expenses_amounts[i] = expenses_amounts[j];
				expenses_amounts[j] = aux;
			}
		}
	}
}

//Descr: sort the amounts of daily expenses for a certain type of expense
//In:
//Out:
void Service::sortAmountsByType(char* type, int amounts[], int& contor_amounts) {
	contor_amounts = 0;
	int length = this->repo.getSize();
	for (int i = 0; i < length; i++) {
		if (strcmp(this->getAll()[i].getType(), type) == 0) {
			amounts[contor_amounts++] = this->getAll()[i].getAmount();
		}
	}
	for (int i = 0; i < contor_amounts - 1; i++) {
		for (int j = i + 1; j < contor_amounts; j++) {
			if (amounts[i] > amounts[j]) {
				int aux = amounts[i];
				amounts[i] = amounts[j];
				amounts[j] = aux;
			}
		}
	}
}

//Descr: filter expenses by type
//In: type_for_filter - type for filter
//Out: -
void Service::filterByType(char* type_for_filter) {
	int length = this->repo.getSize();
	for (int i = 0; i < length; i++) {
		if (strcmp(this->getAll()[i].getType(), type_for_filter) != 0) {
			this->repo.deleteExpense(this->getAll()[i]);
		}
		if (i) {
			if (strcmp(this->getAll()[i - 1].getType(), type_for_filter) != 0) {
				this->repo.deleteExpense(this->getAll()[i - 1]);
			}
		}
	}
}

//Descr: filter expense by type and condition
//In: type_for_filter - type for filter, value - value for condition
//Out: -
void Service::filterByTypeAndConditionSmaller(char* type_for_filter, int value) {
	int length = this->repo.getSize();
	for (int i = 0; i < length; i++) {
		if ((strcmp(this->getAll()[i].getType(), type_for_filter) == 0) && (this->getAll()[i].getAmount() >= value)) {
			this->repo.deleteExpense(this->getAll()[i]);
		}
		if (strcmp(this->getAll()[i].getType(), type_for_filter) != 0) {
			this->repo.deleteExpense(this->getAll()[i]);
		}
		if (i) {
			if ((strcmp(this->getAll()[i-1].getType(), type_for_filter) == 0) && (this->getAll()[i-1].getAmount() >= value)) {
				this->repo.deleteExpense(this->getAll()[i-1]);
			}
			if (strcmp(this->getAll()[i-1].getType(), type_for_filter) != 0) {
				this->repo.deleteExpense(this->getAll()[i-1]);
			}
		}
	}
}

//Descr: filter expense by type and condition
//In: type_for_filter - type for filter, value - value for condition
//Out: -
void Service::filterByTypeAndConditionEqual(char* type_for_filter, int value) {
	int length = this->repo.getSize();
	for (int i = 0; i < length; i++) {
		if ((strcmp(this->getAll()[i].getType(), type_for_filter) == 0) && (this->getAll()[i].getAmount() != value)) {
			this->repo.deleteExpense(this->getAll()[i]);
		}
		if (strcmp(this->getAll()[i].getType(), type_for_filter) != 0) {
			this->repo.deleteExpense(this->getAll()[i]);
		}
		if (i) {
			if ((strcmp(this->getAll()[i-1].getType(), type_for_filter) == 0) && (this->getAll()[i-1].getAmount() != value)) {
				this->repo.deleteExpense(this->getAll()[i-1]);
			}
			if (strcmp(this->getAll()[i-1].getType(), type_for_filter) != 0) {
				this->repo.deleteExpense(this->getAll()[i-1]);
			}
		}
	}
}
