#include "Repo.h"

Repo::Repo() {
	this->noExpense = 0;
}

Repo::~Repo() {
	this->noExpense = 0;
}

void Repo::addExpense(Cheltuiala& c) {
	this->cgeltuieli[this->noExpense++] = c;
}

int Repo::getSize() {
	return this->noExpense;
}

Cheltuiala* Repo::getAll() {
	return this->cgeltuieli;
}

Cheltuiala Repo::getItemFromPos(int pos) {
	return this->cgeltuieli[pos];
}
