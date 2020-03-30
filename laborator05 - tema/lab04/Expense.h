#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>
using namespace std;

class Expense {
private: //optional; implicit all the data and methods are private
	int day;
	int amount;
	char* type;
public:
	Expense(); // implicit constructor
	Expense(int valDay, int valAmount, char* valType); // constructor by parameters
	Expense(const Expense& e); // copy constructor
	~Expense(); // destructor
	void setDay(int valueDay); // setter
	void setAmount(int valAmount); // setter
	void setType(char* valType); // setter
	int getDay(); // getter
	int getAmount(); // getter
	char* getType(); // getter

		//unary operators
	//const Expense& operator+();
	//const Expense operator-();
	Expense* operator&(); // adress operator
		//binary local operators
	//const Expense& operator++();
	//const Expense operator++(int);
	//const Expense operator+(const Expense& eRight) const;
	//void addToThis(const Expense& e);
	//Expense& operator+=(const Expense& eRight);
	Expense& operator=(const Expense& e); // operator =
	bool operator==(const Expense& e); // operator == 

		//IO operators
	friend istream& operator>>(istream& is, Expense& e); // IO operator
	friend ostream& operator<<(ostream& os, Expense& e); // IO operator
};
#endif // !EXPENSE_H
