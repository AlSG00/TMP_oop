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
};