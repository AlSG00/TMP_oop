#include "Movie.h"
#include "Cartoon.h"
#include "Fiction.h"
#include <iostream>
#include <string>

using namespace std;

Movie* Movie::In(ifstream& ifst) {
	Movie* mv;
	int k;
	ifst >> k;
	switch (k) {
	case 1:
		mv = new Cartoon;
		break;
	case 2:
		mv = new Fiction;
		break;
	default: //Если попадаем сюда, то застрянем. Временное решение: пусть мудрость с неправильным ключом просто не будет заноситься в контейнер
		char Junk[50]; //для мусора
		ifst.getline(Junk, 50); //Здесь - выражение
		ifst.getline(Junk, 50); //Здесь - уникальная характеристика
		ifst.getline(Junk, 50); //Здесь - оценка
		return 0;
	}
	string Line; //Временное решение на случай переполнения
	getline(ifst, Line); //Строка заносится в Line
	getline(ifst, Line); //Строка заносится в Line
	if (Line.length() < 50) { //Проверка на переполнение - если длина Line < 100
		strcpy_s(mv->mName, 50, Line.c_str());
		mv->InData(ifst);
		return mv;
	}
	else { //иначе придется отсечь лишнее
		Line.resize(49);
		strcpy_s(mv->mName, 50, Line.c_str());
		mv->InData(ifst);
		return mv;
	}
	Line.clear();
}

void Movie::InCommon(ifstream& ifst)
{
	ifst >> mName;
};

void Movie::OutCommon(ofstream& ofst)
{
	ofst << mName;
};

