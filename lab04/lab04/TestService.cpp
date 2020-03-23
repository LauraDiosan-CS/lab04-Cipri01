#include "Service.h"
#include <assert.h>
#include <string.h>

void testService() {
	Service s;
	//Repo r;
	char* type1 = new char[10];
	strcpy_s(type1, strlen("water") + 1, "water");
	assert(strcmp(type1, "water") == 0);				//ASSERT
	s.addExpense(1, 100, type1);
	assert(s.getAll()[0].getDay() == 1);
	assert(s.getAll()[0].getAmount() == 100);
	assert(strcmp(s.getAll()[0].getType(), type1) == 0);
	char* type2 = new char[10];
	strcpy_s(type2, strlen("clothes") + 1, "clothes");
	assert(strcmp(type2, "clothes") == 0);				//ASSERT
	s.updateExpense(0, 23, 1000, type2);
	assert(s.getAll()[0].getDay() == 23);
	assert(s.getAll()[0].getAmount() == 1000);
	assert(strcmp(s.getAll()[0].getType(), type2) == 0);
	assert(s.getSizeRepo() == 1);
	assert(s.getBudget() == 98999);
	s.deleteExpenseByDay(23);
	assert(s.getSizeRepo() == 0);


}

void serviceTEST() {
	cout << "--------------------------------------------------------------" << endl;
	cout << "TEST FOR SERVICE..." << endl;
	cout << "START..." << endl;
	testService();
	cout << "TESTS DONE!..." << endl;
	cout << "--------------------------------------------------------------" << endl;
}