#pragma once
#include "Movie.h"

class Container 
{
    enum { max_len = 100 }; // ������������ �����
    Movie* cont[max_len];
public:
    int len; // ������� �����
    void In(ifstream& ifst); // ����
    void Out(ofstream& ofst); // �����
    void Sort();
    void Clear(); // ������� ���������� �� �����
    void OutCartoons(ofstream& ofst);
    Container(); // ������������� ����������
    ~Container() { Clear(); } // ���������� ����������
};