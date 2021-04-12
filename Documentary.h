#pragma once
#include "Movie.h"

class Documentary : public Movie
{
	int mYear;
public:
	// �������������� ��������� ������
	void InData(ifstream& ifst); // ����
	void Out(ofstream& ofst); // �����
	Documentary() {} // �������� ��� �������������.

	virtual void MultiMethod(Movie* other, ofstream& ofst);
	virtual void MMCartoon(ofstream& ofst);
	virtual void MMFiction(ofstream& ofst);
	virtual void MMDocumentary(ofstream& ofst);
};