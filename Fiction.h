#pragma once
#include "Movie.h"

class Fiction : public Movie
{
	char mDirector[50];
public:
	// переопределяем интерфейс класса
	void InData(ifstream& ifst); // ввод
	void Out(ofstream& ofst); // вывод
	Fiction() {} // создание без инициализации.

	virtual void MultiMethod(Movie* other, ofstream& ofst);
	virtual void MMCartoon(ofstream& ofst);
	virtual void MMFiction(ofstream& ofst);
	virtual void MMDocumentary(ofstream& ofst);
};