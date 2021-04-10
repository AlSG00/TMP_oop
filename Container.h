#pragma once
#include "Movie.h"

class Container 
{
    enum { max_len = 100 }; // максимальная длина
    Movie* cont[max_len];
public:
    int len; // текущая длина
    void In(ifstream& ifst); // ввод
    void Out(ofstream& ofst); // вывод
    void Sort();
    void Clear(); // очистка контейнера от фигур
    void OutCartoons(ofstream& ofst);
    Container(); // инициализация контейнера
    ~Container() { Clear(); } // утилизация контейнера
};