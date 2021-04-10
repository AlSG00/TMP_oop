#pragma once
#include <fstream>
#include <string>

using namespace std;

class Movie 
{
public:
	char mName[50];
	char mCountry[50];
	// �������������, ���������� � ���� ������ �� ����-��
	static Movie* In(ifstream& ifst);
	virtual void InData(ifstream& ifst) = 0; // ����
	virtual void Out(ofstream& ofst) = 0; // �����
	virtual void OutCartoon(ofstream& ofst, Movie* mv);
	void InCommon(ifstream& ifst);
	void OutCommon(ofstream& ofst);
	void OutCountry(ofstream& ofst);
	int VowelsCount();
	bool Compare(Movie& second);
};