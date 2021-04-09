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
};