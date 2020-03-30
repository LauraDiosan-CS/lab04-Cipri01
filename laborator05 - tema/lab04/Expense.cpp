#include "Expense.h"
#include <iostream>
#include <string.h>

//Descr: create an expense object
//In: - 
//Out: an instance of Expense
Expense::Expense() {
	// cout << "implicit constructor Expense(0, 0, NULL)" << endl;
	this->day = 0;
	this->amount = 0;
	this->type = NULL; 
}

//Descr: create an expense object
//In: valDay - integer number (between 1 and 28/29/30/31), valAmount - integer number, 
//valType - char* (household, food, transpotation, clothes, internet, others)
//Out: an instance of Expense
Expense::Expense(int valDay, int valAmount, char* valType) {
	// cout << "constructor by parameters Expense : " << endl;
	this->day = valDay;
	this->amount = valAmount;
	this->type = new char[strlen(valType) + 1];
	strcpy_s(this->type, 1 + strlen(valType), valType);

}

//Descr: create an expense object from another Expense object
//In: an Expense object
//Out: an instance of Expense equal to e
Expense::Expense(const Expense& e) {
	// cout << "copy constructor Expense : " << endl;
	this->day = e.day;
	this->amount = e.amount;
	this->type = new char[strlen(e.type) + 1];
	strcpy_s(this->type, 1 + strlen(e.type), e.type);
}

//Descr: destroy an Expense object
//In: the current Expense object
//Out: -
Expense::~Expense() {
	// cout << "destructor Expense " << endl;
	if (this->type) {
		delete[] this->type;
		this->type = NULL;
	}
}

//Descr: change the day of an Expense object
//In: an Expense object and a value for day
//Out: the Expense object with changed day
void Expense::setDay(int valDay) {
	this->day = valDay;
}

//Descr: change the amount of an Expense object
//In: an Expense object and a value for amount
//Out: the Expense object with changed amount
void Expense::setAmount(int valAmount) {
	this->amount = valAmount;
}

//Descr: change the type of an Expense object
//In: an Expense object and a value for type
//Out: the Expense object with changed type
void Expense::setType(char* valType) {
	if (this->type) {
		delete[] this->type;
	}
	this->type = new char[strlen(valType) + 1];
	strcpy_s(this->type, strlen(valType) + 1, valType);
}

//Descr: acces the day of an Expense object
//In: an Expense object
//Out: the day for an Expense
int Expense::getDay() {
	return this->day;
}

//Descr: acces the amount of an Expense object
//In: an Expense object
//Out: the amount of an Expense
int Expense::getAmount() {
	return this->amount;
}

//Descr: acces the type of an Expense object
//In: an Expense object
//Out: the type of an Expense
char* Expense::getType() {
	return this->type;
}

//Descr: acces the adress of an Expense object
//In: an Expense object
//Out: the adress of an Expense
Expense* Expense::operator&() {
	//cout << "adress operator & for crt object: " << endl;
	return this;
}

//Descr: create a new Expense object (equal to  given Expense object)
//In: an Expense object
//Out: a new Expense object
Expense& Expense::operator=(const Expense& e) {
	this->setDay(e.day);
	this->setAmount(e.amount);
	this->setType(e.type);
	return *this;
}

//Descr: compare two Expense object
//In: two Expense object (the crt one, e)
//Out: true or false
bool Expense::operator==(const Expense& e) {
	return ((this->day == e.day) && (this->amount == e.amount) && (strcmp(this->type, e.type) == 0));
}

//IO operators
//Descr: load an Expense object from an input stream
//In: an input stream
//Out: a new Expense object
istream& operator>>(istream& is, Expense& e) {
	cout << "is >> r" << endl;
	cout << "day = ";
	is >> e.day;
	cout << "amount = ";
	is >> e.amount;
	cout << "type = ";
	is >> e.type;
	cout << e.day << "," << e.amount << "," << e.type;
	return is;
}

//IO operators
//Descr: save an Expense object into an output stream
//In: an output stream, an Expense object
//Out: the output stream (loaded by info about Expense object)
ostream& operator<<(ostream& os, Expense& e) {
	//cout << "os << e for " << e.day << "," << e.amount << "," << e.type << endl;
	os <<"day: " << e.day << ", amount: " << e.amount << ", type: " << e.type << endl;
	return os;
}
