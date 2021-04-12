#pragma once
#include <fstream>
#include <string>

using namespace std;

class Movie 
{
public:
	char mName[50];
	// �������������, ���������� � ���� ������ �� ����-��
	static Movie* In(ifstream& ifst);
	virtual void InData(ifstream& ifst) = 0; // ����
	virtual void Out(ofstream& ofst) = 0; // �����
	void InCommon(ifstream& ifst);
	void OutCommon(ofstream& ofst);

	virtual void MultiMethod(Movie* other, ofstream& ofst) = 0;
	virtual void MMCartoon(ofstream& ofst) = 0;
	virtual void MMFiction(ofstream& ofst) = 0;
	//virtual void MMOut(ofstream& ofst) = 0;
};