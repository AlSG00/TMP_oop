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
	switch (k) {
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
		char Junk[50]; //дл€ мусора
		ifst.getline(Junk, 50);
		ifst.getline(Junk, 50);
		ifst.getline(Junk, 50);
		return 0;
	}
	string Line; //¬ременное решение на случай переполнени€
	getline(ifst, Line); //—трока заноситс€ в Line
	getline(ifst, Line); //—трока заноситс€ в Line
	if (Line.length() < 50) 
	{ //ѕроверка на переполнение - если длина Line < 50
		strcpy_s(mv->mName, 50, Line.c_str());
		mv->InData(ifst);
		ifst >> mv->mCountry;
		return mv;
	}
	else 
	{ //иначе придетс€ отсечь лишнее
		Line.resize(49);
		strcpy_s(mv->mName, 50, Line.c_str());
		mv->InData(ifst);
		ifst >> mv->mCountry;
		return mv;
	}
	Line.clear();
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

