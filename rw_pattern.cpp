#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char s[100];
	cout << "Enter your name\n";
	cin.getline(s, 100, '\n');

	for(int i=1;i<=strlen(s);++i)
	{
		cout.write(s, i);
		cout << "\n";
	}

	return 0;
}
