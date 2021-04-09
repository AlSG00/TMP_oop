#pragma once
#include <fstream>
#include <string>

using namespace std;

class Movie 
{
public:
	char mName[50];
	// иденитфикация, порождение и ввод фигуры из пото-ка
	static Movie* In(ifstream& ifst);
	virtual void InData(ifstream& ifst) = 0; // ввод
	virtual void Out(ofstream& ofst) = 0; // вывод
	virtual void OutCartoon(ofstream& ofst, Movie* mv);
	void InCommon(ifstream& ifst);
	void OutCommon(ofstream& ofst);
};