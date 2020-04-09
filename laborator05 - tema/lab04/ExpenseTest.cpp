
#include "Expense.h"
#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

void printExpense(Expense e) {
	cout << e.getDay() << "," << e.getAmount() << "," << e.getType() << endl;
}

void testConstructors() {
		//static (fiexd) objects
	Expense e1; //implicit constructor
	assert((e1.getDay() == 0) && (e1.getDay() == 0));
	char* type1 = new char[10];
	strcpy_s(type1, strlen("water") + 1, "water");
	assert(strcmp(type1, "water") == 0);
	Expense e2(5, 450, type1); //constructir with param
	assert((e2.getDay() == 5) && (e2.getAmount() == 450) && (strcmp(e2.getType(), type1) == 0));
	//printExpense(e2);
		//dynamic objects
	Expense* pe1; //no constructor
	pe1 = new Expense(); //implicit constructor
	assert((pe1->getDay() == 0) && (pe1->getAmount() == 0));
	char* type2 = new char[10];
	strcpy_s(type2, strlen("clothes") + 1, "clothes");
	Expense* pe2 = new Expense(7, 450, type2); //constructor with param
	assert((pe2->getDay() == 7) && (pe2->getAmount() == 450) && (strcmp(pe2->getType(), type2) == 0));
	if (pe2 != NULL) {
		delete pe2;//destructor
		pe2 = NULL;
	}
	if (pe1 != NULL) {
		delete pe1;//destructor
		pe1 = NULL;
	}
}

void testSetGet() {
		//static object
	Expense e1; //Expense object
	e1.setDay(19); //setter
	e1.setAmount(500); //setter
	char* type1 = new char[10]; //char*
	strcpy_s(type1, strlen("water") + 1, "water"); //char*
	e1.setType(type1); //setter
	assert(e1.getDay() == 19); //assert
	assert(e1.getAmount() == 500); //assert
	assert(strcmp(e1.getType(), type1) == 0); //assert
		//dynamic object
	char* type2 = new char[10]; //char*
	strcpy_s(type2, strlen("clothes") + 1, "clothes"); //char*
	Expense* pe1 = new Expense(); //Expense object
	pe1->setDay(9); //setter
	pe1->setAmount(21); //setter
	pe1->setType(type2); //setter
	assert(pe1->getDay() == 9); //assert
	assert(pe1->getAmount() == 21); //assert
	assert(strcmp(pe1->getType(), type2) == 0); //assert
	if (pe1 != NULL) {
		delete pe1;//destructor
		pe1 = NULL;
	}
}

void testEquality() {
	char* type1 = new char[10]; //char*
	strcpy_s(type1, strlen("water") + 1, "water"); //char*
	Expense e1(5, 15, type1); //Expense object
	Expense e2(5, 15, type1); //Expense object
	if (e1 == e2)
		cout << " equal Expense object " << endl;
	else
		cout << " different Expense object " << endl;
}

void expenseTEST() {
	cout << "--------------------------------------------------------------" << endl;
	cout << "TEST FOR CONSTRUCTORS, GETTERS AND SETTERS..." << endl;
	cout << "START..." << endl;
	testConstructors();
	testSetGet();
	//testEquality();
	cout << "TESTS DONE!..." << endl;
	cout << "--------------------------------------------------------------" << endl;
}
