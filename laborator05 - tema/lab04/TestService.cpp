#include "Service.h"
#include <assert.h>
#include <string.h>

void testServiceAdd() {
	Service s;
	//Repo r;
	char* type1 = new char[10];
	strcpy_s(type1, strlen("water") + 1, "water");
	assert(strcmp(type1, "water") == 0);				//ASSERT
	s.addExpense(1, 100, type1);
	assert(s.getAll()[0].getDay() == 1);				//ASSERT
	assert(s.getAll()[0].getAmount() == 100);			//ASSERT
	assert(strcmp(s.getAll()[0].getType(), type1) == 0);//ASSERT
	char* type2 = new char[10];
	strcpy_s(type2, strlen("clothes") + 1, "clothes");
	assert(strcmp(type2, "clothes") == 0);				//ASSERT
	s.updateExpense(0, 23, 1000, type2);
	assert(s.getAll()[0].getDay() == 23);				//ASSERT
	assert(s.getAll()[0].getAmount() == 1000);			//ASSERT
	assert(strcmp(s.getAll()[0].getType(), type2) == 0);//ASSERT
	assert(s.getSizeRepo() == 1);						//ASSERT
	assert(s.getBudget() == 98999);						//ASSERT
	s.deleteExpenseByDay(23);
	assert(s.getSizeRepo() == 0);						//ASSERT
}

void testServiceDelete() {
	Service s;
	char* type1 = new char[10];
	strcpy_s(type1, strlen("water") + 1, "water");
	assert(strcmp(type1, "water") == 0);				//ASSERT
	char* type2 = new char[10];
	strcpy_s(type2, strlen("clothes") + 1, "clothes");
	assert(strcmp(type2, "clothes") == 0);				//ASSERT
	char* type3 = new char[10];
	strcpy_s(type3, strlen("internet") + 1, "internet");
	assert(strcmp(type3, "internet") == 0);				//ASSERT
	s.addExpense(1, 250, type1);
	s.addExpense(2, 400, type2);
	s.addExpense(1, 1000, type3);
	s.addExpense(23, 20, type1);
	assert(s.getSizeRepo() == 4);//ASSERT
	s.deleteExpenseByDay(1);
	assert(s.getSizeRepo() == 2);//ASSERT
	s.deleteExpensesBetweenTwoDays(1, 23);
	assert(s.getSizeRepo() == 0);//ASSERT
	s.addExpense(1, 20, type1);
	assert(s.getSizeRepo() == 1);//ASSERT
	s.deleteExpenseByType(type1);
	assert(s.getSizeRepo() == 0);//ASSERT
	delete[] type1;
	delete[] type2;
	delete[] type3;
}

void testServiceWithProperties() {
	Service s;
	char* type1 = new char[10];
	strcpy_s(type1, strlen("water") + 1, "water");
	assert(strcmp(type1, "water") == 0);				//ASSERT
	char* type2 = new char[10];
	strcpy_s(type2, strlen("clothes") + 1, "clothes");
	assert(strcmp(type2, "clothes") == 0);				//ASSERT
	char* type3 = new char[10];
	strcpy_s(type3, strlen("internet") + 1, "internet");
	assert(strcmp(type3, "internet") == 0);				//ASSERT
	s.addExpense(1, 250, type1);
	s.addExpense(2, 400, type2);
	s.addExpense(8, 1000, type3);
	s.addExpense(23, 20, type1);
	Expense expenses[5] = {};
	int contor = 0;
	s.getExpenseByType(type1, expenses, contor);
	assert(contor == 2);//ASSERT
	assert(expenses[0].getDay() == 1);//ASSERT
	assert(expenses[1].getDay() == 23);

	Expense expenses1[5] = {};
	int contor1 = 0;
	s.getExpenseByTypeAndConditionBigger(type1, 200, expenses1, contor1);
	assert(contor1 == 1);//ASSERT
	assert(expenses1[0].getDay() == 1);//ASSERT

	Expense expenses2[5] = {};
	int contor2 = 0;
	s.getExpenseByTypeAndConditionEqual(type1, 250, expenses2, contor2);
	assert(contor2 == 1);//ASSERT
	assert(expenses2[0].getDay() == 1);//ASSERT
	delete[] type1;
	delete[] type2;
	delete[] type3;
}

void testServiceProperties() {
	Service s;

	char* type1 = new char[10];
	strcpy_s(type1, strlen("water") + 1, "water");
	assert(strcmp(type1, "water") == 0);				//ASSERT
	char* type2 = new char[10];
	strcpy_s(type2, strlen("clothes") + 1, "clothes");
	assert(strcmp(type2, "clothes") == 0);				//ASSERT
	char* type3 = new char[10];
	strcpy_s(type3, strlen("internet") + 1, "internet");
	assert(strcmp(type3, "internet") == 0);				//ASSERT

	s.addExpense(1, 100, type1);
	s.addExpense(2, 200, type2);
	s.addExpense(3, 300, type3);
	s.addExpense(4, 400, type1);
	s.addExpense(1, 500, type3);

	int sum = s.getSumOfAmountsOfExpensesByType(type1);
	assert(sum == 500);//ASSERT

	int max_zi = s.getDayWithMaximumValueForAmount();
	assert(max_zi == 1);//ASSERT

	delete[] type1;
	delete[] type2;
	delete[] type3;

}

void testSort() {
	Service s;

	char* type1 = new char[10];
	strcpy_s(type1, strlen("water") + 1, "water");
	assert(strcmp(type1, "water") == 0);				//ASSERT
	char* type2 = new char[10];
	strcpy_s(type2, strlen("clothes") + 1, "clothes");
	assert(strcmp(type2, "clothes") == 0);				//ASSERT
	char* type3 = new char[10];
	strcpy_s(type3, strlen("internet") + 1, "internet");
	assert(strcmp(type3, "internet") == 0);				//ASSERT

	s.addExpense(1, 100, type1);
	s.addExpense(2, 200, type2);
	s.addExpense(3, 300, type3);
	s.addExpense(4, 400, type1);
	s.addExpense(1, 500, type3);
	s.addExpense(6, 690, type3);

	int sorted[30] = {};
	int contor = 0;

	s.sortDaysByAmount(sorted, contor);
	assert(contor == 5);//ASSERT
	assert(sorted[0] == 690);//ASSERT
	assert(sorted[1] == 600);//ASSERT
	assert(sorted[2] == 400);//ASSERT
	assert(sorted[3] == 300);//ASSERT
	assert(sorted[4] == 200);//ASSERT

	contor = 0;
	s.sortAmountsByType(type3, sorted, contor);
	assert(contor == 3);//ASSERT
	assert(sorted[0] == 300);//ASSERT
	assert(sorted[1] == 500);//ASSERT
	assert(sorted[2] == 690);//ASSERT

	delete[] type1;
	delete[] type2;
	delete[] type3;
}

void testServiceFliter() {
	Service s;

	char* type1 = new char[10];
	strcpy_s(type1, strlen("water") + 1, "water");
	assert(strcmp(type1, "water") == 0);				//ASSERT
	char* type2 = new char[10];
	strcpy_s(type2, strlen("clothes") + 1, "clothes");
	assert(strcmp(type2, "clothes") == 0);				//ASSERT
	char* type3 = new char[10];
	strcpy_s(type3, strlen("internet") + 1, "internet");
	assert(strcmp(type3, "internet") == 0);				//ASSERT

	s.addExpense(1, 100, type1);
	s.addExpense(2, 200, type2);
	s.addExpense(3, 300, type3);
	s.addExpense(4, 400, type1);
	s.addExpense(1, 500, type3);
	s.addExpense(6, 690, type3);

	s.filterByType(type3);
	assert(s.getSizeRepo() == 3);//ASSERT
	assert(s.getAll()[0].getDay() == 3);//ASSERT
	assert(s.getAll()[1].getDay() == 1);//ASSERT
	assert(s.getAll()[2].getDay() == 6);//ASSERT

	s.filterByTypeAndConditionSmaller(type3, 600);
	assert(s.getSizeRepo() == 2);//ASSERT
	assert(s.getAll()[0].getDay() == 3);//ASSERT
	assert(s.getAll()[1].getDay() == 1);//ASSERT

	s.filterByTypeAndConditionEqual(type3, 300);
	assert(s.getAll()[0].getDay() == 3);//ASSERT


}

void serviceTEST() {
	cout << "--------------------------------------------------------------" << endl;
	cout << "TEST FOR SERVICE..." << endl;
	cout << "START..." << endl;
	testServiceAdd();
	testServiceDelete();
	testServiceWithProperties();
	testServiceProperties();
	testSort();
	testServiceFliter();
	cout << "TESTS DONE!..." << endl;
	cout << "--------------------------------------------------------------" << endl;
}