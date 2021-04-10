#include "Container.h"

Container::Container() : len(0) 
{ 
}

// Очистка контейнера от элементов
void Container::Clear() 
{
    for (int i = 0; i < len; i++) 
    {
        delete cont[i];
    }
    len = 0;
}

void Container::In(ifstream& ifst)
{
    while (!ifst.eof())
    {
        if (len <= max_len)
        {
            if ((cont[len] = Movie::In(ifst)) != 0)
            {
                len++;
            }
        }
        else
        {
            break;
        }
    }
}

void Container::Out(ofstream& ofst)
{
    ofst << "Container contents " << len << " elements." << endl;
    for (int i = 0; i < len; i++)
    {
        ofst << i << ": ";
        cont[i]->Out(ofst);
    }
}
