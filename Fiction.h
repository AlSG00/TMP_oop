#pragma once
#include "Movie.h"

class Fiction : public Movie
{
	char mDirector[50];
public:
	// �������������� ��������� ������
	void InData(ifstream& ifst); // ����
	void Out(ofstream& ofst); // �����
	Fiction() {} // �������� ��� �������������.

	virtual void MultiMethod(Movie* other, ofstream& ofst);
	virtual void MMCartoon(ofstream& ofst);
	virtual void MMFiction(ofstream& ofst);
	virtual void MMDocumentary(ofstream& ofst);
};