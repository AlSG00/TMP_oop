#include "Movie.h"

class Container 
{
    enum { max_len = 100 }; // максимальная длина
    int len; // текущая длина
    Movie* cont[max_len];
public:
    void In(ifstream& ifst); // ввод
    void Out(ofstream& ofst); // вывод
    void Sort();
    void Clear(); // очистка контейнера от фигур
    Container(); // инициализация контейнера
    ~Container() { Clear(); } // утилизация контейнера
};