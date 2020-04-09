#include <iostream>
using namespace std;
#include "Cheltuieli.h"
#include <string.h>
#include <assert.h>
#include "Repo.h"

void testClass() {
	char* nume1 = new char[10];
	strcpy_s(nume1, strlen("internet") + 1, "internet");
	Cheltuiala c1(1, 500, nume1);
	int zii = c1.getZi();
	int sumaa = c1.getSuma();
	assert(zii == 1);
	assert(sumaa == 500);
	c1.setZi(5);
	int new_zi = c1.getZi();
	assert(new_zi == 5);
	
}


int main() {
	testClass();
	cout << "ok CLASS!";
	cout << "ok REPO!";
	return 0;
}