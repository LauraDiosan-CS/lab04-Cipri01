#ifndef CHELTUIALA_H
#define CHELTUIALA_H
#include <iostream>
#include <string.h>

class Cheltuiala {
private:
	int zi;
	int suma;
	char* tip;
public:
	Cheltuiala();
	Cheltuiala(int zi, int suma, char* tip);
	Cheltuiala(const Cheltuiala& c);
	~Cheltuiala();
	int getZi();
	int getSuma();
	char* getTip();
	void setZi(int n_zi);
	void setSuma(int n_suma);
	void setTip(char* n_tip);
	bool operator==(const Cheltuiala& c);
};
#endif // !CHELTUIALA_H
