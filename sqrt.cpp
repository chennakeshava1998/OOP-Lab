#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	cout << setprecision(4) ;
	int n;
	cout << fixed;
	cout << "Enter a number\n";
	cout.width(10);
	cin >> n;
	cout << sqrt(n) << endl;
	cout.fill('x');
	cout.width(10);
	cout << right << sqrt(n) << endl;


	return 0;
}
