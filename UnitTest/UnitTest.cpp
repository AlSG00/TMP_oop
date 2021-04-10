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
		
		TEST_METHOD(Container_In_7) //Ïðîâåðêà ôóíêöèè In äëÿ êîíòåéíåðà
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/in_7.txt");
			Container c = Container();
			c.In(ifst);
			int actual = c.len;
			Assert::AreEqual(7, actual);//OK
			c.Clear();
		}
		TEST_METHOD(Container_In_0) //Ïðîâåðêà ôóíêöèè In äëÿ êîíòåéíåðà
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/in_0.txt"); //Â ôàéëå ïóñòî
			Container c = Container();
			c.In(ifst);
			int actual = c.len;
			Assert::AreEqual(0, actual);//OK
			c.Clear();
		}
		TEST_METHOD(Movie_In_3) //Ïðîâåðêà ôóíêöèè In äëÿ Movie
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/in_3_with_incorrect_keys.txt");
			Container c = Container();
			c.In(ifst);
			int actual = c.len;
			Assert::AreEqual(2, actual);//OK
			c.Clear();
		}
		TEST_METHOD(Container_Sort_7) //Ïðîâåðêà ôóíêöèè Sort äëÿ êîíòåéíåðà
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/in_7.txt"); //Â ôàéëå 7 ôèëüìîâ
			ofstream ofst("D:/TMP/TMP_oop/UnitTest/out.txt");
			Container c = Container();
			c.In(ifst);
			c.Sort();
			c.Out(ofst);
			//òóò ñðàâíåíèå äâóõ ôàéëîâ
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_oop/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_oop/UnitTest/out_7_SORTED.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			c.Clear();
		}
		TEST_METHOD(Container_Sort_0) //Ïðîâåðêà ôóíêöèè Sort äëÿ ïóñòîãî êîíòåéíåðà
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/in_0.txt"); //Â ôàéëå ïóñòî
			ofstream ofst("D:/TMP/TMP_oop/UnitTest/out.txt");
			Container c = Container();
			c.In(ifst);
			c.Sort();
			c.Out(ofst);
			//òóò ñðàâíåíèå äâóõ ôàéëîâ
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_oop/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_oop/UnitTest/out_0_SORTED.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			c.Clear();
		}
		TEST_METHOD(Container_Sort_1) //Ïðîâåðêà ôóíêöèè Sort äëÿ êîíòåéíåðà ñ îäíèì ýëåìåíòîì
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/in_1.txt"); //Â ôàéëå îäèí ýëåìåíò
			ofstream ofst("D:/TMP/TMP_oop/UnitTest/out.txt");
			Container c = Container();
			c.In(ifst);
			c.Sort();
			c.Out(ofst);
			//òóò ñðàâíåíèå äâóõ ôàéëîâ
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_oop/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_oop/UnitTest/out_1_SORTED.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			c.Clear();
		}
		TEST_METHOD(Container_Sort_2) //Ïðîâåðêà ôóíêöèè Sort äëÿ êîíòåéíåðà ñ äâóìÿ ýëåìåíòàìè
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/in_2.txt"); //Â ôàéëå äâà ýëåìåíòà
			ofstream ofst("D:/TMP/TMP_oop/UnitTest/out.txt");
			Container c = Container();
			c.In(ifst);
			c.Sort();
			c.Out(ofst);
			//òóò ñðàâíåíèå äâóõ ôàéëîâ
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_oop/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_oop/UnitTest/out_2_SORTED.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			c.Clear();
		}
		TEST_METHOD(Container_OutCartoon_0) //Ïðîâåðêà ôóíêöèè OutCartoon äëÿ ïóñòîãî êîíòåéíåðà
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/in_0.txt"); //Â ôàéëå ïóñòî
			ofstream ofst("D:/TMP/TMP_oop/UnitTest/out.txt");
			Container c = Container();
			c.In(ifst);
			c.OutCartoons(ofst);
			//òóò ñðàâíåíèå äâóõ ôàéëîâ
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_oop/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_oop/UnitTest/out_0_IDEAL.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			c.Clear();
		}
		TEST_METHOD(Container_OutCartoon_without_cartoons) //Ïðîâåðêà ôóíêöèè OutCartoon êîíòåéíåðà áåç cartoons
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/in_5_without_cartoons.txt"); //Â ôàéëå 5 ôèëüìîâ
			ofstream ofst("D:/TMP/TMP_oop/UnitTest/out.txt");
			Container c = Container();
			c.In(ifst);
			c.OutCartoons(ofst);
			//òóò ñðàâíåíèå äâóõ ôàéëîâ
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_oop/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_oop/UnitTest/out_5_without_cartoons_IDEAL.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			c.Clear();
		}
		TEST_METHOD(Movie_InData_OverBuf) //Ïðîâåðêà ôóíêöèè InData íà ïîâåäåíèå â ñëó÷àå ïåðåïîëíåíèÿ
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/in_1_overbuf.txt"); //Â ôàéëå îäèí cartoon ñ âûðàæåíèåì > 50 ñèìâîëîâ
			ofstream ofst("D:/TMP/TMP_oop/UnitTest/out.txt");
			Container c = Container();
			c.In(ifst);
			c.Out(ofst);
			//òóò ñðàâíåíèå äâóõ ôàéëîâ
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_oop/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_oop/UnitTest/out_1_overbuf_IDEAL.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			c.Clear();
		}
		TEST_METHOD(Movie_CountOfVowel_0) //Ïðîâåðêà ôóíêöèè VowelCount â ñëó÷àå 0 ãëàñíûõ
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/in_0_vowels.txt"); //Â âûðàæåíèè íåò ãëàñíûõ
			ofstream ofst("D:/TMP/TMP_oop/UnitTest/out.txt");
			Container c = Container();
			c.In(ifst);
			c.Out(ofst);
			//òóò ñðàâíåíèå äâóõ ôàéëîâ
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_oop/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_oop/UnitTest/out_0_vowels_IDEAL.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			c.Clear();
		}
		TEST_METHOD(Movie_CountOfVowel_5) //Ïðîâåðêà ôóíêöèè VowelCount â ñëó÷àå 5 ãëàñíûõ
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/in_5_vowels.txt"); //Â âûðàæåíèè 5 ãëàñíûõ
			ofstream ofst("D:/TMP/TMP_oop/UnitTest/out.txt");
			Container c = Container();
			c.In(ifst);
			c.Out(ofst);
			//òóò ñðàâíåíèå äâóõ ôàéëîâ
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_oop/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_oop/UnitTest/out_5_vowels_IDEAL.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			c.Clear();
		}
		TEST_METHOD(Container_Clean_0) //Ïðîâåðêà î÷èñòêè êîíòåéíåðà ïðè îòñóòñòâèè ýëåìåíòîâ
		{
			ifstream ifst("D:/TMP/TMP_oop/UnitTest/in_0.txt"); //Â ôàéëå ïóñòî
			Container c = Container();
			c.In(ifst);
			c.Clear();
			Assert::AreEqual(c.len, 0); //OK
		}
	};
}
