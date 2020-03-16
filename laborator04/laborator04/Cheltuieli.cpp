#include "Cheltuieli.h"
#include <iostream>
#include <string.h>

// Constructor
// In: -
// Out: an empty object of type Cheltuiala
Cheltuiala::Cheltuiala() {
	this->zi = 0;
	this->suma = 0;
	this->tip = NULL;
}

// Constructor with parameters
// In: a name (string) and an age (integer)
// Out: an object of type Cheltuiala that contains the given info
Cheltuiala::Cheltuiala(int zii, int sumaa, char* tipp) {
	this->zi = zii;
	this->suma = sumaa;
	this->tip = new char[strlen(tipp) + 1];
	strcpy_s(this->tip, 1 + strlen(tipp), tipp);
}

//Copy Constructor
//In: an object s of type Cheltuiala
//Out: another object of type Cheltuiala that contains the same info as s
Cheltuiala::Cheltuiala(const Cheltuiala& c) {
	this->zi = c.zi;
	this->suma = c.suma;
	this->tip = new char[strlen(c.tip) + 1];
	strcpy_s(this->tip, 1 + strlen(c.tip), c.tip);
}

// Destructor
// In: an object of type Student
// Out: -
Cheltuiala::~Cheltuiala() {
	if (this->tip) {
		delete[] this->tip;
		this->tip = NULL;
	}
}

// getter
// In: an object of type Cheltuiala
// Out: day of the expense
int Cheltuiala::getZi() {
	return this->zi;
}

// getter
// In: an object of type Cheltuiala
// Out: sum of the expense
int Cheltuiala::getSuma() {
	return this->suma;
}

// getter
// In: an object of type Student
// Out: type of the expense
char* Cheltuiala::getTip() {
	return this->tip;
}

// setter
// In: an object of type Cheltuiala and a day (integer)
// Out: the same object with a new day
void Cheltuiala::setZi(int zii) {
	this->zi = zii;
}

// setter
// In: an object of type Cheltuiala and a sum (integer)
// Out: the same object with a new sum
void Cheltuiala::setSuma(int sumaa) {
	this->suma = sumaa;
}

// setter
// In: an object of type Cheltuiala and a type (string)
// Out: the same object with a new type
void Cheltuiala::setTip(char* tipp) {
	if (this->tip) {
		delete[] this->tip;
	}
	this->tip = new char[strlen(tipp) + 1];
	strcpy_s(this->tip, 1 + strlen(tipp), tipp);
}

// comparator
// In: two objects of type Cheltuiala (this and s)
// Out: true or false
bool Cheltuiala::operator==(const Cheltuiala& c) {
	return ((strcmp(this->tip, c.tip) == 0) && (this->zi == c.zi) && (this->suma == c.suma));
}