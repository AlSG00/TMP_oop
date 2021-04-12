#include "Container.h"

void Container::MultiMethod(ofstream& ofst)
{
	ofst << endl << "Multimethod." << endl;
	if (&cont != nullptr)
	{
		for (int i = 0; i < len - 1; i ++) 
		{
			for (int j = i + 1; j < len; j++)
			{
				ofst << endl;
				cont[i]->MultiMethod(cont[j], ofst);
				cont[i]->Out(ofst);
				cont[j]->Out(ofst);
			}
		}
	}
	else
	{
		ofst << "Container is empty!" << endl;
	}
}