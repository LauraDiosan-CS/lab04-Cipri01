#include "TestRepo.h"
#include "Repo.h"
#include "Expense.h"
#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

void testRepo() {
	Repo r;
	assert(r.getSize() == 0);							//ASSERT
	assert(r.getBudget() == 99999);						//ASSERT
	char* type1 = new char[10];
	strcpy_s(type1, strlen("water") + 1, "water");
	assert(strcmp(type1, "water") == 0);				//ASSERT
	Expense e1(5, 450, type1); //constructir with param
	r.addExpense(e1);
	assert(r.getBudget() == 99549);						//ASSERT
	r.updateExpense(e1, 1, 2, type1);
	assert(r.getBudget() == 99997);						//ASSERT
	assert(e1.getDay() == 1);							//ASSERT
	assert(e1.getAmount() == 2);						//ASSERT
	assert(strcmp(e1.getType(), type1) == 0);			//ASSERT
	r.updateExpense(e1, 5, 450, type1);
	assert(r.getBudget() == 99549);						//ASSERT
	Expense* v = r.getAll();
	assert(r.getSize() == 1);							//ASSERT
	char* type2 = new char[10];
	strcpy_s(type2, strlen("clother") + 1, "clothes");
	assert(strcmp(type2, "clothes") == 0);				//ASSERT
	Expense e2(15, 4500, type2); //constructir with param
	r.addExpense(e2);
	assert(r.getBudget() == 95049);						//ASSERT
	assert(r.getSize() == 2);							//ASSERT
	Expense el = r.getItemFromPos(1);
	assert(el.getDay() == 15);							//ASSERT
	assert(el.getAmount() == 4500);						//ASSERT
	assert(strcmp(el.getType(), type2) == 0);			//ASSERT
	r.setBudget(10000);
	assert(r.getBudget() == 10000);						//ASSERT
	int pos = r.search(e1);
	assert(pos == 0);									//ASSERT
	r.deleteExpense(e1);
	assert(r.getSize() == 1);							//ASSERT
	pos = r.search(e1);
	assert(pos == -1);									//ASSERT

}

void t() {
	Repo r;
	assert(r.getSize() == 0);							//ASSERT
	assert(r.getBudget() == 99999);						//ASSERT
	char* type1 = new char[10];
	strcpy_s(type1, strlen("water") + 1, "water");
	assert(strcmp(type1, "water") == 0);				//ASSERT
	Expense e1(5, 450, type1); //constructir with param
	r.addExpense(e1);
	r.updateExpense(e1, 1, 2, type1);
	cout << e1.getDay();
}

void repoTEST() {
	cout << "--------------------------------------------------------------" << endl;
	cout << "TEST FOR REPO..." << endl;
	cout << "START..." << endl;
	testRepo();
	cout << "TESTS DONE!..." << endl;
	cout << "--------------------------------------------------------------" << endl;
}
