#pragma once
#include "Movie.h"

class Documentary : public Movie
{
	int mYear;
public:
	// переопределяем интерфейс класса
	void InData(ifstream& ifst); // ввод
	void Out(ofstream& ofst); // вывод
	Documentary() {} // создание без инициализации.

	virtual void MultiMethod(Movie* other, ofstream& ofst);
	virtual void MMCartoon(ofstream& ofst);
	virtual void MMFiction(ofstream& ofst);
	virtual void MMDocumentary(ofstream& ofst);
};