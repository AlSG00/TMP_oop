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

void Documentary::MultiMethod(Movie* other, ofstream& ofst)
{
	other->MMDocumentary(ofst);
};

void Documentary::MMCartoon(ofstream& ofst)
{
	ofst << "Cartoon and Documentary." << endl;
};

void Documentary::MMFiction(ofstream& ofst)
{
	ofst << "Fiction and Documentary." << endl;
};

void Documentary::MMDocumentary(ofstream& ofst)
{
	ofst << "Documentary and Documentary." << endl;
};