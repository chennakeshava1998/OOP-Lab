#include<iostream>
using namespace std;

int main()
{
	cout << "Enter something:\n";
	char ch;

	while(cin >> noskipws >> ch)
	{
		cout.put(ch);
		cout << " ";
	}

	cout << "\n";

	return 0;
}