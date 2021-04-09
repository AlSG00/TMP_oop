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
	void OutCartoon(ofstream& ofst, Movie* mv);
	Cartoon() {} // создание без инициализации.
};