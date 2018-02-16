#include<bits/stdc++.h>
using namespace std;

class T
{
	int h, m, s;
public:
	T(int x, int y, int z)
	{
		h = x;
		m = y;
		s = z;
	}

	T()
	{
		h = 0;
		m = 0;
		s = 0;
	}

	void operator++(int)
	{
		int temp = h*3600 + m*60 + s;
		temp++;
		
		h = temp/3600;
		temp = temp%3600;
		h = h%24;

		m = temp/60;
		m = m%60;
		temp = temp%60;

		s = temp;
	}

	void disp()
	{
		cout<<"Time:\nhours = "<<h<<"\nminutes = "<<m<<"\nseconds = "<<s<<"\n"; 
	}
};

int main()
{
	cout<<"Enter time in HH:MM:SS 24 hour format\n";
	int h, m, s;
	cin >> h >> m >> s;

	if(h<0 || m < 0 || s < 0)
	{
		cout<<"Invalid operands\n";
		exit(1);
	}

	if(h>=24 || m > 59 || s > 59)
	{
		cout<<"Invalid operands\n";
		exit(1);
	}

	T first(h, m, s);
	
	first.disp();
	first++;
	cout<<"After incrementing the time by one second:\n";
	first.disp();

}
