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
	// �������������� ��������� ������
	void InData(ifstream& ifst); // ����
	void Out(ofstream& ofst); // �����
	Cartoon() {} // �������� ��� �������������.

	virtual void MultiMethod(Movie* other, ofstream& ofst);
	virtual void MMCartoon(ofstream& ofst);
	virtual void MMFiction(ofstream& ofst);
	//virtual void MMOut(ofstream& ofst);
};