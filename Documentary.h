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
};