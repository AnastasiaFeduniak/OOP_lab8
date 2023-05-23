#include "pch.h"
#include "../lab8_un/Functions.cpp"
TEST(UList, Ugetters) {
	UList a;
	EXPECT_EQ(a.getFirstEl(), 0);
	EXPECT_EQ(a.getLastEl(), 0);
	EXPECT_EQ(a.getNumOfEl(), 0);
	vector<double> test = { 5.7, 34, 0.4, 23.3, 5.4 };
	UList b(test);
	EXPECT_EQ(b.getFirstEl(), 5.7);
	EXPECT_EQ(b.getLastEl(), 5.4);
	EXPECT_EQ(b.getNumOfEl(), 5);
	a = b;
	EXPECT_EQ(a.getFirstEl(), 5.7);
	EXPECT_EQ(a.getLastEl(), 5.4);
	EXPECT_EQ(a.getNumOfEl(), 5);

}
TEST(UList, UfindValue) {
	UList a;
	vector<double> test = { 40.3, 34, 0.4, 23.3, 0.1 };
	vector<double> test1 = { 0.1 , 34, 0.4, 6.5, 5.6, 23.3, 38.4 };
	UList b(test);
	UList c(test1);
	EXPECT_EQ(a.findMax(), NULL);
	EXPECT_EQ(b.findMax(), 40.3);
	EXPECT_EQ(c.findMax(), 38.4);
	EXPECT_EQ(a.findMin(), NULL);
	EXPECT_EQ(b.findMin(), 0.1);
	EXPECT_EQ(c.findMin(), 0.1);
	EXPECT_EQ(a.findAVG(), NULL);
	EXPECT_NEAR(b.findAVG(), 19.62, 0.01);
	EXPECT_NEAR(c.findAVG(), 15.47, 0.01);
}
TEST(UList, Usorting) {
	UList a;
	vector<double> test = { 40.3, 34, 0.4, 23.3, 0.1 };
	vector<double> expected1_1 = { 40.3, 34, 23.3, 0.4, 0.1 };
	vector<double> expected1_2 = { 0.1, 0.4, 23.3, 34, 40.3 };
	UList b(test);
	EXPECT_NO_THROW(a.choiceSort());
	EXPECT_NO_THROW(a.choiceSort());
	b.choiceSort();
	for (int i = 0; i < b.getNumOfEl(); i++)
	{
		EXPECT_EQ(b[i], expected1_1[i]);
	}
	b.bubbleSort();
	for (int i = 0; i < b.getNumOfEl(); i++)
	{
		EXPECT_EQ(b[i], expected1_2[i]);
	}

}

TEST(UList, Uskalyar)
{
	UList a;
	vector<double> test = { 40.3, 34, 0.4, 23.3, 0.1 };
	vector<double> expected1_1 = { 0, 0, 0, 0, 0 };
	vector<double> expected1_2 = { 20.15, 17, 0.2, 11.65, 0.05 };
	vector<double> expected1_3 = { 4030, 3400, 40, 2330, 10 };
	UList b(test);
	a = b;
	b.skalyar(0);
	for (int i = 0; i < b.getNumOfEl(); i++) {
		EXPECT_NEAR(b[i], expected1_1[i], 0.01);
	}
	b = a;
	b.skalyar(0.5);
	for (int i = 0; i < b.getNumOfEl(); i++) {
		EXPECT_NEAR(b[i], expected1_2[i], 0.01);
	}
	b = a;
	b.skalyar(100);
	for (int i = 0; i < b.getNumOfEl(); i++) {
		EXPECT_NEAR(b[i], expected1_3[i], 0.01);
	}
}
TEST(operator, UplusAndMinus)
{
	UList a;
	vector<double> test = { 40.3, 34, 0.4, 23.3, 0.1 };
	vector<double> expected1_1 = { 40.3, 34, 0.4, 23.3, 0.1, 5.3, 0.2 };
	vector<double> expected1_2 = { 40.3, 34, 0.4 };
	UList b(test);
	EXPECT_NO_THROW(a.operator-());
	EXPECT_NO_THROW(a.operator+(5.3));
	EXPECT_EQ(a[0], 5.3);
	a.operator+(4.3);
	a.operator-();
	a.operator-();
	EXPECT_NO_THROW(a.operator-());
	b.operator+(5.3);
	b.operator+(0.2);
	for (int i = 0; i < expected1_1.size(); i++) {
		EXPECT_EQ(b[i], expected1_1[i]);
	}
	b.operator-();
	b.operator-();
	b.operator-();
	b.operator-();
	for (int i = 0; i < expected1_2.size(); i++) {
		EXPECT_EQ(b[i], expected1_2[i]);
	}
}
TEST(operator, Uequal)
{
	UList a;
	vector<double> test = { 40.3, 34, 0.4, 23.3, 0.1 };
	vector<double> test1 = { 4.3, 5.6, 1.3 };
	UList b(test); UList c(test1);
	a = b;
	for (int i = 0; i < a.getNumOfEl(); i++) {
		EXPECT_EQ(b[i], a[i]);
	}
	b = c;
	a = move(c);
	for (int i = 0; i < a.getNumOfEl(); i++) {
		EXPECT_EQ(b[i], a[i]);
	}
	EXPECT_EQ(c.getNumOfEl(), 0);
	EXPECT_EQ(a[2], 1.3);
	EXPECT_FALSE(a[6]);
}
TEST(UList, output) {
	ostringstream out;
	UList a;
	out << a;
	EXPECT_EQ("\n", out.str());
	std::ostringstream out1;
	vector<double> test = { 40.3, 34, 0.4 };
	UList b(test);
	out1 << b;
	EXPECT_EQ("40.3 34 0.4 \n", out1.str());
}
TEST(UList, input)
{
	UList test;
	istringstream input("3\n1.2\n3.4\n-5.6\n");
	input >> test;
	EXPECT_EQ(test.getNumOfEl(), 3);
	EXPECT_EQ(test[0], 1.2);
	EXPECT_EQ(test[1], 3.4);
	EXPECT_EQ(test[2], -5.6);
}
TEST(UList, InputOtputExcepton)
{
	UList test;
	istringstream input("3\nsdf\n5\n34\n");
	input >> test;
	EXPECT_FALSE(input);
}
TEST(UList, EmptyListException)
{
	UList r;
	EXPECT_FALSE(r.findAVG());
	EXPECT_EQ(r.findAVG(), 0);
	EXPECT_FALSE(r.findMin());
	EXPECT_EQ(r.findMin(), 0);
	EXPECT_FALSE(r.findMax());
	EXPECT_EQ(r.findMax(), 0);

	EXPECT_FALSE(r.getFirstEl());
	EXPECT_EQ(r.getFirstEl(), 0);
	EXPECT_FALSE(r.getLastEl());
	EXPECT_EQ(r.getLastEl(), 0);
}
TEST(UList, AddSubtException)
{
	vector<double> a = { 3.5, 4.5 };
	vector<double> b = { 4.5, 7.1, 4, 7 };
	vector<double> c = { 0, 1 };
	UList u(a);
	UList x(b);
	UList i(c);
	UList p;
	p = u + x;
	EXPECT_EQ(p.getNumOfEl(), 0);
	EXPECT_EQ(p.getFirstEl(), 0);
	EXPECT_EQ(p.getLastEl(), 0);
	p = u + i;
	for (int s = 0; s < u.getNumOfEl(); s++)
	{
		EXPECT_EQ(p[s], u[s] + i[s]);
	}
	p = u - x;
	EXPECT_EQ(p.getNumOfEl(), 0);
	EXPECT_EQ(p.getFirstEl(), 0);
	EXPECT_EQ(p.getLastEl(), 0);
	p = u - i;
	for (int s = 0; s < u.getNumOfEl(); s++)
	{
		EXPECT_EQ(p[s], u[s]-i[s]);
	}
}
TEST(UList, ArrayException)
{
	vector<double> b = { 4.5, 7.1, 4, 7 };
	UList u(b);
	EXPECT_TRUE(u[2]);
	EXPECT_EQ(u[2], 4);
	EXPECT_FALSE(u[10]);
	EXPECT_EQ(u[6], 0);
}

TEST(UList, DynamicOverload)
{
	vector<UList> a;
	vector<double> y = {2};
	
	try
	{
		UList r;
		UList* f = r.getArray(120000000000000);
		FAIL();

	} catch(OutOfMemoryException r)
	{
		EXPECT_STREQ(r.what(), "Out of memory.");
	}

}