#pragma once
#include "Movie.h"

class Cartoon : public Movie 
{
	enum creationType
	{
		DRAWN,
		RAGDOLL,
		PLASTICINE
	};
	creationType mType;
public:
	// переопределяем интерфейс класса
	void InData(ifstream& ifst); // ввод
	void Out(ofstream& ofst); // вывод
	Cartoon() {} // создание без инициализации.

	virtual void MultiMethod(Movie* other, ofstream& ofst);
	virtual void MMCartoon(ofstream& ofst);
	virtual void MMFiction(ofstream& ofst);
	//virtual void MMOut(ofstream& ofst);
};