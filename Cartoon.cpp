#include <iostream>
#include "Cartoon.h"

using namespace std;

void Cartoon::InData(ifstream& ifst) 
{
	int Line;
	ifst >> Line;
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

void Cartoon::Out(ofstream& ofst) 
{
	ofst << "It is CARTOON movie called "; 
	OutCommon(ofst);
	ofst << ", Creation type = ";
	if (mType == 0)
	{
		ofst << "Drawned" << endl;
	}
	else if (mType == 1)
	{
		ofst << "Ragdoll" << endl;
	}
	else if (mType == 2)
	{
		ofst << "Plasticine" << endl;
	}
}

void Cartoon::OutCartoon(ofstream& ofst, Movie* mv) 
{
	Out(ofst);
}