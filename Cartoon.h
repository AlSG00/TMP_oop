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
};