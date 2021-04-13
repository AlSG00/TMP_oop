#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>

#include "../Container.h"
#include "../Container.cpp"

#include "../Movie.h"
#include "../Movie.cpp"

#include "../Cartoon.h"
#include "../Cartoon.cpp"

#include "../Fiction.h"
#include "../Fiction.cpp"

#include "../Documentary.h"
#include "../Documentary.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		//Проверка функции In для контейнера на 7 элементов
		TEST_METHOD(ContainerInSeven) 
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/InSeven.txt");
			Container c = Container();
			c.In(ifst);
			int actual = c.len;
			Assert::AreEqual(7, actual);
			c.Clear();
		}
		//Проверка функции In для пустого контейнера
		TEST_METHOD(ContainerInEmpty)
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/InEmpty.txt");
			Container c = Container();
			c.In(ifst);
			int actual = c.len;
			Assert::AreEqual(0, actual);
			c.Clear();
		}
		//Проверка функции In для Movie с некорректными входными данными
		TEST_METHOD(MovieInCorrupted)
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/InCorruptedThree.txt");
			Container c = Container();
			c.In(ifst);
			int actual = c.len;
			Assert::AreEqual(2, actual);
			c.Clear();
		}
		//Проверка функции Sort для контейнера на 7 элементов
		TEST_METHOD(ContainerSortSeven)
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/InSeven.txt");
			ofstream ofst("D:/TMP/TMP_oop/UnitTest/Out.txt");
			Container c = Container();
			c.In(ifst);
			c.Sort();
			c.Out(ofst);
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_oop/UnitTest/Out.txt");
			ifstream fin_exp("D:/TMP/TMP_oop/UnitTest/OutSortedSevenSample.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual);
			c.Clear();
		}
		//Проверка функции Sort для пустого контейнера
		TEST_METHOD(ContainerSortEmpty)
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/InEmpty.txt");
			ofstream ofst("D:/TMP/TMP_oop/UnitTest/Out.txt");
			Container c = Container();
			c.In(ifst);
			c.Sort();
			c.Out(ofst);
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_oop/UnitTest/Out.txt");
			ifstream fin_exp("D:/TMP/TMP_oop/UnitTest/OutSortedEmptySample.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual);
			c.Clear();
		}
		//Проверка функции Sort для контейнера с одним элементом
		TEST_METHOD(ContainerSortOne)
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/InSortOne.txt");
			ofstream ofst("D:/TMP/TMP_oop/UnitTest/Out.txt");
			Container c = Container();
			c.In(ifst);
			c.Sort();
			c.Out(ofst);
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_oop/UnitTest/Out.txt");
			ifstream fin_exp("D:/TMP/TMP_oop/UnitTest/OutSortedOneSample.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual);
			c.Clear();
		}
		//Проверка функции Sort для контейнера с двумя элементами
		TEST_METHOD(ContainerSortTwo)
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/InTwo.txt");
			ofstream ofst("D:/TMP/TMP_oop/UnitTest/out.txt");
			Container c = Container();
			c.In(ifst);
			c.Sort();
			c.Out(ofst);
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_oop/UnitTest/Out.txt");
			ifstream fin_exp("D:/TMP/TMP_oop/UnitTest/OutSortedTwoSample.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual);
			c.Clear();
		}
		//Проверка функции OutCartoon для пустого контейнера
		TEST_METHOD(OutCartoonEmpty)
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/InEmpty.txt");
			ofstream ofst("D:/TMP/TMP_oop/UnitTest/Out.txt");
			Container c = Container();
			c.In(ifst);
			c.OutCartoons(ofst);
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_oop/UnitTest/Out.txt");
			ifstream fin_exp("D:/TMP/TMP_oop/UnitTest/OutEmptySample.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual);
			c.Clear();
		}
		//Проверка функции OutCartoon контейнера без cartoons
		TEST_METHOD(ContainerWithoutCartoons)
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/InWithoutCartoonsFive.txt");
			ofstream ofst("D:/TMP/TMP_oop/UnitTest/Out.txt");
			Container c = Container();
			c.In(ifst);
			c.OutCartoons(ofst);
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_oop/UnitTest/Out.txt");
			ifstream fin_exp("D:/TMP/TMP_oop/UnitTest/outWithoutCartoonsSample.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual);
			c.Clear();
		}
		//Проверка функции InData на поведение в случае переполнения
		TEST_METHOD(MovieInDataOverbuf)
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/InOverbufOne.txt");
			ofstream ofst("D:/TMP/TMP_oop/UnitTest/Out.txt");
			Container c = Container();
			c.In(ifst);
			c.Out(ofst);
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_oop/UnitTest/Out.txt");
			ifstream fin_exp("D:/TMP/TMP_oop/UnitTest/OutOverbufOneSample.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual);
			c.Clear();
		}
		//Проверка функции VowelCount в случае 0 гласных
		TEST_METHOD(CountOfVowelEmpty)
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/InVowelsEmpty.txt");
			ofstream ofst("D:/TMP/TMP_oop/UnitTest/Out.txt");
			Container c = Container();
			c.In(ifst);
			c.Out(ofst);
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_oop/UnitTest/Out.txt");
			ifstream fin_exp("D:/TMP/TMP_oop/UnitTest/OutVowelsEmptySample.txt");
			getline(fin_act, actual, '\0');
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual);
			c.Clear();
		}
		//Проверка функции VowelCount в случае 5 гласных
		TEST_METHOD(CountOfVowelFive)
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/InVowelsFive.txt");
			ofstream ofst("D:/TMP/TMP_oop/UnitTest/Out.txt");
			Container c = Container();
			c.In(ifst);
			c.Out(ofst);
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_oop/UnitTest/Out.txt");
			ifstream fin_exp("D:/TMP/TMP_oop/UnitTest/OutVowelsFiveSample.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual);
			c.Clear();
		}
		//Проверка очистки контейнера при отсутствии элементов
		TEST_METHOD(ClearEmptyContainer)
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/InEmpty.txt");
			Container c = Container();
			c.In(ifst);
			c.Clear();
			Assert::AreEqual(c.len, 0);
		}
	};
}
