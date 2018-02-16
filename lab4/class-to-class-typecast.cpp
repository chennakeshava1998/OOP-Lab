#include<bits/stdc++.h>
using namespace std;

class B
{
	
public:
	int h, m, s;
	B(int x, int y, int z)
	{
		h = x;
		m = y;
		s = z;
	}

	void disp()
	{
		cout<<"Time:\nhours = "<<h<<"\nminutes = "<<m<<"\nseconds = "<<s<<"\n"; 
	}
};

class A
{
	int t;
public:
	A(int x)
	{
		t = x;
	}

	A(B tmp)
	{
		t = tmp.h*3600 + tmp.m*60 + tmp.s;
	}

	void disp()
	{
		cout<<"Object-A : Total Time = "<<t<<endl;
	}

};

int main()
{
	cout<<"Enter time in HH:MM:SS 24 hour format\n";
	int h, m, s;
	cin >> h >> m >> s;
	B obj_b(h, m, s);
	obj_b.disp();

	cout<<"Typecasting to object A:\n";

	A obj_a(obj_b);
	obj_a.disp();


}