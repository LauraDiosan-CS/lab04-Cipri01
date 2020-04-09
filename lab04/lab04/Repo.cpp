#include "Repo.h"

//Descr: create a Repo object
//In: - 
//Out: an instance of Repo
Repo::Repo() {
	this->noExpense = 0;
	this->budget = 99999;
}

//Descr: create a Repo object
//In: n_costs[] - list of expences, n_noExpences - number of expences, n_budget - value for budget
//Out: an instance of Repo
Repo::Repo(Expense n_costs[], int n_noExpense, int n_budget) {
	this->noExpense = n_noExpense;
	this->budget = n_budget;
	for (int i = 0; i < noExpense; i++) {
		this->costs[i] = n_costs[i];
	}
}

//Descr: destroy a Repo object
//In: the current Repo object
//Out: -
Repo::~Repo() {
	this->noExpense = 0;
	this->budget = 0;
}

//Descr: create a new Repo object (equal to given Repo object)
//In: a Repo object 
//Out: a new Repo object
Repo& Repo::operator=(Repo& r) {
	this->noExpense = 0;
	for (int i = 0; i < this->noExpense; i++) {
		this->addExpense(r.getAll()[i]);
	}
	return *this;
}

//Descr: get all Expense object from costs
//In: -
//Out: costs 
Expense* Repo::getAll() {
	return this->costs;
}

//Descr: get an Expense from costs
//In: a position (integer)
//Out: - an Expense object from an given position
Expense Repo::getItemFromPos(int pos) {
	return this->costs[pos];
}

//Descr: add an Expense object in costs
//In: an Expense object
//Out: -
void Repo::addExpense(Expense& e) {
	this->costs[this->noExpense++] = e;
	this->budget -= e.getAmount();
}

//Descr: update an Expense obkect in costs
//In: an Expense object, a day, an amount, a type
//Out: -
void Repo::updateExpense(Expense& e, int day, int amount, char* type) {
	this->budget = this->budget + e.getAmount() - amount;
	e.setDay(day);
	e.setAmount(amount);
	e.setType(type);
}

//Descr: delete an expense from costs
//In: an Expense object
//Out: -
void Repo::deleteExpense(Expense e) {
	int pos = this->search(e);
	int lenght = this->getSize();
	if (pos != -1) {
		for (int i = pos; i < lenght - 1; i++) {
			this->costs[i] = this->costs[i + 1];
		}
		this->setBudget(this->budget + costs[pos].getAmount());
		//this->costs[lenght - 1] = Expense();
		this->setSize(lenght - 1);
	}
}

//Descr: search for an Expense object
//In: an given Expense object
//Out: the position in costs or -1 if not exist
int Repo::search(const Expense& e) {
	int length = this->getSize();
	for (int i = 0; i < length; i++) {
		if (this->costs[i] == e) {
			return i;
		}
	}
	return -1;
}

//Descr: Determine the size for costs
//In: -
//Out: size 
int Repo::getSize() {
	return this->noExpense;
}

//Descr: Determine the value for budget
//In: -
//Out: budget value
int Repo::getBudget() {
	return this->budget;
}

//Descr: set the value for size
//In: new_noExpense - new value for size
//Out: -
void Repo::setSize(int new_noExpense) {
	this->noExpense = new_noExpense;
}

//Descr: set the value for budget
//In: new_budget - new value for budget
//Out: -
void Repo::setBudget(int new_budget) {
	this->budget = new_budget;
}
