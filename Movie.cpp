#include "Movie.h"
#include "Cartoon.h"
#include "Fiction.h"
#include "Documentary.h"
#include <iostream>
#include <string>

using namespace std;

Movie* Movie::In(ifstream& ifst) 
{
	Movie* mv;
	int k;
	ifst >> k;
	if (ifst.fail())
	{
		ifst.clear();
		ifst.ignore(numeric_limits<streamsize>::max(), '\n');
		return 0;
	}
	else
	{
		switch (k)
		{
		case 1:
			mv = new Cartoon;
			break;
		case 2:
			mv = new Fiction;
			break;
		case 3:
			mv = new Documentary;
			break;
		default:
			char Junk[50];
			ifst.getline(Junk, 50);
			ifst.getline(Junk, 50);
			ifst.getline(Junk, 50);
			return 0;
		}
		string Line; //Временное решение на случай переполнения
		getline(ifst, Line); 
		getline(ifst, Line); 
		Line.resize(49);
		strcpy_s(mv->mName, 50, Line.c_str());
		mv->InData(ifst);
		
		Line.clear();
		ifst >> Line;
		Line.resize(49);
		strcpy_s(mv->mCountry, 50, Line.c_str());
		Line.clear();
		return mv;
	}
}

void Movie::OutCartoon(ofstream& ofst, Movie* sp)
{
	ofst << endl;
}

void Movie::InCommon(ifstream& ifst)
{
	ifst >> mName;
};

void Movie::OutCommon(ofstream& ofst)
{
	ofst << mName;
};

int Movie::VowelsCount()
{
	int vowel = 0;
	int i = 0;
	while (mName[i] != '\0')
	{
		switch (mName[i])
		{
		case 'A':
		case 'a':
		case 'E':
		case 'e':
		case 'I':
		case 'i':
		case 'O':
		case 'o':
		case 'U':
		case 'u':
			vowel++;
		}
		i++;
	}
	return vowel;
};

bool Movie::Compare(Movie& second)
{
	return VowelsCount() > second.VowelsCount();
}

void Movie::OutCountry(ofstream& ofst)
{
	ofst << ", Made in : " << mCountry;
};