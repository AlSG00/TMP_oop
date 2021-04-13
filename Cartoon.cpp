#include <iostream>
#include "Cartoon.h"

using namespace std;
//������� �����
void Cartoon::InData(ifstream& ifst)
{
	int Line;
	ifst >> Line;
	if (ifst.fail())
	{
		return;
	}
	else
	{
		if (Line == 0)
		{
			mType = Cartoon::DRAWN;
		}
		else if (Line == 1)
		{
			mType = Cartoon::RAGDOLL;
		}
		else if (Line == 2)
		{
			mType = Cartoon::PLASTICINE;
		}
	}

}
//������� ������
void Cartoon::Out(ofstream& ofst) 
{
	if (!(mType == 0 || mType == 1 || mType == 2))
	{
		ofst << "It is CARTOON and there is ERROR in Type " << endl;
	}
	else
	{
		ofst << "It is CARTOON movie called ";
		OutCommon(ofst);
		ofst << ", Creation type = ";
		if (mType == 0)
		{
			ofst << "Drawned";
		}
		else if (mType == 1)
		{
			ofst << "Ragdoll";
		}
		else if (mType == 2)
		{
			ofst << "Plasticine";
		}
		OutCountry(ofst);
		ofst << ", Count of vowels = " << VowelsCount() << endl;
	}
}
//����������� ������� ������ ��� OutCartoons
void Cartoon::OutCartoon(ofstream& ofst, Movie* mv) 
{
	Out(ofst);
}