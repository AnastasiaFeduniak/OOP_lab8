#include <csignal>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>
#include <windows.h>
#include <iostream>
#include <exception>
#include "Errors.h"
#include "Functions.h"
using namespace std;
int main(void)
{
	vector<double> a = { 3.5, 4.5 };
	vector<double> b = { 4.5, 7.1, 4, 7 };
	vector<double> c = { 0, 1 };
	UList u(a);
	UList x(b);
	UList i(c);
	UList p;
	UList w;
	p = u + i;
	for (int s = 0; s < u.getNumOfEl(); s++)
	{
		cout << p[s] << "  " << u[s] + i[s] << endl;
	}
	cout << endl;
	p = u + x;
	/*for (int s = 0; s < u.getNumOfEl(); s++)
	{
		cout << p[s] << "  " << u[s] << endl;
	}*/
	cout << endl;
	p = u - x;
	for (int s = 0; s < u.getNumOfEl(); s++)
	{
		cout << p[s] << "  " << u[s] << endl;
		
	}
	cout << endl;
	p = u - i;
	for (int s = 0; s < u.getNumOfEl(); s++)
	{
		cout << p[s] << "  " << u[s]-i[s] << endl;
	
	}
}