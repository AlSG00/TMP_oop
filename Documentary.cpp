#include <iostream>
#include "Documentary.h"

using namespace std;

void Documentary::InData(ifstream& ifst)
{
	int Line;
	ifst >> Line;
	
	if (ifst.fail())
	{
		return;
	}
	else
	{
		mYear = Line;
	}
}

void Documentary::Out(ofstream& ofst)
{
	if (1900 > mYear || 2030 < mYear)
	{
		ofst << "It is DOCUMENTARY and there is ERROR in Year " << endl;
	}
	else
	{
		ofst << "It is DOCUMENTARY movie called ";
		OutCommon(ofst);
		ofst << ", Release Year = ";
		ofst << mYear;
		OutCountry(ofst);
		ofst << ", Count of vowels = " << VowelsCount() << endl;
	}
}