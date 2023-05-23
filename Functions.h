#pragma once
#include <iostream>

#include <vector>
#include<limits>
#include <cmath>

using namespace std;

struct Element
{
    double ch;
    Element* next;
};
class UList
{
private:
    unique_ptr<Element*> begin;
    unique_ptr<Element*> end;
    int count;
public:
    UList();
    UList(vector<double> a);
    UList(UList& a);
    UList(UList&& a) noexcept;
    ~UList();
    void show();
    double getFirstEl();
    double getLastEl();
    double getNumOfEl();
    double findMax();
    double findMin();
    double findAVG();
    void bubbleSort();
    void choiceSort();
    void skalyar(double a);
    friend ostream& operator << (ostream& out, UList& a);
    double operator[](int index);
    friend istream& operator >> (istream& in, UList& a);
    UList& operator=(UList& b);
    UList& operator=(UList&& b) noexcept;
    UList operator - ();
    UList operator+(double b);
    UList operator+(UList& a);
    UList operator-(UList& a);
    UList* getArray(int num);

};
