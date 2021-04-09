#include "Movie.h"
#include "Cartoon.h"
#include "Fiction.h"
#include <iostream>
#include <string>

using namespace std;

Movie* Movie::In(ifstream& ifst) 
{
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
	default:
		char Junk[50]; //��� ������
		ifst.getline(Junk, 50);
		ifst.getline(Junk, 50);
		ifst.getline(Junk, 50);
		return 0;
	}
	string Line; //��������� ������� �� ������ ������������
	getline(ifst, Line); //������ ��������� � Line
	getline(ifst, Line); //������ ��������� � Line
	if (Line.length() < 50) { //�������� �� ������������ - ���� ����� Line < 50
		strcpy_s(mv->mName, 50, Line.c_str());
		mv->InData(ifst);
		return mv;
	}
	else { //����� �������� ������ ������
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

