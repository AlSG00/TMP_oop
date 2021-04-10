#include "Movie.h"

class Container 
{
    enum { max_len = 100 }; // ������������ �����
    int len; // ������� �����
    Movie* cont[max_len];
public:
    void In(ifstream& ifst); // ����
    void Out(ofstream& ofst); // �����
    void Sort();
    void Clear(); // ������� ���������� �� �����
    Container(); // ������������� ����������
    ~Container() { Clear(); } // ���������� ����������
};