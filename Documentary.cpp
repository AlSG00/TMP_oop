#include <iostream>
#include "Documentary.h"

using namespace std;

void Documentary::InData(ifstream& ifst)
{
	ifst >> mYear;
}

void Documentary::Out(ofstream& ofst)
{
	ofst << "It is DOCUMENTARY movie called ";
	OutCommon(ofst);
	ofst << ", Release Year = ";
	ofst << mYear << endl;
}