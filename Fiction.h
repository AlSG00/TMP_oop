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
};