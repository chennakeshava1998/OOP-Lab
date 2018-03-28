#include<fstream>
#include<iostream>

using namespace std;

int main()
{
	ifstream is1("country.txt", ios::in | ios::binary);
	ifstream is2("capital.txt", ios::in | ios::binary);

	char a[100], b[100];
	cout << "Country" << "\t\t\t" << "Capital\n";
	while(is1.getline(a, 100))
	{
		is2.getline(b, 100);
		cout << a << "\t\t" << b << "\n";
	}

	return 0;
}