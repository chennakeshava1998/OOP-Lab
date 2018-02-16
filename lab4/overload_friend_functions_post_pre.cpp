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

	friend void operator++(T &obj);
	friend void operator++(T &obj, int);

	void disp()
	{
		cout<<"Time:\nhours = "<<h<<"\nminutes = "<<m<<"\nseconds = "<<s<<"\n"; 
	}
};

void operator++(T &t)
{
	int temp = t.h*3600 + t.m*60 + t.s;
	temp++;
	
	t.h = temp/3600;
	temp = temp%3600;
	t.h = t.h%24;

	t.m = temp/60;
	t.m = t.m%60;
	temp = temp%60;

	t.s = temp;
}


void operator++(T &t, int)
{
	int temp = t.h*3600 + t.m*60 + t.s;
	temp++;
	
	t.h = temp/3600;
	temp = temp%3600;
	t.h = t.h%24;

	t.m = temp/60;
	t.m = t.m%60;
	temp = temp%60;

	t.s = temp;
}


int main()
{
	cout<<"Enter time in HH:MM:SS 24 hour format to check overloading of preincrement using friend function\n";
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
	++first;
	cout<<"After incrementing the time by one second:\n";
	first.disp();

	cout<<"Enter time in HH:MM:SS 24 hour format to check overloading of postincrement using friend function\n";
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

	T post(h, m, s);
	
	post.disp();
	++post;
	cout<<"After incrementing the time by one second:\n";
	post.disp();
}
